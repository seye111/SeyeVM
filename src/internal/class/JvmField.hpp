#ifndef INTERNAL_JAVMFIELD_H
#define INTERNAL_JAVMFIELD_H

#include "JvmMember.hpp"

#include "boost/shared_ptr.hpp"

using boost::shared_ptr;

namespace Internal{

	class JvmField : public JvmMember {

	};

	typedef shared_ptr<JvmField> sp_JvmField;

}

#endif