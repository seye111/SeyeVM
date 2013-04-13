#ifndef CLASSFILE_CLASSFILEDATABUFFER_H
#define CLASSFILE_CLASSFILEDATABUFFER_H

#include "../../util.h"

#include <string>

using std::string;

namespace ClassFile{

	class ClassFileDataBuffer {
		char* data;
		int size;
		int pos;
		long get_n(int n);
		ClassFileDataBuffer (char* buffer, int size);

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
		virtual ~ClassFileDataBuffer();

		static ClassFileDataBuffer* get_from_file(string & filename) throw (JvmException);
	};

}

#endif