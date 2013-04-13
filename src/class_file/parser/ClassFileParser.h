#ifndef CLASSFILEPARSER_H
#define CLASSFILEPARSER_H

#include "../../util.h"
#include "../ClassFileRepresentation.h"
#include "ClassFileDataBuffer.h"

#include <string>

using std::string;

namespace ClassFile{
	
	const long MAGIC = 0xCAFEBABE;

	ClassFileRepresentation *parse_from_file (string & filename) throw (JvmException);

	ClassFileRepresentation *parse_from_buffer (ClassFileDataBuffer & buffer) throw (JvmException);

}

#endif