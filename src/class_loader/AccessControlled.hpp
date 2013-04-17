#ifndef JVM_ACCESS_CONTROLLED
#define JVM_ACCESS_CONTROLLED

namespace Jvm{

	const int ACC_PUBLIC  = 0x0001;
	const int ACC_PRIVATE  = 0x0002;
	const int ACC_PROTECTED  = 0x0004;
	const int ACC_STATIC  = 0x0008;
	const int ACC_FINAL  = 0x0010;
	const int ACC_SYNCHRONIZED  = 0x0020;
	const int ACC_VOLATILE  = 0x0040;
	const int ACC_TRANSIENT  = 0x0080;
	const int ACC_NATIVE  = 0x0100;
	const int ACC_INTERFACE = 0x0200;
	const int ACC_ABSTRACT  = 0x0400;
	const int ACC_STRICT  = 0x0800;

	////////////////////////////////////////////////////////////////////////////////
	//
	// AccessControlled
	// 
	// both Internal::JvmField and Internal::JvmMethod have access_flags that make
	// use of (slightly different) subsets of the same set of access flag bits
	// this class provides methods for querying the values of these flags 
	//
	////////////////////////////////////////////////////////////////////////////////


	class AccessControlled{
	public:
		int access_flags;
		bool is_public() {return ((access_flags & ACC_PUBLIC) > 0);}
		bool is_private() {return ((access_flags & ACC_PRIVATE) > 0);}
		bool is_protected() {return ((access_flags & ACC_PROTECTED) > 0);}
		bool is_static() {return ((access_flags & ACC_STATIC) > 0);}
		bool is_final() {return ((access_flags & ACC_FINAL) > 0);}
		bool is_synchronized() {return ((access_flags & ACC_SYNCHRONIZED) > 0);}
		bool is_volatile() {return ((access_flags & ACC_VOLATILE) > 0);}
		bool is_transient() {return ((access_flags & ACC_TRANSIENT) > 0);}
		bool is_native() {return ((access_flags & ACC_NATIVE) > 0);}
		bool is_interface() {return ((access_flags & ACC_INTERFACE) > 0);}
		bool is_abstract() {return ((access_flags & ACC_ABSTRACT) > 0);}
		bool is_strict() {return ((access_flags & ACC_STRICT) > 0);}
	};

}

#endif