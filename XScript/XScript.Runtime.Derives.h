#pragma once
#include "stdafx.h"
#include "XScript.Compilation.Ast.h"
#include "XScript.MemoryManager.h"
#include "XScript.Compilation.h"
using namespace XScript::Compilation::Ast;
using namespace XScript::MemoryManager;
using namespace XScript::Compilation;

namespace XScript::Runtime::Derives
{
	template<typename T1, typename T2, typename enable_if<!(is_same<T1, Double>::value || is_same<T1, Single>::value || is_same<T2, Double>::value || is_same<T2, Single>::value), int>::type = 0>
	inline auto XScriptCall value_type_math_operator(T1& t1, T2& t2, MathBinaryExpressionOperator& op)
	{
		switch (op)
		{
		case MathBinaryExpressionOperator::Add:
		{
			return t1 + t2;
		}break;
		case MathBinaryExpressionOperator::Mul:
		{
			return t1*t2;
		}
		break;
		case MathBinaryExpressionOperator::Div:
		{
			return t1 / t2;
		}
		break;
		case MathBinaryExpressionOperator::Sub:
		{
			return t1%t2;
		}
		break;
		default:
			assert(0);
			break;
		}
	}

	template<typename T1, typename T2, typename enable_if<(is_same<T1, Double>::value || is_same<T1, Single>::value || is_same<T2, Double>::value || is_same<T2, Single>::value), int>::type = 0>
	inline auto XScriptCall value_type_math_operator(T1& t1, T2& t2, MathBinaryExpressionOperator& op)
	{
		switch (op)
		{
		case MathBinaryExpressionOperator::Add:
		{
			return t1 + t2;
		}break;
		case MathBinaryExpressionOperator::Mul:
		{
			return t1*t2;
		}
		break;
		case MathBinaryExpressionOperator::Div:
		{
			return t1 / t2;
		}
		break;
		case MathBinaryExpressionOperator::Sub:
		{
			return std::fmod(t1, t2);
		}
		break;
		default:
			assert(0);
			break;
		}
	}

	template<typename T1, typename T2, typename enable_if<(is_same<T1, Boolean>::value && is_same<T2, Boolean>::value), int>::type = 0>
	inline Boolean XScriptCall value_type_compare_operator(T1& t1, T2& t2, CompareBinaryExpressionOperator& op)
	{
		switch (op)
		{
		case CompareBinaryExpressionOperator::Eq:
		{
			return t1 == t2;
		}
		break;
		case CompareBinaryExpressionOperator::Ne:
		{
			return t1 != t2;
		}
		break;
		default:
			return 0;
			assert(0);
			break;
		}
	}

	template<typename T1, typename T2, typename enable_if<!(is_same<T1, Boolean>::value || is_same<T2, Boolean>::value), int>::type = 0>
	inline Boolean XScriptCall value_type_compare_operator(T1& t1, T2& t2, CompareBinaryExpressionOperator& op)
	{
		switch (op)
		{
		case CompareBinaryExpressionOperator::Eq:
		{
			return t1 == t2;
		}
		break;
		case CompareBinaryExpressionOperator::Ne:
		{
			return t1 != t2;
		}
		break;
		case CompareBinaryExpressionOperator::Gt:
			return t1 > t2;
			break;
		case CompareBinaryExpressionOperator::Ge:
			return t2 >= t2;
			break;
		case CompareBinaryExpressionOperator::Lt:
			return t1 < t2;
			break;
		case CompareBinaryExpressionOperator::Le:
			return t1 <= t2;
			break;
		default:
			assert(0);
			return 0;
			break;
		}
	}

	template<typename T1, typename T2, typename enable_if<!(is_same<T1, Double>::value&&is_same<T1, Double>::value&&is_same<T1, Single>::value&&is_same<T1, Single>::value), int>::type = 0>
	inline Boolean XScriptCall value_type_logic_operator(T1& t1, T2& t2, LogicBinaryExpressionOperator& op)
	{
		switch (op)
		{
			break;
		case LogicBinaryExpressionOperator::Or:
			return t1 || t2;
			break;
		case LogicBinaryExpressionOperator::And:
			return t1 &&t2;
			break;
		default:
			assert(0);
			return false;
			break;
		}
	}
}
