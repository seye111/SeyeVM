#ifndef JVMCLASS_H
#define JVMCLASS_H

#include "../AccessControlled.hpp"
#include "JvmField.hpp"
#include "JvmMethod.hpp"

#include "../class_file/ClassFileRepresentation.hpp"

#include "../../util/log.hpp"

#include <vector>
#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

namespace Jvm{

	class JvmClass : public AccessControlled {
	public:
		sp_ClassFileRepresentation sp_class_file_representation;
		std::string name;
		boost::shared_ptr<JvmClass>super_class;
		std::vector<boost::shared_ptr<JvmClass> > interfaces;
		std::map<std::string, sp_JvmField> static_fields;
		std::map<std::string, sp_JvmField> instance_fields;
		std::map<std::string, sp_JvmMethod> static_methods;
		std::map<std::string, sp_JvmMethod> instance_methods;
		std::vector<sp_JvmMethod> v_table;

		int access_flags;
		bool loading;
		bool loaded;
		int* static_data_4;
		long* static_data_8;
		int instance_data_4_count; 
		int instance_data_8_count;

		JvmClass(sp_ClassFileRepresentation sp_class_file_representation) : 
				sp_class_file_representation (sp_class_file_representation),
				static_data_4(NULL), 
				static_data_8(NULL) {}
		~JvmClass() {
			delete[] static_data_4;
			delete[] static_data_8;
		}
	};

	typedef boost::shared_ptr<JvmClass> sp_JvmClass;

}

#endif
