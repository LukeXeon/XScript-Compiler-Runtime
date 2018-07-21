#include "stdafx.h"
#include "xscript0.h"
#include "generate.h"
#include "xvm.h"
#include "code.h"
#include "compiler.h"
#include "debug.h"
#include "utils.h"
#pragma warning(disable:4996)
namespace XScript
{
	using namespace utils;
	using namespace Runtime;
	using namespace Ast;
	using namespace OpCodes;
	namespace Generate
	{

		XvmLocalVariableArray copy_parameter_list(ParameterList src)
		{
			XvmLocalVariableArray arr = xs_new_array<XvmLocalVariable>(src->size());
			for_each(src->begin(), src->end(), [&arr](auto x)->void
			{
				arr->push_back(x->to_xvm_local_varible());
			});
			return arr;
		}

		OpcodeBufferTag::OpcodeBufferTag()
		{
			codes = make_shared<stack<Byte>>();
			label_table = xs_new_array<LabelTable>();
			line_numbers = xs_new_array<XvmLineNumber>();
		}

		void OpcodeBufferTag::GenerateCode(size_t line_number, OpCode code, ...)
		{
			OpcodeBufferTag* ob = this;
			va_list     ap;
			va_start(ap, code);

			char*   param = GetOpCodeInfo(code).parameter;
			size_t	 param_count = strlen(param);

			size_t start_pc = ob->codes->size();
			ob->codes->push((Byte)code);
			for (int i = 0; param[i] != '\0'; i++)
			{
				unsigned int value = va_arg(ap, int);
				switch (param[i]) {
				case 'b': /* byte */
					ob->codes->push((Byte)value);

					break;
				case 's': /* short(2byte int) */
					ob->codes->push((Byte)(value >> 8));
					ob->codes->push((Byte)(value & 0xff));
					break;
				case 'p': /* constant pool index */
					ob->codes->push((Byte)(value >> 8));
					ob->codes->push((Byte)(value & 0xff));
					break;
				default:
				{
					char buffer[20];
					sprintf(buffer, "param..%s, i..%d", param, i);
					DebugerAssert(0, buffer);
				}
				break;
				}
			}
			add_line_number(line_number, start_pc);
			va_end(ap);
		}

		void OpcodeBufferTag::add_line_number(size_t line_number, size_t start_pc)
		{
			if (this->line_numbers == nullptr)
			{
				this->line_numbers = xs_new_array<XvmLineNumber>();
			}
			if (this->line_numbers->operator[](this->line_numbers->size() - 1)->line_number != line_number)
			{
				this->line_numbers->push_back(make_shared<XvmLineNumberTag>(line_number, start_pc, this->line_numbers->size() - start_pc));
			}
			else
			{
				auto temp = this->line_numbers->operator[](this->line_numbers->size() - 1);
				temp->pc_count += this->line_numbers->size() - start_pc;
			}
		}
	
		int get_opcode_type_offset(BasicType basic_type)
		{
			switch (basic_type) 
			{
			case BasicType::Boolean:
			{
				return 0;
			}break;
			case BasicType::Int32:
			{
				return 0;
			}break;
			case BasicType::Double:
			{
				return 1;
			}break;
			case BasicType::String:
			{
				return 2;
			}break;
			default:
			{
				char buffer[20];
				sprintf(buffer, "basic_type..%d", basic_type);
				DebugerAssert(0, buffer);			
			}break;
			}
			return 0;
		}
	}
}

