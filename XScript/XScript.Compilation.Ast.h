#pragma once
#include "stdafx.h"
#include "XScript.Runtime.BasicTypes.h"
using namespace XScript::Runtime::BasicTypes;

namespace XScript::Compilation::Ast
{

	class AstObjectTag;

	//语法树类型前置声明和指针
	typedef AstObjectTag* AstObject;

	class ExpressionTag;
	typedef ExpressionTag* Expression;
	typedef list<Expression>* ExpressionList;

	typedef Expression Argument;
	typedef list<Argument>* ArgumentList;

	class StatementTag;
	typedef StatementTag* Statement;
	typedef list<Statement>* StatementList;

	typedef list<String>*StringList;

	class BlockTag;
	typedef BlockTag* Block;

	class ParameterTag;
	typedef ParameterTag* Parameter;
	typedef list<Parameter>* ParameterList;

	class TypeSpecifierTag;
	typedef TypeSpecifierTag* TypeSpecifier;

	class TypeDeriveTag;
	typedef TypeDeriveTag* TypeDerive;
	typedef list<TypeDerive>* TypeDeriveList;

	class DeclarationTag;
	typedef DeclarationTag* Declaration;
	typedef list<Declaration>* DeclarationList;

	class FunctionDefinitionTag;
	typedef FunctionDefinitionTag* FunctionDefinition;
	typedef list<FunctionDefinition>* FunctionDefinitionList;

	class ElsifTag;
	typedef ElsifTag* Elsif;
	typedef list<Elsif>* ElsifList;

	class IncdecExpressionTag;
	typedef IncdecExpressionTag* IncdecExpression;

	class LogicalNotExpressionTag;
	typedef LogicalNotExpressionTag* LogicalNotExpression;

	class MinusExpressionTag;
	typedef MinusExpressionTag* MinusExpression;

	class IndexExpressionTag;
	typedef IndexExpressionTag* IndexExpression;

	class AssignExpresionTag;
	typedef AssignExpresionTag* AssignExpresion;

	class FunctionCallExpressionTag;
	typedef FunctionCallExpressionTag* FunctionCallExpression;

	class MethodCallExpressionTag;
	typedef MethodCallExpressionTag* MethodCallExpression;

	class CommaExpressionTag;
	typedef CommaExpressionTag* CommaExpression;

	class DeclarationIdExpressionTag;
	typedef DeclarationIdExpressionTag* DeclarationExpression;

	class ConstantExpressionTag;
	typedef ConstantExpressionTag* ConstantExpression;

	class BinaryExpressionTag;
	typedef BinaryExpressionTag* BinaryExpression;

	class CastExpressionTag;
	typedef CastExpressionTag*CastExpression;

	class IdentifierExpressionTag;
	typedef IdentifierExpressionTag* IdentifierExpression;

	class ExpressionStatementTag;
	typedef ExpressionStatementTag* ExpressionStatement;

	class IfStatementTag;
	typedef IfStatementTag* IfStatement;

	class WhileStatementTag;
	typedef WhileStatementTag* WhileStatement;

	class ForStatementTag;
	typedef ForStatementTag* ForStatement;

	class ReturnStatementTag;
	typedef ReturnStatementTag* ReturnStatement;

	class ForeachStatementTag;
	typedef ForeachStatementTag* ForeachStatement;

	class BreakStatementTag;
	typedef BreakStatementTag* BreakStatement;

	class ContinueStatementTag;
	typedef ContinueStatementTag* ContinueStatement;

	class TryStatementTag;
	typedef TryStatementTag* TryStatement;

	class ThrowStatementTag;
	typedef ThrowStatementTag* ThrowStatement;

	class DeclarationTag;
	typedef DeclarationTag* Declaration;

	class TypeDeriveTag;
	typedef TypeDeriveTag* TypeDerive;

	class FunctionDeriveTag;
	typedef FunctionDeriveTag* FunctionDerive;

	class DeclarationStatementTag;
	typedef DeclarationStatementTag* DeclarationStatement;

	class BlockParentInfoTag;
	typedef BlockParentInfoTag*BlockParentInfo;

	class FunctionBlockInfoTag;
	typedef FunctionBlockInfoTag*FunctionBlockInfo;

	class StatementBlockInfoTag;
	typedef StatementBlockInfoTag*StatementBlockInfo;

	typedef class InvokeExpressionTag*InvokeExpression;

	typedef list<TypeSpecifier>* TypeSpecifierList;

	//语法树枚举,抽象代价较高时才使用
	enum class DeriveTag
	{
		FunctionDerive = 1
	};

	enum class IdentifierPointToType
	{
		Undefind = 0,
		Function,
		Declaration,
	};

