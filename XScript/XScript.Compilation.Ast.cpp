#include "stdafx.h"
#include "XScript.Compilation.Errors.h"
#include "XScript.Compilation.Ast.h"
#include "XScript.DebugTools.h"
#include "XScript.Compilation.YaccInterface.h"
#include "XScript.Compilation.h"
#include "XScript.Memory.h"
#include "XScript.Runtime.Derives.h"
#include "XScript.Memory.StringTools.h"
using namespace XScript::Compilation::Ast;
using namespace XScript::Compilation::YaccInterface;
using namespace XScript::Compilation;
using namespace XScript::Memory;
using namespace XScript::Runtime::Derives;
using namespace XScript::Memory::StringTools;
using namespace XScript::Compilation::Errors;

namespace XScript::Compilation::Ast
{
	template<typename _Ty>
	static inline typename XScript::Runtime::BasicTypes::String ToString(_Ty value)
	{
		return std::to_wstring(value).c_str();
	}

	template<typename _Ty, typename... _Types>
	static inline typename _Ty  * XScriptCall StaicNewPointer(_Types&&... _Args)
	{
		auto xs_compiler = GetCurrentCompiler();
		assert(xs_compiler->current_memory != nullptr);
		return	xs_compiler->current_memory->NewPointer<_Ty>(std::forward<_Types>(_Args)...);
	}

	static String GetCastTypeName(CastType index)
	{
		static const vector<Character*> cast_name = {
			L"Int32ToDoubleCast",
			L"DoudbleToInt32Cast",
			L"BooleanToStringCast",
			L"Int32ToStringCast",
			L"DoubleToStringCast",
		};
		assert((cast_name.size() + 1) != (size_t)CastType::CastTypeCountPlusOne);
		return cast_name[(size_t)index];
	}

	ExpressionTag::ExpressionTag(size_t line) :AstObjectTag(line)
	{
	}

	Expression ExpressionTag::CreateCast(CastType cast_t, TypeSpecifier target)
	{
#ifdef _DEBUG
		PrintFix();
		wcout << L"插入转型节点 → cast type : " << (GetCastTypeName(cast_t)) << endl;
#endif // _DEBUG
		return	StaicNewPointer<CastExpressionTag>(this->line, cast_t, this);
	}

	void AstObjectTag::PrintFix()
	{
		cout << "fix in line : " << line;
	}

	IndexExpressionTag::IndexExpressionTag(size_t line, Expression array, Expression index) : ExpressionTag(line)
	{
		this->array = array;
		this->index = index;
	}

	AssignExpresionTag::AssignExpresionTag(size_t line, Expression left, AssignmentOperator _operator, Expression operand) :ExpressionTag(line)
	{
		this->left = left;
		this->_operator = _operator;
		this->operand = operand;
	}

	Expression AssignExpresionTag::Fix(Block current_block)
	{
		this->left = this->left->Fix(current_block);
		if (typeid(*(this->left)) != typeid(DeclarationIdExpressionTag))
		{
			CompileNotLeftValueError(this->line);
		}
		this->operand = this->operand->Fix(current_block);
		this->operand = CreateAssignCast()->Fix(current_block);
		this->type = left->type;
		return this;
	}

	Expression AssignExpresionTag::CreateAssignCast()
	{
		if (!this->operand->type->derive_list->empty()
			|| !this->left->type->derive_list->empty())
		{
			DeriveTypeCastError(this->line);
		}
		if (this->operand->type->is_int32() &&
			this->left->type->is_double())
		{
			return this->operand->CreateCast(CastType::Int32ToDoubleCast);
		}
		else if (this->operand->type->is_double() &&
			this->left->type->is_int32())
		{
			return this->CreateCast(CastType::DoudbleToInt32Cast);
		}
		else
		{
			CastMissMatchError(this->operand->line, this->operand->type, this->left->type);
		}
		return nullptr;
	}

	FunctionCallExpressionTag::FunctionCallExpressionTag(size_t line, Expression function, ArgumentList argument) :InvokeExpressionTag(line, argument)
	{
		this->function = function;
	}

	Expression FunctionCallExpressionTag::Fix(Block current_block)
	{
		this->function = this->function->Fix(current_block);
		IdentifierExpression fdexpr = dynamic_cast<IdentifierExpression>(function);
		if (fdexpr == nullptr || fdexpr->type != IdentifierPointToType::Function)
		{
			//error
		}
		FunctionDefinition fd = GetCurrentCompiler()->SearchFunction(fdexpr->name);
		if (fd == nullptr)
		{

			//error
		}
		//check


		//
		this->type = fd->type;
		return this;
	}

