#ifndef JVM_CLASSFILEREPRESENTATION_H
#define JVM_CLASSFILEREPRESENTATION_H

#include "ConstantPool.hpp"
#include "ClassFileMember.hpp"

#include <vector>
#include <boost/shared_ptr.hpp>

namespace Jvm{

	////////////////////////////////////////////////////////////////////////////////
	//
	// struct ClassFileRepresentation
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
		std::vector<sp_ConstantPoolEntry> constant_pool;
		int access_flags;
		int this_class;
		int super_class;
		std::vector<int> interfaces;
		std::vector<ClassFileMember> fields;
		std::vector<ClassFileMember> methods;
		std::vector<sp_Attribute> attributes;
	};

	typedef boost::shared_ptr<ClassFileRepresentation> sp_ClassFileRepresentation;

}

#endif