	enum class StatementBlockType
	{
		Undefind = 0,
		WhileStatementBlock,
		ForStatamentBlock,
		ForeachStatamentBlock,
	};

	enum class AssignmentOperator
	{
		NomalAssign = 1,
		AddAssign,
		SubAssign,
		MulAssign,
		DivAssign,
		ModAssign
	};

	enum class MathBinaryExpressionOperator
	{
		Add,
		Mul,
		Div,
		Sub,
		Mod,
	};

	enum class CompareBinaryExpressionOperator
	{
		Eq,
		Ne,
		Gt,
		Ge,
		Lt,
		Le,
	};

	enum class LogicBinaryExpressionOperator
	{
		Or,
		And,
	};

	enum class IncdecExpressionOprator
	{
		Increment,
		Decrement
	};

	enum class CastType
	{
		Int32ToDoubleCast = 1,
		DoudbleToInt32Cast,
		BooleanToStringCast,
		Int32ToStringCast,
		DoubleToStringCast,
		CastTypeCountPlusOne,
	};

	//语法树类型
	class TypeSpecifierTag
	{
	public:
		TypeSpecifierTag(BasicType basic_type, TypeDeriveList derive_list);
		inline Boolean is_double()
		{
			return basic_type == BasicType::Double&&derive_list == nullptr;
		}
		inline Boolean is_int32()
		{
			return basic_type == BasicType::Int32&&derive_list == nullptr;
		}
		inline Boolean is_string()
		{
			return basic_type == BasicType::String&&derive_list == nullptr;
		}
		inline Boolean is_boolean()
		{
			return basic_type == BasicType::Boolean&&derive_list == nullptr;
		}
		inline Boolean is_number()
		{
			return is_double() || is_int32();
		}
		BasicType basic_type;
		TypeDeriveList derive_list;
	};

	class AstObjectTag
	{
	public:
		AstObjectTag(size_t line);
		void PrintFix();
		size_t line;
		String file_name;
	};

	class ExpressionTag :public AstObjectTag
	{
	public:
		ExpressionTag(size_t line);
		virtual Expression Fix(Block current_block)
		{
			return nullptr;
		}
		Expression CreateCast(CastType cast_t, TypeSpecifier target = nullptr);
		TypeSpecifier type;
	};

	class CastExpressionTag :public ExpressionTag
	{
	public:
		CastExpressionTag(size_t line, CastType cast_type, Expression operand, TypeSpecifier target = nullptr);
		virtual Expression Fix(Block current_block)override;
		CastType cast_type;
		Expression operand;
	};

	union BasicTypeData
	{
		Boolean boolean_v;
		Int32 int32_v;
		Double double_v;
		String string_v;
	};

	class ConstantExpressionTag :public  ExpressionTag
	{
	public:
		ConstantExpressionTag(size_t line, BasicType const_type, BasicTypeData u);
		virtual Expression Fix(Block current_block)override;
		BasicTypeData data;
	};

	class CommaExpressionTag :public ExpressionTag
	{
	public:
		CommaExpressionTag(size_t line, Expression  left,
			Expression  right);
		virtual Expression Fix(Block current_block)override;
		Expression  left;
		Expression  right;
	};

	class EvalExpressionTag :public ExpressionTag
	{
	public:
		using ExpressionTag::ExpressionTag;
		virtual void before_fix(Block current_block)
		{
		};
		virtual Boolean is_constant_probability() = 0;
		virtual Expression Fix(Block current_block)override;
		virtual ConstantExpression do_eval(Block current_block) = 0;
		virtual Expression do_fix(Block current_block) = 0;
	};

	class UnaryExpressionTag :public EvalExpressionTag
	{
	public:
		UnaryExpressionTag(size_t line, Expression operand);
		inline virtual Boolean is_constant_probability()override
		{
			return typeid(*(this->operand)) == typeid(ConstantExpressionTag);
		}
		virtual void UnaryExpressionTag::before_fix(Block current_block)override;
		virtual ConstantExpression try_eval(Block current_block, ConstantExpression coperand) = 0;
		virtual ConstantExpression do_eval(Block current_block);
		Expression operand;
	};

	class IncdecExpressionTag :public UnaryExpressionTag
	{
	public:
		IncdecExpressionTag(size_t line, Expression operand, IncdecExpressionOprator op);
		virtual Expression do_fix(Block current_block)override
		{
			return nullptr;
		}
		virtual ConstantExpression try_eval(Block current_block, ConstantExpression coperand)override
		{
			return nullptr;
		}
		IncdecExpressionOprator op;
	};

