#ifndef JVM_SINGLEFILEBYTEBUFFERSOURCE
#define JVM_SINGLEFILEBYTEBUFFERSOURCE

#include "ByteBufferSource.hpp"

#include "../Exception.hpp"

namespace Jvm{

	class SingleFileByteBufferSource : public ByteBufferSource {
		std::string folder;
	public:
		SingleFileByteBufferSource(std::string folder) : folder(folder){}
		virtual sp_ByteBuffer get_bytes(std::string name);	
	};

	typedef boost::shared_ptr<SingleFileByteBufferSource> sp_SingleFileByteBufferSource;

}

#endif