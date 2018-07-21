#include "stdafx.h"
#include "XScript.Memory.h"
#include "XScript.Compilation.Ast.h"
#include "XScript.Compilation.Errors.h"
#include "XScript.Compilation.YaccInterface.h"
#include "XScript.Compilation.h"
#include "XScript.DebugTools.h"
using namespace XScript::Compilation;
using namespace XScript::Compilation::Errors;
using namespace XScript::Memory;
using namespace XScript::Compilation::Ast;

template<typename _Ty, typename... _Types>
static inline typename _Ty  * XScriptCall NewPointerShowLine(_Types&&... _Args)
{
	auto xs_compiler = GetCurrentCompiler();
	assert(xs_compiler->current_memory != nullptr);
#ifdef _DEBUG
	wcout << L"in line : " << xs_compiler->current_line_number << L" ¡ú stotage alloc type ¡ý\n          ";
	cout << typeid(_Ty).name() << endl;
#endif // _DEBUG
	return	xs_compiler->current_memory->NewPointer<_Ty>(std::forward<_Types>(_Args)...);
}

template<typename _Ty>
static inline typename list<_Ty>* XScriptCall CreateList(typename _Ty src)
{
	auto li = NewPointerShowLine<std::list<_Ty>>();
	li->push_back(src);
	return li;
}

template<typename _Ty>
static inline typename list<_Ty>* XScriptCall ChainList(typename list<_Ty>* list, _Ty arg)
{
	if (list == nullptr)
	{
		list = CreateList<_Ty>(arg);
	}
	else
	{
		list->push_back(arg);
	}
	return list;
}

static std::string&GetStringBuffer()
{
	static std::string buffer;
	return buffer;
}

void XScriptCall AppendToStringBuffer(const char letter)
{
	GetStringBuffer() += letter;
}

String XScriptCall FlushStringBuffer()
{
	String raw = GetCurrentCompiler()->string_pool->CreateFromMultiByte(GetStringBuffer().c_str());
	GetStringBuffer().clear();
	return raw;
}

String XScriptCall CreateIdentifier(const char * str)
{
	return GetCurrentCompiler()->string_pool->CreateFromMultiByte(str);
}

namespace XScript::Compilation::YaccInterface
{
	DeclarationList XScriptCall
		xs_chain_declaration(DeclarationList list, Declaration decl)
	{
		return	ChainList(list, decl);
	}

	TypeSpecifier XScriptCall
		xs_alloc_type_specifier(BasicType type)
	{
		TypeSpecifier ts = NewPointerShowLine<TypeSpecifierTag>(type, nullptr);
		return ts;
	}

	static FunctionDefinition XScriptCall
		create_function_definition(BasicType type, String identifier,
			ParameterList parameter_list, Block block)
	{
		FunctionDefinition fd = NewPointerShowLine<FunctionDefinitionTag>(
			xs_alloc_type_specifier(type),
			identifier,
			parameter_list,
			block);
		return fd;
	}

	void XScriptCall
		xs_function_define(BasicType type, String identifier,
			ParameterList parameter_list, Block block)
	{
		Compiler com = GetCurrentCompiler();
		if (com->SearchFunction(identifier)
			|| com->SearchDeclaration(identifier, nullptr))
		{
			FunctionMultipleDefine(GetCurrentCompiler()->current_line_number, identifier);
			return;
		}
		FunctionDefinition	fd = create_function_definition(type, identifier, parameter_list,
			block);
		if (block)
		{
			FunctionBlockInfo finfo = NewPointerShowLine<FunctionBlockInfoTag>(fd);
			block->parent = finfo;
		}
		com->AppendFunction(fd);
	}

	Parameter XScriptCall
		xs_create_parameter(BasicType type, String identifier)
	{
		Parameter p = NewPointerShowLine<ParameterTag>(GetCurrentLineNumber(), identifier, xs_alloc_type_specifier(type));
		return p;
	}

	ParameterList XScriptCall
		xs_create_parameter_list(Parameter pram)
	{
		return	CreateList(pram);
	}

	ParameterList XScriptCall
		xs_chain_parameter(ParameterList list, Parameter p)
	{
		return ChainList(list, p);
	}

	ArgumentList XScriptCall
		xs_create_argument_list(Expression expression)
	{
		return CreateList(expression);
	}

	ArgumentList XScriptCall
		xs_chain_argument_list(ArgumentList list, Argument alg)
	{
		return ChainList(list, alg);
	}

	StatementList XScriptCall
		xs_create_statement_list(Statement statement)
	{
		return CreateList(statement);
	}


	StatementList XScriptCall
		xs_chain_statement_list(StatementList list, Statement statement)
	{
		return ChainList(list, statement);
	}


