#ifndef JAVMMEMBER_H
#define JAVMMEMBER_H

#include "JvmClass.hpp"

#include "../AccessControlled.hpp"

#include <boost/shared_ptr.hpp>

namespace Jvm{

	class JvmClass;
	typedef boost::shared_ptr<JvmClass> sp_JvmClass;

	class JvmMember : public AccessControlled {
	public:
		sp_JvmClass sp_jvm_class;
		JvmClass & jvm_class;
		std::string name;
		std::string descriptor;
		int index;

		JvmMember(sp_JvmClass sp_jvm_class) : sp_jvm_class(sp_jvm_class), jvm_class(*sp_jvm_class) {}	
	};

	typedef boost::shared_ptr<JvmMember> sp_JvmMember;

}


#endif