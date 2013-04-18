#ifndef JAVMMETHOD_H
#define JAVMMETHOD_H

#include "JvmMember.hpp"

#include <boost/shared_ptr.hpp>

namespace Jvm{

	class JvmMethod : public JvmMember {

	};

	typedef boost::shared_ptr<JvmMethod> sp_JvmMethod;

}


#endif