	CommaExpression XScriptCall
		xs_create_comma_expression(Expression left, Expression right)
	{
		CommaExpression exp = NewPointerShowLine<CommaExpressionTag>(GetCurrentLineNumber(), left, right);
		return exp;
	}

	AssignExpresion XScriptCall
		xs_create_assign_expression(Expression left, AssignmentOperator _operator,
			Expression operand)
	{
		AssignExpresion exp = NewPointerShowLine<AssignExpresionTag>(GetCurrentLineNumber(), left, _operator, operand);
		return exp;
	}

	BinaryExpression XScriptCall
		xs_create_math_binary_expression(MathBinaryExpressionOperator _operator,
			Expression left, Expression right)
	{
		switch (_operator)
		{
		case MathBinaryExpressionOperator::Add:
		case MathBinaryExpressionOperator::Mul:
		case MathBinaryExpressionOperator::Div:
		case MathBinaryExpressionOperator::Sub:
		case MathBinaryExpressionOperator::Mod:
		{
			return NewPointerShowLine<MathBinaryExpressionTag>(GetCurrentLineNumber(), left, _operator, right);
		}break;
		default:
			assert(0);
			break;
		}
		return nullptr;
	}

	BinaryExpression XScriptCall
		xs_create_compare_binary_expression(CompareBinaryExpressionOperator _operator,
			Expression left, Expression right)
	{
		switch (_operator)
		{
		case CompareBinaryExpressionOperator::Eq:
		case CompareBinaryExpressionOperator::Ne:
		case CompareBinaryExpressionOperator::Gt:
		case CompareBinaryExpressionOperator::Ge:
		case CompareBinaryExpressionOperator::Lt:
		case CompareBinaryExpressionOperator::Le:
		{
			return NewPointerShowLine<CompareBinaryExpressionTag>(GetCurrentLineNumber(), left, _operator, right);
		}break;
		default:
			assert(0);
			break;
		}
		return nullptr;
	}

	BinaryExpression XScriptCall
		xs_create_logic_binary_expression(LogicBinaryExpressionOperator _operator,
			Expression left, Expression right)
	{
		switch (_operator)
		{
		case LogicBinaryExpressionOperator::Or:
		case LogicBinaryExpressionOperator::And:
		{
			return NewPointerShowLine<LogicBinaryExpressionTag>(GetCurrentLineNumber(), left, _operator, right);
		}break;
		default:
			assert(0);
			break;
		}
		return nullptr;
	}

	MinusExpression XScriptCall
		xs_create_minus_expression(Expression operand)
	{
		MinusExpression exp = NewPointerShowLine<MinusExpressionTag>(GetCurrentLineNumber(), operand);
		return exp;
	}

	LogicalNotExpression XScriptCall
		xs_create_logical_not_expression(Expression operand)
	{
		LogicalNotExpression exp = NewPointerShowLine<LogicalNotExpressionTag>(GetCurrentLineNumber(), operand);
		return exp;
	}

	IncdecExpression XScriptCall
		xs_create_incdec_expression(Expression operand, IncdecExpressionOprator inc_or_dec)
	{
		IncdecExpression exp = NewPointerShowLine<IncdecExpressionTag>(GetCurrentLineNumber(), operand, inc_or_dec);
		return exp;
	}

	IdentifierExpression XScriptCall
		xs_create_identifier_expression(String identifier)
	{
		IdentifierExpression exp = NewPointerShowLine<IdentifierExpressionTag>(GetCurrentLineNumber(), identifier);
		return exp;
	}

	FunctionCallExpression XScriptCall
		xs_create_function_call_expression(Expression function,
			ArgumentList argument)
	{
		FunctionCallExpression  exp = NewPointerShowLine<FunctionCallExpressionTag>(GetCurrentLineNumber(), function, argument);
		return exp;
	}

	ConstantExpression XScriptCall
		xs_create_boolean_expression(Boolean value)
	{
		BasicTypeData v;
		v.boolean_v = value;
		ConstantExpression exp = NewPointerShowLine<ConstantExpressionTag>(GetCurrentLineNumber(), BasicType::Boolean, v);
		return exp;
	}

	ConstantExpression XScriptCall
		xs_create_int32_expression(Int32 value)
	{
		BasicTypeData v;
		v.boolean_v = value;
		ConstantExpression exp = NewPointerShowLine<ConstantExpressionTag>(GetCurrentLineNumber(), BasicType::Int32, v);
		return exp;
	}

	ConstantExpression XScriptCall
		xs_create_double_expression(Double value)
	{
		BasicTypeData v;
		v.double_v = value;
		ConstantExpression exp = NewPointerShowLine<ConstantExpressionTag>(GetCurrentLineNumber(), BasicType::Double, v);
		return exp;
	}

