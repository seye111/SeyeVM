#ifndef LOADER_SINGLEFILECLASSLOADER
#define LOADER_SINGLEFILECLASSLOADER

#include "ClassLoader.hpp"

namespace Loader{

	class SingleFileClassLoader : public ClassLoader {
	protected:
		virtual sp_JvmClass load_class(string & name, int depth = 0){
			byte_buffer buffer = bytes_from_file(name);
			ClassFileDataBuffer cfdb(buffer.data, buffer.size);
			sp_ClassFileRepresentation sp_cfr = ClassFile::parse_from_buffer(cfdb);
			sp_JvmClass sp_jvm_class(new JvmClass); 
			Expander(sp_cfr, sp_jvm_class, depth).expand_class_representation();
			return sp_jvm_class;
		}
	public:
	};
}

#endif