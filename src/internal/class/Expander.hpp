#ifndef INTERNAL_EXPANDER_H
#define INTERNAL_EXPANDER_H

#include "../../class_file/ClassFileRepresentation.hpp"
#include "../../util/util.hpp"
#include "JvmClass.hpp"

using ClassFile::sp_ClassFileRepresentation;
using ClassFile::ClassFileRepresentation;
using ClassFile::sp_ConstantPoolEntry;
using ClassFile::ConstantPoolEntry;


namespace Internal{

	class Expander{
		// fields
		sp_ClassFileRepresentation sp_cfr;
		ClassFileRepresentation & cfr;
		sp_JvmClass sp_jvm_class;
		JvmClass & jvm_class;
		vector<sp_ConstantPoolEntry> & cp;
		int depth;

		//methods
		string & get_class_name();
		string & get_super_class_name();
		void expand_members();
		void expand_fields();
		void expand_methods();
		string & get_string(int index);
		ConstantPoolEntry* check_and_get(int index, int tag);
	public:
		Expander(sp_ClassFileRepresentation sp_cfr, sp_JvmClass sp_jvm_class, int depth)	: 
			sp_cfr(sp_cfr),
			cfr(*sp_cfr),
			sp_jvm_class(sp_jvm_class),
			jvm_class(*sp_jvm_class),
			depth(depth),
			cp(cfr.constant_pool)
			{} 
		
		void expand_class_representation();
	};
}

#endif