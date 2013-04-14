#include "ClassFileDataBuffer.hpp"

#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::ios;

namespace ClassFile{

	ClassFileDataBuffer::ClassFileDataBuffer (shared_ptr<char> data, int size) : 
		data(data),
		size(size),
		pos(0){}

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
		return data.get()[pos++];
	}

	string ClassFileDataBuffer::get_string(){
		int length = get_u2();
		char* chars = new char[length];
		for(int i=0; i<length; i++)
			chars[i] = get_byte();
		chars[length] = NULL;
		string result = string(chars);
		delete chars;
		return result;
	}

	shared_ptr<ClassFileDataBuffer> ClassFileDataBuffer::get_from_file(string & filename) throw(JvmException) {
		cout << "loading class file raw data " << filename << endl;
		int size = 0;
		shared_ptr<char> data;
		ifstream file (filename.c_str(), ios::in|ios::binary|ios::ate);
		if(file.is_open()){
			size = file.tellg();
			data = shared_ptr<char> (new char[size]);
			cout << "size: " << size << endl;
			file.seekg (0, ios::beg);
			file.read (data.get(), size);
			if (!file){
				throw JvmException ("could not load file " + filename); 
			}
			file.close();
		}else{
			throw JvmException ("could not load file " + filename);
		}

		return shared_ptr<ClassFileDataBuffer> (new ClassFileDataBuffer (data, size));
	}
}
