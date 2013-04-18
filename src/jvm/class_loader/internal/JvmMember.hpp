#ifndef JAVMMEMBER_H
#define JAVMMEMBER_H

#include "../AccessControlled.hpp"

#include <boost/shared_ptr.hpp>

namespace Jvm{

	class JvmMember : public AccessControlled {
	public:
		std::string name;
		std::string descriptor;	
	};

	typedef boost::shared_ptr<JvmMember> sp_JvmMember;

}


#endif