#include "class_loader/ClassLoader.hpp"
#include "class_loader/ClassPathByteBufferSource.hpp"
#include "util/log.hpp"
#include "runtime/Runtime.hpp"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char** argv) throw (JvmException){
	LOG_LEVEL = LOG_LEVEL_DEBUG;
	try{
		if(logger.is_info()) logger.log_info() << "starting JVM..." << endl;
		Jvm::Runtime runtime;
		string classpath(argv[1]);
		Jvm::ClassLoader class_loader(
			Jvm::sp_ByteBufferSource(new Jvm::ClassPathByteBufferSource(classpath)));
		class_loader.get_class(argv[2], 0);

		return 0;

	}catch (JvmException & ex){
		cout << "exception: " << ex.what() << endl;
		return -1;
	}
}