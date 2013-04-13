#ifndef CLASSFILE_CLASSFILEPARSER_H
#define CLASSFILE_CLASSFILEPARSER_H

#include "../../util.hpp"
#include "../ClassFileRepresentation.hpp"
#include "ClassFileDataBuffer.hpp"

#include <string>

using std::string;

namespace ClassFile{
	
	const long MAGIC = 0xCAFEBABE;

	ClassFileRepresentation *parse_from_file (string & filename) throw (JvmException);

	ClassFileRepresentation *parse_from_buffer (ClassFileDataBuffer & buffer) throw (JvmException);

}

#endif