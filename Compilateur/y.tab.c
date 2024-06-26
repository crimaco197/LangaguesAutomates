/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tTEXT = 258,
     tID = 259,
     tSTRING = 260,
     tNB = 261,
     tVOID = 262,
     tINT = 263,
     tMAIN = 264,
     tPOINTER = 265,
     tCDIV = 266,
     tSPAN = 267,
     tCSPAN = 268,
     tIF = 269,
     tELSE = 270,
     tWHILE = 271,
     tSUB = 272,
     tADD = 273,
     tDIV = 274,
     tMUL = 275,
     tASSIGN = 276,
     tLT = 277,
     tGT = 278,
     tNE = 279,
     tEQ = 280,
     tGE = 281,
     tLE = 282,
     tAND = 283,
     tOR = 284,
     tNOT = 285,
     tLBRACE = 286,
     tRBRACE = 287,
     tLPAR = 288,
     tRPAR = 289,
     tSEMI = 290,
     tCOMMA = 291,
     tERROR = 292,
     tPRINT = 293,
     tRETURN = 294
   };
#endif
/* Tokens.  */
#define tTEXT 258
#define tID 259
#define tSTRING 260
#define tNB 261
#define tVOID 262
#define tINT 263
#define tMAIN 264
#define tPOINTER 265
#define tCDIV 266
#define tSPAN 267
#define tCSPAN 268
#define tIF 269
#define tELSE 270
#define tWHILE 271
#define tSUB 272
#define tADD 273
#define tDIV 274
#define tMUL 275
#define tASSIGN 276
#define tLT 277
#define tGT 278
#define tNE 279
#define tEQ 280
#define tGE 281
#define tLE 282
#define tAND 283
#define tOR 284
#define tNOT 285
#define tLBRACE 286
#define tRBRACE 287
#define tLPAR 288
#define tRPAR 289
#define tSEMI 290
#define tCOMMA 291
#define tERROR 292
#define tPRINT 293
#define tRETURN 294




/* Copy the first part of user declarations.  */
#line 1 "analizador.y"

