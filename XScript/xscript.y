%{

#define YYDEBUG 1
%}

%union
{
    Identifier                 identifier;
	Parameter                  parameter;
    ParameterList		       parameter_list;
    ArgumentList               argument_list;
    Expression                 expression;
    Statement                  statement;
    StatementList              statement_list;
    Block                      block;
	Elsif					   elsif;
    ElsifList				   elsif_list;
    AssignmentOperator		   assignment_operator;
    XvmBasicType			   type_specifier;
}

%token <expression>     _IntLiteral_
%token <expression>     _DoubleLiteral_
%token <expression>     _StringLiteral_
%token <expression>     _RegexpLiteral_
%token <identifier>     _Identifier_
%token _If_ _Else_ _Elseif_ _While_ _For_ _Foreach_ _Return_ _Break_ _Continue_
        _Lp_ _Rp_ _Lc_ _Rc_ _Semicolon_ _Colon_ _Comma_ _Assign_ _LogicalAnd_ _LogicalOr_
        _Eq_ _Ne_ _Gt_ _Ge_ _Lt_ _Le_ _Add_ _Sub_ _Mul_ _Div_ _Mod_ _True_ _False_ _Exclamation_ _Dot_
        _AddAssign_ _SubAssign_ _MulAssign_ _DivAssign_ _ModAssign_
        _Increment_ _Decrement_ _Try_ _Catch_ _Finally_ _Throw_
        _Boolean_ _Int_ _Double_ _String_
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
            compiler->statement_list = xs_chain_statement_list(compiler->statement_list, $1);
        }
        ;
type_specifier
        : _Boolean_
        {
            $$ = XvmBasicType::Boolean;
        }
        | _Int_
        {
            $$ = XvmBasicType::Int32;
        }
        | _Double_
        {
            $$ = XvmBasicType::Double;
        }
        | _String_
        {
            $$ = XvmBasicType::String;
        }
        ;
function_definition
        : type_specifier _Identifier_ _Lp_ parameter_list _Rp_ block
        {
            xs_function_define($1, $2, $4, $6);
        }
        | type_specifier _Identifier_ _Lp_ _Rp_ block
        {
            xs_function_define($1, $2, nullptr, $5);
        }
        | type_specifier _Identifier_ _Lp_ parameter_list _Rp_ _Semicolon_
        {
           xs_function_define($1, $2, $4, nullptr);
        }
        | type_specifier _Identifier_ _Lp_ _Rp_ _Semicolon_
        {
           xs_function_define($1, $2, nullptr, nullptr);
        }
        ;
parameter_list
        : parameter
        {
            $$ = xs_create_parameter_list($1);
        }
        | parameter_list _Comma_ type_specifier _Identifier_
        {
            $$ = xs_chain_parameter($1,xs_create_parameter($3, $4));
        }
        ;
parameter
		: type_specifier _Identifier_
        {
            $$ = xs_create_parameter($1, $2);
        }
argument_list
        : assignment_expression
        {
            $$ = xs_create_argument_list($1);
        }
        | argument_list _Comma_ assignment_expression
        {
            $$ = xs_chain_argument_list($1, $3);
        }
        ;
statement_list
        : statement
        {
            $$ = xs_create_statement_list($1);
        }
        | statement_list statement
        {
            $$ = xs_chain_statement_list($1, $2);
        }
        ;
expression
        : assignment_expression
        | expression _Comma_ assignment_expression
        {
            $$ = xs_create_comma_expression($1, $3);
        }
        ;
assignment_expression
        : logical_or_expression
        | postfix_expression assignment_operator assignment_expression
        {
            $$ = xs_create_assign_expression($1,$2, $3);
        }
        ;
assignment_operator
        : _Assign_
        {
            $$ = AssignmentOperator::NomalAssign;
        }
        | _AddAssign_
        {
            $$ = AssignmentOperator::AddAssign;
        }
        | _SubAssign_
        {
            $$ = AssignmentOperator::SubAssign;
        }
        | _MulAssign_
        {
            $$ = AssignmentOperator::MulAssign;
        }
        | _DivAssign_
        {
            $$ = AssignmentOperator::DivAssign;
        }
        | _ModAssign_
        {
            $$ = AssignmentOperator::ModAssign;
        }
        ;
logical_or_expression
        : logical_and_expression
        | logical_or_expression _LogicalOr_ logical_and_expression
        {
            $$ = xs_create_logic_binary_expression(LogicBinaryExpressionOperator::Or, $1, $3);
        }
        ;
logical_and_expression
        : equality_expression
        | logical_and_expression _LogicalAnd_ equality_expression
        {
            $$ = xs_create_logic_binary_expression(LogicBinaryExpressionOperator::And, $1, $3);
        }
        ;
equality_expression
        : relational_expression
        | equality_expression _Eq_ relational_expression
        {
            $$ = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Eq, $1, $3);
        }
        | equality_expression _Ne_ relational_expression
        {
            $$ = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Ne, $1, $3);
        }
        ;
relational_expression
        : additive_expression
        | relational_expression _Gt_ additive_expression
        {
            $$ = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Gt, $1, $3);
        }
        | relational_expression _Ge_ additive_expression
        {
            $$ = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Ge, $1, $3);
        }
        | relational_expression _Lt_ additive_expression
        {
            $$ = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Lt, $1, $3);
        }
        | relational_expression _Le_ additive_expression
        {
            $$ = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Le, $1, $3);
        }
        ;
additive_expression
        : multiplicative_expression
        | additive_expression _Add_ multiplicative_expression
        {
            $$ = xs_create_math_binary_expression(MathBinaryExpressionOperator::Add, $1, $3);
        }
        | additive_expression _Sub_ multiplicative_expression
        {
            $$ = xs_create_math_binary_expression(MathBinaryExpressionOperator::Sub, $1, $3);
        }
        ;
