#ifndef JVM_RUNTIME_H
#define JVM_RUNTIME_H

#include "InstructionSet.hpp"

#include "../util/log.hpp"

namespace Jvm{

	class Runtime{
	public:
		InstructionSet instruction_set;
		
		Runtime(){
			if(logger.is_debug()) logger.log_debug() << "runtime created" << std::endl;
		}
	};

}

#endif