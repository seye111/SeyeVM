#ifndef JVM_BYTEBUFFER_H
#define JVM_BYTEBUFFER_H

namespace Jvm{

	class ByteBuffer{
	public:
		int size;
		char* data;
		ByteBuffer(int size) : size(size), data(new char[size]) {}
		~ByteBuffer(){delete[] data;}
	};
}

#endif