#include "expander.hpp"

#include <sstream>

using std::ostringstream;

namespace Internal{


	using ClassFile::CONSTANT_CLASS;
	using ClassFile::CONSTANT_UTF8;

	using ClassFile::CONSTANT_MAX_TAG;

	using ClassFile::ConstantClass;
	using ClassFile::ConstantUtf8;


	sp_JvmClass expander::expand_class_representation(){
		sp_JvmClass result(new JvmClass);
		JvmClass & jvm_class = *result;
		if(logger.is_info()) logger.log_info() 
			<< "expanding..." << endl;
		
		jvm_class.name = get_class_name();
		if(logger.is_info()) logger.log_info() 
			<< "name             : " << jvm_class.name << endl;
		
		if(jvm_class.name == "java/lang/Object")
			jvm_class.super_class_name = "n/a";
		else
			jvm_class.super_class_name = get_super_class_name();
		if(logger.is_info()) logger.log_info() 
			<< "super class name : " << jvm_class.super_class_name << endl;
		
		return result;
	}

	string & expander::get_class_name(){
		int name_index = ((ConstantClass *)check_and_get(cfr.this_class, CONSTANT_UTF8))->name_index;
		return ((ConstantUtf8 *)check_and_get(name_index, CONSTANT_UTF8))->str;
	}

	string & expander::get_super_class_name(){
		int name_index = ((ConstantClass *)check_and_get(cfr.super_class, CONSTANT_CLASS))->name_index;
		return ((ConstantUtf8 *)check_and_get(name_index, CONSTANT_UTF8))->str;
	}

	//	get a pointer to a constant pool entry at a given index and
	//  check it will be castable to the required type.
	//
	//  perform bounds checking on the index and tag before comparing
	//  their types.
	//
	//	constant pool should references should all be consistent, but
	//  handle inconsistencies gracefully anyway

	ConstantPoolEntry* expander::check_and_get(int index, int tag){
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