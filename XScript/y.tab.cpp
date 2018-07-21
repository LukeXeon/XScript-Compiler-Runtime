#include "stdafx.h"
#include "yyinteface.h"
#include "y.tab.h"

/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
infringing on user name space.  This should be done even for local
variables, as they might otherwise be expanded by user macros.
There are some unavoidable exceptions within include files to
define necessary library symbols; they are noted "INFRINGES ON
USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "xscript.y"


#define YYDEBUG 1


/* Line 189 of yacc.c  */
#line 79 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

	/* Line 214 of yacc.c  */
#line 7 "xscript.y"

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



	/* Line 214 of yacc.c  */
#line 244 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 256 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID(int yyi)
#else
static int
YYID(yyi)
int yyi;
#endif
{
	return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
/* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
/* The OS might guarantee only one guard page at the bottom of the stack,
and a page size can be as small as 4096 bytes.  So we cannot safely
invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc(YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free(void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

				   /* A type that is properly aligned for any stack member.  */
union yyalloc
{
	yytype_int16 yyss_alloc;
	YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
local variables YYSIZE and YYSTACKSIZE give the old and new number of
elements in the stack, and YYPTR gives the new location of the
stack.  Advance YYPTR to a properly aligned location for the next
stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNRULES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
	0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
	2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
	5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
	15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
	25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
	35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
	45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
	55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
	0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
	20,    27,    33,    40,    46,    48,    53,    56,    58,    62,
	64,    67,    69,    73,    75,    79,    81,    83,    85,    87,
	89,    91,    93,    97,    99,   103,   105,   109,   113,   115,
	119,   123,   127,   131,   133,   137,   141,   143,   147,   151,
	155,   157,   160,   163,   165,   170,   174,   177,   180,   184,
	186,   188,   190,   192,   194,   196,   198,   201,   203,   205,
	207,   209,   211,   213,   215,   217,   219,   221,   227,   235,
	242,   251,   253,   256,   262,   263,   266,   273,   284,   293,
	294,   296,   300,   301,   303,   307,   311,   321,   326,   334,
	338,   342,   348,   349,   354
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
	58,     0,    -1,    59,    -1,    58,    59,    -1,    61,    -1,
	78,    -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,
	60,     7,    17,    62,    18,    94,    -1,    60,     7,    17,
	18,    94,    -1,    60,     7,    17,    62,    18,    21,    -1,
	60,     7,    17,    18,    21,    -1,    63,    -1,    62,    23,
	60,     7,    -1,    60,     7,    -1,    67,    -1,    64,    23,
	67,    -1,    78,    -1,    65,    78,    -1,    67,    -1,    66,
	23,    67,    -1,    69,    -1,    76,    68,    67,    -1,    24,
	-1,    42,    -1,    43,    -1,    44,    -1,    45,    -1,    46,
	-1,    70,    -1,    69,    26,    70,    -1,    71,    -1,    70,
	25,    71,    -1,    72,    -1,    71,    27,    72,    -1,    71,
	28,    72,    -1,    73,    -1,    72,    29,    73,    -1,    72,
	30,    73,    -1,    72,    31,    73,    -1,    72,    32,    73,
	-1,    74,    -1,    73,    33,    74,    -1,    73,    34,    74,
	-1,    75,    -1,    74,    35,    75,    -1,    74,    36,    75,
	-1,    74,    37,    75,    -1,    76,    -1,    34,    75,    -1,
	40,    75,    -1,    77,    -1,    76,    17,    64,    18,    -1,
	76,    17,    18,    -1,    76,    47,    -1,    76,    48,    -1,
	17,    66,    18,    -1,     7,    -1,     3,    -1,     4,    -1,
	5,    -1,     6,    -1,    38,    -1,    39,    -1,    66,    21,
	-1,    79,    -1,    83,    -1,    84,    -1,    85,    -1,    87,
	-1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,    93,
	-1,     8,    17,    66,    18,    94,    -1,     8,    17,    66,
	18,    94,     9,    94,    -1,     8,    17,    66,    18,    94,
	80,    -1,     8,    17,    66,    18,    94,    80,     9,    94,
	-1,    81,    -1,    80,    81,    -1,    10,    17,    66,    18,
	94,    -1,    -1,     7,    22,    -1,    82,    11,    17,    66,
	18,    94,    -1,    82,    12,    17,    86,    21,    86,    21,
	86,    18,    94,    -1,    82,    13,    17,     7,    22,    66,
	18,    94,    -1,    -1,    66,    -1,    14,    86,    21,    -1,
	-1,     7,    -1,    15,    88,    21,    -1,    16,    88,    21,
	-1,    49,    94,    50,    17,     7,    18,    94,    51,    94,
	-1,    49,    94,    51,    94,    -1,    49,    94,    50,    17,
	7,    18,    94,    -1,    52,    66,    21,    -1,    60,     7,
	21,    -1,    60,     7,    24,    66,    21,    -1,    -1,    19,
	95,    65,    20,    -1,    19,    20,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
	0,    54,    54,    55,    58,    59,    66,    70,    74,    78,
	84,    88,    92,    96,   102,   106,   112,   117,   121,   127,
	131,   137,   138,   144,   145,   151,   155,   159,   163,   167,
	171,   177,   178,   184,   185,   191,   192,   196,   202,   203,
	207,   211,   215,   221,   222,   226,   232,   233,   237,   241,
	247,   248,   252,   258,   259,   263,   267,   271,   277,   281,
	285,   286,   287,   288,   289,   293,   299,   303,   304,   305,
	306,   307,   308,   309,   310,   311,   312,   315,   319,   323,
	327,   333,   337,   343,   350,   353,   359,   365,   372,   379,
	382,   385,   392,   395,   398,   404,   410,   414,   418,   423,
	428,   432,   439,   438,   446
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
	"$end", "error", "$undefined", "_IntLiteral_", "_DoubleLiteral_",
	"_StringLiteral_", "_RegexpLiteral_", "_Identifier_", "_If_", "_Else_",
	"_Elseif_", "_While_", "_For_", "_Foreach_", "_Return_", "_Break_",
	"_Continue_", "_Lp_", "_Rp_", "_Lc_", "_Rc_", "_Semicolon_", "_Colon_",
	"_Comma_", "_Assign_", "_LogicalAnd_", "_LogicalOr_", "_Eq_", "_Ne_",
	"_Gt_", "_Ge_", "_Lt_", "_Le_", "_Add_", "_Sub_", "_Mul_", "_Div_",
	"_Mod_", "_True_", "_False_", "_Exclamation_", "_Dot_", "_AddAssign_",
	"_SubAssign_", "_MulAssign_", "_DivAssign_", "_ModAssign_",
	"_Increment_", "_Decrement_", "_Try_", "_Catch_", "_Finally_", "_Throw_",
	"_Boolean_", "_Int_", "_Double_", "_String_", "$accept",
	"translation_unit", "definition_or_statement", "type_specifier",
	"function_definition", "parameter_list", "parameter", "argument_list",
	"statement_list", "expression", "assignment_expression",
	"assignment_operator", "logical_or_expression", "logical_and_expression",
	"equality_expression", "relational_expression", "additive_expression",
	"multiplicative_expression", "unary_expression", "postfix_expression",
	"primary_expression", "statement", "if_statement", "elsif_list", "elsif",
	"label_opt", "while_statement", "for_statement", "foreach_statement",
	"expression_opt", "return_statement", "identifier_opt",
	"break_statement", "continue_statement", "try_statement",
	"throw_statement", "declaration_statement", "block", "@1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
	0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
	265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
	275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
	285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
	295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
	305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
	0,    57,    58,    58,    59,    59,    60,    60,    60,    60,
	61,    61,    61,    61,    62,    62,    63,    64,    64,    65,
	65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
	68,    69,    69,    70,    70,    71,    71,    71,    72,    72,
	72,    72,    72,    73,    73,    73,    74,    74,    74,    74,
	75,    75,    75,    76,    76,    76,    76,    76,    77,    77,
	77,    77,    77,    77,    77,    77,    78,    78,    78,    78,
	78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
	79,    80,    80,    81,    82,    82,    83,    84,    85,    86,
	86,    87,    88,    88,    89,    90,    91,    91,    91,    92,
	93,    93,    95,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
	0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
	6,     5,     6,     5,     1,     4,     2,     1,     3,     1,
	2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
	1,     1,     3,     1,     3,     1,     3,     3,     1,     3,
	3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
	1,     2,     2,     1,     4,     3,     2,     2,     3,     1,
	1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
	1,     1,     1,     1,     1,     1,     1,     5,     7,     6,
	8,     1,     2,     5,     0,     2,     6,    10,     8,     0,
	1,     3,     0,     1,     3,     3,     9,     4,     7,     3,
	3,     5,     0,     4,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
	84,    60,    61,    62,    63,    59,     0,    89,    92,    92,
	0,     0,    64,    65,     0,     0,     0,     6,     7,     8,
	9,    84,     2,     0,     4,     0,    21,    23,    31,    33,
	35,    38,    43,    46,    50,    53,     5,    67,     0,    68,
	69,    70,    71,    72,    73,    74,    75,    76,    85,     0,
	59,    90,     0,    93,     0,     0,     0,    51,    50,    52,
	102,     0,     0,     1,     3,     0,    66,     0,     0,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
	0,     0,    25,    26,    27,    28,    29,    30,    56,    57,
	0,     0,     0,     0,     0,    91,    94,    95,    58,   104,
	84,     0,     0,    99,     0,   100,     0,    22,    32,    34,
	36,    37,    39,    40,    41,    42,    44,    45,    47,    48,
	49,    55,     0,    17,    24,     0,    89,     0,     0,     0,
	84,    19,     0,    97,     0,     0,     0,    14,     0,    54,
	0,     0,     0,     0,    77,     0,   103,    20,     0,    13,
	11,    16,     0,     0,   101,    18,     0,    89,     0,     0,
	0,    79,    81,     0,    12,    10,     0,    86,     0,     0,
	78,     0,     0,    82,    98,    15,    89,     0,     0,    80,
	0,     0,    88,     0,    96,     0,    83,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
	-1,    21,    22,    23,    24,   136,   137,   122,   130,    25,
	26,    90,    27,    28,    29,    30,    31,    32,    33,    34,
	35,    36,    37,   161,   162,    38,    39,    40,    41,    52,
	42,    54,    43,    44,    45,    46,    47,    61,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
	221,  -123,  -123,  -123,  -123,    -8,     4,   261,    33,    33,
	261,   261,  -123,  -123,   261,    24,   261,  -123,  -123,  -123,
	-123,   100,  -123,    46,  -123,     1,  -123,    72,    35,    42,
	80,    47,    95,  -123,     2,  -123,  -123,  -123,   124,  -123,
	-123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   261,
	-123,    90,    56,  -123,   112,   125,     0,  -123,   -10,  -123,
	128,    51,     9,  -123,  -123,    -4,  -123,   261,   261,   261,
	261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
	261,   245,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
	261,   146,   151,   159,    16,  -123,  -123,  -123,  -123,  -123,
	221,   160,    24,  -123,    11,  -123,   261,  -123,    35,    42,
	80,    80,    47,    47,    47,    47,    95,    95,  -123,  -123,
	-123,  -123,    34,  -123,  -123,   261,   261,   171,    24,   172,
	167,  -123,   173,  -123,   122,   178,    38,  -123,   121,  -123,
	261,    45,   165,   145,   148,    -9,  -123,  -123,   170,  -123,
	-123,  -123,   126,    68,  -123,  -123,    24,   261,   261,    24,
	174,   150,  -123,    24,  -123,  -123,   182,  -123,   169,    60,
	-123,   261,    24,  -123,   141,  -123,   261,    24,   102,  -123,
	24,   175,  -123,    24,  -123,    24,  -123,  -123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
	-123,  -123,   176,   -94,  -123,  -123,  -123,  -123,  -123,    -7,
	-65,  -123,  -123,   127,   129,    91,    54,    89,    -6,    17,
	-123,   -89,  -123,  -123,    39,  -123,  -123,  -123,  -123,  -122,
	-123,   185,  -123,  -123,  -123,  -123,  -123,  -101,  -123
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
positive, shift that token.  If negative, reduce the rule which
number is the opposite.  If zero, do what YYDEFACT says.
If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
	51,   133,   107,    56,   142,    57,   129,    81,    59,    62,
	135,   131,   105,   104,    48,   106,   123,   105,    98,    81,
	106,    49,    66,    67,    67,   124,    82,   144,    58,   134,
	103,    58,    67,   150,   128,   168,   129,    88,    89,    67,
	53,   147,    94,    60,    83,    84,    85,    86,    87,    88,
	89,   165,   139,    65,   181,   167,   152,   140,   170,   166,
	69,   153,   174,   156,    17,    18,    19,    20,    67,    70,
	71,   179,   118,   119,   120,   155,   182,    95,   177,   184,
	76,    77,   186,    67,   187,    58,    58,    58,    58,    58,
	58,    58,    58,    58,    58,    58,    58,    58,    68,   138,
	63,   101,   102,     1,     2,     3,     4,     5,     6,    72,
	73,    74,    75,    67,     7,     8,     9,    10,   141,    51,
	183,    17,    18,    19,    20,    67,   112,   113,   114,   115,
	78,    79,    80,    96,    11,    91,    92,    93,    12,    13,
	14,    60,   154,   149,    67,    60,    97,   164,    99,    15,
	51,   169,    16,    17,    18,    19,    20,   159,   160,   172,
	160,   110,   111,   125,   178,   116,   117,   158,   126,    51,
	1,     2,     3,     4,     5,     6,   127,   132,   143,   145,
	148,     7,     8,     9,    10,   151,   157,   146,   163,   175,
	176,   171,   180,   185,    55,   108,     0,    64,   109,     0,
	173,    11,     0,     0,     0,    12,    13,    14,     0,     0,
	0,     0,     0,     0,     0,     0,    15,     0,     0,    16,
	17,    18,    19,    20,     1,     2,     3,     4,     5,     6,
	0,     0,     0,     0,     0,     7,     8,     9,    10,     0,
	0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
	3,     4,    50,     0,     0,    11,     0,     0,     0,    12,
	13,    14,    10,   121,     1,     2,     3,     4,    50,     0,
	15,     0,     0,    16,    17,    18,    19,    20,    10,    11,
	0,     0,     0,    12,    13,    14,     0,     0,     0,     0,
	0,     0,     0,     0,     0,    11,     0,     0,     0,    12,
	13,    14
};

static const yytype_int16 yycheck[] =
{
	7,   102,    67,    10,   126,    11,   100,    17,    14,    16,
	104,   100,    21,    17,    22,    24,    81,    21,    18,    17,
	24,    17,    21,    23,    23,    90,    24,   128,    11,    18,
	21,    14,    23,   134,    18,   157,   130,    47,    48,    23,
	7,   130,    49,    19,    42,    43,    44,    45,    46,    47,
	48,   152,    18,     7,   176,   156,    18,    23,   159,   153,
	25,    23,   163,    18,    53,    54,    55,    56,    23,    27,
	28,   172,    78,    79,    80,   140,   177,    21,    18,   180,
	33,    34,   183,    23,   185,    68,    69,    70,    71,    72,
	73,    74,    75,    76,    77,    78,    79,    80,    26,   106,
	0,    50,    51,     3,     4,     5,     6,     7,     8,    29,
	30,    31,    32,    23,    14,    15,    16,    17,   125,   126,
	18,    53,    54,    55,    56,    23,    72,    73,    74,    75,
	35,    36,    37,    21,    34,    11,    12,    13,    38,    39,
	40,    19,    21,    21,    23,    19,    21,    21,    20,    49,
	157,   158,    52,    53,    54,    55,    56,     9,    10,     9,
	10,    70,    71,    17,   171,    76,    77,    22,    17,   176,
	3,     4,     5,     6,     7,     8,    17,    17,     7,     7,
	7,    14,    15,    16,    17,     7,    21,    20,    18,     7,
	21,    17,    51,    18,     9,    68,    -1,    21,    69,    -1,
	161,    34,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
	53,    54,    55,    56,     3,     4,     5,     6,     7,     8,
	-1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    -1,
	-1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
	5,     6,     7,    -1,    -1,    34,    -1,    -1,    -1,    38,
	39,    40,    17,    18,     3,     4,     5,     6,     7,    -1,
	49,    -1,    -1,    52,    53,    54,    55,    56,    17,    34,
	-1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
	-1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
	39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
	0,     3,     4,     5,     6,     7,     8,    14,    15,    16,
	17,    34,    38,    39,    40,    49,    52,    53,    54,    55,
	56,    58,    59,    60,    61,    66,    67,    69,    70,    71,
	72,    73,    74,    75,    76,    77,    78,    79,    82,    83,
	84,    85,    87,    89,    90,    91,    92,    93,    22,    17,
	7,    66,    86,     7,    88,    88,    66,    75,    76,    75,
	19,    94,    66,     0,    59,     7,    21,    23,    26,    25,
	27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
	37,    17,    24,    42,    43,    44,    45,    46,    47,    48,
	68,    11,    12,    13,    66,    21,    21,    21,    18,    20,
	95,    50,    51,    21,    17,    21,    24,    67,    70,    71,
	72,    72,    73,    73,    73,    73,    74,    74,    75,    75,
	75,    18,    64,    67,    67,    17,    17,    17,    18,    60,
	65,    78,    17,    94,    18,    60,    62,    63,    66,    18,
	23,    66,    86,     7,    94,     7,    20,    78,     7,    21,
	94,     7,    18,    23,    21,    67,    18,    21,    22,     9,
	10,    80,    81,    18,    21,    94,    60,    94,    86,    66,
	94,    17,     9,    81,    94,     7,    21,    18,    66,    94,
	51,    86,    94,    18,    94,    18,    94,    94
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
to ease the transition to the new meaning of YYERROR, for GCC.
Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
If N is 0, then set CURRENT to the empty location which ends
the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
This macro was not mandated originally: define only if we know
we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print(FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print(yyoutput, yytype, yyvaluep)
FILE *yyoutput;
int yytype;
YYSTYPE const * const yyvaluep;
#endif
{
	if (!yyvaluep)
		return;
# ifdef YYPRINT
	if (yytype < YYNTOKENS)
		YYPRINT(yyoutput, yytoknum[yytype], *yyvaluep);
# else
	YYUSE(yyoutput);
# endif
	switch (yytype)
	{
	default:
		break;
	}
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print(FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print(yyoutput, yytype, yyvaluep)
FILE *yyoutput;
int yytype;
YYSTYPE const * const yyvaluep;
#endif
{
	if (yytype < YYNTOKENS)
		YYFPRINTF(yyoutput, "token %s (", yytname[yytype]);
	else
		YYFPRINTF(yyoutput, "nterm %s (", yytname[yytype]);

	yy_symbol_value_print(yyoutput, yytype, yyvaluep);
	YYFPRINTF(yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print(yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print(yybottom, yytop)
yytype_int16 *yybottom;
yytype_int16 *yytop;
#endif
{
	YYFPRINTF(stderr, "Stack now");
	for (; yybottom <= yytop; yybottom++)
	{
		int yybot = *yybottom;
		YYFPRINTF(stderr, " %d", yybot);
	}
	YYFPRINTF(stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print(YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print(yyvsp, yyrule)
YYSTYPE *yyvsp;
int yyrule;
#endif
{
	int yynrhs = yyr2[yyrule];
	int yyi;
	unsigned long int yylno = yyrline[yyrule];
	YYFPRINTF(stderr, "Reducing stack by rule %d (line %lu):\n",
		yyrule - 1, yylno);
	/* The symbols being reduced.  */
	for (yyi = 0; yyi < yynrhs; yyi++)
	{
		YYFPRINTF(stderr, "   $%d = ", yyi + 1);
		yy_symbol_print(stderr, yyrhs[yyprhs[yyrule] + yyi],
			&(yyvsp[(yyi + 1) - (yynrhs)])
		);
		YYFPRINTF(stderr, "\n");
	}
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
if the built-in stack extension method is used).

Do not make this value too large; the results are undefined if
YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen(const char *yystr)
#else
static YYSIZE_T
yystrlen(yystr)
const char *yystr;
#endif
{
	YYSIZE_T yylen;
	for (yylen = 0; yystr[yylen]; yylen++)
		continue;
	return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy(char *yydest, const char *yysrc)
#else
static char *
yystpcpy(yydest, yysrc)
char *yydest;
const char *yysrc;
#endif
{
	char *yyd = yydest;
	const char *yys = yysrc;

	while ((*yyd++ = *yys++) != '\0')
		continue;

	return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
quotes and backslashes, so that it's suitable for yyerror.  The
heuristic is that double-quoting is unnecessary unless the string
contains an apostrophe, a comma, or backslash (other than
backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
null, do not copy; instead, return the length of what the result
would have been.  */
static YYSIZE_T
yytnamerr(char *yyres, const char *yystr)
{
	if (*yystr == '"')
	{
		YYSIZE_T yyn = 0;
		char const *yyp = yystr;

		for (;;)
			switch (*++yyp)
			{
			case '\'':
			case ',':
				goto do_not_strip_quotes;

			case '\\':
				if (*++yyp != '\\')
					goto do_not_strip_quotes;
				/* Fall through.  */
			default:
				if (yyres)
					yyres[yyn] = *yyp;
				yyn++;
				break;

			case '"':
				if (yyres)
					yyres[yyn] = '\0';
				return yyn;
			}
	do_not_strip_quotes:;
	}

	if (!yyres)
		return yystrlen(yystr);

	return yystpcpy(yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
YYCHAR while in state YYSTATE.  Return the number of bytes copied,
including the terminating null byte.  If YYRESULT is null, do not
copy anything; just return the number of bytes that would be
copied.  As a special case, return 0 if an ordinary "syntax error"
message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
size calculation.  */
static YYSIZE_T
yysyntax_error(char *yyresult, int yystate, int yychar)
{
	int yyn = yypact[yystate];

	if (!(YYPACT_NINF < yyn && yyn <= YYLAST))
		return 0;
	else
	{
		int yytype = YYTRANSLATE(yychar);
		YYSIZE_T yysize0 = yytnamerr(0, yytname[yytype]);
		YYSIZE_T yysize = yysize0;
		YYSIZE_T yysize1;
		int yysize_overflow = 0;
		enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
		char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
		int yyx;

# if 0
		/* This is so xgettext sees the translatable formats that are
		constructed on the fly.  */
		YY_("syntax error, unexpected %s");
		YY_("syntax error, unexpected %s, expecting %s");
		YY_("syntax error, unexpected %s, expecting %s or %s");
		YY_("syntax error, unexpected %s, expecting %s or %s or %s");
		YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
		char *yyfmt;
		char const *yyf;
		static char const yyunexpected[] = "syntax error, unexpected %s";
		static char const yyexpecting[] = ", expecting %s";
		static char const yyor[] = " or %s";
		char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
				* (sizeof yyor - 1))];
		char const *yyprefix = yyexpecting;

		/* Start YYX at -YYN if negative to avoid negative indexes in
		YYCHECK.  */
		int yyxbegin = yyn < 0 ? -yyn : 0;

		/* Stay within bounds of both yycheck and yytname.  */
		int yychecklim = YYLAST - yyn + 1;
		int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
		int yycount = 1;

		yyarg[0] = yytname[yytype];
		yyfmt = yystpcpy(yyformat, yyunexpected);

		for (yyx = yyxbegin; yyx < yyxend; ++yyx)
			if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
			{
				if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
				{
					yycount = 1;
					yysize = yysize0;
					yyformat[sizeof yyunexpected - 1] = '\0';
					break;
				}
				yyarg[yycount++] = yytname[yyx];
				yysize1 = yysize + yytnamerr(0, yytname[yyx]);
				yysize_overflow |= (yysize1 < yysize);
				yysize = yysize1;
				yyfmt = yystpcpy(yyfmt, yyprefix);
				yyprefix = yyor;
			}

		yyf = YY_(yyformat);
		yysize1 = yysize + yystrlen(yyf);
		yysize_overflow |= (yysize1 < yysize);
		yysize = yysize1;

		if (yysize_overflow)
			return YYSIZE_MAXIMUM;

		if (yyresult)
		{
			/* Avoid sprintf, as that infringes on the user's name space.
			Don't have undefined behavior even if the translation
			produced a string with the wrong number of "%s"s.  */
			char *yyp = yyresult;
			int yyi = 0;
			while ((*yyp = *yyf) != '\0')
			{
				if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
				{
					yyp += yytnamerr(yyp, yyarg[yyi++]);
					yyf += 2;
				}
				else
				{
					yyp++;
					yyf++;
				}
			}
		}
		return yysize;
	}
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct(const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct(yymsg, yytype, yyvaluep)
const char *yymsg;
int yytype;
YYSTYPE *yyvaluep;
#endif
{
	YYUSE(yyvaluep);

	if (!yymsg)
		yymsg = "Deleting";
	YY_SYMBOL_PRINT(yymsg, yytype, yyvaluep, yylocationp);

	switch (yytype)
	{

	default:
		break;
	}
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse(void *YYPARSE_PARAM);
#else
int yyparse();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse(void);
#else
int yyparse();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse(void *YYPARSE_PARAM)
#else
int
yyparse(YYPARSE_PARAM)
void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse(void)
#else
int
yyparse()

#endif
#endif
{


	int yystate;
	/* Number of tokens to shift before error messages enabled.  */
	int yyerrstatus;

	/* The stacks and their tools:
	`yyss': related to states.
	`yyvs': related to semantic values.

	Refer to the stacks thru separate pointers, to allow yyoverflow
	to reallocate them elsewhere.  */

	/* The state stack.  */
	yytype_int16 yyssa[YYINITDEPTH];
	yytype_int16 *yyss;
	yytype_int16 *yyssp;

	/* The semantic value stack.  */
	YYSTYPE yyvsa[YYINITDEPTH];
	YYSTYPE *yyvs;
	YYSTYPE *yyvsp;

	YYSIZE_T yystacksize;

	int yyn;
	int yyresult;
	/* Lookahead token as an internal (translated) token number.  */
	int yytoken;
	/* The variables used to return semantic value and location from the
	action routines.  */
	YYSTYPE yyval;

#if YYERROR_VERBOSE
	/* Buffer for error messages, and its allocated size.  */
	char yymsgbuf[128];
	char *yymsg = yymsgbuf;
	YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

	/* The number of symbols on the RHS of the reduced rule.
	Keep to zero when no symbol should be popped.  */
	int yylen = 0;

	yytoken = 0;
	yyss = yyssa;
	yyvs = yyvsa;
	yystacksize = YYINITDEPTH;

	YYDPRINTF((stderr, "Starting parse\n"));

	yystate = 0;
	yyerrstatus = 0;
	yynerrs = 0;
	yychar = YYEMPTY; /* Cause a token to be read.  */

					  /* Initialize stack pointers.
					  Waste one element of value and location stack
					  so that they stay on the same level as the state stack.
					  The wasted elements are never initialized.  */
	yyssp = yyss;
	yyvsp = yyvs;

	goto yysetstate;

	/*------------------------------------------------------------.
	| yynewstate -- Push a new state, which is found in yystate.  |
	`------------------------------------------------------------*/
yynewstate:
	/* In all cases, when you get here, the value and location stacks
	have just been pushed.  So pushing a state here evens the stacks.  */
	yyssp++;

yysetstate:
	*yyssp = yystate;

	if (yyss + yystacksize - 1 <= yyssp)
	{
		/* Get the current used size of the three stacks, in elements.  */
		YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
		{
			/* Give user a chance to reallocate the stack.  Use copies of
			these so that the &'s don't force the real ones into
			memory.  */
			YYSTYPE *yyvs1 = yyvs;
			yytype_int16 *yyss1 = yyss;

			/* Each stack pointer address is followed by the size of the
			data in use in that stack, in bytes.  This used to be a
			conditional around just the two extra args, but that might
			be undefined if yyoverflow is a macro.  */
			yyoverflow(YY_("memory exhausted"),
				&yyss1, yysize * sizeof(*yyssp),
				&yyvs1, yysize * sizeof(*yyvsp),
				&yystacksize);

			yyss = yyss1;
			yyvs = yyvs1;
		}
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
		goto yyexhaustedlab;
# else
		/* Extend the stack our own way.  */
		if (YYMAXDEPTH <= yystacksize)
			goto yyexhaustedlab;
		yystacksize *= 2;
		if (YYMAXDEPTH < yystacksize)
			yystacksize = YYMAXDEPTH;

		{
			yytype_int16 *yyss1 = yyss;
			union yyalloc *yyptr =
				(union yyalloc *) YYSTACK_ALLOC(YYSTACK_BYTES(yystacksize));
			if (!yyptr)
				goto yyexhaustedlab;
			YYSTACK_RELOCATE(yyss_alloc, yyss);
			YYSTACK_RELOCATE(yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
			if (yyss1 != yyssa)
				YYSTACK_FREE(yyss1);
		}
# endif
#endif /* no yyoverflow */

		yyssp = yyss + yysize - 1;
		yyvsp = yyvs + yysize - 1;

		YYDPRINTF((stderr, "Stack size increased to %lu\n",
			(unsigned long int) yystacksize));

		if (yyss + yystacksize - 1 <= yyssp)
			YYABORT;
	}

	YYDPRINTF((stderr, "Entering state %d\n", yystate));

	if (yystate == YYFINAL)
		YYACCEPT;

	goto yybackup;

	/*-----------.
	| yybackup.  |
	`-----------*/
yybackup:

	/* Do appropriate processing given the current state.  Read a
	lookahead token if we need one and don't already have one.  */

	/* First try to decide what to do without reference to lookahead token.  */
	yyn = yypact[yystate];
	if (yyn == YYPACT_NINF)
		goto yydefault;

	/* Not known => get a lookahead token if don't already have one.  */

	/* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
	if (yychar == YYEMPTY)
	{
		YYDPRINTF((stderr, "Reading a token: "));
		yychar = YYLEX;
	}

	if (yychar <= YYEOF)
	{
		yychar = yytoken = YYEOF;
		YYDPRINTF((stderr, "Now at end of input.\n"));
	}
	else
	{
		yytoken = YYTRANSLATE(yychar);
		YY_SYMBOL_PRINT("Next token is", yytoken, &yylval, &yylloc);
	}

	/* If the proper action on seeing token YYTOKEN is to reduce or to
	detect an error, take that action.  */
	yyn += yytoken;
	if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
		goto yydefault;
	yyn = yytable[yyn];
	if (yyn <= 0)
	{
		if (yyn == 0 || yyn == YYTABLE_NINF)
			goto yyerrlab;
		yyn = -yyn;
		goto yyreduce;
	}

	/* Count tokens shifted since error; after three, turn off error
	status.  */
	if (yyerrstatus)
		yyerrstatus--;

	/* Shift the lookahead token.  */
	YY_SYMBOL_PRINT("Shifting", yytoken, &yylval, &yylloc);

	/* Discard the shifted token.  */
	yychar = YYEMPTY;

	yystate = yyn;
	*++yyvsp = yylval;

	goto yynewstate;


	/*-----------------------------------------------------------.
	| yydefault -- do the default action for the current state.  |
	`-----------------------------------------------------------*/
yydefault:
	yyn = yydefact[yystate];
	if (yyn == 0)
		goto yyerrlab;
	goto yyreduce;


	/*-----------------------------.
	| yyreduce -- Do a reduction.  |
	`-----------------------------*/
yyreduce:
	/* yyn is the number of a rule to reduce with.  */
	yylen = yyr2[yyn];

	/* If YYLEN is nonzero, implement the default value of the action:
	`$$ = $1'.

	Otherwise, the following line sets YYVAL to garbage.
	This behavior is undocumented and Bison
	users should not rely upon it.  Assigning to YYVAL
	unconditionally makes the parser a bit smaller, and it avoids a
	GCC warning that YYVAL may be used uninitialized.  */
	yyval = yyvsp[1 - yylen];


	YY_REDUCE_PRINT(yyn);
	switch (yyn)
	{
	case 5:

		/* Line 1455 of yacc.c  */
#line 60 "xscript.y"
	{
		Compiler Compilation = GetCurrentCompiler();
		Compilation->statement_list = xs_chain_statement_list(Compilation->statement_list, (yyvsp[(1) - (1)].statement));
	}
	break;

	case 6:

		/* Line 1455 of yacc.c  */
#line 67 "xscript.y"
	{
		(yyval.type_specifier) = BasicType::Boolean;
	}
	break;

	case 7:

		/* Line 1455 of yacc.c  */
#line 71 "xscript.y"
	{
		(yyval.type_specifier) = BasicType::Int32;
	}
	break;

	case 8:

		/* Line 1455 of yacc.c  */
#line 75 "xscript.y"
	{
		(yyval.type_specifier) = BasicType::Double;
	}
	break;

	case 9:

		/* Line 1455 of yacc.c  */
#line 79 "xscript.y"
	{
		(yyval.type_specifier) = BasicType::String;
	}
	break;

	case 10:

		/* Line 1455 of yacc.c  */
#line 85 "xscript.y"
	{
		xs_function_define((yyvsp[(1) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].parameter_list), (yyvsp[(6) - (6)].block));
	}
	break;

	case 11:

		/* Line 1455 of yacc.c  */
#line 89 "xscript.y"
	{
		xs_function_define((yyvsp[(1) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), nullptr, (yyvsp[(5) - (5)].block));
	}
	break;

	case 12:

		/* Line 1455 of yacc.c  */
#line 93 "xscript.y"
	{
		xs_function_define((yyvsp[(1) - (6)].type_specifier), (yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].parameter_list), nullptr);
	}
	break;

	case 13:

		/* Line 1455 of yacc.c  */
#line 97 "xscript.y"
	{
		xs_function_define((yyvsp[(1) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), nullptr, nullptr);
	}
	break;

	case 14:

		/* Line 1455 of yacc.c  */
#line 103 "xscript.y"
	{
		(yyval.parameter_list) = xs_create_parameter_list((yyvsp[(1) - (1)].parameter));
	}
	break;

	case 15:

		/* Line 1455 of yacc.c  */
#line 107 "xscript.y"
	{
		(yyval.parameter_list) = xs_chain_parameter((yyvsp[(1) - (4)].parameter_list), xs_create_parameter((yyvsp[(3) - (4)].type_specifier), (yyvsp[(4) - (4)].identifier)));
	}
	break;

	case 16:

		/* Line 1455 of yacc.c  */
#line 113 "xscript.y"
	{
		(yyval.parameter) = xs_create_parameter((yyvsp[(1) - (2)].type_specifier), (yyvsp[(2) - (2)].identifier));
	}
	break;

	case 17:

		/* Line 1455 of yacc.c  */
#line 118 "xscript.y"
	{
		(yyval.argument_list) = xs_create_argument_list((yyvsp[(1) - (1)].expression));
	}
	break;

	case 18:

		/* Line 1455 of yacc.c  */
#line 122 "xscript.y"
	{
		(yyval.argument_list) = xs_chain_argument_list((yyvsp[(1) - (3)].argument_list), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 19:

		/* Line 1455 of yacc.c  */
#line 128 "xscript.y"
	{
		(yyval.statement_list) = xs_create_statement_list((yyvsp[(1) - (1)].statement));
	}
	break;

	case 20:

		/* Line 1455 of yacc.c  */
#line 132 "xscript.y"
	{
		(yyval.statement_list) = xs_chain_statement_list((yyvsp[(1) - (2)].statement_list), (yyvsp[(2) - (2)].statement));
	}
	break;

	case 22:

		/* Line 1455 of yacc.c  */
#line 139 "xscript.y"
	{
		(yyval.expression) = xs_create_comma_expression((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 24:

		/* Line 1455 of yacc.c  */
#line 146 "xscript.y"
	{
		(yyval.expression) = xs_create_assign_expression((yyvsp[(1) - (3)].expression), (yyvsp[(2) - (3)].assignment_operator), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 25:

		/* Line 1455 of yacc.c  */
#line 152 "xscript.y"
	{
		(yyval.assignment_operator) = AssignmentOperator::NomalAssign;
	}
	break;

	case 26:

		/* Line 1455 of yacc.c  */
#line 156 "xscript.y"
	{
		(yyval.assignment_operator) = AssignmentOperator::AddAssign;
	}
	break;

	case 27:

		/* Line 1455 of yacc.c  */
#line 160 "xscript.y"
	{
		(yyval.assignment_operator) = AssignmentOperator::SubAssign;
	}
	break;

	case 28:

		/* Line 1455 of yacc.c  */
#line 164 "xscript.y"
	{
		(yyval.assignment_operator) = AssignmentOperator::MulAssign;
	}
	break;

	case 29:

		/* Line 1455 of yacc.c  */
#line 168 "xscript.y"
	{
		(yyval.assignment_operator) = AssignmentOperator::DivAssign;
	}
	break;

	case 30:

		/* Line 1455 of yacc.c  */
#line 172 "xscript.y"
	{
		(yyval.assignment_operator) = AssignmentOperator::ModAssign;
	}
	break;

	case 32:

		/* Line 1455 of yacc.c  */
#line 179 "xscript.y"
	{
		(yyval.expression) = xs_create_logic_binary_expression(LogicBinaryExpressionOperator::Or, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 34:

		/* Line 1455 of yacc.c  */
#line 186 "xscript.y"
	{
		(yyval.expression) = xs_create_logic_binary_expression(LogicBinaryExpressionOperator::And, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 36:

		/* Line 1455 of yacc.c  */
#line 193 "xscript.y"
	{
		(yyval.expression) = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Eq, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 37:

		/* Line 1455 of yacc.c  */
#line 197 "xscript.y"
	{
		(yyval.expression) = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Ne, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 39:

		/* Line 1455 of yacc.c  */
#line 204 "xscript.y"
	{
		(yyval.expression) = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Gt, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 40:

		/* Line 1455 of yacc.c  */
#line 208 "xscript.y"
	{
		(yyval.expression) = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Ge, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 41:

		/* Line 1455 of yacc.c  */
#line 212 "xscript.y"
	{
		(yyval.expression) = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Lt, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 42:

		/* Line 1455 of yacc.c  */
#line 216 "xscript.y"
	{
		(yyval.expression) = xs_create_compare_binary_expression(CompareBinaryExpressionOperator::Le, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 44:

		/* Line 1455 of yacc.c  */
#line 223 "xscript.y"
	{
		(yyval.expression) = xs_create_math_binary_expression(MathBinaryExpressionOperator::Add, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 45:

		/* Line 1455 of yacc.c  */
#line 227 "xscript.y"
	{
		(yyval.expression) = xs_create_math_binary_expression(MathBinaryExpressionOperator::Sub, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 47:

		/* Line 1455 of yacc.c  */
#line 234 "xscript.y"
	{
		(yyval.expression) = xs_create_math_binary_expression(MathBinaryExpressionOperator::Mul, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 48:

		/* Line 1455 of yacc.c  */
#line 238 "xscript.y"
	{
		(yyval.expression) = xs_create_math_binary_expression(MathBinaryExpressionOperator::Div, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 49:

		/* Line 1455 of yacc.c  */
#line 242 "xscript.y"
	{
		(yyval.expression) = xs_create_math_binary_expression(MathBinaryExpressionOperator::Mod, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
	}
	break;

	case 51:

		/* Line 1455 of yacc.c  */
#line 249 "xscript.y"
	{
		(yyval.expression) = xs_create_minus_expression((yyvsp[(2) - (2)].expression));
	}
	break;

	case 52:

		/* Line 1455 of yacc.c  */
#line 253 "xscript.y"
	{
		(yyval.expression) = xs_create_logical_not_expression((yyvsp[(2) - (2)].expression));
	}
	break;

	case 54:

		/* Line 1455 of yacc.c  */
#line 260 "xscript.y"
	{
		(yyval.expression) = xs_create_function_call_expression((yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].argument_list));
	}
	break;

	case 55:

		/* Line 1455 of yacc.c  */
#line 264 "xscript.y"
	{
		(yyval.expression) = xs_create_function_call_expression((yyvsp[(1) - (3)].expression), nullptr);
	}
	break;

	case 56:

		/* Line 1455 of yacc.c  */
#line 268 "xscript.y"
	{
		(yyval.expression) = xs_create_incdec_expression((yyvsp[(1) - (2)].expression), IncdecExpressionOprator::Increment);
	}
	break;

	case 57:

		/* Line 1455 of yacc.c  */
#line 272 "xscript.y"
	{
		(yyval.expression) = xs_create_incdec_expression((yyvsp[(1) - (2)].expression), IncdecExpressionOprator::Decrement);
	}
	break;

	case 58:

		/* Line 1455 of yacc.c  */
#line 278 "xscript.y"
	{
		(yyval.expression) = (yyvsp[(2) - (3)].expression);
	}
	break;

	case 59:

		/* Line 1455 of yacc.c  */
#line 282 "xscript.y"
	{
		(yyval.expression) = xs_create_identifier_expression((yyvsp[(1) - (1)].identifier));
	}
	break;

	case 64:

		/* Line 1455 of yacc.c  */
#line 290 "xscript.y"
	{
		(yyval.expression) = xs_create_boolean_expression((true));
	}
	break;

	case 65:

		/* Line 1455 of yacc.c  */
#line 294 "xscript.y"
	{
		(yyval.expression) = xs_create_boolean_expression((false));
	}
	break;

	case 66:

		/* Line 1455 of yacc.c  */
#line 300 "xscript.y"
	{
		(yyval.statement) = xs_create_expression_statement((yyvsp[(1) - (2)].expression));
	}
	break;

	case 77:

		/* Line 1455 of yacc.c  */
#line 316 "xscript.y"
	{
		(yyval.statement) = xs_create_if_statement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block), nullptr, nullptr);
	}
	break;

	case 78:

		/* Line 1455 of yacc.c  */
#line 320 "xscript.y"
	{
		(yyval.statement) = xs_create_if_statement((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].block), nullptr, (yyvsp[(7) - (7)].block));
	}
	break;

	case 79:

		/* Line 1455 of yacc.c  */
#line 324 "xscript.y"
	{
		(yyval.statement) = xs_create_if_statement((yyvsp[(3) - (6)].expression), (yyvsp[(5) - (6)].block), (yyvsp[(6) - (6)].elsif_list), nullptr);
	}
	break;

	case 80:

		/* Line 1455 of yacc.c  */
#line 328 "xscript.y"
	{
		(yyval.statement) = xs_create_if_statement((yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].block), (yyvsp[(6) - (8)].elsif_list), (yyvsp[(8) - (8)].block));
	}
	break;

	case 81:

		/* Line 1455 of yacc.c  */
#line 334 "xscript.y"
	{
		(yyval.elsif_list) = xs_create_elsif_lsit((yyvsp[(1) - (1)].elsif));
	}
	break;

	case 82:

		/* Line 1455 of yacc.c  */
#line 338 "xscript.y"
	{
		(yyval.elsif_list) = xs_chain_elsif_list((yyvsp[(1) - (2)].elsif_list), (yyvsp[(2) - (2)].elsif));
	}
	break;

	case 83:

		/* Line 1455 of yacc.c  */
#line 344 "xscript.y"
	{
		(yyval.elsif) = xs_create_elsif((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].block));
	}
	break;

	case 84:

		/* Line 1455 of yacc.c  */
#line 350 "xscript.y"
	{
		(yyval.identifier) = nullptr;
	}
	break;

	case 85:

		/* Line 1455 of yacc.c  */
#line 354 "xscript.y"
	{
		(yyval.identifier) = (yyvsp[(1) - (2)].identifier);
	}
	break;

	case 86:

		/* Line 1455 of yacc.c  */
#line 360 "xscript.y"
	{
		(yyval.statement) = xs_create_while_statement((yyvsp[(1) - (6)].identifier), (yyvsp[(4) - (6)].expression), (yyvsp[(6) - (6)].block));
	}
	break;

	case 87:

		/* Line 1455 of yacc.c  */
#line 367 "xscript.y"
	{
		(yyval.statement) = xs_create_for_statement((yyvsp[(1) - (10)].identifier), (yyvsp[(4) - (10)].expression), (yyvsp[(6) - (10)].expression), (yyvsp[(8) - (10)].expression), (yyvsp[(10) - (10)].block));
	}
	break;

	case 88:

		/* Line 1455 of yacc.c  */
#line 373 "xscript.y"
	{
		(yyval.statement) = xs_create_foreach_statement((yyvsp[(1) - (8)].identifier), (yyvsp[(4) - (8)].identifier), (yyvsp[(6) - (8)].expression), (yyvsp[(8) - (8)].block));
	}
	break;

	case 89:

		/* Line 1455 of yacc.c  */
#line 379 "xscript.y"
	{
		(yyval.expression) = nullptr;
	}
	break;

	case 91:

		/* Line 1455 of yacc.c  */
#line 386 "xscript.y"
	{
		(yyval.statement) = xs_create_return_statement((yyvsp[(2) - (3)].expression));
	}
	break;

	case 92:

		/* Line 1455 of yacc.c  */
#line 392 "xscript.y"
	{
		(yyval.identifier) = nullptr;
	}
	break;

	case 94:

		/* Line 1455 of yacc.c  */
#line 399 "xscript.y"
	{
		(yyval.statement) = xs_create_break_statement((yyvsp[(2) - (3)].identifier));
	}
	break;

	case 95:

		/* Line 1455 of yacc.c  */
#line 405 "xscript.y"
	{
		(yyval.statement) = xs_create_continue_statement((yyvsp[(2) - (3)].identifier));
	}
	break;

	case 96:

		/* Line 1455 of yacc.c  */
#line 411 "xscript.y"
	{
		(yyval.statement) = xs_create_try_statement((yyvsp[(2) - (9)].block), (yyvsp[(5) - (9)].identifier), (yyvsp[(7) - (9)].block), (yyvsp[(9) - (9)].block));
	}
	break;

	case 97:

		/* Line 1455 of yacc.c  */
#line 415 "xscript.y"
	{
		(yyval.statement) = xs_create_try_statement((yyvsp[(2) - (4)].block), nullptr, nullptr, (yyvsp[(4) - (4)].block));
	}
	break;

	case 98:

		/* Line 1455 of yacc.c  */
#line 419 "xscript.y"
	{
		(yyval.statement) = xs_create_try_statement((yyvsp[(2) - (7)].block), (yyvsp[(5) - (7)].identifier), (yyvsp[(7) - (7)].block), nullptr);
	}
	break;

	case 99:

		/* Line 1455 of yacc.c  */
#line 424 "xscript.y"
	{
		(yyval.statement) = xs_create_throw_statement((yyvsp[(2) - (3)].expression));
	}
	break;

	case 100:

		/* Line 1455 of yacc.c  */
#line 429 "xscript.y"
	{
		(yyval.statement) = xs_create_declaration_statement((yyvsp[(1) - (3)].type_specifier), (yyvsp[(2) - (3)].identifier), nullptr);
	}
	break;

	case 101:

		/* Line 1455 of yacc.c  */
#line 433 "xscript.y"
	{
		(yyval.statement) = xs_create_declaration_statement((yyvsp[(1) - (5)].type_specifier), (yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].expression));
	}
	break;

	case 102:

		/* Line 1455 of yacc.c  */
#line 439 "xscript.y"
	{
		(yyval.block) = xs_open_block();
	}
	break;

	case 103:

		/* Line 1455 of yacc.c  */
#line 443 "xscript.y"
	{
		(yyval.block) = xs_close_block((yyvsp[(2) - (4)].block), (yyvsp[(3) - (4)].statement_list));
	}
	break;

	case 104:

		/* Line 1455 of yacc.c  */
#line 447 "xscript.y"
	{
		Block empty_block = xs_open_block();
		(yyval.block) = xs_close_block(empty_block, nullptr);
	}
	break;



	/* Line 1455 of yacc.c  */
#line 2326 "y.tab.c"
	default: break;
	}
	YY_SYMBOL_PRINT("-> $$ =", yyr1[yyn], &yyval, &yyloc);

	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);

	*++yyvsp = yyval;

	/* Now `shift' the result of the reduction.  Determine what state
	that goes to, based on the state we popped back to and the rule
	number reduced by.  */

	yyn = yyr1[yyn];

	yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
	if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
		yystate = yytable[yystate];
	else
		yystate = yydefgoto[yyn - YYNTOKENS];

	goto yynewstate;


	/*------------------------------------.
	| yyerrlab -- here on detecting error |
	`------------------------------------*/
yyerrlab:
	/* If not already recovering from an error, report this error.  */
	if (!yyerrstatus)
	{
		++yynerrs;
#if ! YYERROR_VERBOSE
		yyerror(YY_("syntax error"));
#else
		{
			YYSIZE_T yysize = yysyntax_error(0, yystate, yychar);
			if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
			{
				YYSIZE_T yyalloc = 2 * yysize;
				if (!(yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
					yyalloc = YYSTACK_ALLOC_MAXIMUM;
				if (yymsg != yymsgbuf)
					YYSTACK_FREE(yymsg);
				yymsg = (char *)YYSTACK_ALLOC(yyalloc);
				if (yymsg)
					yymsg_alloc = yyalloc;
				else
				{
					yymsg = yymsgbuf;
					yymsg_alloc = sizeof yymsgbuf;
				}
			}

			if (0 < yysize && yysize <= yymsg_alloc)
			{
				(void)yysyntax_error(yymsg, yystate, yychar);
				yyerror(yymsg);
			}
			else
			{
				yyerror(YY_("syntax error"));
				if (yysize != 0)
					goto yyexhaustedlab;
			}
		}
#endif
	}



	if (yyerrstatus == 3)
	{
		/* If just tried and failed to reuse lookahead token after an
		error, discard it.  */

		if (yychar <= YYEOF)
		{
			/* Return failure if at end of input.  */
			if (yychar == YYEOF)
				YYABORT;
		}
		else
		{
			yydestruct("Error: discarding",
				yytoken, &yylval);
			yychar = YYEMPTY;
		}
	}

	/* Else will try to reuse lookahead token after shifting the error
	token.  */
	goto yyerrlab1;


	/*---------------------------------------------------.
	| yyerrorlab -- error raised explicitly by YYERROR.  |
	`---------------------------------------------------*/
yyerrorlab:

	/* Pacify compilers like GCC when the user code never invokes
	YYERROR and the label yyerrorlab therefore never appears in user
	code.  */
	if (/*CONSTCOND*/ 0)
		goto yyerrorlab;

	/* Do not reclaim the symbols of the rule which action triggered
	this YYERROR.  */
	YYPOPSTACK(yylen);
	yylen = 0;
	YY_STACK_PRINT(yyss, yyssp);
	yystate = *yyssp;
	goto yyerrlab1;


	/*-------------------------------------------------------------.
	| yyerrlab1 -- common code for both syntax error and YYERROR.  |
	`-------------------------------------------------------------*/
yyerrlab1:
	yyerrstatus = 3;	/* Each real token shifted decrements this.  */

	for (;;)
	{
		yyn = yypact[yystate];
		if (yyn != YYPACT_NINF)
		{
			yyn += YYTERROR;
			if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
			{
				yyn = yytable[yyn];
				if (0 < yyn)
					break;
			}
		}

		/* Pop the current state because it cannot handle the error token.  */
		if (yyssp == yyss)
			YYABORT;


		yydestruct("Error: popping",
			yystos[yystate], yyvsp);
		YYPOPSTACK(1);
		yystate = *yyssp;
		YY_STACK_PRINT(yyss, yyssp);
	}

	*++yyvsp = yylval;


	/* Shift the error token.  */
	YY_SYMBOL_PRINT("Shifting", yystos[yyn], yyvsp, yylsp);

	yystate = yyn;
	goto yynewstate;


	/*-------------------------------------.
	| yyacceptlab -- YYACCEPT comes here.  |
	`-------------------------------------*/
yyacceptlab:
	yyresult = 0;
	goto yyreturn;

	/*-----------------------------------.
	| yyabortlab -- YYABORT comes here.  |
	`-----------------------------------*/
yyabortlab:
	yyresult = 1;
	goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
	/*-------------------------------------------------.
	| yyexhaustedlab -- memory exhaustion comes here.  |
	`-------------------------------------------------*/
	yyexhaustedlab :
				   yyerror(YY_("memory exhausted"));
				   yyresult = 2;
				   /* Fall through.  */
#endif

			   yyreturn:
				   if (yychar != YYEMPTY)
					   yydestruct("Cleanup: discarding lookahead",
						   yytoken, &yylval);
				   /* Do not reclaim the symbols of the rule which action triggered
				   this YYABORT or YYACCEPT.  */
				   YYPOPSTACK(yylen);
				   YY_STACK_PRINT(yyss, yyssp);
				   while (yyssp != yyss)
				   {
					   yydestruct("Cleanup: popping",
						   yystos[*yyssp], yyvsp);
					   YYPOPSTACK(1);
				   }
#ifndef yyoverflow
				   if (yyss != yyssa)
					   YYSTACK_FREE(yyss);
#endif
#if YYERROR_VERBOSE
				   if (yymsg != yymsgbuf)
					   YYSTACK_FREE(yymsg);
#endif
				   /* Make sure YYID is used.  */
				   return YYID(yyresult);
}



/* Line 1675 of yacc.c  */
#line 452 "xscript.y"