	class LogicalNotExpressionTag :public UnaryExpressionTag
	{
	public:
		LogicalNotExpressionTag(size_t line, Expression operand);
		virtual ConstantExpression try_eval(Block current_block, ConstantExpression coperand)override;
		virtual Expression do_fix(Block current_block)override;
	};

	class MinusExpressionTag :public UnaryExpressionTag
	{
	public:
		MinusExpressionTag(size_t line, Expression operand);
		virtual void before_fix(Block current_block)override;
		virtual ConstantExpression try_eval(Block current_block, ConstantExpression coperand)override;
		virtual Expression do_fix(Block current_block)override
		{
			this->type = this->operand->type;
			return this;
		}
	};

	class IndexExpressionTag :public ExpressionTag
	{
	public:
		IndexExpressionTag(size_t line, Expression array, Expression index);
		Expression array;
		Expression index;
	};

	class AssignExpresionTag :public ExpressionTag
	{
	public:
		AssignExpresionTag(size_t line, Expression left, AssignmentOperator _operator, Expression operand);
		virtual Expression Fix(Block current_block)override;
		Expression CreateAssignCast();
		Expression left;
		AssignmentOperator _operator;
		Expression operand;
	};

	class InvokeExpressionTag :public ExpressionTag
	{
	public:
		InvokeExpressionTag(size_t line, ArgumentList argument) :ExpressionTag(line)
		{
			this->argument = argument;
		}
		void check_argment()
		{

		}
		ArgumentList argument;
	};

	class FunctionCallExpressionTag :public InvokeExpressionTag
	{
	public:
		FunctionCallExpressionTag(size_t line, Expression function,
			ArgumentList        argument);
		virtual Expression Fix(Block current_block)override;
		Expression function;
	};

	class MethodCallExpressionTag :public InvokeExpressionTag
	{
	public:
		MethodCallExpressionTag(size_t line, Expression          expression,
			String identifier,
			ArgumentList        argument);
		Expression          expression;
		String identifier;
	};

	class IdentifierExpressionTag :public ExpressionTag
	{
	public:
		IdentifierExpressionTag(size_t line, String name);
		virtual Expression Fix(Block current_block)override;
		void FixPointToFunction(FunctionDefinition function);
		void FixPointToDeclaration(Declaration declaration);
		String name;
		IdentifierPointToType type;
		union IdentifierPointTo
		{
			FunctionDefinition function;
			Declaration declaration;
		}point_to_;
	};

	class BinaryExpressionTag :public EvalExpressionTag
	{
	public:
		BinaryExpressionTag(size_t line, Expression left, Expression right);
		inline Boolean is_constant_probability()
		{
			return typeid(*(this->right)) == typeid(ConstantExpressionTag) && typeid(*(this->left)) == typeid(ConstantExpressionTag);
		}
		virtual void before_fix(Block current_block)override;
		virtual void cast_fix(Block current_block)
		{
		};
		virtual Expression do_fix(Block current_block)
		{
			cast_fix(current_block);
			return determined_type(current_block);
		}
		virtual Expression determined_type(Block current_block) = 0;
		virtual ConstantExpression do_eval(Block current_block)override;
		virtual ConstantExpression try_eval(Block current_block, ConstantExpression cleft, ConstantExpression cright) = 0;
		Expression  left;
		Expression  right;
	};

	class MathBinaryExpressionTag :public BinaryExpressionTag
	{
	public:
		MathBinaryExpressionTag(size_t line, Expression left, MathBinaryExpressionOperator op, Expression right);
		virtual Expression determined_type(Block current_block)override;
		virtual	ConstantExpression try_eval(Block current_block, ConstantExpression cleft, ConstantExpression cright)override;
		virtual void cast_fix(Block b)override;
		MathBinaryExpressionOperator op;
	};

	class LogicBinaryExpressionTag :public BinaryExpressionTag
	{
	public:
		LogicBinaryExpressionTag(size_t line, Expression left, LogicBinaryExpressionOperator op, Expression right);
		virtual Expression determined_type(Block current_block)override;
		virtual ConstantExpression try_eval(Block current_block, ConstantExpression cleft, ConstantExpression cright)override;
		LogicBinaryExpressionOperator op;
	};

	class CompareBinaryExpressionTag :public BinaryExpressionTag
	{
	public:
		CompareBinaryExpressionTag(size_t line, Expression left, CompareBinaryExpressionOperator op, Expression right);
		virtual Expression determined_type(Block current_block)override;
		virtual ConstantExpression try_eval(Block current_block, ConstantExpression cleft, ConstantExpression cright)override;
		virtual void cast_fix(Block b)override;
		CompareBinaryExpressionOperator op;
	};

