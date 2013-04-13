#include "ClassFileParser.h"
#include "ClassFileDataBuffer.h"

#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::vector;

namespace ClassFile{

	ClassFileRepresentation* parse_from_file(string & filename) throw (JvmException){
		ClassFileDataBuffer* buffer = ClassFileDataBuffer::get_from_file(filename);
		ClassFileRepresentation* result = parse_from_buffer(*buffer);
		delete buffer;
		return result;
	}

	void check_magic(long magic) throw (JvmException){
		if(magic == MAGIC){
			cout << "magic number checked" << endl;
		}else{
			ostringstream os;
			os << "magic number mismatch - expected " << std::hex << MAGIC << ", got " << magic;
			throw JvmException (os.str());
		}
	}

	void load_constant_pool(ClassFileDataBuffer & buffer, vector<ConstantPoolEntry*> & constant_pool) throw (JvmException){
		
		int count = buffer.get_u2();
		cout << "constant pool count - " << count << endl;

		for(int index = 1; index < count; index++){
			int tag = buffer.get_u1();
			cout << index << " - ";
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

	void parse_attributes(ClassFileDataBuffer & buffer, ClassFileRepresentation & cfrep, vector<Attribute*> attributes){
		int attribute_count = buffer.get_u2();
		cout << attribute_count << " attribute(s)" << endl;
		for(int index = 0; index < attribute_count; index++){
			cout << index << " - ";
			int name_index = buffer.get_u2();
			string name = ((ConstantUtf8*)cfrep.constant_pool[name_index])->str;
			cout << name << endl;
			int attribute_length = buffer.get_u4();
			if(name == "Code"){
				CodeAttribute *attr = new CodeAttribute();
				attr->max_stack = buffer.get_u2();
				attr->max_locals = buffer.get_u2();
				attr->code_length = buffer.get_u4();
				attr->code = new char[attr->code_length];
				for(int i=0; i < attr->code_length; i++){
					attr->code[i] = buffer.get_byte();
				}
				int exception_table_length = buffer.get_u2();
				for(int i=0; i < exception_table_length; i++){
					ExceptionInfo ei;
					ei.start_pc = buffer.get_u2();
					ei.end_pc = buffer.get_u2();
					ei.handler_pc = buffer.get_u2();
					ei.catch_type = buffer.get_u2();
					attr->exception_table.push_back(ei);
				}
				parse_attributes(buffer, cfrep, attr->attributes);
				attributes.push_back(attr);
			}else if(name == "ConstantValue"){
				ConstantValueAttribute *attr = new ConstantValueAttribute();
				attr->constantvalue_index = buffer.get_u2();
				attributes.push_back(attr);

			}else if(name == "Deprecated"){
				DepricatedAttribute *attr = new DepricatedAttribute();
				attributes.push_back(attr);

			}else if(name == "Exceptions"){
				ExceptionsAttribute *attr = new ExceptionsAttribute();
				int exception_count = buffer.get_u2();
				for(int i=0; i < exception_count; i++){
					attr->exception_indexes.push_back(buffer.get_u2());
				}
				attributes.push_back(attr);

			}else if(name == "InnerClasses"){
				InnerClassesAttribute *attr = new InnerClassesAttribute();
				int number_of_classes = buffer.get_u2();
				for(int i=0; i < number_of_classes; i++){
					InnerClassInfo ici;
					ici.inner_class_info_index = buffer.get_u2();
					ici.outer_class_info_index = buffer.get_u2();
					ici.inner_name_index = buffer.get_u2();
					ici.inner_class_access_flags = buffer.get_u2();
					attr->classes.push_back(ici);
				}
				attributes.push_back(attr);

			}else if(name == "LineNumberTable"){
				LineNumberTableAttribute *attr = new LineNumberTableAttribute();
				int line_number_table_length = buffer.get_u2();
				for(int i=0; i < line_number_table_length; i++){
					LineNumberInfo lni;
					lni.start_pc = buffer.get_u2();
					lni.line_number = buffer.get_u2();
					attr->line_number_table.push_back(lni);
				}
				attributes.push_back(attr);

			}else if(name == "LocalVariableTable"){
				LocalVariableTableAttribute *attr = new LocalVariableTableAttribute();
				int local_variable_table_length = buffer.get_u2();
				for(int i=0; i < local_variable_table_length; i++){
					LocalVariableInfo lvi;
					lvi.start_pc = buffer.get_u2();
					lvi.length = buffer.get_u2();
					lvi.name_index = buffer.get_u2();
					lvi.descriptor_index = buffer.get_u2();
					lvi.index = buffer.get_u2();
					attr->local_variable_table.push_back(lvi);
				}
				attributes.push_back(attr);

			}else if(name == "SourceFile"){
				SourceFileAttribute *attr = new SourceFileAttribute();
				attr->source_file_index = buffer.get_u2();
				attributes.push_back(attr);

			}else if(name == "Synthetic"){
				SyntheticAttribute *attr = new SyntheticAttribute();
				attributes.push_back(attr);

			}else if(
					name == "Signature"	
				){
				for(int i=0; i < attribute_length; i++){
					buffer.get_byte();
				}
			}else {
				throw JvmException("unknown attribute name " + name);
			}
		}
	}

	void parse_members(ClassFileDataBuffer & buffer, ClassFileRepresentation & cfrep){
		int member_count = buffer.get_u2();
		cout << "member_count " << member_count << endl;
		for(int index = 0; index < member_count; index++){
			cout << index << " - ";
			Member member;
			member.access_flags = buffer.get_u2();
			member.name_index = buffer.get_u2();
			member.descriptor_index = buffer.get_u2();
			// todo - remove
			string name = ((ConstantUtf8*)cfrep.constant_pool[member.name_index])->str;
			string descriptor = ((ConstantUtf8*)cfrep.constant_pool[member.descriptor_index])->str;
			cout << name << " : " << descriptor << endl;
			parse_attributes(buffer, cfrep, member.attributes);
		}
	}


	ClassFileRepresentation* parse_from_buffer(ClassFileDataBuffer & buffer) throw (JvmException){
		
		check_magic(buffer.get_u4()); 

		ClassFileRepresentation* cfrep = new ClassFileRepresentation();
	
		int minor = buffer.get_u2();
		cfrep->minor_version = minor;
		cout << "minor version - " << minor << endl;
	
		int major = buffer.get_u2();
		cfrep->major_version = major;
		cout << "major version - " << major << endl;

		// zeroth entry in constant pool is empty
		cfrep->constant_pool.push_back(new ConstantPoolEntry());
		load_constant_pool(buffer, cfrep->constant_pool);

		cfrep->access_flags = buffer.get_u2();
		cout << "access flags " << cfrep->access_flags << endl;
		cfrep->this_class = buffer.get_u2();
		cout << "this_class " << cfrep->this_class << endl;
		cfrep->super_class = buffer.get_u2();
		cout << "super_class " << cfrep->super_class << endl;
		int interface_count = buffer.get_u2();
		cout << "interface_count " << interface_count << endl;
		for(int i=0; i < interface_count; i++){
			cfrep->interfaces.push_back(buffer.get_u2());
		}

		// fields
		parse_members(buffer, *cfrep);
		//methods
		parse_members(buffer, *cfrep);
		parse_attributes(buffer, *cfrep, cfrep->attributes);
		return cfrep;
	}

}