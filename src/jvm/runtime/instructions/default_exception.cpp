#include "../InstructionSet.hpp"

#include "../../Exception.hpp"

namespace Jvm{

	void i_reserved(ExecutionContext & context){
		throw JvmException("reserved opcode");
	}
	void i_invalid_pc(ExecutionContext & context){
		throw JvmException("no instruction at pc");
	}


	void i_nop(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - nop");
	}

	void i_aconst_null(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aconst_null");
	}

	void i_iconst_m1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iconst_m1");
	}

	void i_iconst_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iconst_0");
	}

	void i_iconst_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iconst_1");
	}

	void i_iconst_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iconst_2");
	}

	void i_iconst_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iconst_3");
	}

	void i_iconst_4(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iconst_4");
	}

	void i_iconst_5(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iconst_5");
	}

	void i_lconst_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lconst_0");
	}

	void i_lconst_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lconst_1");
	}

	void i_fconst_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fconst_0");
	}

	void i_fconst_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fconst_1");
	}

	void i_fconst_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fconst_2");
	}

	void i_dconst_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dconst_0");
	}

	void i_dconst_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dconst_1");
	}

	void i_bipush(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - bipush");
	}

	void i_sipush(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - sipush");
	}

	void i_ldc(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ldc");
	}

	void i_ldc_w(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ldc_w");
	}

	void i_ldc2_w(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ldc2_w");
	}

	void i_iload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iload");
	}

	void i_lload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lload");
	}

	void i_fload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fload");
	}

	void i_dload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dload");
	}

	void i_aload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aload");
	}

	void i_iload_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iload_0");
	}

	void i_iload_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iload_1");
	}

	void i_iload_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iload_2");
	}

	void i_iload_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iload_3");
	}

	void i_lload_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lload_0");
	}

	void i_lload_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lload_1");
	}

	void i_lload_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lload_2");
	}

	void i_lload_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lload_3");
	}

	void i_fload_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fload_0");
	}

	void i_fload_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fload_1");
	}

	void i_fload_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fload_2");
	}

	void i_fload_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fload_3");
	}

	void i_dload_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dload_0");
	}

	void i_dload_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dload_1");
	}

	void i_dload_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dload_2");
	}

	void i_dload_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dload_3");
	}

	void i_aload_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aload_0");
	}

	void i_aload_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aload_1");
	}

	void i_aload_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aload_2");
	}

	void i_aload_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aload_3");
	}

	void i_iaload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iaload");
	}

	void i_laload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - laload");
	}

	void i_faload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - faload");
	}

	void i_daload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - daload");
	}

	void i_aaload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aaload");
	}

	void i_baload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - baload");
	}

	void i_caload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - caload");
	}

	void i_saload(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - saload");
	}

	void i_istore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - istore");
	}

	void i_lstore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lstore");
	}

	void i_fstore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fstore");
	}

	void i_dstore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dstore");
	}

	void i_astore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - astore");
	}

	void i_istore_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - istore_0");
	}

	void i_istore_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - istore_1");
	}

	void i_istore_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - istore_2");
	}

	void i_istore_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - istore_3");
	}

	void i_lstore_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lstore_0");
	}

	void i_lstore_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lstore_1");
	}

	void i_lstore_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lstore_2");
	}

	void i_lstore_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lstore_3");
	}

	void i_fstore_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fstore_0");
	}

	void i_fstore_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fstore_1");
	}

	void i_fstore_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fstore_2");
	}

	void i_fstore_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fstore_3");
	}

	void i_dstore_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dstore_0");
	}

	void i_dstore_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dstore_1");
	}

	void i_dstore_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dstore_2");
	}

	void i_dstore_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dstore_3");
	}

	void i_astore_0(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - astore_0");
	}

	void i_astore_1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - astore_1");
	}

	void i_astore_2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - astore_2");
	}

	void i_astore_3(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - astore_3");
	}

	void i_iastore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iastore");
	}

	void i_lastore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lastore");
	}

	void i_fastore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fastore");
	}

	void i_dastore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dastore");
	}

	void i_aastore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - aastore");
	}

	void i_bastore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - bastore");
	}

	void i_castore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - castore");
	}

	void i_sastore(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - sastore");
	}

	void i_pop(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - pop");
	}

	void i_pop2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - pop2");
	}

	void i_dup(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dup");
	}

	void i_dup_x1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dup_x1");
	}

	void i_dup_x2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dup_x2");
	}

	void i_dup2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dup2");
	}

	void i_dup2_x1(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dup2_x1");
	}

	void i_dup2_x2(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dup2_x2");
	}

	void i_swap(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - swap");
	}

	void i_iadd(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iadd");
	}

	void i_ladd(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ladd");
	}

	void i_fadd(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fadd");
	}

	void i_dadd(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dadd");
	}

	void i_isub(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - isub");
	}

	void i_lsub(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lsub");
	}

	void i_fsub(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fsub");
	}

	void i_dsub(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dsub");
	}

	void i_imul(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - imul");
	}

	void i_lmul(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lmul");
	}

	void i_fmul(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fmul");
	}

	void i_dmul(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dmul");
	}

	void i_idiv(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - idiv");
	}

	void i_ldiv(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ldiv");
	}

	void i_fdiv(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fdiv");
	}

	void i_ddiv(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ddiv");
	}

	void i_irem(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - irem");
	}

	void i_lrem(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lrem");
	}

	void i_frem(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - frem");
	}

	void i_drem(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - drem");
	}

	void i_ineg(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ineg");
	}

	void i_lneg(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lneg");
	}

	void i_fneg(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fneg");
	}

	void i_dneg(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dneg");
	}

	void i_ishl(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ishl");
	}

	void i_lshl(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lshl");
	}

	void i_ishr(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ishr");
	}

	void i_lshr(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lshr");
	}

	void i_iushr(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iushr");
	}

	void i_lushr(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lushr");
	}

	void i_iand(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iand");
	}

	void i_land(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - land");
	}

	void i_ior(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ior");
	}

	void i_lor(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lor");
	}

	void i_ixor(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ixor");
	}

	void i_lxor(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lxor");
	}

	void i_iinc(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iinc");
	}

	void i_i2l(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - i2l");
	}

	void i_i2f(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - i2f");
	}

	void i_i2d(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - i2d");
	}

	void i_l2i(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - l2i");
	}

	void i_l2f(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - l2f");
	}

	void i_l2d(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - l2d");
	}

	void i_f2i(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - f2i");
	}

	void i_f2l(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - f2l");
	}

	void i_f2d(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - f2d");
	}

	void i_d2i(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - d2i");
	}

	void i_d2l(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - d2l");
	}

	void i_d2f(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - d2f");
	}

	void i_i2b(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - i2b");
	}

	void i_i2c(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - i2c");
	}

	void i_i2s(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - i2s");
	}

	void i_lcmp(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lcmp");
	}

	void i_fcpl(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fcpl");
	}

	void i_fcmg(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - fcmg");
	}

	void i_dcmpl(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dcmpl");
	}

	void i_dcmpg(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dcmpg");
	}

	void i_ifeq(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ifeq");
	}

	void i_ifne(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ifne");
	}

	void i_iflt(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - iflt");
	}

	void i_ifge(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ifge");
	}

	void i_ifgt(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ifgt");
	}

	void i_ifle(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ifle");
	}

	void i_if_icmeq(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_icmeq");
	}

	void i_if_icmpne(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_icmpne");
	}

	void i_if_icmplt(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_icmplt");
	}

	void i_if_icmpge(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_icmpge");
	}

	void i_if_icmpgt(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_icmpgt");
	}

	void i_if_icmple(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_icmple");
	}

	void i_if_acmpeq(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_acmpeq");
	}

	void i_if_acmpne(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - if_acmpne");
	}

	void i_goto(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - goto");
	}

	void i_jsr(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - jsr");
	}

	void i_ret(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ret");
	}

	void i_tableswitch(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - tableswitch");
	}

	void i_lookupswitch(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lookupswitch");
	}

	void i_ireturn(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ireturn");
	}

	void i_lreturn(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - lreturn");
	}

	void i_freturn(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - freturn");
	}

	void i_dreturn(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - dreturn");
	}

	void i_areturn(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - areturn");
	}

	void i_return(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - return");
	}

	void i_getstatic(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - getstatic");
	}

	void i_putstatic(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - putstatic");
	}

	void i_getfield(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - getfield");
	}

	void i_putfield(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - putfield");
	}

	void i_invokevirtual(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - invokevirtual");
	}

	void i_invokespecial(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - invokespecial");
	}

	void i_invokestatic(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - invokestatic");
	}

	void i_invokeinterface(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - invokeinterface");
	}

	void i_invokedynamic(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - invokedynamic");
	}

	void i_new(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - new");
	}

	void i_newarray(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - newarray");
	}

	void i_anewarray(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - anewarray");
	}

	void i_arraylength(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - arraylength");
	}

	void i_athrow(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - athrow");
	}

	void i_checkcast(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - checkcast");
	}

	void i_instanceof(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - instanceof");
	}

	void i_monitorenter(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - monitorenter");
	}

	void i_monitorexit(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - monitorexit");
	}

	void i_wide(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - wide");
	}

	void i_multianewarray(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - multianewarray");
	}

	void i_ifnull(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ifnull");
	}

	void i_ifnonnull(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - ifnonnull");
	}

	void i_goto_w(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - goto_w");
	}

	void i_jsr_w(ExecutionContext & context){
		throw JvmIntsructionNotImplementedException("instruction not implemented - jsr_w");
	}

}
