#include "ClassFileParser.hpp"
#include "ClassFileDataBuffer.hpp"

#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::vector;

namespace Jvm{

	ClassFileParser::ClassFileParser(ClassFileDataBuffer & buffer) : buffer(buffer) {}
	
	ClassFileParser::~ClassFileParser(){}

	ClassFileRepresentation* ClassFileParser::parse_from_buffer(){
		if(logger.is_debug()) logger.log_debug() << "parsing class file data..." << endl;
		check_magic(buffer.get_u4()); 

		p_class_file_representation = new ClassFileRepresentation;

		ClassFileRepresentation & cfrep = *p_class_file_representation;

		int minor = buffer.get_u2();
		cfrep.minor_version = minor;
		if(logger.is_trace()) logger.log_trace() << "minor version - " << minor << endl;

		int major = buffer.get_u2();
		cfrep.major_version = major;
		if(logger.is_trace()) logger.log_trace() << "major version - " << major << endl;

		// zeroth entry in constant pool is empty
		
		cfrep.constant_pool.push_back(new ConstantPoolEntry());
		load_constant_pool();

		cfrep.access_flags = buffer.get_u2();
		if(logger.is_trace()) logger.log_trace() << "access flags " << cfrep.access_flags << endl;
		cfrep.this_class = buffer.get_u2();
		if(logger.is_trace()) logger.log_trace() << "this_class " << cfrep.this_class << endl;
		cfrep.super_class = buffer.get_u2();
		if(logger.is_trace()) logger.log_trace() << "super_class " << cfrep.super_class << endl;
		int interface_count = buffer.get_u2();
		if(logger.is_trace()) logger.log_trace() << "interface_count " << interface_count << endl;
		for(int i=0; i < interface_count; i++){
			cfrep.interfaces.push_back(buffer.get_u2());
		}

		parse_members(cfrep.fields);
		parse_members(cfrep.methods);
		parse_attributes(cfrep.attributes);
		
		if(logger.is_debug()) logger.log_debug() << "...parsed class file data." << endl;
		return p_class_file_representation;
	}

	void ClassFileParser::check_magic(long magic){
		if(magic == MAGIC){
			if(logger.is_trace()) logger.log_trace() << "magic number checked" << endl;
		}else{
			ostringstream os;
			os << "magic number mismatch - expected " << std::hex << MAGIC << ", got " << magic;
			throw JvmException (os.str());
		}
	}

	void ClassFileParser::load_constant_pool(){
		int count = buffer.get_u2();
		if(logger.is_trace()) logger.log_trace() << "constant pool count - " << count << endl;
		std::vector<ConstantPoolEntry*> & constant_pool = p_class_file_representation->constant_pool;
		for(int index = 1; index < count; index++){
			int tag = buffer.get_u1();
			switch(tag){
				case CONSTANT_UTF8:
					constant_pool.push_back(new ConstantUtf8(buffer.get_string()));
					break; 
				case CONSTANT_INTEGER: 
					constant_pool.push_back(new ConstantInteger(buffer.get_int()));
					break; 
				case CONSTANT_FLOAT: 
					constant_pool.push_back(new ConstantFloat(buffer.get_float()));
					break; 
				case CONSTANT_LONG: 
					constant_pool.push_back(new ConstantLong(buffer.get_long()));
					// longs take up two slots in the constant pool;
					constant_pool.push_back(new ConstantPoolEntry());
					index++;
					break; 
				case CONSTANT_DOUBLE: 
					constant_pool.push_back(new ConstantDouble(buffer.get_double()));
					// doubles take up two slots in the constant pool;
					constant_pool.push_back(new ConstantPoolEntry());
					index++;
					break; 
				case CONSTANT_CLASS: 
					constant_pool.push_back(new ConstantClass(buffer.get_u2()));
					break; 
				case CONSTANT_STRING: 
					constant_pool.push_back(new ConstantString(buffer.get_u2()));
					break; 
				case CONSTANT_FIELDREF: {
						int class_index = buffer.get_u2();
						int name_and_type_index = buffer.get_u2(); 
						constant_pool.push_back(new ConstantFieldref(class_index, name_and_type_index));
					}
					break; 
				case CONSTANT_METHODREF: {
						int class_index = buffer.get_u2();
						int name_and_type_index = buffer.get_u2(); 
						constant_pool.push_back(new ConstantMethodref(class_index, name_and_type_index));
					}
					break; 
				case CONSTANT_INTERFACEMETHODREF: {
						int class_index = buffer.get_u2();
						int name_and_type_index = buffer.get_u2();
						constant_pool.push_back(new ConstantInterfaceMethodref(class_index, name_and_type_index));
					}
					break; 
				case CONSTANT_NAMEANDTYPE: {
						int name_index = buffer.get_u2();
						int descriptor_index = buffer.get_u2();
						constant_pool.push_back(new ConstantNameAndType(name_index, descriptor_index));
					}
					break; 
				default:
					ostringstream os;
					os << "unsupported tag " << tag;
					throw JvmException (os.str());
			}
		}
	}