	MethodCallExpressionTag::MethodCallExpressionTag(size_t line, Expression expression, String identifier, ArgumentList argument) : InvokeExpressionTag(line, argument)
	{
		this->expression = expression;
		this->identifier = identifier;
	}

	CommaExpressionTag::CommaExpressionTag(size_t line, Expression left, Expression right) : ExpressionTag(line)
	{
		this->left = left;
		this->right = right;
	}

	Expression CommaExpressionTag::Fix(Block current_block)
	{
		this->left = this->left->Fix(current_block);
		this->right = this->right->Fix(current_block);
		this->type = this->right->type;
		return this;
	}

	IdentifierExpressionTag::IdentifierExpressionTag(size_t line, String name) : ExpressionTag(line)
	{
		this->name = name;
	}

	Expression IdentifierExpressionTag::Fix(Block current_block)
	{
		Compiler com = GetCurrentCompiler();
		Declaration decl = com->SearchDeclaration(this->name, current_block);
		if (decl != nullptr)
		{
			FixPointToDeclaration(decl);
			return this;
		}
		FunctionDefinition fd = com->SearchFunction(name);
		if (fd != nullptr)
		{
			FixPointToFunction(fd);
			return this;
		}
		IdentifierNotFoundError(this->line, this->name);
		return nullptr;
	}

	 void IdentifierExpressionTag::FixPointToFunction(FunctionDefinition function)
	{
#ifdef _DEBUG
		this->PrintFix();
		wcout << *(this->name) << L" fix point to function" << endl;
#endif // _DEBUG
		type = IdentifierPointToType::Function;
		this->point_to_.function = function;
	}

	 void IdentifierExpressionTag::FixPointToDeclaration(Declaration declaration)
	{
#ifdef _DEBUG
		this->PrintFix();
		wcout << *(this->name) << L" fix point to function" << endl;
#endif // _DEBUG
		type = IdentifierPointToType::Declaration;
		this->point_to_.declaration = declaration;
	}


	IfStatementTag::IfStatementTag(size_t line, Expression condition, Block then_block, ElsifList elsif_list, Block else_block) : StatementTag(line)
	{
		this->condition = condition;
		this->then_block = then_block;
		this->elsif_list = elsif_list;
		this->else_block = else_block;
	}
	WhileStatementTag::WhileStatementTag(size_t line, String label, Expression condition, Block block) :StatementTag(line)
	{
		this->label = label;
		this->condition = condition;
		this->block = block;
	}
	ForStatementTag::ForStatementTag(size_t line, String label, Expression init, Expression condition, Expression post, Block block) :StatementTag(line)
	{
		this->label = label;
		this->init = init;
		this->condition = condition;
		this->post = post;
		this->block = block;
	}
	ReturnStatementTag::ReturnStatementTag(size_t line, Expression return_value) :StatementTag(line)
	{
		this->return_value = return_value;
	}
	ForeachStatementTag::ForeachStatementTag(size_t line, String label, String variable, Expression collection, Block block) : StatementTag(line)
	{
		this->label = label;
		this->variable = variable;
		this->collection = collection;
		this->block = block;
	}
	BreakStatementTag::BreakStatementTag(size_t line, String label) :StatementTag(line)
	{
		this->label = label;
	}
	ContinueStatementTag::ContinueStatementTag(size_t line, String label) : StatementTag(line)
	{
		label = label;
	}
	TryStatementTag::TryStatementTag(size_t line, Block try_block, Block catch_block, String exception, Block finally_block) : StatementTag(line)
	{
		this->try_block = try_block;
		this->catch_block = catch_block;
		this->exception = exception;
		this->finally_block = finally_block;
	}
	ThrowStatementTag::ThrowStatementTag(size_t line, Expression expression) :StatementTag(line)
	{
		this->exception = expression;
	}


	StatementTag::StatementTag(size_t line) :AstObjectTag(line)
	{
	}

	DeclarationTag::DeclarationTag(String name, TypeSpecifier type, int variable_index)
	{
		this->name = name;
		this->type = type;
		this->variable_index = variable_index;
	}
	TypeSpecifierTag::TypeSpecifierTag(BasicType basic_type, TypeDeriveList derive_list)
	{
		this->basic_type = basic_type;
		this->derive_list = derive_list;
	}

