#ifndef JVM_CLASSFILEPARSER_H
#define JVM_CLASSFILEPARSER_H

#include "../../Exception.hpp"
#include "ClassFileRepresentation.hpp"
#include "ClassFileDataBuffer.hpp"

#include <string>
#include "../../util/shared_ptr.hpp"

namespace Jvm{

	const long MAGIC = 0xCAFEBABE;

	////////////////////////////////////////////////////////////////////////////////
	//
	// ClassFile::parse_from_buffer produces a ClassFile::ClassFileRepresentation
	// from a ClassFile::ClassFileDataBuffer
	//
	////////////////////////////////////////////////////////////////////////////////

	class ClassFileParser{
		ClassFileDataBuffer & buffer;
		ClassFileRepresentation* p_class_file_representation;

		void check_magic(long magic);
		void load_constant_pool();
		void parse_attributes(std::vector<Attribute*> & attributes);
		void parse_members(std::vector<ClassFileMember*> & members);
	public:
		ClassFileParser(ClassFileDataBuffer & buffer);
		~ClassFileParser();
		ClassFileRepresentation* parse_from_buffer ();
	};

}

#endif