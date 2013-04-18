#ifndef JAVMMETHOD_H
#define JAVMMETHOD_H

#include "JvmMember.hpp"

#include "../../runtime/Instruction.hpp"

#include "../ByteBuffer.hpp"

#include <boost/shared_ptr.hpp>

namespace Jvm{

	class JvmMethod : public JvmMember {
	public:
		int max_stack;
		int max_locals;
		int code_length;
		sp_ByteBuffer code;
		Instruction** instructions;
	
		JvmMethod() : max_stack(0), max_locals(0), code_length(0), instructions(NULL) {}

		~JvmMethod(){
			delete[] instructions;
		}
	};

	typedef boost::shared_ptr<JvmMethod> sp_JvmMethod;

}


#endif