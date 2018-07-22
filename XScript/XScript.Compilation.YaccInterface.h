#pragma once
#include "stdafx.h"
#include "XScript.Compilation.Ast.h"
#define register 
using namespace XScript::Compilation::Ast;
typedef String Identifier;
void XScriptCall AppendToStringBuffer(const char letter);

String XScriptCall FlushStringBuffer();

String XScriptCall CreateIdentifier(const char *str);

namespace XScript::Compilation::YaccInterface
{
	DeclarationList XScriptCall ChainDeclarationList(DeclarationList list, Declaration decl);

	TypeSpecifier XScriptCall CreateTypeSpecifier(BasicType type);

	void XScriptCall AddFunctionDefine(BasicType type, String identifier, ParameterList parameter_list, Block block);

	Parameter XScriptCall CreateParameter(BasicType type, String identifier);

	ParameterList XScriptCall CreateParameterList(Parameter pram);

	ParameterList XScriptCall ChainParameter(ParameterList list, Parameter p);

	ArgumentList XScriptCall CreateArgumentList(Expression expression);

	ArgumentList XScriptCall ChainArgumentList(ArgumentList list, Argument alg);

	StatementList XScriptCall CreateStatementList(Statement statement);

	StatementList XScriptCall ChainStatementList(StatementList list, Statement statement);

	CommaExpression XScriptCall CreateCommaExpression(Expression left, Expression right);

	AssignExpresion XScriptCall CreateAssignExpression(Expression left, AssignmentOperator _operator, Expression operand);

	BinaryExpression XScriptCall CreateMathBinaryExpression(MathBinaryExpressionOperator _operator, Expression left, Expression right);

	BinaryExpression XScriptCall CreateCompareBinaryExpression(CompareBinaryExpressionOperator _operator, Expression left, Expression right);

	BinaryExpression XScriptCall CreateLogicBinaryExpression(LogicBinaryExpressionOperator _operator, Expression left, Expression right);

	MinusExpression XScriptCall CreateMinusExpression(Expression operand);

	LogicalNotExpression XScriptCall CreateLogicalNotExpression(Expression operand);

	IncdecExpression XScriptCall CreateIncDecExpression(Expression operand, IncDecExpressionOprator inc_or_dec);

	IdentifierExpression XScriptCall CreateIdentifierExpression(String identifier);

	FunctionCallExpression XScriptCall CreateFunctionCallExpression(Expression function, ArgumentList argument);

	ConstantExpression XScriptCall CreateBooleanExpression(Boolean value);

	ConstantExpression XScriptCall CreateInt32Expression(Int32 value);

	ConstantExpression XScriptCall CreateDoubleExpression(Double value);

	ConstantExpression XScriptCall CreateStringExpression(String value);

	IfStatement XScriptCall CreateIfStatement(Expression condition, Block then_block, ElsifList elsif_list, Block else_block);

	ElsifList XScriptCall ChainElsifList(ElsifList list, Elsif add);

	Elsif XScriptCall CreateElsif(Expression expr, Block block);

	WhileStatement XScriptCall CreateWhileStatement(String label, Expression condition, Block block);

	ForStatement XScriptCall CreateForStatement(String label, Expression init, Expression cond, Expression post, Block block);

	ForeachStatement XScriptCall CreateForeachStatement(String label, String variable, Expression collection, Block block);

	Block XScriptCall OpenBlock();

	Block XScriptCall CloseBlock(Block block, StatementList statement_list);

	ExpressionStatement XScriptCall CreateExpressionStatement(Expression expression);

	ReturnStatement XScriptCall CreateReturnStatement(Expression expression);

	BreakStatement XScriptCall CreateBreakStatement(String label);

	ContinueStatement XScriptCall CreateContinueStatement(String label);

	TryStatement XScriptCall CreateTryStatement(Block try_block, String exception, Block catch_block, Block finally_block);

	ThrowStatement XScriptCall CreateThrowStatement(Expression expression);

	DeclarationStatement XScriptCall CreateDeclarationStatement(BasicType type, String identifier, Expression initializer);

	ElsifList XScriptCall CreateElsifLsit(Elsif elsif);

}
using namespace XScript::Compilation::YaccInterface;
