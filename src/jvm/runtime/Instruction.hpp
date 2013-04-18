#ifndef JVM_INSTRUCTION_H
#define JVM_INSTRUCTION_H

#include "ExecutionContext.hpp"

#include <string>

namespace Jvm{

	struct Instruction{
		std::string name;
		int opcode;
		int arg_count;
		void (*execute)(ExecutionContext & context);
	};

}

#endif