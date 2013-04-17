#ifndef CLASSLOADER
#define CLASSLOADER

#include "ByteBufferSource.hpp"

#include "internal/JvmClass.hpp"
#include "internal/Expander.hpp"

#include "class_file/ClassFileDataBuffer.hpp"
#include "class_file/ClassFileRepresentation.hpp"

#include "../util/util.hpp"

namespace Jvm{

	class Expander;

	class ClassLoader{
		
		sp_ByteBufferSource sp_byte_buffer_source;

		sp_JvmClass load_class(const std::string & name, int depth);

	public:
		std::map <string, sp_JvmClass> classes;

		ClassLoader(sp_ByteBufferSource sp_byte_buffer_source) : sp_byte_buffer_source(sp_byte_buffer_source) {}

		sp_JvmClass get_class(const std::string & name, int depth);


	};

	typedef boost::shared_ptr<ClassLoader> sp_ClassLoader;

}

#endif;