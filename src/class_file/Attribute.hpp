#ifndef CLASSFILE_ATTRIBUTE
#define CLASSFILE_ATTRIBUTE

#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using boost::shared_ptr;

namespace ClassFile{

	////////////////////////////////////////////////////////////////////////////////
	//
	// ClassFile::Attribute
	// 
	// represents an attribute of a field, method, other attribute or the class
	// itself as seen in a java class file
	//
	////////////////////////////////////////////////////////////////////////////////

	const int ATTRIBUTE_CODE = 1;
	const int ATTRIBUTE_CONSTANTVALUE = 2;
	const int ATTRIBUTE_DEPRICATED = 3;
	const int ATTRIBUTE_EXCEPTIONS = 4;
	const int ATTRIBUTE_INNERCLASSES = 5;
	const int ATTRIBUTE_LINENUMBERTABLE = 6;
	const int ATTRIBUTE_LOCALVARIABLETABLE = 7;
	const int ATTRIBUTE_SOURCEFILE = 8;
	const int ATTRIBUTE_SYNTHETIC = 9;

	class Attribute{
	public:
		virtual int get_tag(){return 0;}
	};

	typedef shared_ptr<Attribute> sp_Attribute;

	struct ExceptionInfo{
		int start_pc;
		int end_pc;
		int handler_pc;
		int catch_type;
	};

	typedef shared_ptr<char> sp_char;

	class CodeAttribute : public Attribute{
	public:
		int max_stack;
		int max_locals;
		int code_length;
		sp_char code;
		vector<ExceptionInfo> exception_table;
		vector<sp_Attribute> attributes;
		
		virtual int get_tag(){
			return ATTRIBUTE_CODE;
		}
	};

	class ConstantValueAttribute : public Attribute{
	public:
		int constantvalue_index;

		virtual int get_tag(){
			return ATTRIBUTE_CONSTANTVALUE;
		}
	};

	class DepricatedAttribute : public Attribute{
	public:
		virtual int get_tag(){
			return ATTRIBUTE_DEPRICATED;
		}
	};

	class ExceptionsAttribute : public Attribute{
	public:
		vector<int> exception_indexes;
		virtual int get_tag(){
			return ATTRIBUTE_EXCEPTIONS;
		}
	};

	struct InnerClassInfo{
		int inner_class_info_index;
		int outer_class_info_index;
		int inner_name_index;
		int inner_class_access_flags;
	};

	class InnerClassesAttribute : public Attribute{
	public:
		vector<InnerClassInfo> classes;
		virtual int get_tag(){
			return ATTRIBUTE_INNERCLASSES;
		}
	};

	struct LineNumberInfo{
		int start_pc;
		int line_number;
	};

	class LineNumberTableAttribute : public Attribute{
	public:
		vector<LineNumberInfo> line_number_table;
		virtual int get_tag(){
			return ATTRIBUTE_LINENUMBERTABLE;
		}
	};

	struct LocalVariableInfo{
		int start_pc;
		int length;
		int name_index;
		int descriptor_index;
		int index;
	};

	class LocalVariableTableAttribute : public Attribute{
	public:
		vector<LocalVariableInfo> local_variable_table;
		virtual int get_tag(){
			return ATTRIBUTE_LOCALVARIABLETABLE;
		}
	};

	class SourceFileAttribute : public Attribute{
	public:
		int source_file_index;
		virtual int get_tag(){
			return ATTRIBUTE_SOURCEFILE;
		}
	};

	class SyntheticAttribute : public Attribute{
	public:
		virtual int get_tag(){
			return ATTRIBUTE_SYNTHETIC;
		}
	};
}

#endif
