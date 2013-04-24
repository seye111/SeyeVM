#include "SingleFileByteBufferSource.hpp"

using std::ios;

namespace Jvm{

	SingleFileByteBufferSource::SingleFileByteBufferSource(std::string folder) : folder(folder){}

	ByteBuffer* SingleFileByteBufferSource::get_bytes(std::string name){
		std::string filename = folder + "/" + name + ".class";
		std::ifstream file (filename.c_str(), ios::in|ios::binary|ios::ate);
		int size;
		ByteBuffer* p_byte_buffer = NULL;
		if(file.is_open()){
			int size = file.tellg();
			p_byte_buffer = new ByteBuffer(size);
			file.seekg (0, ios::beg);
			file.read (p_byte_buffer->data, size);
			if (!file){
				// get() will return 0 to indicate file not found;
				return p_byte_buffer;
			}
			file.close();
			return p_byte_buffer;
		}else{
			return p_byte_buffer;
		}
	}

	SingleFileByteBufferSource::~SingleFileByteBufferSource(){
		if(logger.is_trace()) logger.log_trace() << "SingleFileByteBufferSource destructor called (delete_me) " << endl;
	}

}