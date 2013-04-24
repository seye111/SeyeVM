#ifndef JVM_SINGLEFILEBYTEBUFFERSOURCE
#define JVM_SINGLEFILEBYTEBUFFERSOURCE

#include "ByteBufferSource.hpp"

#include "../Exception.hpp"

#include <iostream>
#include <fstream>

namespace Jvm{

	class SingleFileByteBufferSource : public ByteBufferSource {
		std::string folder;
	public:
		SingleFileByteBufferSource(std::string folder);
		virtual ByteBuffer* get_bytes(std::string name);	
		~SingleFileByteBufferSource();
	};

}

#endif