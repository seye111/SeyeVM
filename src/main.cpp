#include "util.hpp"
#include "class_file/ClassFileRepresentation.hpp"
#include "class_file/parser/ClassFileParser.hpp"

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char** argv) throw (JvmException){
	try{
		string filename(argv[1]);
		ClassFile::ClassFileRepresentation* cfrep =  ClassFile::parse_from_file(filename);
		delete cfrep;
		return 0;
	}catch (JvmException & ex){
		cout << "Exception: " << ex.what() << endl;
		return -1;
	}
}