/* Oussama Eljid */
/*  Cristian Martinez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "instruction_table.h"
#include "declaration_var.h"


int address_symbol_previous;
int address_variable;
int address_var_TMP;
int address_function = -1;
int address_main = 0;

char* nameID;
int numberID;
int in_arithmetic_operation = 0; // variable test add COP or NOT in tNB
int idJMF = 0;
int varFirstIF = 0;

int whileIndex = 0;
int varFirstWhile = 0;

int var_to_delete_arg = 0;
int varFirstJMP = 0;
int returnBool = 0;

int mainBool = 0;


int address_POINTER = 0;
int pointer_bool = 0;




char* nameFunction;





// DECLARATING FUNCTIONS
void yyerror(const char *s);
int yylex(void); 


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 52 "analizador.y"
{ 
    char *s;
    int i;
}
/* Line 193 of yacc.c.  */
#line 230 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 243 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     9,    10,    11,    22,    24,
      27,    29,    31,    32,    37,    38,    39,    49,    56,    60,
      61,    66,    67,    70,    72,    75,    78,    80,    83,    90,
      95,    97,    99,   100,   109,   111,   113,   114,   123,   125,
     126,   130,   131,   138,   139,   146,   149,   151,   154,   158,
     162,   166,   170,   174,   178,   182,   186,   190,   193,   200,
     201,   207,   209,   211,   215,   216,   221,   226,   228,   230,
     232,   233,   239,   241,   245,   249,   253,   257,   259,   261,
     263,   265,   267,   268,   270,   272,   274,   278,   280,   282
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    -1,    42,    -1,    47,    41,    -1,    -1,
      -1,    46,     9,    43,    33,    82,    34,    31,    44,    45,
      32,    -1,    55,    -1,    55,    53,    -1,     7,    -1,     8,
      -1,    -1,     7,     4,    48,    51,    -1,    -1,    -1,     8,
       4,    49,    33,    82,    34,    50,    52,    32,    -1,    33,
      82,    34,    31,    55,    32,    -1,    31,    55,    53,    -1,
      -1,    39,    54,    78,    35,    -1,    -1,    55,    56,    -1,
      57,    -1,    70,    35,    -1,    58,    35,    -1,    59,    -1,
      76,    35,    -1,    38,    33,     5,     4,     5,    34,    -1,
      38,    33,    78,    34,    -1,    63,    -1,    60,    -1,    -1,
      16,    33,    69,    34,    61,    31,    62,    32,    -1,    55,
      -1,    53,    -1,    -1,    14,    33,    69,    34,    64,    31,
      55,    65,    -1,    32,    -1,    -1,    32,    66,    52,    -1,
      -1,    32,    15,    31,    67,    55,    32,    -1,    -1,    32,
      15,    31,    68,    52,    32,    -1,    53,    32,    -1,    81,
      -1,    30,    81,    -1,    69,    28,    69,    -1,    69,    30,
      69,    -1,    69,    27,    69,    -1,    69,    26,    69,    -1,
      69,    25,    69,    -1,    69,    24,    69,    -1,    69,    23,
      69,    -1,    69,    22,    69,    -1,    69,    29,    69,    -1,
       8,    72,    -1,     8,    20,     4,    21,    10,     4,    -1,
      -1,     8,     4,    21,    71,    78,    -1,    73,    -1,    73,
      -1,    72,    36,    73,    -1,    -1,     4,    74,    21,    78,
      -1,    20,     4,    21,     6,    -1,     4,    -1,    78,    -1,
      82,    -1,    -1,     4,    33,    77,    75,    34,    -1,    81,
      -1,    78,    18,    78,    -1,    78,    17,    78,    -1,    78,
      19,    78,    -1,    78,    20,    78,    -1,     4,    -1,     6,
      -1,    79,    -1,    80,    -1,    76,    -1,    -1,    84,    -1,
      81,    -1,    85,    -1,    83,    36,    84,    -1,    83,    -1,
       7,    -1,     8,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    77,    78,    81,    88,    81,    98,    99,
     103,   104,   107,   107,   108,   113,   108,   119,   124,   126,
     126,   145,   146,   150,   154,   155,   156,   157,   160,   161,
     165,   166,   169,   169,   178,   179,   182,   182,   190,   191,
     191,   192,   192,   193,   193,   194,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   211,   212,   213,
     213,   220,   224,   225,   228,   228,   233,   237,   240,   241,
     244,   244,   247,   248,   249,   250,   251,   254,   257,   260,
     261,   262,   265,   266,   269,   270,   272,   273,   276,   277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tTEXT", "tID", "tSTRING", "tNB",
  "tVOID", "tINT", "tMAIN", "tPOINTER", "tCDIV", "tSPAN", "tCSPAN", "tIF",
  "tELSE", "tWHILE", "tSUB", "tADD", "tDIV", "tMUL", "tASSIGN", "tLT",
  "tGT", "tNE", "tEQ", "tGE", "tLE", "tAND", "tOR", "tNOT", "tLBRACE",
  "tRBRACE", "tLPAR", "tRPAR", "tSEMI", "tCOMMA", "tERROR", "tPRINT",
  "tRETURN", "$accept", "Program", "main", "@1", "@2", "BodyMain", "type",
  "fun", "@3", "@4", "@5", "Body", "functionBodyReturn", "returnStatement",
  "@6", "structure", "context", "action", "print", "bucles", "while", "@7",
  "whileStructure", "if", "@8", "ifStructure", "@9", "@10", "@11",
  "condition", "declaration", "@12", "assignationAuxList",
  "assignationAux", "@13", "functionArgs", "functionBody", "@14",
  "operationArith", "idName", "idNumber", "var", "args", "argVar",
  "argList", "arg", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    43,    44,    42,    45,    45,
      46,    46,    48,    47,    49,    50,    47,    51,    52,    54,
      53,    55,    55,    56,    57,    57,    57,    57,    58,    58,
      59,    59,    61,    60,    62,    62,    64,    63,    65,    66,
      65,    67,    65,    68,    65,    65,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    70,    71,
      70,    70,    72,    72,    74,    73,    73,    73,    75,    75,
      77,    76,    78,    78,    78,    78,    78,    79,    80,    81,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     0,     0,    10,     1,     2,
       1,     1,     0,     4,     0,     0,     9,     6,     3,     0,
       4,     0,     2,     1,     2,     2,     1,     2,     6,     4,
       1,     1,     0,     8,     1,     1,     0,     8,     1,     0,
       3,     0,     6,     0,     6,     2,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     6,     0,
       5,     1,     1,     3,     0,     4,     4,     1,     1,     1,
       0,     5,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     3,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    10,    11,     0,     3,     0,     2,    12,    14,     1,
       5,     4,     0,     0,     0,    82,    13,    82,    82,    77,
      78,    88,     0,    81,    79,    80,    84,     0,    87,    83,
      85,     0,     0,    70,    89,     0,     0,    15,     0,    82,
      21,    86,     0,     6,     0,    68,    72,    69,     0,    21,
       0,    21,    71,     0,     0,     0,     0,    64,     0,     0,
       0,     0,    17,     0,    22,    23,     0,    26,    31,    30,
       0,    61,     0,     0,    16,     0,     8,    74,    72,    73,
      75,    76,     0,    67,     0,    57,    62,     0,     0,     0,
       0,    25,    24,    27,    19,    18,     7,     9,     0,    59,
       0,     0,     0,     0,    46,     0,     0,     0,     0,     0,
      65,     0,     0,    67,    63,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    32,    66,     0,    29,
       0,    60,     0,    55,    54,    53,    52,    51,    50,    48,
      56,    49,     0,     0,     0,    20,    58,    21,    21,    28,
       0,    35,    34,     0,    38,     0,    37,    33,     0,     0,
      45,    41,    40,    21,     0,     0,     0,    42,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    14,    51,    75,     5,     6,    12,    13,
      42,    16,    50,    95,   109,    48,    64,    65,    66,    67,
      68,   143,   153,    69,   142,   156,   159,   163,   164,   103,
      70,   111,    85,    71,    82,    44,    23,    39,    45,    24,
      25,   104,    27,    28,    29,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -97
