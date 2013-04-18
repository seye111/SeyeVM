#include "JarByteBufferSource.hpp"

#include "../Exception.hpp"

#include <stdio.h>
	
using std::string;

static const int READ_BUFFER_SIZE = 1024 * 1024;

namespace Jvm{
	sp_ByteBuffer JarByteBufferSource::get_bytes(string name){
		FILE *p_file;
		p_file = fopen(jar_name.c_str(), "r");
		if((long)p_file < 1){
			fclose(p_file);
			throw JvmException("could not open file " + jar_name);
		}
		fclose(p_file);
		ByteBuffer read_buffer(READ_BUFFER_SIZE);
		string command =  "unzip -qq -p " + jar_name + " " + name +  ".class  2> /dev/null";
		p_file = popen(command.c_str(), "r");
		if((long)p_file < 1){
			pclose(p_file);
			throw JvmException("could not execute command " + command);
		}
		int bytes_read = fread(read_buffer.data, 1, READ_BUFFER_SIZE, p_file);
		pclose(p_file);
		sp_ByteBuffer result;
		if(bytes_read == 0){
			return result;
		}else{
			result = sp_ByteBuffer(new ByteBuffer(bytes_read));
			for(int i=0; i < bytes_read; i++)
				result->data[i] = read_buffer.data[i];
			return result;
		}
	}

}
