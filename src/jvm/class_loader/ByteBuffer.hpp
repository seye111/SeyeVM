#ifndef JVM_BYTEBUFFER_H
#define JVM_BYTEBUFFER_H

#include <boost/shared_ptr.hpp>

namespace Jvm{

	class ByteBuffer{
	public:
		int size;
		char* data;
		ByteBuffer(int size) : size(size), data(new char[size]) {}
		~ByteBuffer(){delete data;}
	};

	typedef boost::shared_ptr<ByteBuffer> sp_ByteBuffer;

}

#endif