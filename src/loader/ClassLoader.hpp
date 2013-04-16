#ifndef LOADER_CLASSLOADER
#define LOADER_CLASSLOADER

#include "../util/util.hpp"
#include "../class_file/parser/ClassFileDataBuffer.hpp"
#include "../class_file/ClassFileRepresentation.hpp"
#include "../internal/class/JvmClass.hpp"
#include "../internal/class/Expander.hpp"

#include <string>
#include <boost/shared_ptr.hpp>

using ClassFile::ClassFileDataBuffer;
using ClassFile::ClassFileRepresentation;
using Internal::Expander;
using Internal::JvmClass;
using Internal::sp_JvmClass;
using std::string;
using boost::shared_ptr;

namespace Loader{

	class ClassLoader{
	protected:
		virtual sp_JvmClass load_class(string & name, int depth = 0)=0;
	public:
		virtual sp_JvmClass get_class(string & name, int depth = 0){
			return load_class(name, depth);
		}
	};

	typedef boost::shared_ptr<ClassLoader> sp_classLoader;
}

#endif