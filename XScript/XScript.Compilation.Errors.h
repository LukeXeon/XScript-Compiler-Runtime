#pragma once
#include "stdafx.h"
#include "XScript.DebugTools.h"
#include "XScript.Runtime.BasicTypes.h"
#include "XScript.Compilation.Ast.h"
using namespace XScript::Runtime::BasicTypes;
using namespace XScript::Compilation::Ast;
int XScriptCall yyerror(char const * str);
namespace XScript::Compilation::Errors
{
	void XScriptCall CastMissMatchError(size_t line, TypeSpecifier type1, TypeSpecifier type2);

	void XScriptCall DeriveTypeCastError(size_t line);

	void XScriptCall CompileNotLeftValueError(size_t line);

	void XScriptCall IdentifierNotFoundError(size_t line, String name);

	void XScriptCall ConversionStringError(size_t line);

	void XScriptCall BadCharError(size_t line, String bad_char);

	void XScriptCall FunctionMultipleDefine(size_t line, String error_text);

	void XScriptCall MathTypeMissMatch_error(size_t line);

	void XScriptCall CompareTypeMissMatchError(size_t line);

	void XScriptCall LogicTypeMissMatchError(size_t line);

	void XScriptCall MinusTypeMissMatchError(size_t line);

	void XScriptCall CompileLogicNotTypeMissMatchError(size_t line);
}