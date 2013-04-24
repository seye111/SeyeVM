#ifndef JVM_EXECUTIONCONTEXT_H
#define JVM_EXECUTIONCONTEXT_H

namespace Jvm{

	class Thread{

	};

	class StackFrame{
		char* op_stack;
		int op_stack_index;
		int* locals;
	};

	class ExecutionContext{
	public:
	};

}

#endif