	FunctionDefinitionTag::FunctionDefinitionTag(TypeSpecifier type, String name, ParameterList parameter, Block block)
	{
		this->type = type;
		this->name = name;
		this->parameter = parameter;
		this->block = block;
	}

	ElsifTag::ElsifTag(size_t line, Expression condition, Block block) :AstObjectTag(line)
	{
		this->condition = condition;
		this->block = block;
	}

	IncdecExpressionTag::IncdecExpressionTag(size_t line, Expression operand, IncdecExpressionOprator op) :UnaryExpressionTag(line, operand)
	{
		this->op = op;
	}



	LogicalNotExpressionTag::LogicalNotExpressionTag(size_t line, Expression operand) :UnaryExpressionTag(line, operand)
	{
		this->operand = operand;

	}

	inline ConstantExpression LogicalNotExpressionTag::try_eval(Block current_block, ConstantExpression coperand)
	{
		if (this->operand->type->is_boolean())
		{
			coperand->data.boolean_v = !coperand->data.boolean_v;
			return coperand;
		}
		return nullptr;
	}

	inline Expression LogicalNotExpressionTag::do_fix(Block current_block)
	{
		if (!this->operand->type->is_boolean())
		{
			CompileLogicNotTypeMissMatchError(line);
		}
		this->type = this->operand->type;
		return this;
	}


	MinusExpressionTag::MinusExpressionTag(size_t line, Expression operand) :UnaryExpressionTag(line, operand)
	{
		this->operand = operand;
	}

	inline void MinusExpressionTag::before_fix(Block current_block)
	{
		UnaryExpressionTag::before_fix(current_block);
		if (!(this->operand->type->is_number()))
		{
			MinusTypeMissMatchError(line);
		}
	}

	inline ConstantExpression MinusExpressionTag::try_eval(Block current_block, ConstantExpression coperand)
	{
		if (coperand->type->is_int32())
		{
			coperand->data.int32_v = -coperand->data.int32_v;
			return coperand;
		}
		else if (coperand->type->is_double())
		{
			coperand->data.double_v = -coperand->data.double_v;
			return coperand;
		}
		return nullptr;
	}


	BinaryExpressionTag::BinaryExpressionTag(size_t line, Expression left, Expression right) : EvalExpressionTag(line)
	{
		this->left = left;
		this->right = right;
	}

	inline void BinaryExpressionTag::before_fix(Block current_block)
	{
		this->left = this->left->Fix(current_block);
		this->right = this->right->Fix(current_block);
	}

	inline ConstantExpression BinaryExpressionTag::do_eval(Block current_block)
	{
		return	try_eval(current_block, static_cast<ConstantExpression>(this->left), static_cast<ConstantExpression>(this->right));
	}

	ConstantExpressionTag::ConstantExpressionTag(size_t line, BasicType const_type, BasicTypeData u) :ExpressionTag(line)
	{
		switch (const_type)
		{
		case BasicType::Boolean:
		case BasicType::UInt16:
		case BasicType::UInt32:
		case BasicType::UInt64:
		case BasicType::Int16:
		case BasicType::Int32:
		case BasicType::Int64:
		case BasicType::Single:
		case BasicType::Double:
		case BasicType::String:
		{
			this->type = xs_alloc_type_specifier(const_type);
		}break;
		default:
		{
			//wcout << get_xvm_basic_type_name(const_type)<<endl;
			assert(0);
		}break;
		}
		this->data = data;
	}

	Expression ConstantExpressionTag::Fix(Block current_block)
	{
		return this;
	}

	ExpressionStatementTag::ExpressionStatementTag(size_t line, Expression exception) : StatementTag(line)
	{
		this->exception = exception;
	}

	ParameterTag::ParameterTag(size_t line, String name, TypeSpecifier type) : AstObjectTag(line)
	{
		this->name = name;
		this->type = type;
	}

	FunctionDeriveTag::FunctionDeriveTag(ParameterList list)
	{
		this->parameter_list = parameter_list;
	}

	DeclarationStatementTag::DeclarationStatementTag(size_t line, Declaration initializer) :StatementTag(line)
	{
		this->initializer = initializer;
	}

	BlockTag::BlockTag(size_t line, Block outer_block) : AstObjectTag(line)
	{
		this->outer_block = outer_block;
	}

	CastExpressionTag::CastExpressionTag(size_t line, CastType cast_type, Expression operand, TypeSpecifier target) : ExpressionTag(line)
	{
		this->cast_type = cast_type;
		this->operand = operand;

	}

