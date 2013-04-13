#ifndef CLASSFILEREPRESENTATION_H
#define CLASSFILEREPRESENTATION_H

#include "ConstantPool.h"
#include "parser/ClassFileDataBuffer.h"

#include <vector>

using std::vector;

namespace ClassFile{
	

	class ClassFileRepresentation{
		friend ClassFileRepresentation* parse_from_buffer(ClassFileDataBuffer & buffer) throw(JvmException);
		int minor_version;
		int major_version;
		int constant_pool_count;
		vector<ConstantPoolEntry> constant_pool;
	};

	ClassFileRepresentation* parse_from_buffer(ClassFileDataBuffer & buffer) throw(JvmException);

}

#endif