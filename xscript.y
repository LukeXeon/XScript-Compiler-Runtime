%{
#include "yyinteface.h"

#define YYDEBUG 1
%}

%union
{
    UnityType          identifier;
	UnityType          parameter;
    UnityType		   parameter_list;
    UnityType          argument_list;
    UnityType          expression;
    UnityType          statement;
    UnityType          statement_list;
    UnityType          block;
	UnityType          elsif;
    UnityType          elsif_list;
    UnityType		   assignment_operator;
    UnityType          type_specifier;
}

%token <expression>     INT_LITERAL
%token <expression>     DOUBLE_LITERAL
%token <expression>     STRING_LITERAL
%token <expression>     REGEXP_LITERAL
%token <identifier>     IDENTIFIER
%token IF ELSE ELSIF WHILE FOR FOREACH RETURN_T BREAK CONTINUE
        _LP_ RP LC RC SEMICOLON COLON COMMA ASSIGN_T LOGICAL_AND LOGICAL_OR
        EQ NE GT GE LT LE ADD SUB MUL DIV MOD TRUE_T FALSE_T EXCLAMATION DOT
        ADD_ASSIGN_T SUB_ASSIGN_T MUL_ASSIGN_T DIV_ASSIGN_T MOD_ASSIGN_T
        INCREMENT DECREMENT TRY CATCH FINALLY THROW
        BOOLEAN_T INT_T DOUBLE_T STRING_T
%type   <parameter> parameter
%type   <parameter_list> parameter_list
%type   <argument_list> argument_list
%type   <expression> expression expression_opt
        assignment_expression logical_and_expression logical_or_expression
        equality_expression relational_expression
        additive_expression multiplicative_expression
        unary_expression postfix_expression primary_expression
%type   <statement> statement
        if_statement while_statement for_statement foreach_statement
        return_statement break_statement continue_statement try_statement
        throw_statement declaration_statement
%type   <statement_list> statement_list
%type   <block> block
%type   <elsif> elsif
%type   <elsif_list> elsif_list
%type   <assignment_operator> assignment_operator
%type   <identifier> identifier_opt label_opt
%type   <type_specifier> type_specifier
%%
translation_unit
        : definition_or_statement
        | translation_unit definition_or_statement
        ;
definition_or_statement
        : function_definition
        | statement
        {
            XsCompiler compiler = xs_get_current_compiler();
            compiler->statement_list = to_real_statement_list(chain_statement_list(compiler->statement_list, $1));
        }
        ;
type_specifier
        : BOOLEAN_T
        {
            $$ = XvmBasicType::Boolean;
        }
        | INT_T
        {
            $$ = XvmBasicType::Int32;
        }
        | DOUBLE_T
        {
            $$ = XvmBasicType::Double;
        }
        | STRING_T
        {
            $$ = XvmBasicType::String;
        }
        ;
function_definition
        : type_specifier IDENTIFIER _LP_ parameter_list RP block
        {
            function_define($1, $2, $4, $6);
        }
        | type_specifier IDENTIFIER _LP_ RP block
        {
            function_define($1, $2, nullptr, $5);
        }
        | type_specifier IDENTIFIER _LP_ parameter_list RP SEMICOLON
        {
            function_define($1, $2, $4, nullptr);
        }
        | type_specifier IDENTIFIER _LP_ RP SEMICOLON
        {
            function_define($1, $2, nullptr, nullptr);
        }
        ;
parameter_list
        : parameter
        {
            $$ = create_parameter_list($1);
        }
        | parameter_list COMMA type_specifier IDENTIFIER
        {
            $$ = chain_parameter($1,create_parameter($3, $4));
        }
        ;
parameter
		: type_specifier IDENTIFIER
        {
            $$ = create_parameter($1, $2);
        }
argument_list
        : assignment_expression
        {
            $$ = create_argument_list($1);
        }
        | argument_list COMMA assignment_expression
        {
            $$ = chain_argument_list($1, $3);
        }
        ;
statement_list
        : statement
        {
            $$ = create_statement_list($1);
        }
        | statement_list statement
        {
            $$ = chain_statement_list($1, $2);
        }
        ;
expression
        : assignment_expression
        | expression COMMA assignment_expression
        {
            $$ = create_comma_expression($1, $3);
        }
        ;
assignment_expression
        : logical_or_expression
        | postfix_expression assignment_operator assignment_expression
        {
            $$ = create_assign_expression($1,$2, $3);
        }
        ;
assignment_operator
        : ASSIGN_T
        {
            $$ = AssignmentOperator::NomalAssign;
        }
        | ADD_ASSIGN_T
        {
            $$ = AssignmentOperator::AddAssign;
        }
        | SUB_ASSIGN_T
        {
            $$ = AssignmentOperator::SubAssign;
        }
        | MUL_ASSIGN_T
        {
            $$ = AssignmentOperator::MulAssign;
        }
        | DIV_ASSIGN_T
        {
            $$ = AssignmentOperator::DivAssign;
        }
        | MOD_ASSIGN_T
        {
            $$ = AssignmentOperator::ModAssign;
        }
        ;
logical_or_expression
        : logical_and_expression
        | logical_or_expression LOGICAL_OR logical_and_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Or, $1, $3);
        }
        ;
logical_and_expression
        : equality_expression
        | logical_and_expression LOGICAL_AND equality_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::And, $1, $3);
        }
        ;
equality_expression
        : relational_expression
        | equality_expression EQ relational_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Eq, $1, $3);
        }
        | equality_expression NE relational_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Ne, $1, $3);
        }
        ;
