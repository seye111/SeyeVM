#include "ClassLoader.hpp"

#include "class_file/ClassFileParser.hpp"

using std::endl;
using std::map;
using std::string;

namespace Jvm{

	ClassLoader::ClassLoader(Jvm & jvm, ByteBufferSource & byte_buffer_source) : 
				jvm(jvm),
				byte_buffer_source(byte_buffer_source){}


	ClassLoader::~ClassLoader(){
		if(logger.is_trace()) logger.log_trace() << "ClassLoader destructor called (delete_me) " << endl;
		for(map<string, JvmClass*>::iterator it=classes.begin(); it!=classes.end(); ++it){
			if(logger.is_trace()) logger.log_trace() << it->first << " " << it->second->name <<  endl;
			delete it->second;
		}	
		if(logger.is_trace()) logger.log_trace() << "ClassLoader destructor finished (delete_me) " << endl;
	}


	JvmClass & ClassLoader::get_class(const std::string & name, int depth = 0){
		if(logger.is_debug()) logger.log_debug() << "class loader requested class " << name << endl;
		JvmClass* p_jvm_class = classes[name];
		if(p_jvm_class){
			if(logger.is_debug()) logger.log_debug() << "class " << name
				<< " already loaded" << endl;
		}else{
			if(logger.is_info()) logger.log_info() << "class " << name
				<< " not loaded - requesting load" << endl;
			p_jvm_class = &load_class(name, depth);
			classes[name] = p_jvm_class;
		}
		if(logger.is_trace()) logger.log_trace() << "ClassLoader get returning jvm_class (delete_me)" << endl;
		return *p_jvm_class;
	}

	JvmClass & ClassLoader::load_class(const std::string & name, int depth = 0){
		ByteBuffer* byte_buffer = byte_buffer_source.get_bytes(name);
		if(!byte_buffer){
			throw JvmException ("could not find bytes for class " + name);
		}
		ClassFileDataBuffer class_file_data_buffer(byte_buffer);
		ClassFileParser class_file_parser(class_file_data_buffer);
		ClassFileRepresentation* p_class_file_representation = class_file_parser.parse_from_buffer();
		if(logger.is_trace()) logger.log_trace() << "about to create sp_jvm_class (delete_me)" << endl;
		JvmClass* p_jvm_class = new JvmClass(p_class_file_representation); 
		if(logger.is_trace()) logger.log_trace() << "back from create sp_jvm_class (delete_me)" << endl;
		p_jvm_class->loading = true;
		p_jvm_class->loaded = false;
		
		// cant send shared pointer to 'this' as receiver will try to clean up
		if(logger.is_trace()) logger.log_trace() << "about to create Expander (delete_me)" << endl;
		Expander expander(*this, *p_class_file_representation, *p_jvm_class, depth);
		if(logger.is_trace()) logger.log_trace() << "created Expander, about to call expand (delete_me)" << endl;
		expander.expand_class_representation(name);
		if(logger.is_trace()) logger.log_trace() << "back from expand (delete_me)" << endl;
		p_jvm_class->loading = false;
		p_jvm_class->loaded = true;
		if(logger.is_trace()) logger.log_trace() << "ClassLoader load returning jvm_class (delete_me)" << endl;
		return *p_jvm_class;
	}

}