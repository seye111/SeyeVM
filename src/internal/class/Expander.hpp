#ifndef INTERNAL_EXPANDER_H
#define INTERNAL_EXPANDER_H

#include "../../class_file/ClassFileRepresentation.hpp"
#include "../../util/util.hpp"
#include "../../loader/ClassLoader.hpp"
#include "JvmClass.hpp"

using ClassFile::sp_ClassFileRepresentation;
using ClassFile::ClassFileRepresentation;
using ClassFile::sp_ConstantPoolEntry;
using ClassFile::ConstantPoolEntry;

namespace Loader{
	class ClassLoader;
}

using Loader::ClassLoader;

namespace Internal{

	class Expander{
		// fields
		ClassLoader & class_loader;
		sp_ClassFileRepresentation sp_cfr;
		ClassFileRepresentation & cfr;
		sp_JvmClass sp_jvm_class;
		JvmClass & jvm_class;
		vector<sp_ConstantPoolEntry> & cp;
		int depth;
		string indent;

		//methods
		string & get_class_name();
		string & get_super_class_name();
		void expand_members();
		void expand_fields();
		void expand_methods();
		string & get_string(int index);
		void expand_interfaces();
		ConstantPoolEntry* check_and_get(int index, int tag);
	public:
		Expander(ClassLoader & class_loader, sp_ClassFileRepresentation sp_cfr, sp_JvmClass sp_jvm_class, int depth) : 
			class_loader(class_loader),
			sp_cfr(sp_cfr),
			cfr(*sp_cfr),
			sp_jvm_class(sp_jvm_class),
			jvm_class(*sp_jvm_class),
			cp(cfr.constant_pool)
			{
				for(int i=0; i<depth; i++)
					indent.append("....");
			} 
		
		void expand_class_representation(const string & name);
	};
}

#endif