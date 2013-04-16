#ifndef INTERNAL_JVMCLASS_H
#define INTERNAL_JVMCLASS_H

#include "JvmField.hpp"
#include "JvmMethod.hpp"

#include "../../util/log.hpp"

#include <map>
#include <string>
#include <boost/shared_ptr.hpp>

using std::map;
using boost::shared_ptr;

namespace Internal{

	class JvmClass{
	public:
		string name;
		shared_ptr<JvmClass>super_class;
		vector<shared_ptr<JvmClass> > interfaces;
		map<string, sp_JvmField> static_fields;
		map<string, sp_JvmField> instance_fields;
		map<string, sp_JvmMethod> static_methods;
		map<string, sp_JvmMethod> instance_methods;
		bool loading;
		bool loaded;
	};

	typedef shared_ptr<JvmClass> sp_JvmClass;

}

#endif
