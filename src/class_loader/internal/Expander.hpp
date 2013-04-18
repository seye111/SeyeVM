#ifndef EXPANDER_H
#define EXPANDER_H

#include "JvmClass.hpp"

#include "../ClassLoader.hpp"

#include "../class_file/ClassFileRepresentation.hpp"
#include "../../util/util.hpp"


namespace Jvm{

class ClassLoader;

	class Expander{

		ClassLoader & class_loader;
		sp_ClassFileRepresentation sp_cfr;
		ClassFileRepresentation & cfr;
		sp_JvmClass sp_jvm_class;
		JvmClass & jvm_class;
		std::vector<sp_ConstantPoolEntry> & cp;
		int depth;
		std::string indent;

		std::string & get_class_name();
		std::string & get_super_class_name();
		void expand_members();
		void expand_fields();
		void expand_methods();
		std::string & get_string(int index);
		void expand_interfaces();
		ConstantPoolEntry* check_and_get(int index, int tag);
		int get_width(string & descriptor);
	public:
		Expander(ClassLoader & class_loader, sp_ClassFileRepresentation sp_cfr, sp_JvmClass sp_jvm_class, int depth) : 
			class_loader(class_loader),
			sp_cfr(sp_cfr),
			cfr(*sp_cfr),
			sp_jvm_class(sp_jvm_class),
			jvm_class(*sp_jvm_class),
			cp(cfr.constant_pool),
			depth(depth)
			{
				for(int i=0; i<depth; i++)
					indent.append("    ");
			} 
		
		void expand_class_representation(const string & name);
	};


}


#endif