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
using Internal::JvmClass;
using Internal::sp_JvmClass;
using std::string;
using boost::shared_ptr;

namespace Internal{
	class Expander;
}

using Internal::Expander;


namespace Loader{

	class ClassLoader{
	public:
		map <string, sp_JvmClass> classes;

 		virtual sp_JvmClass load_class(const string & name, int depth = 0)=0;

		virtual sp_JvmClass get_class(const string & name, int depth = 0){
			if(logger.is_debug()) logger.log_debug() << "class loader requested class " << name << endl;
			sp_JvmClass sp_jvm_class = classes[name];
			if(sp_jvm_class.get()){
				if(logger.is_debug()) logger.log_debug() << "class " << name
					<< " already loaded" << endl;
			}else{
				if(logger.is_info()) logger.log_info() << "class " << name
					<< " not found - requesting load" << endl;
				sp_jvm_class = load_class(name, depth);
			}
			return sp_jvm_class;
		}
	};

	typedef boost::shared_ptr<ClassLoader> sp_ClassLoader;
}

#endif;