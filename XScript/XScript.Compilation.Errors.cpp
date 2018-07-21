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
	wcerr << L"error in line : " << L"��(" << err << L")���������﷨����" << endl;
	exit(1);
	return 0;
}
namespace XScript::Compilation::Errors
{

	void XScriptCall CastMissMatchError(size_t line, TypeSpecifier type1, TypeSpecifier type2)
	{
		wcerr << L"error in line : "
			<< L"���ܽ�(" << GetBasicTypeName(type2->basic_type) << L")ת��Ϊ(" << GetBasicTypeName(type2->basic_type) << L")��"
			<< endl;
		exit(1);
	}

	void XScriptCall DeriveTypeCastError(size_t line)
	{
		wcerr << L"error in line : " << L"����ǿ��ת��Ϊ�������͡�" << endl;
		exit(1);
	}

	void XScriptCall CompileNotLeftValueError(size_t line)
	{
		wcerr << L"error in line : " << L"���ʽ������ֵ��" << endl;
		exit(1);
	}

	void XScriptCall IdentifierNotFoundError(size_t line, String name)
	{
		wcerr << L"error in line : " << L"�Ҳ�����������(" << *name << L")��" << endl;
		exit(1);
	}

	void XScriptCall ConversionStringError(size_t line)
	{
		wcerr << L"error in line : " << L"����������ת���ַ��������Ƿ��������⡣" << endl;
		exit(1);
	}

	void XScriptCall BadCharError(size_t line, String bad_char)
	{
		wcerr << L"error in line : " << L"����ȷ���ַ�(" << *bad_char << L")��" << endl;
		exit(1);
	}

	void XScriptCall FunctionMultipleDefine(size_t line, String error_text)
	{
		wcerr << L"error in line : " << L"�����Ĳ������ظ�(" << *error_text << L")��" << endl;
		exit(1);
	}

	void XScriptCall MathTypeMissMatch_error(size_t line)
	{
		wcerr << L"error in line : " << L"����������Ĳ��������Ͳ���ȷ��" << endl;
		exit(1);
	}

	void XScriptCall CompareTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"�Ƚ�������Ĳ��������Ͳ���ȷ��" << endl;
		exit(1);
	}

	void XScriptCall LogicTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"�߼����������Ĳ��������Ͳ���ȷ��" << endl;
		exit(1);
	}

	void XScriptCall MinusTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"����������Ĳ��������Ͳ���ȷ��" << endl;
		exit(1);
	}

	void XScriptCall CompileLogicNotTypeMissMatchError(size_t line)
	{
		wcerr << L"error in line : " << L"�߼���������Ĳ��������Ͳ���ȷ��" << endl;
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
					{ L"��($(token))���������﷨����" },
					{ L"����ȷ���ַ�($(bad_char))" },
					{ L"�������ظ�($(name))" },
					{ L"����ȷ�Ķ��ֽ��ַ���" },
					{ L"Ԥ����Ŀ��ַ�����" },
					{ L"�����Ĳ������ظ�($(name))��" },
					{ L"������$(name)�ظ���" },
					{ L"�Ҳ�����������$(name)��" },
					{ L"����ǿ��ת��Ϊ�������͡�" },
					{ L"���ܽ�$(src)ת��Ϊ$(dest)��" },
					{ L"����������Ĳ��������Ͳ���ȷ��" },
					{ L"�Ƚ�������Ĳ��������Ͳ���ȷ��" },
					{ L"�߼�and/or������Ĳ��������Ͳ���ȷ��" },
					{ L"����������Ĳ��������Ͳ���ȷ��" },
					{ L"�߼���������Ĳ��������Ͳ���ȷ��" },
					{ L"����/�Լ�������Ĳ��������Ͳ���ȷ��" },
					{ L"��������������Ĳ��������Ǻ�������" },
					{ L"�Ҳ�������$(name)��" },
					{ L"�����Ĳ�����������" },
					{ L"��ֵ���������߲���һ�����ֵ��" },
					{ L"��ǩ$(label)�����ڡ�" },
					{ L"dummy" }
				};
				return error_message_format;
			}
	*/


}
