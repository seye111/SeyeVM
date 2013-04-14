#ifndef CLASSFILE_CLASSFILEDATABUFFER_H
#define CLASSFILE_CLASSFILEDATABUFFER_H

#include "../../util.hpp"

#include <string>
#include <boost/shared_ptr.hpp>

using boost::shared_ptr;
using std::string;

namespace ClassFile{
    
	typedef shared_ptr<char> sp_char;

	class ClassFileDataBuffer {
		sp_char data;
		int size;
		int pos;
		long get_n(int n);
		ClassFileDataBuffer (sp_char data, int size);

	public:
		long get_u4();
		int get_u2();
		int get_u1();
		char get_byte();
		int get_int();
		long get_long();
		float get_float();
		double get_double();
		string get_string();

		static shared_ptr<ClassFileDataBuffer> get_from_file(string & filename) throw (JvmException);
	};

}

#endif