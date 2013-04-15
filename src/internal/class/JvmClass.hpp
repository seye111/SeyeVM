#ifndef INTERNAL_JVMCLASS_H
#define INTERNAL_JVMCLASS_H

#include "../../util/log.hpp"

#include <string>
#include <boost/shared_ptr.hpp>

using boost::shared_ptr;

namespace Internal{

	class JvmClass{
	public:
		string name;
		string super_class_name;
	};

	typedef shared_ptr<JvmClass> sp_JvmClass;

}

#endif
