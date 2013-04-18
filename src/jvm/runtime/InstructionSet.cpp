#include "InstructionSet.hpp"

#include "../Exception.hpp"

namespace Jvm{

	void i_nop(ExecutionContext & context);
	void i_aconst_null(ExecutionContext & context);
	void i_iconst_m1(ExecutionContext & context);
	void i_iconst_0(ExecutionContext & context);
	void i_iconst_1(ExecutionContext & context);
	void i_iconst_2(ExecutionContext & context);
	void i_iconst_3(ExecutionContext & context);
	void i_iconst_4(ExecutionContext & context);
	void i_iconst_5(ExecutionContext & context);
	void i_lconst_0(ExecutionContext & context);
	void i_lconst_1(ExecutionContext & context);
	void i_fconst_0(ExecutionContext & context);
	void i_fconst_1(ExecutionContext & context);
	void i_fconst_2(ExecutionContext & context);
	void i_dconst_0(ExecutionContext & context);
	void i_dconst_1(ExecutionContext & context);
	void i_bipush(ExecutionContext & context);
	void i_sipush(ExecutionContext & context);
	void i_ldc(ExecutionContext & context);
	void i_ldc_w(ExecutionContext & context);
	void i_ldc2_w(ExecutionContext & context);
	void i_iload(ExecutionContext & context);
	void i_lload(ExecutionContext & context);
	void i_fload(ExecutionContext & context);
	void i_dload(ExecutionContext & context);
	void i_aload(ExecutionContext & context);
	void i_iload_0(ExecutionContext & context);
	void i_iload_1(ExecutionContext & context);
	void i_iload_2(ExecutionContext & context);
	void i_iload_3(ExecutionContext & context);
	void i_lload_0(ExecutionContext & context);
	void i_lload_1(ExecutionContext & context);
	void i_lload_2(ExecutionContext & context);
	void i_lload_3(ExecutionContext & context);
	void i_fload_0(ExecutionContext & context);
	void i_fload_1(ExecutionContext & context);
	void i_fload_2(ExecutionContext & context);
	void i_fload_3(ExecutionContext & context);
	void i_dload_0(ExecutionContext & context);
	void i_dload_1(ExecutionContext & context);
	void i_dload_2(ExecutionContext & context);
	void i_dload_3(ExecutionContext & context);
	void i_aload_0(ExecutionContext & context);
	void i_aload_1(ExecutionContext & context);
	void i_aload_2(ExecutionContext & context);
	void i_aload_3(ExecutionContext & context);
	void i_iaload(ExecutionContext & context);
	void i_laload(ExecutionContext & context);
	void i_faload(ExecutionContext & context);
	void i_daload(ExecutionContext & context);
	void i_aaload(ExecutionContext & context);
	void i_baload(ExecutionContext & context);
	void i_caload(ExecutionContext & context);
	void i_saload(ExecutionContext & context);
	void i_istore(ExecutionContext & context);
	void i_lstore(ExecutionContext & context);
	void i_fstore(ExecutionContext & context);
	void i_dstore(ExecutionContext & context);
	void i_astore(ExecutionContext & context);
	void i_istore_0(ExecutionContext & context);
	void i_istore_1(ExecutionContext & context);
	void i_istore_2(ExecutionContext & context);
	void i_istore_3(ExecutionContext & context);
	void i_lstore_0(ExecutionContext & context);
	void i_lstore_1(ExecutionContext & context);
	void i_lstore_2(ExecutionContext & context);
	void i_lstore_3(ExecutionContext & context);
	void i_fstore_0(ExecutionContext & context);
	void i_fstore_1(ExecutionContext & context);
	void i_fstore_2(ExecutionContext & context);
	void i_fstore_3(ExecutionContext & context);
	void i_dstore_0(ExecutionContext & context);
	void i_dstore_1(ExecutionContext & context);
	void i_dstore_2(ExecutionContext & context);
	void i_dstore_3(ExecutionContext & context);
	void i_astore_0(ExecutionContext & context);
	void i_astore_1(ExecutionContext & context);
	void i_astore_2(ExecutionContext & context);
	void i_astore_3(ExecutionContext & context);
	void i_iastore(ExecutionContext & context);
	void i_lastore(ExecutionContext & context);
	void i_fastore(ExecutionContext & context);
	void i_dastore(ExecutionContext & context);
	void i_aastore(ExecutionContext & context);
	void i_bastore(ExecutionContext & context);
	void i_castore(ExecutionContext & context);
	void i_sastore(ExecutionContext & context);
	void i_pop(ExecutionContext & context);
	void i_pop2(ExecutionContext & context);
	void i_dup(ExecutionContext & context);
	void i_dup_x1(ExecutionContext & context);
	void i_dup_x2(ExecutionContext & context);
	void i_dup2(ExecutionContext & context);
	void i_dup2_x1(ExecutionContext & context);
	void i_dup2_x2(ExecutionContext & context);
	void i_swap(ExecutionContext & context);
	void i_iadd(ExecutionContext & context);
	void i_ladd(ExecutionContext & context);
	void i_fadd(ExecutionContext & context);
	void i_dadd(ExecutionContext & context);
	void i_isub(ExecutionContext & context);
	void i_lsub(ExecutionContext & context);
	void i_fsub(ExecutionContext & context);
	void i_dsub(ExecutionContext & context);
	void i_imul(ExecutionContext & context);
	void i_lmul(ExecutionContext & context);
	void i_fmul(ExecutionContext & context);
	void i_dmul(ExecutionContext & context);
	void i_idiv(ExecutionContext & context);
	void i_ldiv(ExecutionContext & context);
	void i_fdiv(ExecutionContext & context);
	void i_ddiv(ExecutionContext & context);
	void i_irem(ExecutionContext & context);
	void i_lrem(ExecutionContext & context);
	void i_frem(ExecutionContext & context);
	void i_drem(ExecutionContext & context);
	void i_ineg(ExecutionContext & context);
	void i_lneg(ExecutionContext & context);
	void i_fneg(ExecutionContext & context);
	void i_dneg(ExecutionContext & context);
	void i_ishl(ExecutionContext & context);
	void i_lshl(ExecutionContext & context);
	void i_ishr(ExecutionContext & context);
	void i_lshr(ExecutionContext & context);
	void i_iushr(ExecutionContext & context);
	void i_lushr(ExecutionContext & context);
	void i_iand(ExecutionContext & context);
	void i_land(ExecutionContext & context);
	void i_ior(ExecutionContext & context);
	void i_lor(ExecutionContext & context);
	void i_ixor(ExecutionContext & context);
	void i_lxor(ExecutionContext & context);
	void i_iinc(ExecutionContext & context);
	void i_i2l(ExecutionContext & context);
	void i_i2f(ExecutionContext & context);
	void i_i2d(ExecutionContext & context);
	void i_l2i(ExecutionContext & context);
	void i_l2f(ExecutionContext & context);
	void i_l2d(ExecutionContext & context);
	void i_f2i(ExecutionContext & context);
	void i_f2l(ExecutionContext & context);
	void i_f2d(ExecutionContext & context);
	void i_d2i(ExecutionContext & context);
	void i_d2l(ExecutionContext & context);
	void i_d2f(ExecutionContext & context);
	void i_i2b(ExecutionContext & context);
	void i_i2c(ExecutionContext & context);
	void i_i2s(ExecutionContext & context);
	void i_lcmp(ExecutionContext & context);
	void i_fcpl(ExecutionContext & context);
	void i_fcmg(ExecutionContext & context);
	void i_dcmpl(ExecutionContext & context);
	void i_dcmpg(ExecutionContext & context);
	void i_ifeq(ExecutionContext & context);
	void i_ifne(ExecutionContext & context);
	void i_iflt(ExecutionContext & context);
	void i_ifge(ExecutionContext & context);
	void i_ifgt(ExecutionContext & context);
	void i_ifle(ExecutionContext & context);
	void i_if_icmeq(ExecutionContext & context);
	void i_if_icmpne(ExecutionContext & context);
	void i_if_icmplt(ExecutionContext & context);
	void i_if_icmpge(ExecutionContext & context);
	void i_if_icmpgt(ExecutionContext & context);
	void i_if_icmple(ExecutionContext & context);
	void i_if_acmpeq(ExecutionContext & context);
	void i_if_acmpne(ExecutionContext & context);
	void i_goto(ExecutionContext & context);
	void i_jsr(ExecutionContext & context);
	void i_ret(ExecutionContext & context);
	void i_tableswitch(ExecutionContext & context);
	void i_lookupswitch(ExecutionContext & context);
	void i_ireturn(ExecutionContext & context);
	void i_lreturn(ExecutionContext & context);
	void i_freturn(ExecutionContext & context);
	void i_dreturn(ExecutionContext & context);
	void i_areturn(ExecutionContext & context);
	void i_return(ExecutionContext & context);
	void i_getstatic(ExecutionContext & context);
	void i_putstatic(ExecutionContext & context);
	void i_getfield(ExecutionContext & context);
	void i_putfield(ExecutionContext & context);
	void i_invokevirtual(ExecutionContext & context);
	void i_invokespecial(ExecutionContext & context);
	void i_invokestatic(ExecutionContext & context);
	void i_invokeinterface(ExecutionContext & context);
	void i_invokedynamic(ExecutionContext & context);
	void i_new(ExecutionContext & context);
	void i_newarray(ExecutionContext & context);
	void i_anewarray(ExecutionContext & context);
	void i_arraylength(ExecutionContext & context);
	void i_athrow(ExecutionContext & context);
	void i_checkcast(ExecutionContext & context);
	void i_instanceof(ExecutionContext & context);
	void i_monitorenter(ExecutionContext & context);
	void i_monitorexit(ExecutionContext & context);
	void i_wide(ExecutionContext & context);
	void i_multianewarray(ExecutionContext & context);
	void i_ifnull(ExecutionContext & context);
	void i_ifnonnull(ExecutionContext & context);
	void i_goto_w(ExecutionContext & context);
	void i_jsr_w(ExecutionContext & context);

