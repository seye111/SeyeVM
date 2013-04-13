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

	void load_constant_pool(ClassFileDataBuffer & buffer, vector<ConstantPoolEntry> & constant_pool, int count) throw (JvmException){
		for(int index = 1; index < count; index++){
			int tag = buffer.get_u1();
			cout << index << " - ";
			int class_index;
			int name_and_type_index;
			int name_index;
			int descriptor_index;
			switch(tag){
				case CONSTANT_UTF8:
					constant_pool.push_back(ConstantUtf8(buffer.get_string()));
					break; 
				case CONSTANT_INTEGER: 
					constant_pool.push_back(ConstantInteger(buffer.get_int()));
					break; 
				case CONSTANT_FLOAT: 
					constant_pool.push_back(ConstantFloat(buffer.get_float()));
					break; 
				case CONSTANT_LONG: 
					constant_pool.push_back(ConstantLong(buffer.get_long()));
					// longs take up two slots in the constant pool;
					constant_pool.push_back(ConstantPoolEntry());
					index++;
					break; 
				case CONSTANT_DOUBLE: 
					constant_pool.push_back(ConstantDouble(buffer.get_double()));
					// doubles take up two slots in the constant pool;
					constant_pool.push_back(ConstantPoolEntry());
					index++;
					break; 
				case CONSTANT_CLASS: 
					constant_pool.push_back(ConstantClass(buffer.get_u2()));
					break; 
				case CONSTANT_STRING: 
					constant_pool.push_back(ConstantString(buffer.get_u2()));
					break; 
				case CONSTANT_FIELDREF: {
						int class_index = buffer.get_u2();
						int name_and_type_index = buffer.get_u2(); 
						constant_pool.push_back(ConstantFieldref(class_index, name_and_type_index));
					}
					break; 
				case CONSTANT_METHODREF: {
						int class_index = buffer.get_u2();
						int name_and_type_index = buffer.get_u2(); 
						constant_pool.push_back(ConstantMethodref(class_index, name_and_type_index));
					}
					break; 
				case CONSTANT_INTERFACEMETHODREF: {
						int class_index = buffer.get_u2();
						int name_and_type_index = buffer.get_u2();
						constant_pool.push_back(ConstantInterfaceMethodref(class_index, name_and_type_index));
					}
					break; 
				case CONSTANT_NAMEANDTYPE: {
						int name_index = buffer.get_u2();
						int descriptor_index = buffer.get_u2();
						constant_pool.push_back(ConstantNameAndType(name_index, descriptor_index));
					}
					break; 
				default:
					ostringstream os;
					os << "unsupported tag " << tag;
					throw JvmException (os.str());
			}
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

		int c_pool_count = buffer.get_u2();
		cout << "constant pool count - " << c_pool_count << endl;
		cfrep->constant_pool_count = c_pool_count;

		cfrep->constant_pool = vector<ConstantPoolEntry>(c_pool_count + 1);
		cfrep->constant_pool.push_back(ConstantPoolEntry());

		load_constant_pool(buffer, cfrep->constant_pool, c_pool_count);

		return cfrep;
	}


}