static const yytype_int16 yypact[] =
{
      14,    30,    47,    74,   -97,    82,    14,   -97,   -97,   -97,
     -97,   -97,    65,    75,    76,    88,   -97,    88,    88,    85,
     -97,   -97,   119,   -97,   -97,   -97,   -97,    90,   100,   -97,
     -97,   101,   105,   -97,   -97,   109,    88,   -97,   111,    88,
     -97,   -97,   112,   -97,   107,   110,   118,   -97,    99,   -97,
     124,   -97,   -97,    63,    63,    63,    63,    50,     9,   122,
     134,   164,   -97,   147,   -97,   -97,   146,   -97,   -97,   -97,
     148,   -97,   150,    32,   -97,   137,    32,    60,   -97,    60,
     -97,   -97,   161,   163,   182,   151,   -97,     8,     8,   167,
     128,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    63,   -97,
     168,    19,    63,   123,   -97,   136,   184,   187,    13,    63,
     110,    63,   115,   171,   -97,   -97,     8,     8,     8,     8,
       8,     8,     8,     8,     8,   -97,   -97,   -97,   188,   -97,
       0,   110,   190,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   165,   166,   169,   -97,   -97,   -97,   156,   -97,
      73,   -97,    68,   170,    34,   172,   -97,   -97,   174,   112,
     -97,   175,   -97,   -97,   112,   106,   176,   -97,   -97
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   192,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -96,   -75,   -97,   -47,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -62,
     -97,   -97,   -97,   -51,   -97,   -97,   -48,   -97,   -45,   -97,
     -97,   -12,    -2,   -97,   173,   -97
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -85
static const yytype_int16 yytable[] =
{
      72,    97,    73,    26,    76,    26,    26,    86,    77,    79,
      80,    81,    19,    83,    20,    31,    32,    53,    54,    55,
      56,     1,     2,   113,    26,    72,   105,    46,    72,    84,
      53,    54,    55,    56,     7,   145,    57,    47,   102,    61,
      58,    78,    78,    78,    78,   108,    59,   129,    60,   158,
     114,     8,    61,   110,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   162,   130,   -39,   131,    19,   166,    20,
      63,    94,    57,   151,     9,   155,    58,    57,    78,    55,
      56,    58,    59,    33,    60,   -67,    78,    59,    61,    60,
     115,    10,    19,    61,    20,    21,    22,    78,    15,    78,
     150,   152,    72,    57,    72,   154,    63,    58,    17,    18,
      57,    63,    94,    59,    58,    60,   165,    72,    33,    61,
      59,   127,    60,    34,    35,   132,    61,    53,    54,    55,
      56,    62,    19,   107,    20,    37,    36,    63,   167,    38,
      40,    52,    43,    49,    63,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   -84,    87,    74,   125,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    88,    89,    96,
     126,   116,   117,   118,   119,   120,   121,   122,   123,   124,
      90,    91,    98,    92,    99,    93,   100,   101,   106,   112,
     127,   128,   -64,   144,   146,    94,   147,   148,    11,     0,
       0,     0,   157,   149,   160,   161,   -43,     0,   168,    41
};

static const yytype_int16 yycheck[] =
{
      48,    76,    49,    15,    51,    17,    18,    58,    53,    54,
      55,    56,     4,     4,     6,    17,    18,    17,    18,    19,
      20,     7,     8,     4,    36,    73,    88,    39,    76,    20,
      17,    18,    19,    20,     4,    35,     4,    39,    30,    20,
       8,    53,    54,    55,    56,    90,    14,    34,    16,    15,
     101,     4,    20,    98,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   159,   109,    31,   111,     4,   164,     6,
      38,    39,     4,   148,     0,   150,     8,     4,    90,    19,
      20,     8,    14,    33,    16,    35,    98,    14,    20,    16,
     102,     9,     4,    20,     6,     7,     8,   109,    33,   111,
     147,   148,   150,     4,   152,    32,    38,     8,    33,    33,
       4,    38,    39,    14,     8,    16,   163,   165,    33,    20,
      14,     6,    16,     4,    34,    10,    20,    17,    18,    19,
      20,    32,     4,     5,     6,    34,    36,    38,    32,    34,
      31,    34,    31,    31,    38,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    36,    33,    32,    34,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    33,     4,    32,
      34,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      33,    35,    21,    35,    21,    35,     4,    36,    21,    21,
       6,     4,    21,     5,     4,    39,    31,    31,     6,    -1,
      -1,    -1,    32,    34,    32,    31,    31,    -1,    32,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    41,    42,    46,    47,     4,     4,     0,
       9,    41,    48,    49,    43,    33,    51,    33,    33,     4,
       6,     7,     8,    76,    79,    80,    81,    82,    83,    84,
      85,    82,    82,    33,     4,    34,    36,    34,    34,    77,
      31,    84,    50,    31,    75,    78,    81,    82,    55,    31,
      52,    44,    34,    17,    18,    19,    20,     4,     8,    14,
      16,    20,    32,    38,    56,    57,    58,    59,    60,    63,
      70,    73,    76,    55,    32,    45,    55,    78,    81,    78,
      78,    78,    74,     4,    20,    72,    73,    33,    33,     4,
      33,    35,    35,    35,    39,    53,    32,    53,    21,    21,
       4,    36,    30,    69,    81,    69,    21,     5,    78,    54,
      78,    71,    21,     4,    73,    81,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    34,    34,     6,     4,    34,
      78,    78,    10,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    64,    61,     5,    35,     4,    31,    31,    34,
      55,    53,    55,    62,    32,    53,    65,    32,    15,    66,
      32,    31,    52,    67,    68,    55,    52,    32,    32
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
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
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
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
yytnamerr (char *yyres, const char *yystr)
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
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
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
      yyfmt = yystpcpy (yyformat, yyunexpected);

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
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
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
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

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
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 81 "analizador.y"
    { printf("Function MAIN Found : %s\n", yytext); 
                   mainBool = 1;
                   nameFunction = "main"; 
                   add_symbol("?ADR", nameFunction, 0);
                   add_symbol("?VAL", nameFunction, 0);
                   address_main = address_instruction;
        }
    break;

  case 6:
#line 88 "analizador.y"
    { returnBool = 0;}
    break;

  case 7:
#line 89 "analizador.y"
    {  
                            delete_adr_val();
                            add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                            update_instruction("JMP", varFirstJMP, address_main, 0,0 ); 
                            add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  
                            mainBool = 0;
}
    break;

  case 10:
#line 103 "analizador.y"
    { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); }
    break;

  case 11:
#line 104 "analizador.y"
    { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); }
    break;

  case 12:
