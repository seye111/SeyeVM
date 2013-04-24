#ifndef JVM_JVM_H
#define JVM_JVM_H

#include "class_loader/ClassLoader.hpp"
#include "class_loader/ByteBufferSource.hpp"

#include "runtime/Runtime.hpp"

namespace Jvm{

	class Jvm{
	public:
		ClassLoader system_class_loader;
		
		Runtime runtime;
		
		Jvm(ByteBufferSource & byte_buffer_source) : system_class_loader(*this, byte_buffer_source), runtime() {}
	
		~Jvm(){
			if(logger.is_trace()) logger.log_trace() << "Jvm destructor called (delete_me) " << endl;
		}
	};

}

#endif