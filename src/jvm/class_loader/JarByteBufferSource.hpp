#ifndef JVM_JARBYTEBUFFERSOURCE
#define JVM_JARBYTEBUFFERSOURCE

#include "ByteBufferSource.hpp"

namespace Jvm{

	class JarByteBufferSource : public ByteBufferSource {
		std::string jar_name;
	public:
		JarByteBufferSource(std::string jar_name) : jar_name(jar_name) {}
		virtual sp_ByteBuffer get_bytes(std::string name);
	};

}

#endif