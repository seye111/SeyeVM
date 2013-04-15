#include "class_file/ClassFileRepresentation.hpp"
#include "class_file/parser/ClassFileParser.hpp"

#include "internal/class/Expander.hpp"

#include "util/util.hpp"
#include "util/log.hpp"

#include <iostream>
#include <boost/shared_ptr.hpp>


using std::string;
using std::cout;
using std::endl;
using boost::shared_ptr;
using ClassFile::ClassFileDataBuffer;
using ClassFile::sp_ClassFileRepresentation;
using Internal::sp_JvmClass;
using Internal::Expander;

int main(int argc, char** argv) throw (JvmException){
	LOG_LEVEL = LOG_LEVEL_DEBUG;
	try{
		if(logger.is_info()) logger.log_info() << "starting JVM..." << endl;
		string filename(argv[1]);
		byte_buffer buffer = bytes_from_file(filename);
		ClassFileDataBuffer cfdb(buffer.data, buffer.size);
		sp_ClassFileRepresentation sp_cfr = ClassFile::parse_from_buffer(cfdb);
		sp_JvmClass jvm_class = Expander(sp_cfr).expand_class_representation();
		return 0;
	}catch (JvmException & ex){
		cout << "exception: " << ex.what() << endl;
		return -1;
	}
}