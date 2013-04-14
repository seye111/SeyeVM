#ifndef CLASSFILE_MEMBER_H
#define CLASSFILE_MEMBER_H

#include "Attribute.hpp"
#include "../internal/AccessControlled.hpp"

#include <vector>

using std::vector;

namespace ClassFile{

	class Member{
	public:
		int access_flags;
		int name_index;
		int descriptor_index;
		vector<sp_Attribute> attributes;
	};

}

#endif