#ifndef JVM_BYTEBUFFERSOURCE_H
#define JVM_BYTEBUFFERSOURCE_H

#include "ByteBuffer.hpp"

#include "../util/log.hpp"

#include <string>

using std::endl;

namespace Jvm{

	class ByteBufferSource{
		public:
		virtual ByteBuffer* get_bytes(std::string name)=0;

		virtual ~ByteBufferSource(){
			if(logger.is_trace()) logger.log_trace() << "ByteBufferSource destructor called (delete_me) " << endl;
		}
	};

}

#endif