require 'yaml'
require 'pathname'

class MakeBuilder
	
	def create_make_file source_root, include_path, build_root,  build_target, truncate_output_path_by, makefile_name
		@include_path_list = include_path.split /:/
		@directories = []
		@truncate_by = truncate_output_path_by.to_i
		process_directory source_root
		makefile = "#{build_target}:"
		@directories.each{| dir | makefile << " #{build_root}/#{dir[:trunc]}_dir.o" }
		makefile << "\n"
		makefile << "\t@echo '====>changed' $?\n"
		makefile << "\tld -r"
		@directories.each{| dir | makefile << " #{build_root}/#{dir[:trunc]}_dir.o" }
		makefile << " -o #{build_target} \n"
		sourcefiles = {}
		@directories.each do | dir |
			makefile << "\n#{build_root}/#{dir[:trunc]}_dir.o:"
				dir [:dependencies].each{|dep| makefile << " #{build_root}/#{dep[:object]}"}
				makefile << " | #{build_root}/#{dir[:trunc]}\n"
				makefile << "\t@echo '====>changed' $?\n"
				makefile << "\tld -r"
				dir [:dependencies].each{|dep| makefile << " #{build_root}/#{dep[:object]}"}
				makefile << " -o #{build_root}/#{dir[:trunc]}_dir.o\n"
				makefile << "\n#{build_root}/#{dir[:trunc]}:\n"
				makefile << "\tmkdir -p #{build_root}/#{dir[:trunc]}\n"
		end
		@directories.each do | dir | 
			dir [:dependencies].each do |dep|
				makefile << "\n#{build_root}/#{dep[:object]}: #{dep[:name]}"
				dep[:dependencies].each{|ddep| makefile << " #{ddep}"}
				makefile << " | #{build_root}/#{dir[:trunc]}\n"
				makefile << "\t@echo '====>changed' $?\n"
				makefile << "\tg++ -c #{dep[:name]} -o #{build_root}/#{dep[:object]} -pg\n"
			end
		end
		File.open(makefile_name, 'w'){|f| f.puts makefile}
	end

	def truncate_path_by path, num
		arry = path.split /\//
		if arry.size < num
			throw "cannot truncate #{path} by #{num}"
		end
		return arry[num...arry.size].join('/') || "--"
	end

	def process_directory directory_name
		if !Dir.exists?(directory_name)
			throw "directory #{directory_name}  does not exist"
		end
		directory = {name: directory_name}
		directory[:trunc] = truncate_path_by directory_name, @truncate_by
		directory[:dependencies] = []
		has_source = false
		Dir.foreach(directory_name).grep(/^[^\.]/) do |entry|
			full_path = directory_name + "/" + entry
			if  File.directory?(full_path) 
				process_directory full_path
			else
				if entry =~ /.cpp$/
					has_source = true
					dependency = {name: full_path}
					process_dependency dependency
					directory[:dependencies] << dependency
				end
			end
		end
		@directories << directory if has_source	
	end
	
	def process_dependency dependency
		file_dependencies = {}
		dependency[:trunc] = truncate_path_by dependency[:name], @truncate_by
		dependency[:object] = dependency[:trunc].chomp(".cpp") + ".o"
		get_file_dependencies dependency[:name], file_dependencies
		dependency[:dependencies] = file_dependencies.keys
	end

	def get_file_dependencies file_name, dependencies, level = 0
		search_list = [File.dirname(file_name)] + @include_path_list
		File.open(file_name, 'r').each do |line|
			if line =~ /^\s*#\s*include\s*"(.*)"/
				begin
					path_for_header = get_file_path_for_include $1, search_list
					path_for_header = Pathname.new(path_for_header).cleanpath
				rescue Exception => e
					puts "exception while finding includes for #{file_name}"
					raise e
				end
				if !dependencies[path_for_header]
					dependencies[path_for_header] = 1
					get_file_dependencies path_for_header, dependencies, level + 1
				end
			end
		end
	end
	
	def get_file_path_for_include file_name, search_list
		search_list.each do |folder|
			full_path = folder + "/" + file_name
			return full_path if File.exists? full_path
		end
		raise "file not found #{file_name}"
	end
	
end

MakeBuilder.new.create_make_file ARGV[0], ARGV[1], ARGV[2], ARGV[3], ARGV[4], ARGV[5] 
