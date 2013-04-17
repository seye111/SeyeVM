#include "SingleFileByteBufferSource.hpp"

namespace Jvm{

	sp_ByteBuffer SingleFileByteBufferSource::get_bytes(std::string name){
		std::string filename = folder + "/" + name + ".class";
		ifstream file (filename.c_str(), ios::in|ios::binary|ios::ate);
		int size;
		sp_ByteBuffer sp_byte_buffer;
		if(file.is_open()){
			int size = file.tellg();
			sp_byte_buffer = sp_ByteBuffer(new ByteBuffer(size));
			file.seekg (0, ios::beg);
			file.read (sp_byte_buffer->data, size);
			if (!file){
				// get() will return 0 to indicate file not found;
				return sp_byte_buffer;
			}
			file.close();
			return sp_byte_buffer;
		}else{
			return sp_byte_buffer;
		}
	}


}