	class StatementTag :public AstObjectTag
	{
	public:
		StatementTag(size_t line);
		void virtual Fix(Block current_block, FunctionDefinition fd)
		{

		}
	private:
	};

	class ExpressionStatementTag :public StatementTag
	{
	public:
		ExpressionStatementTag(size_t line, Expression exception);
		void virtual Fix(Block current_block, FunctionDefinition fd)override
		{
			exception->Fix(current_block);
		}
		Expression exception;
	};

	class IfStatementTag :public StatementTag
	{
	public:
		IfStatementTag(size_t line, Expression condition, Block then_block, ElsifList elsif_list, Block else_block);
		Expression condition;
		Block then_block;
		ElsifList elsif_list;
		Block else_block;
	};

	class WhileStatementTag :public StatementTag
	{
	public:
		WhileStatementTag(size_t line, String label, Expression condition,
			Block block);
		String label;
		Expression condition;
		Block block;
	};

	class ForStatementTag :public StatementTag
	{
	public:
		ForStatementTag(size_t line, String label,
			Expression init,
			Expression condition,
			Expression post,
			Block block);
		String label;
		Expression init;
		Expression condition;
		Expression post;
		Block block;
	};

	class ReturnStatementTag :public StatementTag
	{
	public:
		ReturnStatementTag(size_t line, Expression return_value);
		Expression return_value;
	};

	class ForeachStatementTag :public StatementTag
	{
	public:
		ForeachStatementTag(size_t line, String label,
			String variable,
			Expression collection,
			Block block);
		String label;
		String variable;
		Expression collection;
		Block block;
	};

	class BreakStatementTag :public StatementTag
	{
	public:
		BreakStatementTag(
			size_t line,
			String label
		);
		String label;
	};

	class ContinueStatementTag :public StatementTag
	{
	public:
		ContinueStatementTag(size_t line, String label);
		String label;
	};

	class TryStatementTag :public StatementTag
	{
	public:
		TryStatementTag(size_t line,
			Block try_block,
			Block catch_block,
			String exception,
			Block finally_block);
		Block try_block;
		Block catch_block;
		String exception;
		Block finally_block;
	};

	class ThrowStatementTag :public StatementTag
	{
	public:
		ThrowStatementTag(size_t line, Expression expression);
	protected:
		Expression exception;
	};

	class DeclarationTag
	{
	public:
		DeclarationTag(String name, TypeSpecifier type, int variable_index);
		String name;
		TypeSpecifier type;
		Expression initializer;
		int variable_index;
		Boolean is_local;
	};

	class FunctionDefinitionTag
	{
	public:
		FunctionDefinitionTag(TypeSpecifier type, String name, ParameterList parameter, Block block);
		TypeSpecifier		type;
		String			name;
		ParameterList       parameter;
		Block				block;
		DeclarationList		local_variable;//no fix
		int                 index;

	};

	class BlockParentInfoTag
	{
	public:
		virtual void Fix(Block current_block)
		{

		}
	};

	class FunctionBlockInfoTag :public BlockParentInfoTag
	{
	public:
		inline FunctionBlockInfoTag(FunctionDefinition fd)
		{
			this->function = fd;
			this->end_label = 0;
		}
		FunctionDefinition  function;
		int         end_label;
	};

	class StatementBlockInfoTag :public BlockParentInfoTag
	{
	public:
		StatementBlockType type;
		inline StatementBlockInfoTag(StatementBlockType type, Statement statement)
		{
			this->type = type;
			this->statement = statement;
			this->continue_label = 0;
			this->break_label = 0;
		}
		Statement   statement;
		int         continue_label;
		int         break_label;
	};

	class BlockTag :public AstObjectTag
	{
	public:
		BlockTag(size_t line, Block outer_block);
		BlockParentInfo parent;
		Block				outer_block;
		StatementList       statement_list;
		DeclarationList     declaration_list;
	};

	class ElsifTag :public AstObjectTag
	{
	public:
		ElsifTag(size_t line, Expression condition, Block block);
		Expression  condition;
		Block       block;
	};

	class ParameterTag :public AstObjectTag
	{
	public:
		ParameterTag(size_t line, String name, TypeSpecifier type);
		String			name;
		TypeSpecifier       type;
	};

	class TypeDeriveTag
	{
	public:
	};

	class FunctionDeriveTag :public TypeDeriveTag
	{
	public:
		FunctionDeriveTag(ParameterList list);
		ParameterList       parameter_list;
	};

	class DeclarationStatementTag :public StatementTag
	{
	public:
		DeclarationStatementTag(size_t line, Declaration initializer);
		Declaration initializer;

	};
}

