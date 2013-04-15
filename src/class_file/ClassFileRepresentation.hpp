
#ifndef CLASSFILE_CLASSFILEREPRESENTATION_H
#define CLASSFILE_CLASSFILEREPRESENTATION_H

#include "ConstantPool.hpp"
#include "Member.hpp"

#include <vector>

using std::vector;

namespace ClassFile{

	////////////////////////////////////////////////////////////////////////////////
	//
	// struct ClassFile::ClassFileRepresentation
	// 
	// describes the intermediate representation of the contents of a 
	// java class file. it closely resembles the format of the class file itself
	// and none of the references or code in it are expanded.
	//
	// it is intended to be parsed from the raw class file data and then handed on 
	// to be converted to a richer, expanded representation for linking and 
	// execution.  
	//
	////////////////////////////////////////////////////////////////////////////////

	struct ClassFileRepresentation{
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