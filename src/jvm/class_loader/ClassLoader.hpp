#ifndef JVM_CLASSLOADER_H
#define JVM_CLASSLOADER_H

#include "ByteBufferSource.hpp"

#include "internal/JvmClass.hpp"
#include "internal/Expander.hpp"

#include "class_file/ClassFileDataBuffer.hpp"
#include "class_file/ClassFileRepresentation.hpp"

#include "../runtime/Runtime.hpp"

#include "../Exception.hpp"

namespace Jvm{

	class Jvm;
	class Expander;

	class ClassLoader{
		
		JvmClass & load_class(const std::string & name, int depth);
		std::map <std::string, JvmClass* > classes;

	public:
		Jvm & jvm;
		ByteBufferSource & byte_buffer_source;

		ClassLoader(Jvm & jvm, ByteBufferSource & byte_buffer_source);
		~ClassLoader();
		JvmClass & get_class(const std::string & name, int depth);
	};
}

#endif