	static Instruction instruction_list[] = {
		{"nop", 0, i_nop},
		{"aconst_null", 0, i_aconst_null},
		{"iconst_m1", 0, i_iconst_m1},
		{"iconst_0", 0, i_iconst_0},
		{"iconst_1", 0, i_iconst_1},
		{"iconst_2", 0, i_iconst_2},
		{"iconst_3", 0, i_iconst_3},
		{"iconst_4", 0, i_iconst_4},
		{"iconst_5", 0, i_iconst_5},
		{"lconst_0", 0, i_lconst_0},
		{"lconst_1", 0, i_lconst_1},
		{"fconst_0", 0, i_fconst_0},
		{"fconst_1", 0, i_fconst_1},
		{"fconst_2", 0, i_fconst_2},
		{"dconst_0", 0, i_dconst_0},
		{"dconst_1", 0, i_dconst_1},
		{"bipush", 1, i_bipush},
		{"sipush", 2, i_sipush},
		{"ldc", 1, i_ldc},
		{"ldc_w", 2, i_ldc_w},
		{"ldc2_w", 2, i_ldc2_w},
		{"iload", 1, i_iload},
		{"lload", 1, i_lload},
		{"fload", 1, i_fload},
		{"dload", 1, i_dload},
		{"aload", 1, i_aload},
		{"iload_0", 0, i_iload_0},
		{"iload_1", 0, i_iload_1},
		{"iload_2", 0, i_iload_2},
		{"iload_3", 0, i_iload_3},
		{"lload_0", 0, i_lload_0},
		{"lload_1", 0, i_lload_1},
		{"lload_2", 0, i_lload_2},
		{"lload_3", 0, i_lload_3},
		{"fload_0", 0, i_fload_0},
		{"fload_1", 0, i_fload_1},
		{"fload_2", 0, i_fload_2},
		{"fload_3", 0, i_fload_3},
		{"dload_0", 0, i_dload_0},
		{"dload_1", 0, i_dload_1},
		{"dload_2", 0, i_dload_2},
		{"dload_3", 0, i_dload_3},
		{"aload_0", 0, i_aload_0},
		{"aload_1", 0, i_aload_1},
		{"aload_2", 0, i_aload_2},
		{"aload_3", 0, i_aload_3},
		{"iaload", 0, i_iaload},
		{"laload", 0, i_laload},
		{"faload", 0, i_faload},
		{"daload", 0, i_daload},
		{"aaload", 0, i_aaload},
		{"baload", 0, i_baload},
		{"caload", 0, i_caload},
		{"saload", 0, i_saload},
		{"istore", 1, i_istore},
		{"lstore", 1, i_lstore},
		{"fstore", 1, i_fstore},
		{"dstore", 1, i_dstore},
		{"astore", 1, i_astore},
		{"istore_0", 0, i_istore_0},
		{"istore_1", 0, i_istore_1},
		{"istore_2", 0, i_istore_2},
		{"istore_3", 0, i_istore_3},
		{"lstore_0", 0, i_lstore_0},
		{"lstore_1", 0, i_lstore_1},
		{"lstore_2", 0, i_lstore_2},
		{"lstore_3", 0, i_lstore_3},
		{"fstore_0", 0, i_fstore_0},
		{"fstore_1", 0, i_fstore_1},
		{"fstore_2", 0, i_fstore_2},
		{"fstore_3", 0, i_fstore_3},
		{"dstore_0", 0, i_dstore_0},
		{"dstore_1", 0, i_dstore_1},
		{"dstore_2", 0, i_dstore_2},
		{"dstore_3", 0, i_dstore_3},
		{"astore_0", 0, i_astore_0},
		{"astore_1", 0, i_astore_1},
		{"astore_2", 0, i_astore_2},
		{"astore_3", 0, i_astore_3},
		{"iastore", 0, i_iastore},
		{"lastore", 0, i_lastore},
		{"fastore", 0, i_fastore},
		{"dastore", 0, i_dastore},
		{"aastore", 0, i_aastore},
		{"bastore", 0, i_bastore},
		{"castore", 0, i_castore},
		{"sastore", 0, i_sastore},
		{"pop", 0, i_pop},
		{"pop2", 0, i_pop2},
		{"dup", 0, i_dup},
		{"dup_x1", 0, i_dup_x1},
		{"dup_x2", 0, i_dup_x2},
		{"dup2", 0, i_dup2},
		{"dup2_x1", 0, i_dup2_x1},
		{"dup2_x2", 0, i_dup2_x2},
		{"swap", 0, i_swap},
		{"iadd", 0, i_iadd},
		{"ladd", 0, i_ladd},
		{"fadd", 0, i_fadd},
		{"dadd", 0, i_dadd},
		{"isub", 0, i_isub},
		{"lsub", 0, i_lsub},
		{"fsub", 0, i_fsub},
		{"dsub", 0, i_dsub},
		{"imul", 0, i_imul},
		{"lmul", 0, i_lmul},
		{"fmul", 0, i_fmul},
		{"dmul", 0, i_dmul},
		{"idiv", 0, i_idiv},
		{"ldiv", 0, i_ldiv},
		{"fdiv", 0, i_fdiv},
		{"ddiv", 0, i_ddiv},
		{"irem", 0, i_irem},
		{"lrem", 0, i_lrem},
		{"frem", 0, i_frem},
		{"drem", 0, i_drem},
		{"ineg", 0, i_ineg},
		{"lneg", 0, i_lneg},
		{"fneg", 0, i_fneg},
		{"dneg", 0, i_dneg},
		{"ishl", 0, i_ishl},
		{"lshl", 0, i_lshl},
		{"ishr", 0, i_ishr},
		{"lshr", 0, i_lshr},
		{"iushr", 0, i_iushr},
		{"lushr", 0, i_lushr},
		{"iand", 0, i_iand},
		{"land", 0, i_land},
		{"ior", 0, i_ior},
		{"lor", 0, i_lor},
		{"ixor", 0, i_ixor},
		{"lxor", 0, i_lxor},
		{"iinc", 2, i_iinc},
		{"i2l", 0, i_i2l},
		{"i2f", 0, i_i2f},
		{"i2d", 0, i_i2d},
		{"l2i", 0, i_l2i},
		{"l2f", 0, i_l2f},
		{"l2d", 0, i_l2d},
		{"f2i", 0, i_f2i},
		{"f2l", 0, i_f2l},
		{"f2d", 0, i_f2d},
		{"d2i", 0, i_d2i},
		{"d2l", 0, i_d2l},
		{"d2f", 0, i_d2f},
		{"i2b", 0, i_i2b},
		{"i2c", 0, i_i2c},
		{"i2s", 0, i_i2s},
		{"lcmp", 0, i_lcmp},
		{"fcpl", 0, i_fcpl},
		{"fcmg", 0, i_fcmg},
		{"dcmpl", 0, i_dcmpl},
		{"dcmpg", 0, i_dcmpg},
		{"ifeq", 2, i_ifeq},
		{"ifne", 2, i_ifne},
		{"iflt", 2, i_iflt},
		{"ifge", 2, i_ifge},
		{"ifgt", 2, i_ifgt},
		{"ifle", 2, i_ifle},
		{"if_icmeq", 2, i_if_icmeq},
		{"if_icmpne", 2, i_if_icmpne},
		{"if_icmplt", 2, i_if_icmplt},
		{"if_icmpge", 2, i_if_icmpge},
		{"if_icmpgt", 2, i_if_icmpgt},
		{"if_icmple", 2, i_if_icmple},
		{"if_acmpeq", 2, i_if_acmpeq},
		{"if_acmpne", 2, i_if_acmpne},
		{"goto", 2, i_goto},
		{"jsr", 0, i_jsr},
		{"ret", 1, i_ret},
		{"tableswitch", 100, i_tableswitch},
		{"lookupswitch", 100, i_lookupswitch},
		{"ireturn", 0, i_ireturn},
		{"lreturn", 0, i_lreturn},
		{"freturn", 0, i_freturn},
		{"dreturn", 0, i_dreturn},
		{"areturn", 0, i_areturn},
		{"return", 0, i_return},
		{"getstatic", 2, i_getstatic},
		{"putstatic", 2, i_putstatic},
		{"getfield", 2, i_getfield},
		{"putfield", 2, i_putfield},
		{"invokevirtual", 2, i_invokevirtual},
		{"invokespecial", 2, i_invokespecial},
		{"invokestatic", 2, i_invokestatic},
		{"invokeinterface", 4, i_invokeinterface},
		{"invokedynamic", 4, i_invokedynamic},
		{"new", 2, i_new},
		{"newarray", 1, i_newarray},
		{"anewarray", 2, i_anewarray},
		{"arraylength", 0, i_arraylength},
		{"athrow", 0, i_athrow},
		{"checkcast", 2, i_checkcast},
		{"instanceof", 2, i_instanceof},
		{"monitorenter", 0, i_monitorenter},
		{"monitorexit", 0, i_monitorexit},
		{"wide", 100, i_wide},
		{"multianewarray", 2, i_multianewarray},
		{"ifnull", 2, i_ifnull},
		{"ifnonnull", 2, i_ifnonnull},
		{"goto_w", 4, i_goto_w},
		{"jsr_w", 0, i_jsr_w},
	};

	InstructionSet::InstructionSet(){
		if(logger.is_debug()) logger.log_debug() << "creating instruction set" << std::endl;
 		instructions = instruction_list;
 		if(logger.is_debug()) logger.log_debug() << "instruction set created" << std::endl;
	}

}