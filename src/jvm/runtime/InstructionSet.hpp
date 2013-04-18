#ifndef JVM_INSTRUCTIONSET_H
#define JVM_INSTRUCTIONSET_H

#include "Instruction.hpp"

#include "../util/log.hpp"

namespace Jvm{

	class InstructionSet{
	public:
		Instruction* instructions;
		InstructionSet();
	};

}

#endif