#line 107 "analizador.y"
    {  printf("Function VOID Found : %s\n", yytext); nameFunction = "int"; }
    break;

  case 14:
#line 108 "analizador.y"
    { printf("Function INT Found : %s\n", yytext);
                 nameFunction = "int";
                 add_symbol("?ADR", nameFunction, 0);  // OK
                 add_symbol("?VAL", nameFunction, 0); 
      }
    break;

  case 15:
#line 113 "analizador.y"
    { varFirstJMP = address_instruction;
                         add_instruction( "JMP", address_instruction, -999 , 0 , 0 ); 
                         address_function = address_instruction; }
    break;

  case 16:
#line 116 "analizador.y"
    { delete_adr_val(); delete_last_symbol(var_to_delete_arg); }
    break;

  case 17:
#line 119 "analizador.y"
    { add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  }
    break;

  case 19:
#line 126 "analizador.y"
    { 
                            returnBool = 1; 
                  }
    break;

  case 20:
#line 129 "analizador.y"
    {
                                    address_variable = find_symbol("?VAL");  
                                    if (returnBool){
                                        delete_symbol(address_var_TMP);
                                        add_instruction( "COP", address_instruction, address_variable , address_symbol , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                        
                                        break;
                                    }
                                    if(returnBool && !mainBool){
                                        add_instruction( "COPrrr", address_instruction, address_variable , address_symbol , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                    }
}
    break;

  case 28:
#line 160 "analizador.y"
    { add_instruction("PRI", address_instruction,numberID,0,0);  delete_symbol(address_var_TMP);  }
    break;

  case 29:
#line 161 "analizador.y"
    { add_instruction("PRI", address_instruction, numberID,0,0);  delete_symbol(address_var_TMP);    // On ajoute l'instruction PRI
}
    break;

  case 32:
#line 169 "analizador.y"
    {  delete_symbol(address_var_TMP); 
                                      varFirstWhile++;
                                      whileIndex = address_instruction;
                                      add_instruction( "JMF", 2, varFirstWhile , -999 , 0 );
                                      idJMF = varFirstWhile;
                                      push(idJMF);
        }
    break;

  case 33:
#line 175 "analizador.y"
    { update_jmf(); add_instruction( "JMP", address_instruction, whileIndex , 0 , 0 ); }
    break;

  case 36:
#line 182 "analizador.y"
    { delete_symbol(address_var_TMP); 
                                varFirstIF++;
                                add_instruction( "JMF", 1, varFirstIF , -999 , 0 );
                                idJMF = varFirstIF;
                                push(idJMF);
    }
    break;

  case 38:
#line 190 "analizador.y"
    { update_jmf();}
    break;

  case 39:
#line 191 "analizador.y"
    { update_jmf();}
    break;

  case 41:
#line 192 "analizador.y"
    { update_jmf();}
    break;

  case 43:
#line 193 "analizador.y"
    { update_jmf();}
    break;

  case 45:
#line 194 "analizador.y"
    { update_jmf();}
    break;

  case 58:
#line 212 "analizador.y"
    { nameID = (yyvsp[(3) - (6)].s); add_symbol((yyvsp[(3) - (6)].s), "POINTER", find_symbol((yyvsp[(6) - (6)].s))); }
    break;

  case 59:
#line 213 "analizador.y"
    { nameID = (yyvsp[(2) - (3)].s); add_symbol((yyvsp[(2) - (3)].s), nameFunction, 0);  }
    break;

  case 60:
#line 213 "analizador.y"
    { address_variable = find_symbol((yyvsp[(2) - (5)].s)); 
                                                                                                    delete_symbol(address_var_TMP);
                                                                                                 //  if(address_main){address_var_TMP = address_var_TMP - 2; }; 
                                                                                                    add_instruction("COP", address_instruction, address_variable, address_var_TMP, 0);  
                                                                                                    // printf("DELETING add_operation  : %d\n", address_var_TMP); 
                                                                                                    
                                                                                                     }
    break;

  case 64:
#line 228 "analizador.y"
    {  nameID = (yyvsp[(1) - (1)].s);  }
    break;

  case 65:
#line 228 "analizador.y"
    { 
                    delete_symbol(address_var_TMP); 
                    address_variable = find_symbol((yyvsp[(1) - (4)].s)); 
                    add_instruction("COP", address_instruction, address_variable, address_symbol, 0); 
                 }
    break;

  case 66:
#line 233 "analizador.y"
    {  
                    find_symbol((yyvsp[(2) - (4)].s));
                    add_instruction("ACF", address_instruction, address_POINTER, (yyvsp[(4) - (4)].i), 0); 
                 }
    break;

  case 67:
#line 237 "analizador.y"
    {  add_symbol((yyvsp[(1) - (1)].s), nameFunction, 0); }
    break;

  case 68:
#line 240 "analizador.y"
    { fin_function(); }
    break;

  case 69:
#line 241 "analizador.y"
    { fin_function(); }
    break;

  case 70:
#line 244 "analizador.y"
    { add_adr_val(); }
    break;

  case 73:
#line 248 "analizador.y"
    { in_arithmetic_operation = 1; add_operation("ADD"); }
    break;

  case 74:
#line 249 "analizador.y"
    { in_arithmetic_operation = 1; add_operation("SUB"); }
    break;

  case 75:
#line 250 "analizador.y"
    { in_arithmetic_operation = 1; add_operation("DIV"); }
    break;

  case 76:
#line 251 "analizador.y"
    { in_arithmetic_operation = 1; add_operation("MUL"); }
    break;

  case 77:
#line 254 "analizador.y"
    {  add_symbol((yyvsp[(1) - (1)].s) , nameFunction, 0);  }
    break;

  case 78:
#line 257 "analizador.y"
    { numberID = (yyvsp[(1) - (1)].i); add_symbol("tmp" , nameFunction, (yyvsp[(1) - (1)].i));}
    break;

  case 89:
#line 277 "analizador.y"
    {  add_symbol((yyvsp[(2) - (2)].s), nameFunction, 0); 
                  var_to_delete_arg = find_symbol((yyvsp[(2) - (2)].s));
         }
    break;


/* Line 1267 of yacc.c.  */
#line 1851 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
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
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 282 "analizador.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d - ERROR JUST BEFORE SYMBOL %s\n", s, yylineno, yytext);
}


int main() {
    symbol_table = create_symbol_table();
    instruction_table = create_instruction_table();
    yyparse();
    print_symbol_table();
    print_instruction_table();
    return 0;
}

