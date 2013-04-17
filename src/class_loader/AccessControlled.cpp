#include "AccessControlled.hpp"

namespace Jvm{

	using std::string;

	string AccessControlled::get_access_string(){
		string str;
		if (is_public()) str.append("public, ");
		if (is_private()) str.append("private, ");
		if (is_protected()) str.append("protected, ");
		if (is_static()) str.append("static, ");
		if (is_final()) str.append("final, ");
		if (is_synchronized()) str.append("synchronized, ");
		if (is_volatile()) str.append("volatile, ");
		if (is_transient()) str.append("transient, ");
		if (is_native()) str.append("native, ");
		if (is_interface()) str.append("interface, ");
		if (is_abstract()) str.append("abstract, ");
		if (is_strict()) str.append("strict, ");
		return str.substr(0, str.find_last_of(','));
	}


}