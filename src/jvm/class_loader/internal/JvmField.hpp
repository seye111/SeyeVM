#ifndef JAVMFIELD_H
#define JAVMFIELD_H

#include "JvmMember.hpp"

#include "../../util/shared_ptr.hpp"

namespace Jvm{

	class JvmField : public JvmMember {
	public:

		JvmField(JvmClass & jvm_class, ClassFileMember & class_file_member) : 
			JvmMember(jvm_class, class_file_member) {}


		virtual ~JvmField(){
			if(logger.is_trace()) logger.log_trace() << "JvmField destructor called (delete_me) " << endl;
		}
		
		int offset;
	};

}
#endif