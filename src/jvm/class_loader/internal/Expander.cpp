#include "Expander.hpp"

#include "../../runtime/InstructionSet.hpp"

#include <sstream>

using std::vector;
using std::map;

using std::ostringstream;
using std::endl;

namespace Jvm{

	typedef std::pair<string, sp_JvmField> f_map_entry;
	typedef std::pair<string, sp_JvmMethod> m_map_entry;

	void Expander::expand_class_representation(const string & name){
		if(logger.is_info()) logger.log_info() 
			<< indent << name << " : expanding..." << endl;
		
		jvm_class.name = get_class_name();
		if(jvm_class.name != name){
			ostringstream os;
			os << "name mismatch - expected to expand " << name
				<< " but class file representation contains "
				<< jvm_class.name << endl;
			throw JvmException (os.str());
		}

		jvm_class.access_flags = cfr.access_flags;
		if(logger.is_info()) logger.log_info() 
			<< indent << jvm_class.name << " : access specifiers [" 
				<< jvm_class.get_access_string() << "]" << endl; 

		if(jvm_class.name == "java/lang/Object"){
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : has no super class"  << endl;
		}else{
			string super_class_name = get_super_class_name();
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : super class name : " << super_class_name << endl;
			jvm_class.super_class = class_loader.get_class(super_class_name, depth + 1);
		}
		expand_interfaces();
		expand_members();
		if(logger.is_info()) logger.log_info() 
			<< indent << name << " : ...expanded" << endl;
	}

	void Expander::expand_interfaces(){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " 
			<< "expanding interfaces..." << endl;
		for(int index = 0; index < cfr.interfaces.size(); index++){
			int name_index = ((ConstantClass*)check_and_get(cfr.interfaces[index], 
				CONSTANT_CLASS))->name_index;
			string interface_name = get_string(name_index);
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : " 
				<< interface_name << endl;
			jvm_class.interfaces.push_back(class_loader.get_class(interface_name, depth + 1));	
		}
	}

	void Expander::expand_members(){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " << "expanding members..." << endl;
		expand_fields();
		expand_methods();
	}