	void ClassFileParser::parse_attributes(vector<Attribute*> & attributes){
		int attribute_count = buffer.get_u2();
		if(logger.is_trace()) logger.log_trace() << attribute_count << " attribute(s)" << endl;
		for(int index = 0; index < attribute_count; index++){
			int name_index = buffer.get_u2();
			string name = ((ConstantUtf8*)p_class_file_representation->constant_pool[name_index])->str;
			if(logger.is_trace()) logger.log_trace() << name << endl;
			int attribute_length = buffer.get_u4();
			if(name == "Code"){
				CodeAttribute* attr = new CodeAttribute;
				attr->max_stack = buffer.get_u2();
				attr->max_locals = buffer.get_u2();
				attr->code_length = buffer.get_u4();
				if(attr->code_length > 0){
					attr->code = new char[attr->code_length];
					for(int i=0; i < attr->code_length; i++){
						attr->code[i] = buffer.get_byte();
					}
				}else{
					if(logger.is_trace()) logger.log_trace() << "low code length " << attr->code_length << " (delete me)" << endl;
				}
				int exception_table_length = buffer.get_u2();
				for(int i=0; i < exception_table_length; i++){
					ExceptionInfo* ei = new ExceptionInfo;
					ei->start_pc = buffer.get_u2();
					ei->end_pc = buffer.get_u2();
					ei->handler_pc = buffer.get_u2();
					ei->catch_type = buffer.get_u2();
					attr->exception_table.push_back(ei);
				}
				parse_attributes(attr->attributes);
				attributes.push_back(attr);
			}else if(name == "ConstantValue"){
				ConstantValueAttribute* attr = new ConstantValueAttribute;
				attr->constantvalue_index = buffer.get_u2();
				attributes.push_back(attr);

			}else if(name == "Deprecated"){
				attributes.push_back(new DepricatedAttribute);

			}else if(name == "Exceptions"){
				ExceptionsAttribute* attr = new ExceptionsAttribute;
				int exception_count = buffer.get_u2();
				for(int i=0; i < exception_count; i++){
					attr->exception_indexes.push_back(buffer.get_u2());
				}
				attributes.push_back(attr);

			}else if(name == "InnerClasses"){
				InnerClassesAttribute* attr = new InnerClassesAttribute;
				int number_of_classes = buffer.get_u2();
				for(int i=0; i < number_of_classes; i++){
					InnerClassInfo* ici = new InnerClassInfo;
					ici->inner_class_info_index = buffer.get_u2();
					ici->outer_class_info_index = buffer.get_u2();
					ici->inner_name_index = buffer.get_u2();
					ici->inner_class_access_flags = buffer.get_u2();
					attr->classes.push_back(ici);
				}
				attributes.push_back(attr);

			}else if(name == "LineNumberTable"){
				LineNumberTableAttribute* attr = new LineNumberTableAttribute;
				int line_number_table_length = buffer.get_u2();
				for(int i=0; i < line_number_table_length; i++){
					LineNumberInfo* lni = new LineNumberInfo;
					lni->start_pc = buffer.get_u2();
					lni->line_number = buffer.get_u2();
					attr->line_number_table.push_back(lni);
				}
				attributes.push_back(attr);

			}else if(name == "LocalVariableTable"){
				LocalVariableTableAttribute* attr = new LocalVariableTableAttribute;
				int local_variable_table_length = buffer.get_u2();
				for(int i=0; i < local_variable_table_length; i++){
					LocalVariableInfo* lvi = new LocalVariableInfo;
					lvi->start_pc = buffer.get_u2();
					lvi->length = buffer.get_u2();
					lvi->name_index = buffer.get_u2();
					lvi->descriptor_index = buffer.get_u2();
					lvi->index = buffer.get_u2();
					attr->local_variable_table.push_back(lvi);
				}
				attributes.push_back(attr);

			}else if(name == "SourceFile"){
				SourceFileAttribute* attr = new SourceFileAttribute;
				attr->source_file_index = buffer.get_u2();
				attributes.push_back(attr);

			}else if(name == "Synthetic"){
				attributes.push_back(new SyntheticAttribute());

			}else if(
					name == "Signature" || name == "RuntimeVisibleAnnotations"	
				){
				for(int i=0; i < attribute_length; i++){
					buffer.get_byte();
				}
			}else {
				throw JvmException("unknown attribute name " + name);
			}
		}
	}

	void ClassFileParser::parse_members(vector<ClassFileMember*> & members){
		int member_count = buffer.get_u2();
		if(logger.is_trace()) logger.log_trace() << "member_count " << member_count << endl;
		for(int index = 0; index < member_count; index++){
			if(logger.is_trace()) logger.log_trace() << index << endl;
			ClassFileMember* member = new ClassFileMember;
			member->access_flags = buffer.get_u2();
			member->name_index = buffer.get_u2();
			member->descriptor_index = buffer.get_u2();
			string name = ((ConstantUtf8*)p_class_file_representation->constant_pool[member->name_index])->str;
			string descriptor = ((ConstantUtf8*)p_class_file_representation->constant_pool[member->descriptor_index])->str;
			if(logger.is_trace()) logger.log_trace() << name << " : " << descriptor << endl;
			parse_attributes(member->attributes);
			members.push_back(member);
		}
	}

}