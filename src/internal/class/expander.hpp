#ifndef INTERNAL_EXPANDER_H
#define INTERNAL_EXPANDER_H

#include "../../class_file/ClassFileRepresentation.hpp"
#include "JvmClass.hpp"

using ClassFile::ClassFileRepresentation;

namespace Internal{

	sp_JvmClass expand_class_representation(ClassFileRepresentation & cfrep);

}

#endif