	void Expander::expand_fields(){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " << "===== fields..." << endl;
		
		int static_data_4_offset = 0;
		int static_data_8_offset = 0;
		int instance_data_4_offset = 0;
		int instance_data_8_offset = 0;
		for(int index=0; index < cfr.fields.size(); index++){
			ClassFileMember & cf_field = cfr.fields[index];
			sp_JvmField sp_jvm_field(new JvmField(sp_jvm_class));
			JvmField & jvm_field = *sp_jvm_field;
			
			jvm_field.name = get_string(cf_field.name_index);
			jvm_field.descriptor = get_string(cf_field.descriptor_index);
			jvm_field.access_flags = cf_field.access_flags;
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : [" << jvm_field.get_access_string() << "] " 
				<< jvm_field.name << " : " 
				<< jvm_field.descriptor << endl;
			if(jvm_field.is_static()){
				sp_jvm_class->static_fields.insert(
					f_map_entry(jvm_field.descriptor + "0" + jvm_field.name, sp_jvm_field));
			}else{
				sp_jvm_class->instance_fields.insert(
					f_map_entry(jvm_field.descriptor + "0" + jvm_field.name, sp_jvm_field));
			}

			int width = get_width(jvm_field.descriptor);
			if(jvm_field.is_static()){
				if(width == 4){
					jvm_field.offset = static_data_4_offset;
					++static_data_4_offset;
				}else{
					jvm_field.offset = static_data_8_offset;
					++static_data_8_offset;
				}
			}else{
				if(width == 4){
					jvm_field.offset = instance_data_4_offset;
					++instance_data_4_offset;
				}else{
					jvm_field.offset = instance_data_8_offset;
					++instance_data_8_offset;
				}
			}

		}

		jvm_class.static_data_4 = new int[static_data_4_offset];
		jvm_class.static_data_8 = new long[static_data_8_offset];
		jvm_class.instance_data_4_count = instance_data_4_offset;
		jvm_class.instance_data_8_count = instance_data_8_offset;

		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : [" 
			<< "static_data_4_count: " << static_data_4_offset << ", " 
			<< "static_data_8_count: " << static_data_8_offset << ", " 
			<< "instance_data_4_count: " << instance_data_4_offset << ", " 
			<< "instance_data_8_count: " << instance_data_8_offset 
			<< "] " << endl;
	}

	int Expander::get_width(string & descriptor){
		int result = 0;
		switch(descriptor[0]){
			case 'F': case 'I': case 'S': case 'B': case 'C': case 'Z':
				result = 4;
				break;
			case '[': case 'L': case 'J': case 'D':
				result = 8;
				break;
			default:
				throw JvmException("couldn't find the width of descriptor " + descriptor);
		}
		if(logger.is_trace()) logger.log_trace() 
			<< indent << jvm_class.name << " : width of " 
			<< descriptor << " is " << result << endl;
		return result;
	}

	void Expander::expand_methods (){
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : " << "===== methods..." << endl;
		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : "
			"loading v_table from superclass (if any)" << endl;
		if(jvm_class.super_class.get()){
			vector<sp_JvmMethod> super_v_table = jvm_class.super_class->v_table;
			for(int i=0; i < super_v_table.size(); i++){
				sp_JvmMethod pjm = super_v_table[i];
				jvm_class.v_table.push_back(pjm);
				if(logger.is_debug()) logger.log_debug() 
					<< indent << jvm_class.name << " : "
					<< "---> " << pjm->name << " : " << pjm->descriptor << endl;
			}
		}else{
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : "
				"no superclass" << endl;

		}

		if(logger.is_debug()) logger.log_debug() 
			<< indent << jvm_class.name << " : "
			"parsing methods defined in this class " << endl;



		for(int index=0; index < cfr.methods.size(); index++){
			ClassFileMember & cf_method = cfr.methods[index];
			sp_JvmMethod sp_jvm_method(new JvmMethod(sp_jvm_class));
			JvmMethod & jvm_method = *sp_jvm_method;
			
			jvm_method.name = get_string(cf_method.name_index);
			jvm_method.descriptor = get_string(cf_method.descriptor_index);
			
			jvm_method.access_flags = cf_method.access_flags;
			
			if(logger.is_debug()) logger.log_debug() 
				<< indent << jvm_class.name << " : [" << jvm_method.get_access_string() << "] " 
				<< jvm_method.name << " : " 
				<< jvm_method.descriptor << endl;




			if(jvm_method.is_static()){
				sp_jvm_class->static_methods.insert(
					m_map_entry(jvm_method.descriptor + "0" + jvm_method.name, sp_jvm_method));
			}else{
				string key = jvm_method.descriptor + "0" + jvm_method.name; 
				sp_jvm_class->instance_methods.insert(
					m_map_entry(key, sp_jvm_method));
				if(jvm_class.super_class.get()){
					// check to see if this method is in the superclasses v_table
					map<string, sp_JvmMethod> scim = jvm_class.super_class->instance_methods;
					map<string, sp_JvmMethod>::iterator it = scim.find(key);
					if(it != scim.end()){
						if(logger.is_debug()) logger.log_debug() 
							<< indent << jvm_class.name << " : "
							<< "overrides superclass method " << endl;
						int v_table_index = it->second->v_table_index;
						jvm_class.v_table[v_table_index] = sp_jvm_method;
						jvm_method.v_table_index = v_table_index;
					}else{
						if(logger.is_debug()) logger.log_debug() 
							<< indent << jvm_class.name << " : "
							<< "doesn't override superclass method " << endl;
						jvm_method.v_table_index = jvm_class.v_table.size();
						jvm_class.v_table.push_back(sp_jvm_method);
					}
				}else{
					if(logger.is_debug()) logger.log_debug() 
						<< indent << jvm_class.name << " : "
						<< "doesn't override superclass method " << endl;
					jvm_method.v_table_index = jvm_class.v_table.size();
					jvm_class.v_table.push_back(sp_jvm_method);
				}
				if(logger.is_debug()) logger.log_debug() 
					<< indent << jvm_class.name << " : "
					<< "v_table_index is " << jvm_method.v_table_index << endl;
			}

			expand_method_attributes(cf_method, jvm_method);
		}
	}

	void Expander::expand_method_attributes(ClassFileMember & cf_method, JvmMethod & jvm_method){
		for(int i=0; i < cf_method.attributes.size(); i++){
			Attribute* attribute = cf_method.attributes[i].get();
			switch(attribute->get_tag()){
				case ATTRIBUTE_CODE:
					if(logger.is_debug()) logger.log_debug() 
						<< indent << jvm_class.name << " : expanding code" << endl;  
					CodeAttribute *p_attr = (CodeAttribute*)attribute;
					jvm_method.max_stack = p_attr->max_stack;
					jvm_method.max_locals = p_attr->max_locals;
					jvm_method.code_length = p_attr->code_length;
					if(logger.is_debug()) logger.log_debug() 
						<< indent << jvm_class.name << " : code length - " 
						<< jvm_method.code_length << endl;
					jvm_method.instructions = new Instruction*[p_attr->code_length];
					Instruction* instructions = class_loader.sp_runtime->instruction_set.instructions;
					jvm_method.code = p_attr->code;
					char* code_bytes = p_attr->code->data;
 					for(int ci = 0; ci < jvm_method.code_length; ci++){
						Instruction* instruction = &instructions[255 & code_bytes[ci]];
						if(logger.is_debug()) logger.log_debug() 
							<< indent << jvm_class.name << " : [" << ci << "]  "
							<< instruction->opcode << " - " <<instruction->name  << " (" 
							<< instruction->arg_count << ")" << endl;
						jvm_method.instructions[ci] = instruction;
						if(instruction->arg_count > 4){
							throw JvmException("can't parse instruction " + instruction->name);
						}
						for(int bi = 0; bi < instruction->arg_count; bi++){
							jvm_method.instructions[ci++] = &instructions[203];
						}
					}
					break;
			}
		}
	}

	string & Expander::get_class_name(){
		int name_index = ((ConstantClass*)check_and_get(cfr.this_class, CONSTANT_CLASS))->name_index;
		return get_string(name_index);
	}

	string & Expander::get_super_class_name(){
		int name_index = ((ConstantClass*)check_and_get(cfr.super_class, CONSTANT_CLASS))->name_index;
		return get_string(name_index);
	}

	// gets a string from the constant pool at the given index
	//
	string & Expander::get_string(int index){
		return ((ConstantUtf8*)check_and_get(index, CONSTANT_UTF8))->str;
	}

	//	get a pointer to a constant pool entry at a given index and
	//  check it will be castable to the required type.
	//
	//  perform bounds checking on the index and tag before comparing
	//  their types.
	//
	//	constant pool should references should all be consistent, but
	//  handle inconsistencies gracefully anyway
	//
	ConstantPoolEntry* Expander::check_and_get(int index, int tag){
		int max_index = cp.size() - 1;
		if(index < 0 || index > max_index){
			ostringstream os;
			os << "index " << index << " outside range [0-"
				<< max_index << "] in constant pool"; 
			throw JvmException (os.str());
		}
		if(tag < 1 || tag > CONSTANT_MAX_TAG){
			ostringstream os;
			os << "tag " << tag << " outside range [1-"
				<< CONSTANT_MAX_TAG << "] for constant pool"; 
			throw JvmException (os.str());
		}
		ConstantPoolEntry* entry = cp[index].get();
		if(entry->get_tag() != tag){
			ostringstream os;
			os << "tag mismatch at index " << index 
				<< ", requested " << CONSTANT_POOL_TAG_NAMES[tag]
				<< ", found " << CONSTANT_POOL_TAG_NAMES[entry->get_tag()];
			throw JvmException (os.str());
		}
		return entry;
	}

}