	Expression CastExpressionTag::Fix(Block current_block)
	{
		switch (cast_type)
		{
		case CastType::Int32ToDoubleCast:
		{
			this->type = xs_alloc_type_specifier(BasicType::Double);
		}break;
		case CastType::DoudbleToInt32Cast:
		{
			this->type = xs_alloc_type_specifier(BasicType::Int32);

		}break;
		case CastType::BooleanToStringCast:
		case CastType::Int32ToStringCast:
		case CastType::DoubleToStringCast:
		{
			this->type = xs_alloc_type_specifier(BasicType::String);
		}break;
		default:
			break;
		}
		return this;
	}

	AstObjectTag::AstObjectTag(size_t line)
	{
		this->line = line;
	}

	UnaryExpressionTag::UnaryExpressionTag(size_t line, Expression operand) :EvalExpressionTag(line)
	{
		this->operand = operand;
	}

	void UnaryExpressionTag::before_fix(Block current_block)
	{
		this->operand->Fix(current_block);
	}

	inline ConstantExpression UnaryExpressionTag::do_eval(Block current_block)
	{
		return try_eval(current_block, static_cast<ConstantExpression>(this->operand));
	}

	MathBinaryExpressionTag::MathBinaryExpressionTag(size_t line, Expression left, MathBinaryExpressionOperator op, Expression right)
		: BinaryExpressionTag(line, left, right)
	{
		this->op = op;
	}

	Expression MathBinaryExpressionTag::determined_type(Block current_block)
	{
		if (this->left->type->is_int32() && this->right->type->is_int32())
		{
			this->type = xs_alloc_type_specifier(BasicType::Int32);
		}
		else if (this->left->type->is_double() && this->right->type->is_double())
		{
			this->type = xs_alloc_type_specifier(BasicType::Double);
		}
		else if (this->left->type->is_string() && this->right->type->is_string())
		{
			this->type = xs_alloc_type_specifier(BasicType::String);
		}
		else
		{
			MathTypeMissMatch_error(this->line);
		}
		return this;
	}

	ConstantExpression MathBinaryExpressionTag::try_eval(Block current_block, ConstantExpression cleft, ConstantExpression cright)
	{
		if (cleft->type->is_int32())
		{
			if (cright->type->is_int32())
			{
				cleft->data.int32_v = value_type_math_operator(cleft->data.int32_v, cright->data.int32_v, this->op);
				return cleft;
			}
			else if (cright->type->is_double())
			{
				cright->data.double_v = value_type_math_operator(cleft->data.int32_v, cright->data.double_v, this->op);
				return cright;
			}
		}
		else if (cleft->type->is_double())
		{
			if (cright->type->is_int32())
			{
				cleft->data.double_v = value_type_math_operator(cleft->data.double_v, cright->data.int32_v, this->op);
				return cright;
			}
			else if (cright->type->is_double())
			{
				cleft->data.double_v = value_type_math_operator(cleft->data.double_v, cright->data.double_v, this->op);
				return cright;
			}
		}
		else if (cleft->type->is_string()
			&& this->op == MathBinaryExpressionOperator::Add)
		{
			if (cright->type->is_int32())
			{
				cleft->data.string_v = GetCurrentCompiler()->string_pool->Chain(cleft->data.string_v, ToString(cright->data.int32_v));
				return cleft;
			}
			else if (cleft->type->is_double())
			{
				cleft->data.string_v = GetCurrentCompiler()->string_pool->Chain(cleft->data.string_v, ToString(cright->data.double_v));
				return cleft;
			}
			else if (cleft->type->is_string())
			{
				cleft->data.string_v = GetCurrentCompiler()->string_pool->Chain(cleft->data.string_v, cright->data.string_v);
				return cleft;
			}
		}
		return nullptr;
	}

	void MathBinaryExpressionTag::cast_fix(Block b)
	{
		if (this->left->type->is_int32() && this->right->type->is_double())
		{
			this->left = this->left->CreateCast(CastType::Int32ToDoubleCast);
		}
		else if (this->left->type->is_double() && this->right->type->is_int32())
		{
			this->right = this->right->CreateCast(CastType::Int32ToDoubleCast);
		}
		else if (this->left->type->is_string())
		{
			if (this->right->type->is_int32())
			{
				this->right = this->right->CreateCast(CastType::Int32ToStringCast);
			}
			else if (this->right->type->is_double())
			{
				this->right = this->right->CreateCast(CastType::DoubleToStringCast);
			}
			else if (this->right->type->is_boolean())
			{
				this->right = this->right->CreateCast(CastType::BooleanToStringCast);
			}
		}
	}

