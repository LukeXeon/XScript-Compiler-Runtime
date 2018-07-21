#include "stdafx.h"
#include "XScript.Compilation.Errors.h"
#include "XScript.Memory.StringTools.h"
#include "XScript.Compilation.h"
using namespace XScript::Compilation;
using namespace XScript::Memory::StringTools;
int XScriptCall yyerror(char const *str)
{
	size_t line = GetCurrentLineNumber();
	String err = GetCurrentCompiler()->string_pool->CreateFromMultiByte(str);
	wcerr << L"error in line : " << L"在(" << err << L")附近发生语法错误。" << endl;
	exit(1);
	return 0;
}
namespace XScript::Compilation::Errors
{

	void XScriptCall CastMissMatchError(size_t line, TypeSpecifier type1, TypeSpecifier type2)
	{
		wcerr << L"error in line : "
			<< L"不能将(" << GetBasicTypeName(type2->basic_type) << L")转型为(" << GetBasicTypeName(type2->basic_type) << L")。"
			<< endl;
		exit(1);
	}

	void XScriptCall DeriveTypeCastError(size_t line)
	{
		wcerr << L"error in line : " << L"不能强制转型为派生类型。" << endl;
		exit(1);
	}

	void XScriptCall CompileNotLeftValueError(size_t line)
	{
		wcerr << L"error in line : " << L"表达式不是左值。" << endl;
		exit(1);
	}

	void XScriptCall IdentifierNotFoundError(size_t line, String name)
	{
		wcerr << L"error in line : " << L"找不到变量或函数(" << *name << L")。" << endl;
		exit(1);
	}

	void XScriptCall ConversionStringError(size_t line)
	{
		wcerr << L"error in line : " << L"编译器尝试转换字符串，但是发生了意外。" << endl;
		exit(1);
	}

	void XScriptCall BadCharError(size_t line, String bad_char)
	{
		wcerr << L"error in line : " << L"不正确的字符(" << *bad_char << L")。" << endl;
		exit(1);
	}

	void XScriptCall FunctionMultipleDefine(size_t line, String error_text)
	{
		wcerr << L"error in line : " << L"函数的参数名重复(" << *error_text << L")。" << endl;
		exit(1);
	}

	void XScriptCall MathTypeMissMatch_error(size_t line)
	{
		wcerr << L"error in line : " << L"算数运算符的操作数类型不正确。" << endl;
		exit(1);
	}

	void XScriptCall CompareTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"比较运算符的操作数类型不正确。" << endl;
		exit(1);
	}

	void XScriptCall LogicTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"逻辑与或运算符的操作数类型不正确。" << endl;
		exit(1);
	}

	void XScriptCall MinusTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"减法运算符的操作数类型不正确。" << endl;
		exit(1);
	}

	void XScriptCall CompileLogicNotTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"逻辑非运算符的操作数类型不正确。" << endl;
		exit(1);
	}

	/*
			enum class CompileErrorType
			{
				PARSE_ERR = 1,
				CHARACTER_INVALID_ERR,
				FUNCTION_MULTIPLE_DEFINE_ERR,
				BAD_MULTIBYTE_CHARACTER_ERR,
				UNEXPECTED_WIDE_STRING_IN_COMPILE_ERR,
				PARAMETER_MULTIPLE_DEFINE_ERR,
				VARIABLE_MULTIPLE_DEFINE_ERR,
				IDENTIFIER_NOT_FOUND_ERR,
				DERIVE_TYPE_CAST_ERR,
				CAST_MISMATCH_ERR,
				MATH_TYPE_MISMATCH_ERR,
				COMPARE_TYPE_MISMATCH_ERR,
				LOGICAL_TYPE_MISMATCH_ERR,
				MINUS_TYPE_MISMATCH_ERR,
				LOGICAL_NOT_TYPE_MISMATCH_ERR,
				INC_DEC_TYPE_MISMATCH_ERR,
				FUNCTION_NOT_IDENTIFIER_ERR,
				FUNCTION_NOT_FOUND_ERR,
				ARGUMENT_COUNT_MISMATCH_ERR,
				NOT_LVALUE_ERR,
				LABEL_NOT_FOUND_ERR,
				COMPILE_ERROR_COUNT_PLUS_1
			};


			static vector<ErrorDefinition>&
				get_error_message_format()
			{
				static vector<ErrorDefinition> error_message_format = {
					{ L"dummy" },
					{ L"在($(token))附近发生语法错误" },
					{ L"不正确的字符($(bad_char))" },
					{ L"函数名重复($(name))" },
					{ L"不正确的多字节字符。" },
					{ L"预期外的宽字符串。" },
					{ L"函数的参数名重复($(name))。" },
					{ L"变量名$(name)重复。" },
					{ L"找不到变量或函数$(name)。" },
					{ L"不能强制转型为派生类型。" },
					{ L"不能将$(src)转型为$(dest)。" },
					{ L"算数运算符的操作数类型不正确。" },
					{ L"比较运算符的操作数类型不正确。" },
					{ L"逻辑and/or运算符的操作数类型不正确。" },
					{ L"减法运算符的操作数类型不正确。" },
					{ L"逻辑非运算符的操作数类型不正确。" },
					{ L"自增/自减运算符的操作数类型不正确。" },
					{ L"函数调用运算符的操作数不是函数名。" },
					{ L"找不到函数$(name)。" },
					{ L"函数的参数数量错误。" },
					{ L"赋值运算符的左边不是一个左边值。" },
					{ L"标签$(label)不存在。" },
					{ L"dummy" }
				};
				return error_message_format;
			}
	*/


}
