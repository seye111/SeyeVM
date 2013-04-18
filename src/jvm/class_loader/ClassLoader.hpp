#ifndef CLASSLOADER
#define CLASSLOADER

#include "ByteBufferSource.hpp"

#include "internal/JvmClass.hpp"
#include "internal/Expander.hpp"

#include "class_file/ClassFileDataBuffer.hpp"
#include "class_file/ClassFileRepresentation.hpp"

#include "../runtime/Runtime.hpp"

#include "../Exception.hpp"

namespace Jvm{

	class Expander;

	class ClassLoader{
		
		sp_ByteBufferSource sp_byte_buffer_source;
		sp_JvmClass load_class(const std::string & name, int depth);
		std::map <string, sp_JvmClass> classes;

	public:
		sp_Runtime sp_runtime;

		ClassLoader(sp_ByteBufferSource sp_byte_buffer_source, sp_Runtime sp_runtime) : 
				sp_byte_buffer_source(sp_byte_buffer_source),
				sp_runtime(sp_runtime) {}

		sp_JvmClass get_class(const std::string & name, int depth);


	};

	typedef boost::shared_ptr<ClassLoader> sp_ClassLoader;

}

#endif;