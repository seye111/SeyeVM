#ifndef UTIL_H
#define UTIL_H

#include <exception>
#include <string>

using std::exception;
using std::string;

class JvmException : public exception {

	const string what_text;

public:

	JvmException(string what_text) : what_text(what_text) {}

	const char* what() {return what_text.c_str();}

	virtual ~JvmException() throw() {}

};

#endif