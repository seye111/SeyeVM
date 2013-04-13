#ifndef CLASSFILE_CLASSFILEREPRESENTATION_H
#define CLASSFILE_CLASSFILEREPRESENTATION_H

#include "ConstantPool.h"
#include "Field.h"
#include "parser/ClassFileDataBuffer.h"

#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;

namespace ClassFile{
	

	class ClassFileRepresentation{
		friend ClassFileRepresentation* parse_from_buffer(ClassFileDataBuffer & buffer) throw(JvmException);
		int minor_version;
		int major_version;
		int constant_pool_count;
		vector<ConstantPoolEntry> constant_pool;
		map<string, Field> fields;
	};

	ClassFileRepresentation* parse_from_buffer(ClassFileDataBuffer & buffer) throw(JvmException);

}

#endif