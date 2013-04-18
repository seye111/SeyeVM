#ifndef JAVMFIELD_H
#define JAVMFIELD_H

#include "JvmMember.hpp"

#include <boost/shared_ptr.hpp>

namespace Jvm{

	class JvmField : public JvmMember {
	public:
		int offset;
	};

	typedef boost::shared_ptr<JvmField> sp_JvmField;

}
#endif