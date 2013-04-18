#ifndef JVM_CLASSFILEMEMBER_H
#define JVM_CLASSFILEMEMBER_H

#include "Attribute.hpp"
#include "../AccessControlled.hpp"

#include <vector>

namespace Jvm{

	////////////////////////////////////////////////////////////////////////////////
	//
	// ClassFileMember
	// 
	// represents either a field or a method as seen in a java class file
	//
	////////////////////////////////////////////////////////////////////////////////

	class ClassFileMember{
	public:
		int access_flags;
		int name_index;
		int descriptor_index;
		std::vector<sp_Attribute> attributes;
	};

}

#endif