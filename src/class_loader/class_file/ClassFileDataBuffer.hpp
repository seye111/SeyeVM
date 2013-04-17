#ifndef JVM_CLASSFILEDATABUFFER_H
#define JVM_CLASSFILEDATABUFFER_H

#include "../ByteBuffer.hpp"

#include "../../util/util.hpp"

#include <string>
#include <boost/shared_ptr.hpp>

using boost::shared_ptr;
using std::string;

namespace Jvm{

	////////////////////////////////////////////////////////////////////////////////
	//
	// class ClassFileDataBuffer
	//
	// provides methods to sequentially extract data types relevant to the parsing 
	// of the raw binary data of a java class file.
	//
	// works from an internal char array and is able to detect attempted buffer
	// overruns. 
	//
	// intended to be used by a ClassFileParser while it constructs an instance of
	// ClassFile::ClassFileRepresentation.
	//
	////////////////////////////////////////////////////////////////////////////////

		class ClassFileDataBuffer {
		sp_ByteBuffer sp_byte_buffer;
		int pos;
		long get_n(int n);

		public:
		
		ClassFileDataBuffer (sp_ByteBuffer sp_byte_buffer);
		long get_u4();
		int get_u2();
		int get_u1();
		char get_byte();
		int get_int();
		long get_long();
		float get_float();
		double get_double();
		string get_string();
		~ClassFileDataBuffer ();

	};

	typedef shared_ptr<ClassFileDataBuffer> sp_ClassFileDataBuffer;

}

#endif