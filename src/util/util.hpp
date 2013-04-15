#ifndef UTIL_H
#define UTIL_H

#include <exception>
#include <fstream>
#include <string>

using std::ifstream;
using std::ios;
using std::exception;
using std::string;

class SimpleException : public exception {

	string what_text;

public:

	SimpleException(string what_text) : what_text(what_text) {}

	const char* what() {return what_text.c_str();}

	virtual ~SimpleException() throw() {}

};

class JvmException : public SimpleException {
public:
	JvmException(string what_text) : SimpleException(what_text) {}
};

int bytes_from_file(string & filename, char** pp_char);


#endif