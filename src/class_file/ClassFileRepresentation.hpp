
#ifndef CLASSFILE_CLASSFILEREPRESENTATION_H
#define CLASSFILE_CLASSFILEREPRESENTATION_H

#include "ConstantPool.hpp"
#include "Member.hpp"

#include <vector>

using std::vector;

namespace ClassFile{
	
	class ClassFileRepresentation{
	public:
		int minor_version;
		int major_version;
		vector<sp_ConstantPoolEntry> constant_pool;
		int access_flags;
		int this_class;
		int super_class;
		vector<int> interfaces;
		vector<Member> fields;
		vector<Member> methods;
		vector<sp_Attribute> attributes;
	};
}

#endif