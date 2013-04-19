#include "class_loader/ClassLoader.hpp"
#include "class_loader/ClassPathByteBufferSource.hpp"
#include "util/log.hpp"
#include "runtime/Runtime.hpp"

#include <sys/time.h>

using std::string;
using std::cout;
using std::endl;

int elapsed(timeval str_tv, timeval stp_tv){
	int sec_diff = stp_tv.tv_sec - str_tv.tv_sec;
	int u_diff = stp_tv.tv_usec - str_tv.tv_usec;
	return (int)(sec_diff * 1000000 + u_diff);
	//if(u_diff > 0){
	//	return (int)(sec_diff * 1000000 + u_diff);
	//}else if(u_diff < 0){
	//	return (int)(--sec_diff * 1000000 + (1000000 + u_diff));
	//}else{
	//	return sec_diff;
	//}
}

int main(int argc, char** argv) throw (JvmException){
	LOG_LEVEL = LOG_LEVEL_WARN;
	struct timeval str_tv, stp_tv;
	gettimeofday(&str_tv, NULL);	
	try{
		gettimeofday(&str_tv, NULL);	
		for(int i=0; i<50; i++){
			cout << i << endl;
			if(logger.is_info()) logger.log_info() << "starting JVM..." << endl;
			Jvm::Runtime runtime;
			string classpath(argv[1]);
			Jvm::ClassLoader class_loader(
				Jvm::sp_ByteBufferSource(new Jvm::ClassPathByteBufferSource(classpath)),
				Jvm::sp_Runtime(new Jvm::Runtime)
			);
			class_loader.get_class(argv[2], 0);
		}
		gettimeofday(&stp_tv, NULL);	
		cout << str_tv.tv_sec << " " << str_tv.tv_usec << endl;
		cout << stp_tv.tv_sec << " " << stp_tv.tv_usec << endl;
		cout << elapsed (str_tv, stp_tv) << endl;
		return 0;

	}catch (JvmException & ex){
		cout << "exception: " << ex.what() << endl;
		return -1;
	}
}