#ifndef JAVMMETHOD_H
#define JAVMMETHOD_H

#include "JvmMember.hpp"

#include "../../runtime/Instruction.hpp"
#include "../class_file/ClassFileMember.hpp"
#include "../ByteBuffer.hpp"

namespace Jvm{

	class JvmMethod : public JvmMember {
	public:
		int v_table_index;
		int max_stack;
		int max_locals;
		int code_length;
		char* code;
		Instruction** instructions;
	
		JvmMethod(JvmClass & jvm_class, ClassFileMember & class_file_member) : 
			JvmMember(jvm_class, class_file_member),
			v_table_index(-1), 
			max_stack(0), 
			max_locals(0), 
			code_length(0), 
			instructions(NULL) {}

		virtual ~JvmMethod(){
			if(logger.is_trace()) logger.log_trace() << "JvmMethod destructor called (delete_me) " << endl;
			delete[] instructions;
		}
	};

}


#endif