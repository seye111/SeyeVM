#ifndef CLASSFILE_CLASSFILEPARSER_H
#define CLASSFILE_CLASSFILEPARSER_H

#include "../../util/util.hpp"
#include "../ClassFileRepresentation.hpp"
#include "ClassFileDataBuffer.hpp"

#include <string>
#include <boost/shared_ptr.hpp>

using std::string;
using boost::shared_ptr;

namespace ClassFile{
	
	const long MAGIC = 0xCAFEBABE;

	shared_ptr<ClassFileRepresentation> parse_from_file (string & filename) throw (JvmException);

	shared_ptr<ClassFileRepresentation> parse_from_buffer (ClassFileDataBuffer & buffer) throw (JvmException);

}

#endif