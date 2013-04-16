#include "class_file/ClassFileRepresentation.hpp"
#include "class_file/parser/ClassFileParser.hpp"

#include "loader/SingleFileClassLoader.hpp"

#include "util/util.hpp"
#include "util/log.hpp"


using std::string;
using std::endl;

int main(int argc, char** argv) throw (JvmException){
	LOG_LEVEL = LOG_LEVEL_TRACE;
	try{
		if(logger.is_info()) logger.log_info() << "starting JVM..." << endl;
		string filename(argv[1]);
		Loader::SingleFileClassLoader class_loader;
		class_loader.get_class(filename, 0);		
		return 0;
	}catch (JvmException & ex){
		cout << "exception: " << ex.what() << endl;
		return -1;
	}
}