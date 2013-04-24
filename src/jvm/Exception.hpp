#ifndef JVM_EXCEPTION_H
#define JVM_EXCEPTION_H

#include <exception>
#include <string>

namespace Jvm{

	class SimpleException : public std::exception {

		std::string what_text;

	public:

		SimpleException(std::string what_text) : what_text(what_text) {}
		virtual ~SimpleException() throw() {}

		const char* what() {return what_text.c_str();}

	};

	class JvmException : public SimpleException {
	public:
		JvmException(std::string what_text) : SimpleException(what_text) {}
		//~virtual JvmException() throw() {}
	};

	class JvmIntsructionNotImplementedException : public JvmException {
	public:
		JvmIntsructionNotImplementedException(std::string what_text) : JvmException(what_text) {}
		//~virtual JvmIntsructionNotImplementedException() throw() {}
	};

}
#endif