#ifndef JVM_CLASSPATHBYTEBUFFERSOURCE_H
#define JVM_CLASSPATHBYTEBUFFERSOURCE_H

#include "ByteBufferSource.hpp"

#include <vector>

namespace Jvm{

	class ClassPathByteBufferSource : public ByteBufferSource{
		std::vector<boost::shared_ptr<ByteBufferSource> > sources;
		void add_source(std::string class_path_entry);
	public:
		ClassPathByteBufferSource(std::string class_path);
		virtual sp_ByteBuffer get_bytes(std::string name);
	};

}

#endif