#pragma once
#include "stdafx.h"
#include "XScript.Compilation.Ast.h"
using namespace XScript::Compilation::Ast;
typedef String Identifier;
void XScriptCall
AppendToStringBuffer(const char letter);

String XScriptCall
FlushStringBuffer();

String XScriptCall
CreateIdentifier(const char *str);

namespace XScript::Compilation::YaccInterface
{
	DeclarationList XScriptCall xs_chain_declaration(DeclarationList list, Declaration decl);

	TypeSpecifier XScriptCall xs_alloc_type_specifier(BasicType type);

	void XScriptCall xs_function_define(BasicType type, String identifier, ParameterList parameter_list, Block block);

	Parameter XScriptCall xs_create_parameter(BasicType type, String identifier);

	ParameterList XScriptCall xs_create_parameter_list(Parameter pram);

	ParameterList XScriptCall xs_chain_parameter(ParameterList list, Parameter p);

	ArgumentList XScriptCall xs_create_argument_list(Expression expression);

	ArgumentList XScriptCall xs_chain_argument_list(ArgumentList list, Argument alg);

	StatementList XScriptCall xs_create_statement_list(Statement statement);

	StatementList XScriptCall xs_chain_statement_list(StatementList list, Statement statement);

	CommaExpression XScriptCall xs_create_comma_expression(Expression left, Expression right);

	AssignExpresion XScriptCall xs_create_assign_expression(Expression left, AssignmentOperator _operator, Expression operand);

	BinaryExpression XScriptCall xs_create_math_binary_expression(MathBinaryExpressionOperator _operator, Expression left, Expression right);

	BinaryExpression XScriptCall xs_create_compare_binary_expression(CompareBinaryExpressionOperator _operator, Expression left, Expression right);

	BinaryExpression XScriptCall xs_create_logic_binary_expression(LogicBinaryExpressionOperator _operator, Expression left, Expression right);

	MinusExpression XScriptCall xs_create_minus_expression(Expression operand);

	LogicalNotExpression XScriptCall xs_create_logical_not_expression(Expression operand);

	IncdecExpression XScriptCall xs_create_incdec_expression(Expression operand, IncdecExpressionOprator inc_or_dec);

	IdentifierExpression XScriptCall xs_create_identifier_expression(String identifier);

	FunctionCallExpression XScriptCall xs_create_function_call_expression(Expression function, ArgumentList argument);

	ConstantExpression XScriptCall xs_create_boolean_expression(Boolean value);

	ConstantExpression XScriptCall xs_create_int32_expression(Int32 value);

	ConstantExpression XScriptCall xs_create_double_expression(Double value);

	ConstantExpression XScriptCall xs_create_string_expression(String value);

	IfStatement XScriptCall xs_create_if_statement(Expression condition, Block then_block, ElsifList elsif_list, Block else_block);

	ElsifList XScriptCall xs_chain_elsif_list(ElsifList list, Elsif add);

	Elsif XScriptCall xs_create_elsif(Expression expr, Block block);

	WhileStatement XScriptCall xs_create_while_statement(String label, Expression condition, Block block);

	ForStatement XScriptCall xs_create_for_statement(String label, Expression init, Expression cond, Expression post, Block block);

	ForeachStatement XScriptCall xs_create_foreach_statement(String label, String variable, Expression collection, Block block);

	Block XScriptCall xs_open_block();

	Block XScriptCall xs_close_block(Block block, StatementList statement_list);

	ExpressionStatement XScriptCall xs_create_expression_statement(Expression expression);

	ReturnStatement XScriptCall xs_create_return_statement(Expression expression);

	BreakStatement XScriptCall xs_create_break_statement(String label);

	ContinueStatement XScriptCall xs_create_continue_statement(String label);

	TryStatement XScriptCall xs_create_try_statement(Block try_block, String exception, Block catch_block, Block finally_block);

	ThrowStatement XScriptCall xs_create_throw_statement(Expression expression);

	DeclarationStatement XScriptCall xs_create_declaration_statement(BasicType type, String identifier, Expression initializer);

	ElsifList XScriptCall xs_create_elsif_lsit(Elsif elsif);

}
using namespace XScript::Compilation::YaccInterface;
