#include "util.hpp"

byte_buffer bytes_from_file(string & filename){
	ifstream file (filename.c_str(), ios::in|ios::binary|ios::ate);
	int size;
	if(file.is_open()){
		int size = file.tellg();
		byte_buffer buffer(size);
		file.seekg (0, ios::beg);
		file.read (buffer.data, size);
		if (!file){
			throw SimpleException ("could not load file " + filename); 
		}
		file.close();
		return buffer;
	}else{
		throw SimpleException ("could not load file " + filename);
	}
}