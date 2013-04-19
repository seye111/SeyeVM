#include "ClassFileDataBuffer.hpp"
#include "../../util/log.hpp"

#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::ios;

namespace Jvm{

	ClassFileDataBuffer::ClassFileDataBuffer(sp_ByteBuffer sp_byte_buffer) : 
		sp_byte_buffer(sp_byte_buffer), 
		data(sp_byte_buffer->data),
		size(sp_byte_buffer->size),
		pos(0){}

	ClassFileDataBuffer::~ClassFileDataBuffer() {}

	long ClassFileDataBuffer::get_n(int n) {
		long result = 0;
		for (int i=0; i<n; i++){
			result <<= 8;
			result += (255 & get_byte());
		}
		return result;
	}

	long ClassFileDataBuffer::get_u4() { return get_n(4); }

	int ClassFileDataBuffer::get_u2() { return get_n(2); }

	int ClassFileDataBuffer::get_u1() { return get_n(1); }

	int ClassFileDataBuffer::get_int() {
		int result = 0;
		for(int i=0; i<4; i++){
			result <<= 8;
			result += (255 & get_byte());
		}
		return result;
	}

	long ClassFileDataBuffer::get_long() {
		long result = 0;
		for(int i=0; i<8; i++){
			result <<= 8;
			result += (255 & get_byte());
		}
		return result;
	}

	float ClassFileDataBuffer::get_float() {
		int result = 0;
		for(int i=0; i<4; i++){
			result <<= 8;
			result += (255 & get_byte());
		}
		return *((float*)&result);
	}

	double ClassFileDataBuffer::get_double() {
		long result = 0;
		for(int i=0; i<8; i++){
			result <<= 8;
			result += (255 & get_byte());
		}
		return *((double*)&result);
	}

	char ClassFileDataBuffer::get_byte(){
		if (pos >= size){
			throw JvmException("attempt to read beyond buffer");
		}
		return data[pos++];
	}

	string ClassFileDataBuffer::get_string(){
		int length = get_u2();
		ByteBuffer chars(length + 1);
		for(int i = 0; i < length; i++)
			chars.data[i] = get_byte();
		chars.data[length] = NULL;
		string result = string(chars.data);
		return result;

	}	

}