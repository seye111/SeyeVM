#include "ClassFileRepresentation.hpp"

namespace Jvm{

	ClassFileRepresentation::ClassFileRepresentation(){}

	ClassFileRepresentation::~ClassFileRepresentation(){
		if(logger.is_trace()) logger.log_trace() 
			<< "ClassFileRepresentation " << " destructor called (delete_me) " << endl;

		for(int i=0; i < constant_pool.size(); i++){
			delete constant_pool[i];
		}

		for(int i=0; i < fields.size(); i++){
			delete fields[i];
		}

		for(int i=0; i < methods.size(); i++){
			delete methods[i];
		}

		for(int i=0; i < attributes.size(); i++){
			delete attributes[i];
		}

		if(logger.is_trace()) logger.log_trace() 
			<< "ClassFileRepresentation " << " destructor finished (delete_me) " << endl;
	}

}