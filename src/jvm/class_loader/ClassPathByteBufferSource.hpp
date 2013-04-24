#ifndef JVM_CLASSPATHBYTEBUFFERSOURCE_H
#define JVM_CLASSPATHBYTEBUFFERSOURCE_H

#include "ByteBufferSource.hpp"

#include <vector>

namespace Jvm{

	class ClassPathByteBufferSource : public ByteBufferSource{
		std::vector<ByteBufferSource*> sources;
		void add_source(std::string class_path_entry);
	public:
		ClassPathByteBufferSource(std::string class_path);
		virtual ~ClassPathByteBufferSource();

		virtual ByteBuffer* get_bytes(std::string name);
	};

}

#endif