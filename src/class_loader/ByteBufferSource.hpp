#ifndef JVM_BYTEBUFFERSOURCE_H
#define JVM_BYTEBUFFERSOURCE_H

#include "ByteBuffer.hpp"

#include <boost/shared_ptr.hpp>
#include <string>

namespace Jvm{

	class ByteBufferSource{
		public:
		virtual sp_ByteBuffer get_bytes(std::string name)=0;
	};

	typedef boost::shared_ptr<ByteBufferSource> sp_ByteBufferSource; 

}

#endif