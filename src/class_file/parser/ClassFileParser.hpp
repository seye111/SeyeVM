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

	////////////////////////////////////////////////////////////////////////////////
	//
	// ClassFile::parse_from_buffer produces a ClassFile::ClassFileRepresentation
	// from a ClassFile::ClassFileDataBuffer
	//
	////////////////////////////////////////////////////////////////////////////////

	shared_ptr<ClassFileRepresentation> parse_from_buffer (ClassFileDataBuffer & buffer) throw (JvmException);

}

#endif