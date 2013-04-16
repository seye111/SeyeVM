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

	void Expander::expand_class_representation(const string & name){
		if(logger.is_info()) logger.log_info() 
			<< indent << name << " : expanding..." << endl;
		
		jvm_class.name = get_class_name();
		if(jvm_class.name != name){
			ostringstream os;
			os << "name mismatch - expected to expand " << name
				<< " but class file representation contains "
				<< jvm_class.name << endl;
			throw JvmException (os.str());
		}
		if(jvm_class.name == "java/lang/Object"){
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : has no super class"  << endl;
		}else{
			string super_class_name = get_super_class_name();
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : super class name : " << super_class_name << endl;
			jvm_class.super_class = class_loader.get_class(super_class_name, depth + 1);
		}
		expand_interfaces();
		expand_members();
		if(logger.is_info()) logger.log_info() 
			<< indent << name << " : ...expanded" << endl;
	}

	void Expander::expand_interfaces(){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " 
			<< "expanding interfaces..." << endl;
		for(int index = 0; index < cfr.interfaces.size(); index++){
			int name_index = ((ConstantClass*)check_and_get(cfr.interfaces[index], CONSTANT_CLASS))->name_index;
			string interface_name = get_string(name_index);
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : " 
				<< interface_name << endl;
			jvm_class.interfaces.push_back(class_loader.get_class(interface_name, depth + 1));	
		}
	}

	void Expander::expand_members(){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " << "expanding members..." << endl;
		expand_fields();
		expand_methods();
	}

	void Expander::expand_fields(){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " << "===== fields..." << endl;
		
		for(int index=0; index < cfr.fields.size(); index++){
			ClassFile::Member & cf_field = cfr.fields[index];
			Internal::sp_JvmField sp_jvm_field(new JvmField);
			JvmField & jvm_field = *sp_jvm_field;
			
			jvm_field.name = get_string(cf_field.name_index);
			jvm_field.descriptor = get_string(cf_field.descriptor_index);
			jvm_field.access_flags = cf_field.access_flags;
			if(jvm_field.is_static()){
				if(logger.is_debug()) logger.log_debug() 
					<< indent << jvm_class.name << " : [static (" << std::hex 
					<< cf_field.access_flags << std::dec << ")] " 
					<< jvm_field.name << " : " 
					<< jvm_field.descriptor << endl;
				sp_jvm_class->static_fields.insert(f_map_entry(jvm_field.name, sp_jvm_field));
			}else{
				if(logger.is_debug()) logger.log_debug() 
					<< indent << jvm_class.name << " : [instance (" << std::hex 
					<< cf_field.access_flags << std::dec << ")] " 
					<< jvm_field.name << " : " 
					<< jvm_field.descriptor << endl;
				sp_jvm_class->instance_fields.insert(f_map_entry(jvm_field.name, sp_jvm_field));
			}
		}

	}

	void Expander::expand_methods (){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " << "===== methods..." << endl;

		for(int index=0; index < cfr.methods.size(); index++){
			ClassFile::Member & cf_method = cfr.methods[index];
			Internal::sp_JvmMethod sp_jvm_method(new JvmMethod);
			JvmMethod & jvm_method = *sp_jvm_method;
			
			jvm_method.name = get_string(cf_method.name_index);
			jvm_method.descriptor = get_string(cf_method.descriptor_index);
			
			jvm_method.access_flags = cf_method.access_flags;
			
			if(jvm_method.is_static()){
				if(logger.is_debug()) logger.log_debug() 
					<< indent << jvm_class.name << " : [static (" << std::hex 
					<< cf_method.access_flags << std::dec << ")] " 
					<< jvm_method.name << " : " 
					<< jvm_method.descriptor << endl;
				sp_jvm_class->static_methods.insert(m_map_entry(jvm_method.name, sp_jvm_method));
			}else{
				if(logger.is_debug()) logger.log_debug() 
					<< indent << jvm_class.name << " : [instance (" << std::hex 
					<< cf_method.access_flags << std::dec << ")] " 
					<< indent << jvm_class.name << " : [instance] " 
					<< jvm_method.name << " : " 
					<< jvm_method.descriptor << endl;
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