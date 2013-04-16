#include "class_file/ClassFileRepresentation.hpp"
#include "class_file/parser/ClassFileParser.hpp"

#include "loader/SingleFileClassLoader.hpp"

#include "util/util.hpp"
#include "util/log.hpp"


using std::string;
using std::endl;

int main(int argc, char** argv) throw (JvmException){
	LOG_LEVEL = LOG_LEVEL_DEBUG;
	try{
		if(logger.is_info()) logger.log_info() << "starting JVM..." << endl;
		string classpath(argv[1]);
		Loader::SingleFileClassLoader class_loader(classpath);
		if(argc == 3){
			class_loader.get_class(argv[2], 0);
		}else{
			class_loader.get_class("java/lang/Runnable", 0);		
			class_loader.get_class("java/lang/Object", 0);		
		}
		return 0;
	}catch (SimpleException & ex){
		cout << "exception: " << ex.what() << endl;
		return -1;
	}
}