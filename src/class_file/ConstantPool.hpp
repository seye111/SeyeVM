#ifndef CLASSFILECONSTANTPOOL_H
#define CLASSFILECONSTANTPOOL_H

#include "../util/log.hpp"


#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>


using std::string;
using std::endl;
using boost::shared_ptr;

namespace ClassFile{

	const int CONSTANT_UTF8 = 1;
	const int CONSTANT_INTEGER = 3;
	const int CONSTANT_FLOAT = 4;
	const int CONSTANT_LONG = 5;
	const int CONSTANT_DOUBLE = 6;
	const int CONSTANT_CLASS = 7;
	const int CONSTANT_STRING = 8;
	const int CONSTANT_FIELDREF = 9;
	const int CONSTANT_METHODREF = 10;
	const int CONSTANT_INTERFACEMETHODREF = 11;
	const int CONSTANT_NAMEANDTYPE = 12;

	const int CONSTANT_MAX_TAG = 12;

	static string tag_names[] = {
		"UNUSED",
		"CONSTANT_UTF8",
		"UNUSED",
		"CONSTANT_INTEGER",
		"CONSTANT_FLOAT",
		"CONSTANT_LONG",
		"CONSTANT_DOUBLE",
		"CONSTANT_CLASS",
		"CONSTANT_STRING",
		"CONSTANT_FIELDREF",
		"CONSTANT_METHODREF",
		"CONSTANT_INTERFACEMETHODREF",
		"CONSTANT_NAMEANDTYPE"
	};

	////////////////////////////////////////////////////////////////////////////////
	//
	// base class ClassFile::ConstantPoolEntry and a set of subclasses thereof
	//
	// each instance represents one entry in the constant pool of a java class file
	//
	////////////////////////////////////////////////////////////////////////////////

	class ConstantPoolEntry{
	public:
		virtual int get_tag(){return 0;}
	};

	typedef shared_ptr<ConstantPoolEntry> sp_ConstantPoolEntry;

	class ConstantUtf8 : public ConstantPoolEntry{
	public:
		string str;
		ConstantUtf8(const string & str) : str(str) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Utf8 initialized with \"" << str << "\"  " << endl;
		}
		virtual int get_tag(){return CONSTANT_UTF8;}
	};

	class ConstantInteger : public ConstantPoolEntry{
	public:
		int val;
		ConstantInteger(int val) : val(val) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Integer initialized with " << val << endl;
		}
		virtual int get_tag(){return CONSTANT_INTEGER;}
	};

	class ConstantFloat : public ConstantPoolEntry{
	public:
		float val;
		ConstantFloat(float val) : val(val) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Float initialized with " << val << endl;
		}
		virtual int get_tag(){return CONSTANT_FLOAT;}
	};

	class ConstantLong : public ConstantPoolEntry{
	public:
		long val;
		ConstantLong(long val) : val(val) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Long initialized with " << val << endl;
		}
		virtual int get_tag(){return CONSTANT_LONG;}
	};

	class ConstantDouble : public ConstantPoolEntry{
	public:
		double val;
		ConstantDouble(double val) : val(val) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Double initialized with " << val << endl;
		}
		virtual int get_tag(){return CONSTANT_DOUBLE;}
	};

	class ConstantClass : public ConstantPoolEntry{
	public:
		int name_index;
		ConstantClass(int name_index) : name_index(name_index) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Class initialized with " <<  name_index << endl;
		}
		virtual int get_tag(){return CONSTANT_CLASS;}
	};

	class ConstantString : public ConstantPoolEntry{
	public:
		int string_index;
		ConstantString(int string_index) : string_index(string_index) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_String initialized with " <<  string_index << endl;
		}
		virtual int get_tag(){return CONSTANT_STRING;}
	};

	class ConstantFieldref : public ConstantPoolEntry{
	public:
		int class_index;
		int name_and_type_index;
		ConstantFieldref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Fieldref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
		virtual int get_tag(){return CONSTANT_FIELDREF;}
	};

	class ConstantMethodref : public ConstantPoolEntry{
	public:
		int class_index;
		int name_and_type_index;
		ConstantMethodref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_Methodref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
		virtual int get_tag(){return CONSTANT_METHODREF;}
	};

	class ConstantInterfaceMethodref : public ConstantPoolEntry{
	public:
		int class_index;
		int name_and_type_index;
		ConstantInterfaceMethodref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_InterfaceMethodref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
		virtual int get_tag(){return CONSTANT_INTERFACEMETHODREF;}
	};

	class ConstantNameAndType : public ConstantPoolEntry{
	public:
		int name_index;
		int descriptor_index;
		ConstantNameAndType(int name_index, int descriptor_index)
			: name_index(name_index), descriptor_index(descriptor_index) {
			if(logger.is_trace()) logger.log_trace()
				<< "CONSTANT_NameAndType initialized with " <<  name_index << ", " 
				<< descriptor_index << endl;
		}
		virtual int get_tag(){return CONSTANT_NAMEANDTYPE;}
	};

}

#endif