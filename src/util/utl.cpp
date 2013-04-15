#include "util.hpp"

int bytes_from_file(string & filename, char** pp_char){
	ifstream file (filename.c_str(), ios::in|ios::binary|ios::ate);
	int size;
	if(file.is_open()){
		int size = file.tellg();
		*pp_char = new char[size];
		char* data = *pp_char;
		file.seekg (0, ios::beg);
		file.read (data, size);
		if (!file){
			throw SimpleException ("could not load file " + filename); 
		}
		file.close();
	}else{
		throw SimpleException ("could not load file " + filename);
	}
	return size;
}