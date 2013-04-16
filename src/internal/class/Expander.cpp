#include "Expander.hpp"

#include <sstream>

using std::ostringstream;

namespace Internal{


	using ClassFile::CONSTANT_CLASS;
	using ClassFile::CONSTANT_UTF8;

	using ClassFile::CONSTANT_MAX_TAG;

	using ClassFile::ConstantClass;
	using ClassFile::ConstantUtf8;

	typedef std::pair<string, sp_JvmField> f_map_entry;
	typedef std::pair<string, sp_JvmMethod> m_map_entry;

	void Expander::expand_class_representation(){
		if(logger.is_info()) logger.log_info() 
			<< "expanding..." << endl;
		
		jvm_class.name = get_class_name();
		if(logger.is_info()) logger.log_info() 
			<< "name             : " << jvm_class.name << endl;
		
		if(jvm_class.name == "java/lang/Object")
			jvm_class.super_class_name = "n/a";
		else
			jvm_class.super_class_name = get_super_class_name();
		if(logger.is_debug()) logger.log_debug() 
			<< "super class name : " << jvm_class.super_class_name << endl;
		
		expand_members();
	}

	void Expander::expand_members(){
		if(logger.is_debug()) logger.log_debug() 
			<< "expanding members..." << endl;
		expand_fields();
		expand_methods();
	}

	void Expander::expand_fields(){
		if(logger.is_debug()) logger.log_debug() 
			<< "fields..." << endl;
		
		for(int index=0; index < cfr.methods.size(); index++){
			ClassFile::Member & cf_field = cfr.methods[index];
			Internal::sp_JvmField sp_jvm_field(new JvmField);
			JvmField & jvm_field = *sp_jvm_field;
			
			jvm_field.name = get_string(cf_field.name_index);
			jvm_field.descriptor = get_string(cf_field.descriptor_index);
			if(logger.is_debug()) logger.log_debug() 
				<< jvm_field.name << " : " << jvm_field.descriptor << endl;
			
			jvm_field.access_flags = cf_field.access_flags;
			if(jvm_field.is_static()){
				if(logger.is_debug()) logger.log_debug() 
					<< "static" << endl;
				sp_jvm_class->static_fields.insert(f_map_entry(jvm_field.name, sp_jvm_field));
			}else{
				if(logger.is_debug()) logger.log_debug() 
					<< "instance" << endl;
				sp_jvm_class->instance_fields.insert(f_map_entry(jvm_field.name, sp_jvm_field));
			}
		}

	}

	void Expander::expand_methods (){
		if(logger.is_debug()) logger.log_debug() 
			<< "methods..." << endl;

		for(int index=0; index < cfr.fields.size(); index++){
			ClassFile::Member & cf_method = cfr.fields[index];
			Internal::sp_JvmMethod sp_jvm_method(new JvmMethod);
			JvmMethod & jvm_method = *sp_jvm_method;
			
			jvm_method.name = get_string(cf_method.name_index);
			jvm_method.descriptor = get_string(cf_method.descriptor_index);
			if(logger.is_debug()) logger.log_debug() 
				<< jvm_method.name << " : " << jvm_method.descriptor << endl;
			
			jvm_method.access_flags = cf_method.access_flags;
			if(jvm_method.is_static()){
				if(logger.is_debug()) logger.log_debug() 
					<< "static" << endl;
				sp_jvm_class->static_methods.insert(m_map_entry(jvm_method.name, sp_jvm_method));
			}else{
				if(logger.is_debug()) logger.log_debug() 
					<< "instance" << endl;
				sp_jvm_class->instance_methods.insert(m_map_entry(jvm_method.name, sp_jvm_method));
			}
		}
	}

	string & Expander::get_class_name(){
		int name_index = ((ConstantClass*)check_and_get(cfr.this_class, CONSTANT_CLASS))->name_index;
		return get_string(name_index);
	}

	string & Expander::get_super_class_name(){
		int name_index = ((ConstantClass*)check_and_get(cfr.super_class, CONSTANT_CLASS))->name_index;
		return get_string(name_index);
	}

	// gets a string from the constant pool at the given index
	//
	string & Expander::get_string(int index){
		return ((ConstantUtf8*)check_and_get(index, CONSTANT_UTF8))->str;
	}

	//	get a pointer to a constant pool entry at a given index and
	//  check it will be castable to the required type.
	//
	//  perform bounds checking on the index and tag before comparing
	//  their types.
	//
	//	constant pool should references should all be consistent, but
	//  handle inconsistencies gracefully anyway
	//
	ConstantPoolEntry* Expander::check_and_get(int index, int tag){
		int max_index = cp.size() - 1;
		if(index < 0 || index > max_index){
			ostringstream os;
			os << "index " << index << " outside range [0-"
				<< max_index << "] in constant pool"; 
			throw JvmException (os.str());
		}
		if(tag < 1 || tag > CONSTANT_MAX_TAG){
			ostringstream os;
			os << "tag " << tag << " outside range [1-"
				<< CONSTANT_MAX_TAG << "] for constant pool"; 
			throw JvmException (os.str());
		}
		ConstantPoolEntry* entry = cp[index].get();
		if(entry->get_tag() != tag){
			ostringstream os;
			os << "tag mismatch at index " << index 
				<< ", requested " << ClassFile::tag_names[tag]
				<< ", found " << ClassFile::tag_names[entry->get_tag()];
			throw JvmException (os.str());
		}
		return entry;
	}
}