multiplicative_expression
        : unary_expression
        | multiplicative_expression _Mul_ unary_expression
        {
            $$ = xs_create_math_binary_expression(MathBinaryExpressionOperator::Mul, $1, $3);
        }
        | multiplicative_expression _Div_ unary_expression
        {
            $$ = xs_create_math_binary_expression(MathBinaryExpressionOperator::Div, $1, $3);
        }
        | multiplicative_expression _Mod_ unary_expression
        {
            $$ = xs_create_math_binary_expression(MathBinaryExpressionOperator::Mod, $1, $3);
        }
        ;
unary_expression
        : postfix_expression
        | _Sub_ unary_expression
        {
            $$ = xs_create_minus_expression($2);
        }
        | _Exclamation_ unary_expression
        {
            $$ = xs_create_logical_not_expression($2);
        }
        ;
postfix_expression
        : primary_expression
        | postfix_expression _Lp_ argument_list _Rp_
        {
            $$ = xs_create_function_call_expression($1, $3);
        }
        | postfix_expression _Lp_ _Rp_
        {
            $$ = xs_create_function_call_expression($1, nullptr);
        }
        | postfix_expression _Increment_
        {
            $$ = xs_create_incdec_expression($1, IncdecExpressionOprator::Increment);
        }
        | postfix_expression _Decrement_
        {
            $$ = xs_create_incdec_expression($1, IncdecExpressionOprator::Decrement);
        }
        ;
primary_expression
        : _Lp_ expression _Rp_
        {
            $$ = $2;
        }
        | _Identifier_
        {
            $$ = xs_create_identifier_expression($1);
        }
        | _IntLiteral_
        | _DoubleLiteral_
        | _StringLiteral_
        | _RegexpLiteral_
        | _True_
        {
            $$ = xs_create_boolean_expression((true));
        }
        | _False_
        {
            $$ = xs_create_boolean_expression((false));
        }
        ;
statement
        : expression _Semicolon_
        {
          $$ = xs_create_expression_statement($1);
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
        : _If_ _Lp_ expression _Rp_ block
        {
            $$ = xs_create_if_statement($3, $5, nullptr, nullptr);
        }
        | _If_ _Lp_ expression _Rp_ block _Else_ block
        {
            $$ = xs_create_if_statement($3, $5, nullptr, $7);
        }
        | _If_ _Lp_ expression _Rp_ block elsif_list
        {
            $$ = xs_create_if_statement($3, $5, $6, nullptr);
        }
        | _If_ _Lp_ expression _Rp_ block elsif_list _Else_ block
        {
            $$ = xs_create_if_statement($3, $5, $6, $8);
        }
        ;
elsif_list
        : elsif
		{
			$$ = xs_create_elsif_lsit($1);		
		}
        | elsif_list elsif
        {
            $$ = xs_chain_elsif_list($1, $2);
        }
        ;
elsif
        : _Elseif_ _Lp_ expression _Rp_ block
        {
            $$ = xs_create_elsif($3, $5);
        }
        ;
label_opt
        : /* empty */
        {
            $$ = nullptr;
        }
        | _Identifier_ _Colon_
        {
            $$ = $1;
        }
        ;
while_statement
        : label_opt _While_ _Lp_ expression _Rp_ block
        {
            $$ = xs_create_while_statement($1, $4, $6);
        }
        ;
for_statement
        : label_opt _For_ _Lp_ expression_opt _Semicolon_ expression_opt _Semicolon_
          expression_opt _Rp_ block
        {
            $$ = xs_create_for_statement($1, $4, $6, $8, $10);
        }
        ;
foreach_statement
        : label_opt _Foreach_ _Lp_ _Identifier_ _Colon_ expression _Rp_ block
        {
            $$ = xs_create_foreach_statement($1, $4, $6, $8);
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
        : _Return_ expression_opt _Semicolon_
        {
            $$ = xs_create_return_statement($2);
        }
        ;
identifier_opt
        : /* empty */
        {
            $$ = nullptr;
        }
        | _Identifier_
        ;
break_statement 
        : _Break_ identifier_opt _Semicolon_
        {
            $$ = xs_create_break_statement($2);
        }
        ;
continue_statement
        : _Continue_ identifier_opt _Semicolon_
        {
            $$ = xs_create_continue_statement($2);
        }
        ;
try_statement
        : _Try_ block _Catch_ _Lp_ _Identifier_ _Rp_ block _Finally_ block
        {
            $$ = xs_create_try_statement($2, $5, $7, $9);
        }
        | _Try_ block _Finally_ block
        {
            $$ = xs_create_try_statement($2, nullptr, nullptr, $4);
        }
        | _Try_ block _Catch_ _Lp_ _Identifier_ _Rp_ block
        {
            $$ = xs_create_try_statement($2, $5, $7, nullptr);
        }
throw_statement
        : _Throw_ expression _Semicolon_
        {
            $$ = xs_create_throw_statement($2);
        }
declaration_statement
        : type_specifier _Identifier_ _Semicolon_
        {
            $$ = xs_create_declaration_statement($1, $2, nullptr);
        }
        | type_specifier _Identifier_ _Assign_ expression _Semicolon_
        {
            $$ = xs_create_declaration_statement($1, $2, $4);
        }
        ;
block
        : _Lc_
        {
            $<block>$ = xs_open_block();
        }
          statement_list _Rc_
        {
            $<block>$ = xs_close_block($<block>2, $3);
        }
        | _Lc_ _Rc_
        {
            Block empty_block = xs_open_block();
            $<block>$ = xs_close_block(empty_block, nullptr);
        }
        ;
%%