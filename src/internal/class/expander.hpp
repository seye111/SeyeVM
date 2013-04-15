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

	class expander{
		sp_ClassFileRepresentation sp_cfr;
		ClassFileRepresentation & cfr;
		vector<sp_ConstantPoolEntry> & cp;
		string & get_class_name();
		string & get_super_class_name();
		ConstantPoolEntry* check_and_get(int index, int tag);
	public:
		expander(sp_ClassFileRepresentation sp_cfr)	: 
			sp_cfr(sp_cfr),
			cfr(*sp_cfr),
			cp(cfr.constant_pool)
			{} 
		
		sp_JvmClass expand_class_representation();
	};
}

#endif