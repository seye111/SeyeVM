#ifndef JVM_ATTRIBUTE
#define JVM_ATTRIBUTE

#include "../ByteBuffer.hpp"
#include "../../util/log.hpp"

#include <iostream>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
//
// Attribute
// 
// represents an attribute of a field, method, other attribute or the class
// itself as seen in a java class file
//
////////////////////////////////////////////////////////////////////////////////

namespace Jvm{

	using std::endl;

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

		virtual ~Attribute(){
			if(logger.is_trace()) logger.log_trace() << "Attribute destructor called (delete_me) " << endl;
		}
	};

	struct ExceptionInfo{
		int start_pc;
		int end_pc;
		int handler_pc;
		int catch_type;
	};

	class CodeAttribute : public Attribute{
	public:
		int max_stack;
		int max_locals;
		int code_length;
		char* code;
		std::vector<ExceptionInfo*> exception_table;
		std::vector<Attribute*> attributes;
		
		virtual int get_tag(){
			return ATTRIBUTE_CODE;
		}

		virtual ~CodeAttribute(){
			if(logger.is_trace()) logger.log_trace() << "CodeAttribute destructor called (delete_me) " << endl;
			delete code;
			for(int i=0; i < exception_table.size(); i++)
				delete exception_table[i];
			for(int i=0; i < attributes.size(); i++)
				delete attributes[i];
		}
	};

	class ConstantValueAttribute : public Attribute{
	public:
		int constantvalue_index;

		virtual int get_tag(){
			return ATTRIBUTE_CONSTANTVALUE;
		}

		virtual ~ConstantValueAttribute(){
			if(logger.is_trace()) logger.log_trace() << "ConstantValueAttribute destructor called (delete_me) " << endl;
		}
	};

	class DepricatedAttribute : public Attribute{
	public:

		virtual int get_tag(){
			return ATTRIBUTE_DEPRICATED;
		}

		virtual ~DepricatedAttribute(){
			if(logger.is_trace()) logger.log_trace() << "DepricatedAttribute destructor called (delete_me) " << endl;
		}
	};

	class ExceptionsAttribute : public Attribute{
	public:
		std::vector<int> exception_indexes;

		virtual int get_tag(){
			return ATTRIBUTE_EXCEPTIONS;
		}

		virtual ~ExceptionsAttribute(){
			if(logger.is_trace()) logger.log_trace() << "ExceptionsAttribute destructor called (delete_me) " << endl;
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
		std::vector<InnerClassInfo*> classes;

		virtual int get_tag(){
			return ATTRIBUTE_INNERCLASSES;
		}

		virtual ~InnerClassesAttribute(){
			if(logger.is_trace()) logger.log_trace() << "InnerClassesAttribute destructor called (delete_me) " << endl;
			for(int i=0; i < classes.size(); i++)
				delete classes[i];
		}
	};

	struct LineNumberInfo{
		int start_pc;
		int line_number;
	};

	class LineNumberTableAttribute : public Attribute{
	public:
		std::vector<LineNumberInfo*> line_number_table;
		virtual int get_tag(){
			return ATTRIBUTE_LINENUMBERTABLE;
		}

		virtual ~LineNumberTableAttribute(){
			if(logger.is_trace()) logger.log_trace() << "LineNUmberTableAttribute destructor called (delete_me) " << endl;
			for(int i=0; i < line_number_table.size(); i++)
				delete line_number_table[i];
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
		std::vector<LocalVariableInfo*> local_variable_table;
		virtual int get_tag(){
			return ATTRIBUTE_LOCALVARIABLETABLE;
		}

		virtual ~LocalVariableTableAttribute(){
			if(logger.is_trace()) logger.log_trace() << "LocalVariableTableAttribute destructor called (delete_me) " << endl;
			for(int i=0; i < local_variable_table.size(); i++)
				delete local_variable_table[i];
		}
	};

	class SourceFileAttribute : public Attribute{
	public:
		int source_file_index;
		virtual int get_tag(){
			return ATTRIBUTE_SOURCEFILE;
		}

		virtual ~SourceFileAttribute(){
			if(logger.is_trace()) logger.log_trace() << "SourceFileAttribute destructor called (delete_me) " << endl;
		}
	};

	class SyntheticAttribute : public Attribute{
	public:
		virtual int get_tag(){
			return ATTRIBUTE_SYNTHETIC;
		}

		virtual ~SyntheticAttribute(){
			if(logger.is_trace()) logger.log_trace() << "SyntheticAttribute destructor called (delete_me) " << endl;
		}
	};

}

#endif
