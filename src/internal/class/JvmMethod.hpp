#ifndef INTERNAL_JAVMMETHOD_H
#define INTERNAL_JAVMMETHOD_H

#include "JvmMember.hpp"

#include "boost/shared_ptr.hpp"

using boost::shared_ptr;

namespace Internal{

	class JvmMethod : public JvmMember {

	};

	typedef shared_ptr<JvmMethod> sp_JvmMethod;
}

#endif