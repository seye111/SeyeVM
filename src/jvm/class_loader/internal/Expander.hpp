#ifndef EXPANDER_H
#define EXPANDER_H

#include "JvmClass.hpp"

#include "../ClassLoader.hpp"

#include "../class_file/ClassFileRepresentation.hpp"
#include "../../Exception.hpp"


namespace Jvm{

class ClassLoader;

	class Expander{

		ClassLoader & class_loader;
		ClassFileRepresentation & class_file_representation;
		JvmClass & jvm_class;
		std::vector<ConstantPoolEntry*> & constant_pool;
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
		int get_width(std::string & descriptor);
		void expand_method_attributes(ClassFileMember & cf_method, JvmMethod & jvm_method);
	public:
		Expander(ClassLoader & class_loader, ClassFileRepresentation & class_file_representation, 
			JvmClass & jvm_class, int depth) : 
				class_loader(class_loader),
				class_file_representation(class_file_representation),
				jvm_class(jvm_class),
				constant_pool(class_file_representation.constant_pool),
				depth(depth){
				for(int i=0; i<depth; i++)
					indent.append("    ");
			} 
		
		void expand_class_representation(const std::string & name);
	};


}


#endif