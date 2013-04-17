#ifndef JVMCLASS_H
#define JVMCLASS_H

#include "../AccessControlled.hpp"
#include "JvmField.hpp"
#include "JvmMethod.hpp"

#include "../../util/log.hpp"

#include <vector>
#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

namespace Jvm{

	class JvmClass : public AccessControlled {
	public:
		std::string name;
		boost::shared_ptr<JvmClass>super_class;
		std::vector<boost::shared_ptr<JvmClass> > interfaces;
		std::map<std::string, sp_JvmField> static_fields;
		std::map<std::string, sp_JvmField> instance_fields;
		std::map<std::string, sp_JvmMethod> static_methods;
		std::map<std::string, sp_JvmMethod> instance_methods;
		int access_flags;
		bool loading;
		bool loaded;
	};

	typedef boost::shared_ptr<JvmClass> sp_JvmClass;

}

#endif
