#ifndef INTERNAL_JAVMMEMBER_H
#define INTERNAL_JAVMMEMBER_H

#include "../AccessControlled.hpp"

#include "boost/shared_ptr.hpp"

using boost::shared_ptr;

namespace Internal{

	class JvmMember : public AccessControlled {
	public:
		string name;
		string descriptor;	
	};

	typedef shared_ptr<JvmMember> sp_JvmMember;

}

#endif