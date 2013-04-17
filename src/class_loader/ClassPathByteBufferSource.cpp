#include "ClassPathByteBufferSource.hpp"

#include "JarByteBufferSource.hpp"
#include "SingleFileByteBufferSource.hpp"

#include "../util/log.hpp"

using std::string;
using std::endl;

namespace Jvm{
	
	ClassPathByteBufferSource::ClassPathByteBufferSource (string class_path) {
		string str = class_path;
		while(str.length() > 0){
			size_t index = str.find_first_of(':');
			if(index != string::npos){
				add_source(str.substr(0, index));
				str = str.substr(index + 1, str.length() - index - 1);
			}else{
				add_source(str);
				str = "";
			}
		}
	}

	void ClassPathByteBufferSource::add_source(string class_path_entry){
		if(class_path_entry == "") return;
		if(class_path_entry.length() > 5){
			string extension = class_path_entry.substr(class_path_entry.length()-3,3);
			if (extension == "jar" || extension == "zip"){
				sources.push_back(sp_ByteBufferSource(new JarByteBufferSource(class_path_entry)));
				return;
			}
		}
		sources.push_back(sp_ByteBufferSource(new SingleFileByteBufferSource(class_path_entry)));
	}

	sp_ByteBuffer ClassPathByteBufferSource::get_bytes(string name){
		sp_ByteBuffer result;
		for(int i=0; i < sources.size(); i++){
			result = sources[i]->get_bytes(name);
			if(result.get()){
				return result;
			}
		}
		return result;
	}
}
