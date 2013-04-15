#include "expander.hpp"

namespace Internal{

	using ClassFile::sp_ConstantPoolEntry;
	using ClassFile::ConstantClass;
	using ClassFile::ConstantUtf8;

	string & get_class_name(ClassFileRepresentation & rep){
		int name_index = ((ConstantClass *)rep.constant_pool[rep.this_class].get())->name_index;
		return ((ConstantUtf8 *)rep.constant_pool[name_index].get())->str;
	}

	sp_JvmClass expand_class_representation(ClassFileRepresentation & cfrep){
		sp_JvmClass result(new JvmClass);
		JvmClass & jvm_class = *result;
		if(logger.is_info()) logger.log_info() << "expanding..." << endl;
		jvm_class.name = get_class_name(cfrep);
		if(logger.is_info()) logger.log_info() << "name: " << jvm_class.name << endl;
		
		return result;
	}

}