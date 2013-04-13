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
		public: 
		string str;
		ConstantUtf8(const string & str) : str(str) {
			cout << "CONSTANT_Utf8 initialized with \"" << str << "\"  " << endl;
		}
	};

	class ConstantInteger : public ConstantPoolEntry{
		public:
		int val;
		ConstantInteger(int val) : val(val) {
			cout << "CONSTANT_Integer initialized with " << val << endl;
		}
	};

	class ConstantFloat : public ConstantPoolEntry{
		public:
		float val;
		ConstantFloat(float val) : val(val) {
			cout << "CONSTANT_Float initialized with " << val << endl;
		}
	};

	class ConstantLong : public ConstantPoolEntry{
		public:
		long val;
		ConstantLong(long val) : val(val) {
			cout << "CONSTANT_Long initialized with " << val << endl;
		}
	};

	class ConstantDouble : public ConstantPoolEntry{
		public:
		double val;
		ConstantDouble(double val) : val(val) {
			cout << "CONSTANT_Double initialized with " << val << endl;
		}
	};

	class ConstantClass : public ConstantPoolEntry{
		public:
		int name_index;
		ConstantClass(int name_index) : name_index(name_index) {
			cout << "CONSTANT_Class initialized with " <<  name_index << endl;
		}
	};

	class ConstantString : public ConstantPoolEntry{
		public:
		int string_index;
		ConstantString(int string_index) : string_index(string_index) {
			cout << "CONSTANT_String initialized with " <<  string_index << endl;
		}
	};

	class ConstantFieldref : public ConstantPoolEntry{
		public:
		int class_index;
		int name_and_type_index;
		ConstantFieldref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			cout << "CONSTANT_Fieldref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
	};

	class ConstantMethodref : public ConstantPoolEntry{
		public:
		int class_index;
		int name_and_type_index;
		ConstantMethodref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			cout << "CONSTANT_Methodref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
	};

	class ConstantInterfaceMethodref : public ConstantPoolEntry{
		public:
		int class_index;
		int name_and_type_index;
		ConstantInterfaceMethodref(int class_index, int name_and_type_index)
			: class_index(class_index), name_and_type_index(name_and_type_index) {
			cout << "CONSTANT_InterfaceMethodref initialized with " <<  class_index << ", " 
				<< name_and_type_index << endl;
		}
	};

	class ConstantNameAndType : public ConstantPoolEntry{
		public:
		int name_index;
		int descriptor_index;
		ConstantNameAndType(int name_index, int descriptor_index)
			: name_index(name_index), descriptor_index(descriptor_index) {
			cout << "CONSTANT_NameAndType initialized with " <<  name_index << ", " 
				<< descriptor_index << endl;
		}
	};

}

#endif