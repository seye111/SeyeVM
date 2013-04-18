#ifndef JVM_CLASSFILEPARSER_H
#define JVM_CLASSFILEPARSER_H

#include "../../util/util.hpp"
#include "ClassFileRepresentation.hpp"
#include "ClassFileDataBuffer.hpp"

#include <string>
#include <boost/shared_ptr.hpp>

namespace Jvm{

	const long MAGIC = 0xCAFEBABE;

	////////////////////////////////////////////////////////////////////////////////
	//
	// ClassFile::parse_from_buffer produces a ClassFile::ClassFileRepresentation
	// from a ClassFile::ClassFileDataBuffer
	//
	////////////////////////////////////////////////////////////////////////////////

	class ClassFileParser{
		static void check_magic(long magic) throw (JvmException);
		static void load_constant_pool(ClassFileDataBuffer & buffer, std::vector<sp_ConstantPoolEntry> & constant_pool);
		static void parse_attributes(ClassFileDataBuffer & buffer, ClassFileRepresentation & cfrep, std::vector<sp_Attribute> & attributes);
		static void parse_members(ClassFileDataBuffer & buffer, ClassFileRepresentation & cfrep, std::vector<ClassFileMember> & members);
	public:
		static boost::shared_ptr<ClassFileRepresentation> parse_from_buffer (ClassFileDataBuffer & buffer);
	};

}

#endif