	ConstantExpression XScriptCall
		xs_create_string_expression(String value)
	{
		BasicTypeData v;
		v.string_v = value;
		ConstantExpression exp = NewPointerShowLine<ConstantExpressionTag>(GetCurrentLineNumber(), BasicType::String, v);
		return exp;
	}

	IfStatement XScriptCall
		xs_create_if_statement(Expression condition,
			Block then_block, ElsifList elsif_list,
			Block else_block)
	{
		IfStatement st = NewPointerShowLine<IfStatementTag>(GetCurrentLineNumber(), condition, then_block, elsif_list, else_block);
		return st;
	}

	ElsifList XScriptCall
		xs_chain_elsif_list(ElsifList list, Elsif add)
	{
		return ChainList(list, add);
	}


	Elsif XScriptCall
		xs_create_elsif(Expression expr, Block block)
	{
		Elsif e = NewPointerShowLine<ElsifTag>(GetCurrentLineNumber(), expr, block);
		return e;
	}

	WhileStatement XScriptCall
		xs_create_while_statement(String label,
			Expression condition, Block block)
	{
		WhileStatement st = NewPointerShowLine<WhileStatementTag>(GetCurrentLineNumber(), label, condition, block);
		//block->parent =new StatementBlockInfo(){ st,0,0 };
		StatementBlockInfo stinfo = NewPointerShowLine<StatementBlockInfoTag>(StatementBlockType::WhileStatementBlock, st);
		block->parent = stinfo;
		return st;
	}

	ForStatement XScriptCall
		xs_create_for_statement(String label, Expression init, Expression cond,
			Expression post, Block block)
	{
		ForStatement st = NewPointerShowLine<ForStatementTag>(GetCurrentLineNumber(), label, init, cond, post, block);
		StatementBlockInfo stinfo = NewPointerShowLine<StatementBlockInfoTag>(StatementBlockType::ForStatamentBlock, st);
		block->parent = stinfo;
		return st;
	}

	ForeachStatement XScriptCall
		xs_create_foreach_statement(String label, String variable,
			Expression collection, Block block)
	{
		ForeachStatement st = NewPointerShowLine<ForeachStatementTag>(GetCurrentLineNumber(), label, variable, collection, block);
		//	block->type = BlockType::ForeachStatamentBlock;
		//	block->parent.statement = st;
		return st;
	}

	Block XScriptCall
		xs_open_block()
	{
		Compiler Compilation = GetCurrentCompiler();
		Block new_block = NewPointerShowLine<BlockTag>(GetCurrentLineNumber(), Compilation->current_block);
		Compilation->current_block = new_block;
		return new_block;
	}

	Block XScriptCall
		xs_close_block(Block block, StatementList statement_list)
	{
		Compiler Compilation = GetCurrentCompiler();

		DebugerAssert(block == Compilation->current_block,
			("block mismatch.\n"));
		block->statement_list = statement_list;
		Compilation->current_block = block->outer_block;
		return block;
	}

	ExpressionStatement XScriptCall
		xs_create_expression_statement(Expression expression)
	{
		ExpressionStatement st = NewPointerShowLine<ExpressionStatementTag>(GetCurrentLineNumber(), expression);
		return st;
	}

	ReturnStatement XScriptCall
		xs_create_return_statement(Expression expression)
	{
		ReturnStatement st = NewPointerShowLine<ReturnStatementTag>(GetCurrentLineNumber(), expression);
		return st;
	}

	BreakStatement XScriptCall
		xs_create_break_statement(String label)
	{
		BreakStatement st = NewPointerShowLine<BreakStatementTag>(GetCurrentLineNumber(), label);
		return st;
	}

	ContinueStatement XScriptCall
		xs_create_continue_statement(String label)
	{
		ContinueStatement st = NewPointerShowLine<ContinueStatementTag>(GetCurrentLineNumber(), label);
		return st;
	}

	TryStatement XScriptCall
		xs_create_try_statement(Block try_block, String exception,
			Block catch_block, Block finally_block)
	{
		TryStatement st = NewPointerShowLine<TryStatementTag>(GetCurrentLineNumber(), try_block, catch_block, exception, finally_block);
		return st;
	}

	ThrowStatement XScriptCall
		xs_create_throw_statement(Expression expression)
	{
		ThrowStatement st = NewPointerShowLine<ThrowStatementTag>(GetCurrentLineNumber(), expression);
		return st;
	}

	DeclarationStatement XScriptCall
		xs_create_declaration_statement(BasicType type, String identifier,
			Expression initializer)
	{
		Declaration decl = NewPointerShowLine<DeclarationTag>(identifier, xs_alloc_type_specifier(type), -1);
		DeclarationStatement st = NewPointerShowLine<DeclarationStatementTag>(GetCurrentLineNumber(), decl);
		return st;
	}

	ElsifList XScriptCall
		xs_create_elsif_lsit(Elsif elsif)
	{
		return CreateList(elsif);
	}
}
