#ifndef JVM_JVMCLASS_H
#define JVM_JVMCLASS_H

#include "../AccessControlled.hpp"
#include "JvmField.hpp"
#include "JvmMethod.hpp"

#include "../class_file/ClassFileRepresentation.hpp"

#include "../../util/log.hpp"

#include <vector>
#include <map>
#include <string>

namespace Jvm{

	class JvmClass : public AccessControlled {
	public:
		ClassFileRepresentation* p_class_file_representation;
		std::string name;
		JvmClass* super_class;
		std::vector<JvmClass*> interfaces;
		std::map<std::string, JvmField*> static_fields;
		std::map<std::string, JvmField*> instance_fields;
		std::map<std::string, JvmMethod*> static_methods;
		std::map<std::string, JvmMethod*> instance_methods;
		std::vector<JvmMethod*> v_table;

		int access_flags;
		bool loading;
		bool loaded;
		int* static_data_4;
		long* static_data_8;
		int instance_data_4_count; 
		int instance_data_8_count;

		JvmClass(ClassFileRepresentation* p_class_file_representation);
		
		~JvmClass();
	};

}

#endif
