#include "util/util.hpp"
#include "util/log.hpp"
#include "class_file/ClassFileRepresentation.hpp"
#include "class_file/parser/ClassFileParser.hpp"

#include <iostream>
#include <boost/shared_ptr.hpp>

using std::string;
using std::cout;
using std::endl;
using boost::shared_ptr;

int main(int argc, char** argv) throw (JvmException){
	try{
		if(logger.is_info()) logger.log_info() << "Starting JVM..." << endl;
		//if(logger.is_info()) logger.log_info() << "Starting JVM..." << endl;
		//if(logger.is_trace()) logger.log_trace() << "Starting JVM..." << endl;
		//if(logger.is_trace()) logger.log_trace() << "Starting JVM..." << endl;
		string filename(argv[1]);
		shared_ptr<ClassFile::ClassFileRepresentation> cfrep =  ClassFile::parse_from_file(filename);
		return 0;
	}catch (JvmException & ex){
		cout << "Exception: " << ex.what() << endl;
		return -1;
	}
}