relational_expression
        : additive_expression
        | relational_expression GT additive_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Gt, $1, $3);
        }
        | relational_expression GE additive_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Ge, $1, $3);
        }
        | relational_expression LT additive_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Lt, $1, $3);
        }
        | relational_expression LE additive_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Le, $1, $3);
        }
        ;
additive_expression
        : multiplicative_expression
        | additive_expression ADD multiplicative_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Add, $1, $3);
        }
        | additive_expression SUB multiplicative_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Sub, $1, $3);
        }
        ;
multiplicative_expression
        : unary_expression
        | multiplicative_expression MUL unary_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Mul, $1, $3);
        }
        | multiplicative_expression DIV unary_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Div, $1, $3);
        }
        | multiplicative_expression MOD unary_expression
        {
            $$ = create_binary_expression(BinaryExpressionOperator::Mod, $1, $3);
        }
        ;
unary_expression
        : postfix_expression
        | SUB unary_expression
        {
            $$ = create_minus_expression($2);
        }
        | EXCLAMATION unary_expression
        {
            $$ = create_logical_not_expression($2);
        }
        ;
postfix_expression
        : primary_expression
        | postfix_expression _LP_ argument_list RP
        {
            $$ = create_function_call_expression($1, $3);
        }
        | postfix_expression _LP_ RP
        {
            $$ = create_function_call_expression($1, nullptr);
        }
        | postfix_expression INCREMENT
        {
            $$ = create_incdec_expression($1, IncdecExpressionOprator::Increment);
        }
        | postfix_expression DECREMENT
        {
            $$ = create_incdec_expression($1, IncdecExpressionOprator::Decrement);
        }
        ;
primary_expression
        : _LP_ expression RP
        {
            $$ = $2;
        }
        | IDENTIFIER
        {
            $$ = create_identifier_expression($1);
        }
        | INT_LITERAL
        | DOUBLE_LITERAL
        | STRING_LITERAL
        | REGEXP_LITERAL
        | TRUE_T
        {
            $$ = create_boolean_expression((true));
        }
        | FALSE_T
        {
            $$ = create_boolean_expression((false));
        }
        ;
statement
        : expression SEMICOLON
        {
          $$ = create_expression_statement($1);
        }
        | if_statement
        | while_statement
        | for_statement
        | foreach_statement
        | return_statement
        | break_statement
        | continue_statement
        | try_statement
        | throw_statement
        | declaration_statement
        ;
if_statement
        : IF _LP_ expression RP block
        {
            $$ = create_if_statement($3, $5, nullptr, nullptr);
        }
        | IF _LP_ expression RP block ELSE block
        {
            $$ = create_if_statement($3, $5, nullptr, $7);
        }
        | IF _LP_ expression RP block elsif_list
        {
            $$ = create_if_statement($3, $5, $6, nullptr);
        }
        | IF _LP_ expression RP block elsif_list ELSE block
        {
            $$ = create_if_statement($3, $5, $6, $8);
        }
        ;
elsif_list
        : elsif
		{
			$$ = create_elsif_lsit($1);		
		}
        | elsif_list elsif
        {
            $$ = chain_elsif_list($1, $2);
        }
        ;
elsif
        : ELSIF _LP_ expression RP block
        {
            $$ = create_elsif($3, $5);
        }
        ;
label_opt
        : /* empty */
        {
            $$ = nullptr;
        }
        | IDENTIFIER COLON
        {
            $$ = $1;
        }
        ;
while_statement
        : label_opt WHILE _LP_ expression RP block
        {
            $$ = create_while_statement($1, $4, $6);
        }
        ;
for_statement
        : label_opt FOR _LP_ expression_opt SEMICOLON expression_opt SEMICOLON
          expression_opt RP block
        {
            $$ = create_for_statement($1, $4, $6, $8, $10);
        }
        ;
foreach_statement
        : label_opt FOREACH _LP_ IDENTIFIER COLON expression RP block
        {
            $$ = create_foreach_statement($1, $4, $6, $8);
        }
        ;
expression_opt
        : /* empty */
        {
            $$ = nullptr;
        }
        | expression
        ;
return_statement
        : RETURN_T expression_opt SEMICOLON
        {
            $$ = create_return_statement($2);
        }
        ;
identifier_opt
        : /* empty */
        {
            $$ = nullptr;
        }
        | IDENTIFIER
        ;
break_statement 
        : BREAK identifier_opt SEMICOLON
        {
            $$ = create_break_statement($2);
        }
        ;
continue_statement
        : CONTINUE identifier_opt SEMICOLON
        {
            $$ = create_continue_statement($2);
        }
        ;
try_statement
        : TRY block CATCH _LP_ IDENTIFIER RP block FINALLY block
        {
            $$ = create_try_statement($2, $5, $7, $9);
        }
        | TRY block FINALLY block
        {
            $$ = create_try_statement($2, nullptr, nullptr, $4);
        }
        | TRY block CATCH _LP_ IDENTIFIER RP block
        {
            $$ = create_try_statement($2, $5, $7, nullptr);
        }
throw_statement
        : THROW expression SEMICOLON
        {
            $$ = create_throw_statement($2);
        }
declaration_statement
        : type_specifier IDENTIFIER SEMICOLON
        {
            $$ = create_declaration_statement($1, $2, nullptr);
        }
        | type_specifier IDENTIFIER ASSIGN_T expression SEMICOLON
        {
            $$ = create_declaration_statement($1, $2, $4);
        }
        ;
block
        : LC
        {
            $<block>$ = open_block();
        }
          statement_list RC
        {
            $<block>$ = close_block($<block>2, $3);
        }
        | LC RC
        {
            Block empty_block = xs_open_block();
            $<block>$ = close_block(empty_block, nullptr);
        }
        ;
%%