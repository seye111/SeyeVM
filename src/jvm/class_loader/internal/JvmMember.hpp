#ifndef JAVMMEMBER_H
#define JAVMMEMBER_H

#include "JvmClass.hpp"

#include "../class_file/ClassFileMember.hpp"

#include "../../util/shared_ptr.hpp"

#include "../AccessControlled.hpp"

namespace Jvm{


	class JvmClass;

	class JvmMember : public AccessControlled {
	public:
		JvmClass & jvm_class;
		ClassFileMember & class_file_member;
		std::string name;
		std::string descriptor;
		int index;

		JvmMember(JvmClass & jvm_class, ClassFileMember & class_file_member) : jvm_class(jvm_class), class_file_member(class_file_member) {}
		
		virtual ~JvmMember(){
			if(logger.is_trace()) logger.log_trace() << "JvmMember destructor called (delete_me) " << endl;
		}
	};


}


#endif