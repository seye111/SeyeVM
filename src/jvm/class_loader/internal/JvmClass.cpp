#include "JvmClass.hpp"

namespace Jvm{

	using std::string;
	using std::map;
	using std::vector;


	JvmClass::JvmClass(ClassFileRepresentation* p_class_file_representation) : 
			p_class_file_representation (p_class_file_representation),
			super_class(NULL),
			static_data_4(NULL), 
			static_data_8(NULL) {}
	
	JvmClass::~JvmClass() {
		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor called (delete_me) " << endl;

		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor static_data_4 (delete_me) " << endl;
		delete[] static_data_4;

		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor static_data_8 (delete_me) " << endl;
		delete[] static_data_8;

		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor static_fields (delete_me) " << endl;
		for(map<string, JvmField*>::iterator it=static_fields.begin(); it!=static_fields.end(); ++it){
			delete it->second;
		}	

		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor instance_fields (delete_me) " << endl;
		for(map<string, JvmField*>::iterator it=instance_fields.begin(); it!=instance_fields.end(); ++it){
			delete it->second;
		}	

		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor static_methods (delete_me) " << endl;
		for(map<string, JvmMethod*>::iterator it=static_methods.begin(); it!=static_methods.end(); ++it){
			delete it->second;
		}	

		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor instance_methods (delete_me) " << endl;
		for(map<string, JvmMethod*>::iterator it=instance_methods.begin(); it!=instance_methods.end(); ++it){
			delete it->second;
		}	

		delete p_class_file_representation;

		if(logger.is_trace()) logger.log_trace() 
			<< "JvmClass " << name << " destructor finished (delete_me) " << endl;
	}


}