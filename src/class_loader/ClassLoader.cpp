#include "ClassLoader.hpp"

#include "class_file/ClassFileParser.hpp"

namespace Jvm{

	sp_JvmClass ClassLoader::get_class(const std::string & name, int depth = 0){
		if(logger.is_debug()) logger.log_debug() << "class loader requested class " << name << endl;
		sp_JvmClass sp_jvm_class = classes[name];
		if(sp_jvm_class.get()){
			if(logger.is_debug()) logger.log_debug() << "class " << name
				<< " already loaded" << endl;
		}else{
			if(logger.is_info()) logger.log_info() << "class " << name
				<< " not found - requesting load" << endl;
			sp_jvm_class = load_class(name, depth);
		}
		return sp_jvm_class;
	}

	sp_JvmClass ClassLoader::load_class(const std::string & name, int depth = 0){
		sp_ByteBuffer sp_byte_buffer = sp_byte_buffer_source->get_bytes(name);
		if(!sp_byte_buffer.get()){
			throw JvmException ("could not find bytes for class " + name);
		}
		ClassFileDataBuffer cfdb(sp_byte_buffer);
		sp_ClassFileRepresentation sp_cfr = ClassFileParser::parse_from_buffer(cfdb);
		sp_JvmClass sp_jvm_class(new JvmClass); 
		classes[name] = sp_jvm_class;
		sp_jvm_class->loading = true;
		sp_jvm_class->loaded = false;
		
		// cant send shared pointer to 'this' as receiver will try to clean up
		Expander(*this, sp_cfr, sp_jvm_class, depth).expand_class_representation(name);
		sp_jvm_class->loading = false;
		sp_jvm_class->loaded = true;
		return sp_jvm_class;

	}

}