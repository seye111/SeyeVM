#ifndef LOADER_SINGLEFILECLASSLOADER
#define LOADER_SINGLEFILECLASSLOADER

#include "ClassLoader.hpp"

namespace Loader{

	class SingleFileClassLoader : public ClassLoader {
		const string class_path;
	public:
		SingleFileClassLoader(const string & class_path) : class_path(class_path) {}

		virtual sp_JvmClass load_class(const string & name, int depth = 0){
			string full_name = class_path + "/" + name + ".class";
			byte_buffer buffer = bytes_from_file(full_name);
			ClassFileDataBuffer cfdb(buffer.data, buffer.size);
			sp_ClassFileRepresentation sp_cfr = ClassFile::parse_from_buffer(cfdb);
			sp_JvmClass sp_jvm_class(new JvmClass); 
			classes[name] = sp_jvm_class;
			sp_jvm_class->loading = true;
			sp_jvm_class->loaded = false;
			// cant send shared pointer to this as receiver will try to clean up
			// 
			Expander(*this, sp_cfr, sp_jvm_class, depth).expand_class_representation(name);
			sp_jvm_class->loading = false;
			sp_jvm_class->loaded = true;
			return sp_jvm_class;
		}
	};
}

#endif