	CompareBinaryExpressionTag::CompareBinaryExpressionTag(size_t line, Expression left, CompareBinaryExpressionOperator op, Expression right)
		: BinaryExpressionTag(line, left, right)
	{
		this->op = op;
	}

	LogicBinaryExpressionTag::LogicBinaryExpressionTag(size_t line, Expression left, LogicBinaryExpressionOperator op, Expression right)
		: BinaryExpressionTag(line, left, right)
	{
		this->op = op;
	}

	Expression LogicBinaryExpressionTag::determined_type(Block current_block)
	{
		if (left->type->is_boolean() && right->type->is_boolean())
		{
			this->type = xs_alloc_type_specifier(BasicType::Boolean);
		}
		else
		{
			LogicTypeMissMatchError(line);
		}
		return this;
	}

	ConstantExpression LogicBinaryExpressionTag::try_eval(Block current_block, ConstantExpression cleft, ConstantExpression cright)
	{
		if (cleft->type->basic_type == BasicType::Boolean&&cleft->type->basic_type == BasicType::Boolean)
		{
			cleft->data.boolean_v = value_type_logic_operator<Boolean>(cleft->data.boolean_v, cright->data.boolean_v, op);
		}
		else
		{
			LogicTypeMissMatchError(line);
		}
		return nullptr;
	}

	Expression CompareBinaryExpressionTag::determined_type(Block current_block)
	{
		if (right->type->basic_type != left->type->basic_type
			|| right->type->derive_list == nullptr
			|| left->type->derive_list == nullptr)
		{
			CompareTypeMissMatchError(line);
		}
		this->type = xs_alloc_type_specifier(BasicType::Boolean);
		return	this;
	}

	ConstantExpression CompareBinaryExpressionTag::try_eval(Block current_block, ConstantExpression cleft, ConstantExpression cright)
	{
		if (cleft->type->is_int32())
		{
			if (cright->type->is_int32())
			{
				cleft->type = xs_alloc_type_specifier(BasicType::Boolean);
				cleft->data.boolean_v = value_type_compare_operator(cleft->data.int32_v, cright->data.int32_v, op);
				return cleft;
			}
			else if (cright->type->is_double())
			{
				cleft->type = xs_alloc_type_specifier(BasicType::Boolean);
				cleft->data.boolean_v = value_type_compare_operator(cleft->data.int32_v, cright->data.double_v, op);
				return cleft;
			}
		}
		else if (cleft->type->is_double())
		{
			if (cright->type->is_int32())
			{
				cleft->type = xs_alloc_type_specifier(BasicType::Boolean);
				cleft->data.boolean_v = value_type_compare_operator(cleft->data.double_v, cright->data.int32_v, op);
				return cleft;
			}
			else if (cright->type->is_double())
			{
				cleft->type = xs_alloc_type_specifier(BasicType::Boolean);
				cleft->data.boolean_v = value_type_compare_operator(cleft->data.double_v, cright->data.double_v, op);
				return cleft;
			}
		}
		else if (cleft->type->is_boolean())
		{
			if (cright->type->is_boolean())
			{
				cleft->data.boolean_v = value_type_compare_operator(cleft->data.boolean_v, cright->data.boolean_v, op);
				return cleft;
			}
		}
		else if (cleft->type->is_string() && cright->type->is_string())
		{
			cleft->type = xs_alloc_type_specifier(BasicType::Boolean);
			cleft->data.boolean_v = *(cleft->data.string_v) == *(cright->data.string_v);
			return cleft;
		}
		return nullptr;
	}

	void CompareBinaryExpressionTag::cast_fix(Block b)
	{
		if (left->type->is_int32())
		{
			if (right->type->is_double())
			{
				left = left->CreateCast(CastType::Int32ToDoubleCast);
			}
		}
		else if (left->type->is_double())
		{
			if (right->type->is_int32())
			{
				right = right->CreateCast(CastType::Int32ToDoubleCast);
			}
		}
	}


	Expression EvalExpressionTag::Fix(Block current_block)
	{
		before_fix(current_block);
		if (is_constant_probability())
		{
			ConstantExpression expr = do_eval(current_block);
			if (expr != nullptr)
			{
				return expr;
			}
		}
		return do_fix(current_block);
	}
}
