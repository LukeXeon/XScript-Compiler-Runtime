#include "stdafx.h"
#include "yyinteface.h"

/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _IntLiteral_ = 258,
     _DoubleLiteral_ = 259,
     _StringLiteral_ = 260,
     _RegexpLiteral_ = 261,
     _Identifier_ = 262,
     _If_ = 263,
     _Else_ = 264,
     _Elseif_ = 265,
     _While_ = 266,
     _For_ = 267,
     _Foreach_ = 268,
     _Return_ = 269,
     _Break_ = 270,
     _Continue_ = 271,
     _Lp_ = 272,
     _Rp_ = 273,
     _Lc_ = 274,
     _Rc_ = 275,
     _Semicolon_ = 276,
     _Colon_ = 277,
     _Comma_ = 278,
     _Assign_ = 279,
     _LogicalAnd_ = 280,
     _LogicalOr_ = 281,
     _Eq_ = 282,
     _Ne_ = 283,
     _Gt_ = 284,
     _Ge_ = 285,
     _Lt_ = 286,
     _Le_ = 287,
     _Add_ = 288,
     _Sub_ = 289,
     _Mul_ = 290,
     _Div_ = 291,
     _Mod_ = 292,
     _True_ = 293,
     _False_ = 294,
     _Exclamation_ = 295,
     _Dot_ = 296,
     _AddAssign_ = 297,
     _SubAssign_ = 298,
     _MulAssign_ = 299,
     _DivAssign_ = 300,
     _ModAssign_ = 301,
     _Increment_ = 302,
     _Decrement_ = 303,
     _Try_ = 304,
     _Catch_ = 305,
     _Finally_ = 306,
     _Throw_ = 307,
     _Boolean_ = 308,
     _Int_ = 309,
     _Double_ = 310,
     _String_ = 311
   };
#endif
/* Tokens.  */
#define _IntLiteral_ 258
#define _DoubleLiteral_ 259
#define _StringLiteral_ 260
#define _RegexpLiteral_ 261
#define _Identifier_ 262
#define _If_ 263
#define _Else_ 264
#define _Elseif_ 265
#define _While_ 266
#define _For_ 267
#define _Foreach_ 268
#define _Return_ 269
#define _Break_ 270
#define _Continue_ 271
#define _Lp_ 272
#define _Rp_ 273
#define _Lc_ 274
#define _Rc_ 275
#define _Semicolon_ 276
#define _Colon_ 277
#define _Comma_ 278
#define _Assign_ 279
#define _LogicalAnd_ 280
#define _LogicalOr_ 281
#define _Eq_ 282
#define _Ne_ 283
#define _Gt_ 284
#define _Ge_ 285
#define _Lt_ 286
#define _Le_ 287
#define _Add_ 288
#define _Sub_ 289
#define _Mul_ 290
#define _Div_ 291
#define _Mod_ 292
#define _True_ 293
#define _False_ 294
#define _Exclamation_ 295
#define _Dot_ 296
#define _AddAssign_ 297
#define _SubAssign_ 298
#define _MulAssign_ 299
#define _DivAssign_ 300
#define _ModAssign_ 301
#define _Increment_ 302
#define _Decrement_ 303
#define _Try_ 304
#define _Catch_ 305
#define _Finally_ 306
#define _Throw_ 307
#define _Boolean_ 308
#define _Int_ 309
#define _Double_ 310
#define _String_ 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 7 "xscript.y"

    String                 identifier;
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
    BasicType			   type_specifier;



/* Line 1676 of yacc.c  */
#line 181 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


