#ifndef CONSTANTPOOL_H
#define CONSTANTPOOL_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

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

	class ConstantPoolEntry{};

	class ConstantUtf8 : public ConstantPoolEntry{
		string str;
		public: 
		ConstantUtf8(const string & str) : str(str) {
			cout << "CONSTANT_Utf8 initialized with \"" << str << "\"" << endl;
		}
		string & get_string() {return str;}
	};

	class ConstantInteger : public ConstantPoolEntry{
		int val;
		public:
		ConstantInteger(int val) : val(val) {
			cout << "CONSTANT_Integer initialized with " << val << endl;
		}
		int get_val() {return val;}
	};

	class ConstantFloat : public ConstantPoolEntry{
		float val;
		public:
		ConstantFloat(float val) : val(val) {
			cout << "CONSTANT_Float initialized with " << val << endl;
		}
		float get_val() {return val;}
	};

	class ConstantLong : public ConstantPoolEntry{
		long val;
		public:
		ConstantLong(long val) : val(val) {
			cout << "CONSTANT_Long initialized with " << val << endl;
		}
		long get_val() {return val;}
	};

	class ConstantDouble : public ConstantPoolEntry{
		double val;
		public:
		ConstantDouble(double val) : val(val) {
			cout << "CONSTANT_Double initialized with " << val << endl;
		}
		double get_val() {return val;}
	};

	class ConstantClass : public ConstantPoolEntry{
		int name_index;
		public:
		ConstantClass(int name_index) : name_index(name_index) {
			cout << "CONSTANT_Class initialized with " <<  name_index << endl;
		}
		int get_name_index() {return name_index;}
	};

	class ConstantString : public ConstantPoolEntry{
		int string_index;
		public:
		ConstantString(int string_index) : string_index(string_index) {
			cout << "CONSTANT_String initialized with " <<  string_index << endl;
		}
		int get_string_index() {return string_index;}
	};

	class ConstantFieldref : public ConstantPoolEntry{
		int class_index;
		int name_and_type_index;
		public:
		ConstantFieldref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			cout << "CONSTANT_Fieldref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
		int get_class_index() {return class_index;}
		int get_name_and_type_index() {return name_and_type_index;}
	};

	class ConstantMethodref : public ConstantPoolEntry{
		int class_index;
		int name_and_type_index;
		public:
		ConstantMethodref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			cout << "CONSTANT_Methodref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
		int get_class_index() {return class_index;}
		int get_name_and_type_index() {return name_and_type_index;}
	};

	class ConstantInterfaceMethodref : public ConstantPoolEntry{
		int class_index;
		int name_and_type_index;
		public:
		ConstantInterfaceMethodref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			cout << "CONSTANT_InterfaceMethodref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
		int get_class_index() {return class_index;}
		int get_name_and_type_index() {return name_and_type_index;}
	};

	class ConstantNameAndType : public ConstantPoolEntry{
		int name_index;
		int descriptor_index;
		public:
		ConstantNameAndType(int name_index, int descriptor_index)
			: name_index(name_index), descriptor_index(descriptor_index) {
			cout << "CONSTANT_NameAndType initialized with " <<  name_index << ", " 
				<< descriptor_index << endl;
		}
		int get_name_index() {return name_index;}
		int get_descriptor_index() {return descriptor_index;}
	};

}

#endif