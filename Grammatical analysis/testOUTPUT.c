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
     tCDIV = 265,
     tSPAN = 266,
     tCSPAN = 267,
     tIF = 268,
     tELSE = 269,
     tWHILE = 270,
     tSUB = 271,
     tADD = 272,
     tDIV = 273,
     tMUL = 274,
     tASSIGN = 275,
     tLT = 276,
     tGT = 277,
     tNE = 278,
     tEQ = 279,
     tGE = 280,
     tLE = 281,
     tAND = 282,
     tOR = 283,
     tNOT = 284,
     tLBRACE = 285,
     tRBRACE = 286,
     tLPAR = 287,
     tRPAR = 288,
     tSEMI = 289,
     tCOMMA = 290,
     tERROR = 291,
     tPRINT = 292,
     tRETURN = 293
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
#define tCDIV 265
#define tSPAN 266
#define tCSPAN 267
#define tIF 268
#define tELSE 269
#define tWHILE 270
#define tSUB 271
#define tADD 272
#define tDIV 273
#define tMUL 274
#define tASSIGN 275
#define tLT 276
#define tGT 277
#define tNE 278
#define tEQ 279
#define tGE 280
#define tLE 281
#define tAND 282
#define tOR 283
#define tNOT 284
#define tLBRACE 285
#define tRBRACE 286
#define tLPAR 287
#define tRPAR 288
#define tSEMI 289
#define tCOMMA 290
#define tERROR 291
#define tPRINT 292
#define tRETURN 293




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


int global_number;
int address_symbol_previous;
int address_variable;
int address_var_TMP;
int address_function = 0;
int address_main = 0;
char* variableTMP;
char* nameID;
int numberID;
int in_arithmetic_operation = 0; // variable test add COP or NOT in tNB
int idJMF = 0;
int varFirstIF = 0;
int var_to_delete = 0;
int varFirstJMP = 0;
int returnBool = 0;
int args_operation = 0;
int mainBool = 0;

int address_operand1 = 0;
int address_operand2 = 0;
int address_result = 0;

char* nameIDtemporal;


char *nameFunction;





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
#line 49 "analizador.y"
{ 
    char *s;
    int i;
}
/* Line 193 of yacc.c.  */
#line 225 "testOUTPUT.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "testOUTPUT.c"

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
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    11,    17,    19,    21,
      22,    27,    28,    29,    39,    46,    52,    53,    61,    65,
      68,    69,    74,    75,    77,    80,    82,    84,    87,    89,
      92,    99,   104,   106,   108,   109,   117,   120,   123,   124,
     131,   135,   136,   145,   150,   151,   160,   165,   169,   171,
     174,   178,   182,   186,   190,   194,   198,   202,   206,   210,
     214,   218,   222,   223,   230,   233,   236,   237,   242,   244,
     245,   249,   250,   251,   256,   260,   261,   267,   268,   270,
     272,   274,   276,   280,   281,   286,   287,   292,   293,   298,
     299,   304,   306,   307,   312,   313,   318,   319,   324,   325,
     330,   332,   334,   336,   337,   339,   341,   344
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    41,    -1,    44,    -1,    44,    40,    -1,
      -1,    43,     9,    42,    49,    31,    -1,     7,    -1,     8,
      -1,    -1,     7,     4,    45,    48,    -1,    -1,    -1,     8,
       4,    46,    32,    89,    33,    47,    51,    31,    -1,    32,
      89,    33,    30,    54,    31,    -1,    32,    89,    33,    30,
      54,    -1,    -1,    32,    89,    33,    30,    50,    54,    52,
      -1,    30,    54,    52,    -1,    30,    52,    -1,    -1,    38,
      53,    83,    34,    -1,    -1,    55,    -1,    55,    54,    -1,
      56,    -1,    68,    -1,    57,    34,    -1,    58,    -1,    75,
      34,    -1,    37,    32,     5,     4,     5,    33,    -1,    37,
      32,    83,    33,    -1,    62,    -1,    59,    -1,    -1,    15,
      32,    67,    33,    60,    61,    31,    -1,    30,    54,    -1,
      30,    52,    -1,    -1,    13,    32,    67,    33,    63,    64,
      -1,    30,    54,    31,    -1,    -1,    30,    54,    31,    14,
      30,    65,    54,    31,    -1,    30,    54,    31,    51,    -1,
      -1,    30,    54,    31,    14,    30,    66,    51,    31,    -1,
      30,    54,    52,    31,    -1,    30,    52,    31,    -1,    88,
      -1,    29,     4,    -1,    88,    27,    67,    -1,    88,    29,
      67,    -1,    88,    26,    67,    -1,    88,    25,    67,    -1,
      88,    24,    67,    -1,    88,    23,    67,    -1,    88,    22,
      67,    -1,    88,    21,    67,    -1,    88,    28,    67,    -1,
      32,    67,    33,    -1,     8,    70,    34,    -1,     8,    73,
      34,    -1,    -1,     8,     4,    20,    69,    83,    34,    -1,
      70,    34,    -1,    73,    34,    -1,    -1,     4,    71,    35,
      70,    -1,     4,    -1,    -1,     4,    72,    35,    -1,    -1,
      -1,     4,    74,    20,    83,    -1,    73,    35,    73,    -1,
      -1,     4,    32,    76,    77,    33,    -1,    -1,    78,    -1,
       4,    -1,     6,    -1,    75,    -1,    78,    35,    78,    -1,
      -1,    78,    79,    18,    78,    -1,    -1,    78,    80,    19,
      78,    -1,    -1,    78,    81,    16,    78,    -1,    -1,    78,
      82,    17,    78,    -1,    88,    -1,    -1,    83,    84,    19,
      88,    -1,    -1,    83,    85,    18,    88,    -1,    -1,    83,
      86,    17,    88,    -1,    -1,    83,    87,    16,    88,    -1,
       4,    -1,     6,    -1,    75,    -1,    -1,    90,    -1,     7,
      -1,     8,     4,    -1,    90,    35,     8,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    69,    70,    73,    73,   108,   109,   112,
     112,   113,   118,   113,   133,   136,   166,   166,   187,   188,
     191,   191,   220,   221,   222,   226,   230,   231,   232,   233,
     236,   237,   241,   242,   245,   245,   276,   286,   289,   289,
     312,   330,   330,   340,   341,   341,   351,   352,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     378,   379,   380,   380,   382,   383,   399,   399,   404,   408,
     408,   408,   411,   411,   412,   415,   415,   458,   459,   462,
     467,   476,   477,   478,   478,   486,   486,   494,   494,   505,
     505,   515,   516,   516,   547,   547,   565,   565,   595,   595,
     616,   632,   657,   660,   661,   664,   665,   669
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tTEXT", "tID", "tSTRING", "tNB",
  "tVOID", "tINT", "tMAIN", "tCDIV", "tSPAN", "tCSPAN", "tIF", "tELSE",
  "tWHILE", "tSUB", "tADD", "tDIV", "tMUL", "tASSIGN", "tLT", "tGT", "tNE",
  "tEQ", "tGE", "tLE", "tAND", "tOR", "tNOT", "tLBRACE", "tRBRACE",
  "tLPAR", "tRPAR", "tSEMI", "tCOMMA", "tERROR", "tPRINT", "tRETURN",
  "$accept", "Program", "main", "@1", "type", "fun", "@2", "@3", "@4",
  "Body", "BodyMain", "@5", "functionBodyReturn", "returnStatement", "@6",
  "structure", "context", "action", "print", "bucles", "while", "@7",
  "whileStructure", "if", "@8", "ifStructure", "@9", "@10", "condition",
  "declaration", "@11", "assignation", "@12", "@13", "assignationAux",
  "@14", "functionName", "@15", "argsName", "argListName", "@16", "@17",
  "@18", "@19", "resultat", "@20", "@21", "@22", "@23", "var", "args",
  "argList", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    42,    41,    43,    43,    45,
      44,    46,    47,    44,    48,    49,    50,    49,    51,    51,
      53,    52,    54,    54,    54,    55,    56,    56,    56,    56,
      57,    57,    58,    58,    60,    59,    61,    61,    63,    62,
      64,    65,    64,    64,    66,    64,    64,    64,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    69,    68,    68,    68,    71,    70,    70,    72,
      70,    73,    74,    73,    73,    76,    75,    77,    77,    78,
      78,    78,    78,    79,    78,    80,    78,    81,    78,    82,
      78,    83,    84,    83,    85,    83,    86,    83,    87,    83,
      88,    88,    88,    89,    89,    90,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     5,     1,     1,     0,
       4,     0,     0,     9,     6,     5,     0,     7,     3,     2,
       0,     4,     0,     1,     2,     1,     1,     2,     1,     2,
       6,     4,     1,     1,     0,     7,     2,     2,     0,     6,
       3,     0,     8,     4,     0,     8,     4,     3,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     6,     2,     2,     0,     4,     1,     0,
       3,     0,     0,     4,     3,     0,     5,     0,     1,     1,
       1,     1,     3,     0,     4,     0,     4,     0,     4,     0,
       4,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       1,     1,     1,     0,     1,     1,     2,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     8,     0,     2,     0,     3,     9,    11,     1,
       5,     4,     0,     0,     0,   103,    10,   103,   103,     0,
     105,     0,     0,   104,     0,     0,     6,   106,     0,     0,
      12,     0,    71,     0,     0,    16,    66,    71,     0,     0,
       0,     0,    22,    25,     0,    28,    33,    32,    26,     0,
       0,     0,   107,    71,     0,    71,    15,    75,     0,     0,
       0,    66,     0,     0,     0,     0,     0,    14,    24,    27,
      64,    65,    71,    29,    20,    19,     0,    13,     0,    77,
       0,    70,     0,    62,    60,    61,   100,   101,     0,     0,
       0,   102,    48,     0,     0,    92,    91,    72,    74,     0,
      18,    17,    79,    80,    81,     0,    78,    66,    67,    73,
       0,    49,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    31,     0,     0,     0,     0,
      92,    76,     0,     0,     0,     0,     0,    92,    59,     0,
      57,    56,    55,    54,    53,    52,    50,    58,    51,     0,
       0,     0,     0,     0,     0,    21,    82,     0,     0,     0,
       0,    63,    71,    39,    71,     0,    30,    93,    95,    97,
      99,    84,    86,    88,    83,     0,     0,    37,    36,    35,
      47,    40,     0,     0,    43,    46,    41,    71,     0,     0,
       0,    42,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    14,     5,     6,    12,    13,    34,    16,
      19,    55,    54,    75,    99,    41,    42,    43,    44,    45,
      46,   149,   165,    47,   139,   163,   187,   188,    90,    48,
     110,    49,    58,    59,    50,    60,    91,    79,   105,   106,
     133,   134,   135,   136,    95,   126,   127,   128,   129,    92,
      22,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -118
static const yytype_int16 yypact[] =
{
     102,    23,    32,    51,  -118,    56,   102,  -118,  -118,  -118,
    -118,  -118,    41,    44,    70,   113,  -118,   113,   113,    60,
    -118,    94,    84,    88,   127,   145,  -118,  -118,   120,   172,
    -118,   149,    62,   177,   152,    62,   117,   179,   153,   154,
     156,   158,    99,  -118,   150,  -118,  -118,  -118,  -118,   157,
     118,   159,  -118,    31,   161,    59,  -118,  -118,   160,   162,
     167,    18,   164,   123,     8,     8,   171,  -118,  -118,  -118,
    -118,  -118,   186,  -118,  -118,  -118,   163,  -118,   163,    27,
     190,  -118,   109,  -118,  -118,  -118,   168,  -118,   192,     8,
     166,  -118,   141,   169,   199,   128,  -118,  -118,   170,   109,
    -118,  -118,   168,  -118,  -118,   173,    66,   174,  -118,   155,
     109,  -118,   176,  -118,     8,     8,     8,     8,     8,     8,
       8,     8,     8,  -118,   202,  -118,   185,   193,   195,   194,
     122,  -118,    27,   196,   197,   201,   198,   125,  -118,   183,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   188,
     187,   109,   109,   109,   109,  -118,   184,    27,    27,    27,
      27,  -118,    11,  -118,    11,   191,  -118,  -118,  -118,  -118,
    -118,    -7,    76,   100,    89,   200,   -13,  -118,  -118,  -118,
    -118,     2,   203,   205,  -118,  -118,   206,    62,   152,   207,
     208,  -118,  -118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,   215,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -117,   -72,  -118,   -33,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   -60,  -118,
    -118,   -30,  -118,  -118,   -29,  -118,   -32,  -118,  -118,   -79,
    -118,  -118,  -118,  -118,   -69,  -118,  -118,  -118,  -118,   -65,
     130,  -118
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
      51,    96,    56,    51,   100,    93,   101,    62,    63,    68,
      51,   -83,    86,   109,    87,    36,   183,    96,   181,    37,
      76,    51,    78,    51,    38,    74,    39,     7,   132,   112,
     130,   102,    53,   103,    96,    36,     8,    88,    83,    37,
      89,   137,   -22,    98,    38,    96,    39,   104,    40,    74,
     108,     9,   -68,   156,   140,   141,   142,   143,   144,   145,
     146,   147,   148,    36,   184,    10,    36,    37,    40,    74,
      37,   190,    38,    15,    39,    38,    17,    39,   171,   172,
     173,   174,   -87,   -89,   -83,   -85,   167,   168,   169,   170,
     175,    26,   177,   -22,   -83,   -85,    40,   -22,    27,    40,
     104,   132,    18,    36,   182,   -87,   -89,    37,   -85,     1,
       2,   132,    38,    86,    39,    87,   -87,    28,   -83,   -85,
      20,    21,   -90,    29,   132,   104,   104,   104,   104,   176,
      51,   178,    51,   -71,   -71,   132,    40,   -72,   -98,   -96,
     -94,   -98,   -96,   -94,   -98,   -96,   -94,    24,    25,    57,
      32,   -68,    71,    72,   189,    51,   155,    85,    72,   161,
      30,   125,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   -98,   -96,   -94,   -92,    86,    94,    87,    31,    35,
      33,    52,    53,    61,    69,    64,    65,    82,    66,    67,
      97,    70,    77,    73,   107,    80,   111,    81,    84,   113,
      57,    74,   123,   124,   151,    72,   131,   150,   -68,   138,
     154,   152,   153,   162,   157,   160,   158,   159,   164,   132,
     166,    11,   179,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,     0,   185,   186,   -44,     0,   191,   192
};

static const yytype_int16 yycheck[] =
{
      32,    66,    35,    35,    76,    65,    78,    37,    37,    42,
      42,    18,     4,    82,     6,     4,    14,    82,    31,     8,
      53,    53,    55,    55,    13,    38,    15,     4,    35,    89,
      99,     4,    30,     6,    99,     4,     4,    29,    20,     8,
      32,   110,    31,    72,    13,   110,    15,    79,    37,    38,
      80,     0,    34,   132,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     4,   181,     9,     4,     8,    37,    38,
       8,   188,    13,    32,    15,    13,    32,    15,   157,   158,
     159,   160,    16,    17,    18,    19,   151,   152,   153,   154,
     162,    31,   164,    31,    18,    19,    37,    38,     4,    37,
     132,    35,    32,     4,   176,    16,    17,     8,    19,     7,
       8,    35,    13,     4,    15,     6,    16,    33,    18,    19,
       7,     8,    33,    35,    35,   157,   158,   159,   160,   162,
     162,   164,   164,    34,    35,    35,    37,    20,    16,    17,
      18,    16,    17,    18,    16,    17,    18,    17,    18,    32,
      30,    34,    34,    35,   187,   187,    34,    34,    35,    34,
      33,    33,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    16,    17,    18,    19,     4,     5,     6,    33,    30,
       8,     4,    30,     4,    34,    32,    32,    20,    32,    31,
       4,    34,    31,    34,     4,    35,     4,    35,    34,    33,
      32,    38,    33,     4,    19,    35,    33,     5,    34,    33,
      16,    18,    17,    30,    18,    17,    19,    16,    30,    35,
      33,     6,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    31,    30,    30,    -1,    31,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    40,    41,    43,    44,     4,     4,     0,
       9,    40,    45,    46,    42,    32,    48,    32,    32,    49,
       7,     8,    89,    90,    89,    89,    31,     4,    33,    35,
      33,    33,    30,     8,    47,    30,     4,     8,    13,    15,
      37,    54,    55,    56,    57,    58,    59,    62,    68,    70,
      73,    75,     4,    30,    51,    50,    54,    32,    71,    72,
      74,     4,    70,    73,    32,    32,    32,    31,    54,    34,
      34,    34,    35,    34,    38,    52,    54,    31,    54,    76,
      35,    35,    20,    20,    34,    34,     4,     6,    29,    32,
      67,    75,    88,    67,     5,    83,    88,     4,    73,    53,
      52,    52,     4,     6,    75,    77,    78,     4,    70,    83,
      69,     4,    67,    33,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    33,     4,    33,    84,    85,    86,    87,
      83,    33,    35,    79,    80,    81,    82,    83,    33,    63,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    60,
       5,    19,    18,    17,    16,    34,    78,    18,    19,    16,
      17,    34,    30,    64,    30,    61,    33,    88,    88,    88,
      88,    78,    78,    78,    78,    52,    54,    52,    54,    31,
      31,    31,    52,    14,    51,    31,    30,    65,    66,    54,
      51,    31,    31
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
#line 73 "analizador.y"
    { printf("Function MAIN Found : %s\n", yytext); 
                   mainBool = 1;
                   nameFunction = "main"; 
                   add_symbol("?ADR", nameFunction, 0);
                   add_symbol("?VAL", nameFunction, 0);
                   // printf("MAIN - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                   // printf("main - tNB NAME ?ADR, ADDRESS %d, NameTMP %s\n" , address_symbol-1, symbolTMP);
                   // printf("main - tNB NAME ?VAL, ADDRESS %d, NameTMP %s\n" , address_symbol-1, symbolTMP);
                  address_main = address_instruction + 1;
        ;}
    break;

  case 6:
#line 83 "analizador.y"
    {  int val = find_symbol("?VAL");
                            int adr = find_symbol("?ADR");
                          
                            delete_symbol(address_variable);  // DELETE LAST VARIABLE OR TEMPORAL
                            address_symbol_previous = address_variable;

                            if(address_symbol_previous > address_symbol){
                                address_variable = address_symbol;
                            }
                            else{
                                address_variable = val;
                            }
                            add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                            add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                            add_instruction( "RET", address_instruction, 0 , 0 , 0 );

                            delete_symbol(val);       // DELETE ?VAL
                            delete_last_symbol(adr);  // DELETE ?ADR

                            update_instruction("JMP", varFirstJMP, address_main, 0,0 );  // todo - encontrar la direccion del MAIN
                            add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  
                            mainBool = 0;
;}
    break;

  case 7:
#line 108 "analizador.y"
    { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); ;}
    break;

  case 8:
#line 109 "analizador.y"
    { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); ;}
    break;

  case 9:
#line 112 "analizador.y"
    {  printf("Function VOID Found : %s\n", yytext); nameFunction = (yyvsp[(2) - (2)].s); ;}
    break;

  case 11:
#line 113 "analizador.y"
    { printf("Function INT Found : %s\n", yytext);
                 nameFunction = (yyvsp[(2) - (2)].s);
                 add_symbol("?ADR", nameFunction, 0);  // OK
                 add_symbol("?VAL", nameFunction, 0); 
      ;}
    break;

  case 12:
#line 118 "analizador.y"
    { varFirstJMP = address_instruction;
                         add_instruction( "JMP", address_instruction, -999 , 0 , 0 ); 
                         address_function = address_instruction;
      ;}
    break;

  case 13:
#line 122 "analizador.y"
    {
      
      int val = find_symbol("?VAL");
      int adr = find_symbol("?ADR");
      // printf("functionBodyReturn - BEFORE val : %d, adr : %d \n", val, adr);
      delete_symbol(val);
      delete_symbol(adr);
      delete_last_symbol(var_to_delete);   
;}
    break;

  case 14:
#line 133 "analizador.y"
    { add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  ;}
    break;

  case 15:
#line 136 "analizador.y"
    { int adr = find_symbol("!ADR");
                                                int val = find_symbol("!VAL");
                                                // printf("structure - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                                if(adr == -1 && val == -1){
                                                    adr = 0;
                                                    //val = 0;
                                                    delete_symbol(address_symbol_previous);
                                                    add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                                                    add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                                                    add_instruction( "POP", address_instruction, adr, 0 , 0 );
                                                    add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                                break;
                                                }
                                                
                                                address_variable = adr;
                                                // printf("BodyMain - BEFORE val : %d, adr : %d \n", val, adr);
                                                delete_symbol(val);  // DELETE !VAL
                                                delete_symbol(adr);  // DELETE !ADR
                                                // printf("structure - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                                delete_symbol(address_symbol_previous);
                                                add_symbol("tmp", nameFunction, 0);
                                                address_symbol_previous = address_symbol;
                                                // printf("structure - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d  , address_instruction : %d , adr : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number, address_instruction , adr);
                                                add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                                                add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                                                add_instruction( "POP", address_instruction, adr, 0 , 0 );
                                                add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                                delete_symbol(address_variable);
            ;}
    break;

  case 16:
#line 166 "analizador.y"
    {args_operation = 0; returnBool = 0;;}
    break;

  case 17:
#line 167 "analizador.y"
    { 
                              int adr = find_symbol("!ADR");
                              int val = find_symbol("!VAL");
                              // printf("BodyMain - BEFORE val : %d, adr : %d \n", val, adr);
                              //printf("structure - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                              address_variable = adr;
                              delete_symbol(val);       // DELETE ?VAL
                              delete_symbol(adr);  // DELETE ?ADR
                              //printf("structure - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                              delete_symbol(address_symbol_previous);
                              add_symbol("tmp", nameFunction, 0);
                              address_symbol_previous = address_symbol;
                              //printf("structure - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                              add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                              add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                              add_instruction( "POP", address_instruction, adr, 0 , 0 );
                              add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
;}
    break;

  case 20:
#line 191 "analizador.y"
    { 
                            returnBool = 1; 
                  ;}
    break;

  case 21:
#line 194 "analizador.y"
    {
                                    address_variable = find_symbol("?VAL");  

                                    // printf("returnStatement - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                    if(in_arithmetic_operation){
                                        process_arithmetic_instructions();
                                        delete_symbol(address_result);
                                        in_arithmetic_operation = 0;
                                    }

                                    // printf("returnStatement - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                    
                                    if (returnBool && args_operation){
                                        address_symbol_previous = address_var_TMP;
                                        add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                        delete_symbol(address_symbol_previous);
                                        break;
                                    }
                                    if(returnBool && !mainBool){
                                        add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                    }
;}
    break;

  case 30:
#line 236 "analizador.y"
    { add_instruction("PRI", address_instruction,numberID,0,0); ;}
    break;

  case 31:
#line 237 "analizador.y"
    { add_instruction("PRI", address_instruction, numberID,0,0);    // On ajoute l'instruction PRI
;}
    break;

  case 34:
#line 245 "analizador.y"
    { //int jmf_index = instruction_table->size - 1;
                      //                   printf("WHILE - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      //                   printf("WHILE - BEFORE address_symbol  %d\n", address_symbol);
                      //                   printf("WHILE - BEFORE address_instruction %d\n", address_instruction);
                      //                   printf("WHILE - BEFORE idJMF %d\n", idJMF);
                      //                   printf("WHILE - BEFORE varFirstIF %d\n", varFirstIF);
                                      
                                      
                                      //printf("address_instruction AGREGANDO %d\n", address_instruction);
                                      add_instruction( "JMF", address_instruction, address_symbol_previous , -999 , 0 );
                                      idJMF = address_symbol_previous;
                                      if (varFirstIF  >= idJMF && address_symbol != 0){
                      //                   printf("WHILE - AFTER address_symbol %d\n", address_symbol);
                      //                   printf("WHILE - AFTER address_instruction %d\n", address_instruction);
                      //                   printf("WHILE - AFTER idJMF %d\n", idJMF);
                      //                   printf("WHILE - AFTER varFirstIF %d\n", varFirstIF);
                                      delete_symbol(address_instruction);  
                      //                   printf("WHILE - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      }
                                      push(instruction_table->size - 1);
        ;}
    break;

  case 35:
#line 265 "analizador.y"
    { int jmf_index = pop(); // GET THE ADDRESS OF JMF ON THE INSTRUCTION TABLE - WHERE IF STARTS
                                              if (jmf_index != -1) {
                                                  update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // UPDATE INSTRUCTION TABLE WITH THE ADDRESS WHERE IF ENDS. LOOK FOR THE JMP + jmf_index IN THE INSTRUCTION, THEN UPDATE.
                                              } 
                                              if (idJMF >=  varFirstIF && address_symbol != 0 ){  // DELETE ALL TEMPORAL VARIABLE OF THIS IF SECTION
                                              delete_symbol(address_symbol_previous);
                                              }
                //                                  printf("ifStructure - AFTER AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
;}
    break;

  case 38:
#line 289 "analizador.y"
    { //int jmf_index = instruction_table->size - 1;
                                //  printf("IF - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                //  printf("IF - BEFORE address_symbol  %d\n", address_symbol);
                                //  printf("IF - BEFORE address_instruction %d\n", address_instruction);
                                //  printf("IF - BEFORE idJMF %d\n", idJMF);
                                //  printf("IF - BEFORE varFirstIF %d\n", varFirstIF);
                                
                                
                                //printf("address_instruction AGREGANDO %d\n", address_instruction);
                                add_instruction( "JMF", address_instruction, address_symbol_previous , -999 , 0 );
                                idJMF = address_symbol_previous;
                                if (varFirstIF  >= idJMF && address_symbol != 0){
                                //  printf("IF - AFTER address_symbol %d\n", address_symbol);
                                //    printf("IF - AFTER address_instruction %d\n", address_instruction);
                                //    printf("IF - AFTER idJMF %d\n", idJMF);
                                //    printf("IF - AFTER varFirstIF %d\n", varFirstIF);
                                 delete_symbol(address_instruction);  
                                //    printf("IF - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                }
                                push(instruction_table->size - 1);
    ;}
    break;

  case 40:
#line 312 "analizador.y"
    { int jmf_index = pop(); // Obtener el índice de la instrucción JMF
                                          //printf("jmf_index UPDATE %d\n", jmf_index);
                                          //printf("address_instruction UPDATE %d\n", address_instruction);
                                          if (jmf_index != -1) {
                                              // printf("ACTUALIZANDO JMF...\n");
                                              update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // Actualizar la instrucción JMF
                                          } 
                                          

                                          if (idJMF >=  varFirstIF && address_symbol != 0 ){
                                       //       printf("ifStructure - AFTER address_symbol  %d\n", address_symbol);
                                       //       printf("ifStructure - AFTER jmf_index  %d\n", jmf_index);
                                       //       printf("ifStructure - AFTER idJMF %d\n", idJMF);
                                       //       printf("ifStructure - AFTER varFirstIF %d\n", varFirstIF);
                                           delete_symbol(address_symbol_previous);
                                       //       printf("ifStructure - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                          }
                                          ;}
    break;

  case 41:
#line 330 "analizador.y"
    { int jmf_index = pop(); // Obtener el índice de la instrucción JMF
                                          if (jmf_index != -1) {
                                              // printf("ACTUALIZANDO JMF...\n");
                                              update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // Actualizar la instrucción JMF
                                          } 
                                          
                                          if (idJMF >=  varFirstIF && address_symbol != 0 ){
                                           delete_symbol(address_symbol_previous);
                                          }
                                          ;}
    break;

  case 44:
#line 341 "analizador.y"
    { int jmf_index = pop(); // Obtener el índice de la instrucción JMF
                                          if (jmf_index != -1) {
                                              // printf("ACTUALIZANDO JMF...\n");
                                              update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // Actualizar la instrucción JMF
                                          } 
                                          
                                          if (idJMF >=  varFirstIF && address_symbol != 0 ){
                                           delete_symbol(address_symbol_previous);
                                          }
                                          ;}
    break;

  case 47:
#line 352 "analizador.y"
    { int jmf_index = pop(); // GET THE ADDRESS OF JMF ON THE INSTRUCTION TABLE - WHERE IF STARTS
                                                if (jmf_index != -1) {
                                                    update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // UPDATE INSTRUCTION TABLE WITH THE ADDRESS WHERE IF ENDS. LOOK FOR THE JMP + jmf_index IN THE INSTRUCTION, THEN UPDATE.
                                                } 
                                                if (idJMF >=  varFirstIF && address_symbol != 0 ){  // DELETE ALL TEMPORAL VARIABLE OF THIS IF SECTION
                                                delete_symbol(address_symbol_previous);
                                                }
                                                // rintf("ifStructure - AFTER AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
;}
    break;

  case 62:
#line 380 "analizador.y"
    { nameID = (yyvsp[(2) - (3)].s); add_symbol((yyvsp[(2) - (3)].s), nameFunction, 0);  ;}
    break;

  case 63:
#line 380 "analizador.y"
    { delete_symbol(address_symbol_previous); // agregado
 ;}
    break;

  case 65:
#line 383 "analizador.y"
    {
                                    // printf("AGREGANDO OPERACIONES ARITMETICAS\n");
                                    if(in_arithmetic_operation){
                                          process_arithmetic_instructions();
                                          delete_symbol(address_result);  // delete last tmp after arithmetic operation
                                          in_arithmetic_operation = 0;
                                          // printf("functionName XxXXX - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                          // printf("nameID - variable %s\n", nameID);
                                          add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                          break;      
                                    }
                                    delete_symbol(address_symbol_previous);

            ;}
    break;

  case 66:
#line 399 "analizador.y"
    { 
                    nameID = (yyvsp[(1) - (1)].s);
                    add_symbol((yyvsp[(1) - (1)].s), nameFunction, 0); 
              ;}
    break;

  case 68:
#line 404 "analizador.y"
    { 
                    nameID = (yyvsp[(1) - (1)].s);
                    add_symbol((yyvsp[(1) - (1)].s), nameFunction, 0); 
              ;}
    break;

  case 69:
#line 408 "analizador.y"
    {  nameID = (yyvsp[(1) - (1)].s);  ;}
    break;

  case 72:
#line 411 "analizador.y"
    {  nameID = (yyvsp[(1) - (1)].s);  ;}
    break;

  case 75:
#line 415 "analizador.y"
    { add_symbol("!ADR", nameFunction, 0);   // !ADR et !VAL antes
                          add_symbol("!VAL", nameFunction, 0); 
                          // printf("ADR y VAL AGREGADAS xxxxxxxxxx\n");
               ;}
    break;

  case 76:
#line 419 "analizador.y"
    { 
                                // printf("functionName XxXXX returnBool : %d, args_operation %d\n", returnBool,  args_operation);
                                // printf("functionName XxXXX - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                if(returnBool && args_operation){
                                      int adr = find_symbol("!ADR");
                                      int val = find_symbol("!VAL");
                                      // printf("functionName - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      address_variable = adr;
                                      delete_symbol(val);  // DELETE !VAL
                                      delete_symbol(adr);  // DELETE !ADR
                                      // printf("structure - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      
                                      add_symbol("tmp", nameFunction, 0);
                                      address_symbol_previous = address_symbol;
                                      // printf("functionName - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                                      add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                                      add_instruction( "POP", address_instruction, adr, 0 , 0 );
                                      add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                      //printf("argsfunctionName - AFTER AFTER Name address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      break;
                                }
                                // printf("functionName XxXXX - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                if(returnBool){
                                    int adr = find_symbol("!ADR");
                                    // int val = find_symbol("!VAL");
                                    // printf("functionName XXXX - returnBool - BEFORE val : %d, adr : %d \n", val, adr);
                                    // printf("functionName XXXX - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                    address_variable = adr;
                                    // printf("functionName XXXX - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                }
                                // printf("functionName XxXXX - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_symbol("tmp" , nameFunction, 0); 
                                // printf("functionName - tTMP NAME %s, ADDRESS %d, NameTMP %s\n" , nameID, address_symbol-1, symbolTMP);
                                // printf("argsName address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_instruction( "AFC", address_instruction, address_symbol_previous , global_number , 0 );  // AFC BEFORE PUSH
;}
    break;

  case 79:
#line 462 "analizador.y"
    { add_symbol("tmp" , nameFunction, 0);
                   nameID = (yyvsp[(1) - (1)].s);
                   address_variable = find_symbol((yyvsp[(1) - (1)].s));
                   // printf("argListName - tID NAME %s, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);  
              ;}
    break;

  case 80:
#line 467 "analizador.y"
    { add_symbol("tmp" , nameFunction, (yyvsp[(1) - (1)].i));
                    numberID = (yyvsp[(1) - (1)].i);
                    // printf("argListName - Agregando tmp numberID : %d\n", numberID);
                    delete_symbol(address_symbol_previous);
                    if(nameID != NULL){
                        address_variable = find_symbol(nameID);  
                    }
                    // printf("argListName - tNB NAME %d, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);
              ;}
    break;

  case 83:
#line 478 "analizador.y"
    { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); ;}
    break;

  case 84:
#line 479 "analizador.y"
    { 
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                add_instruction("DIV", address_instruction, address_symbol_previous, address_symbol_previous, address_symbol);
              ;}
    break;

  case 85:
#line 486 "analizador.y"
    { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); ;}
    break;

  case 86:
#line 487 "analizador.y"
    { 
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                add_instruction("MUL", address_instruction, address_symbol_previous, address_symbol_previous, address_symbol);
              ;}
    break;

  case 87:
#line 494 "analizador.y"
    { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); ;}
    break;

  case 88:
#line 495 "analizador.y"
    { 
                                //printf("SUB BEFORE - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                //printf("SUB HALF - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_instruction("SUB", address_instruction, address_symbol, address_symbol, global_number);
                                //printf("SUB AFTER - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
              ;}
    break;

  case 89:
#line 505 "analizador.y"
    { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); ;}
    break;

  case 90:
#line 506 "analizador.y"
    { 
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                add_instruction("ADD", address_instruction, address_symbol_previous, address_symbol_previous, address_symbol);
        ;}
    break;

  case 92:
#line 516 "analizador.y"
    {  // printf("MUL - BEFORE XXX symbolTMP : %s  , nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                  // printf("MUL - BEFORE XXX symbolTMP : %d\n", find_symbol(symbolTMP)); 
                  // printf("MUL - BEFORE XXX numberID : %d\n", numberID);
                  // printf("MUL - BEFORE XXX numberID : %d\n", find_symbol_by_number(numberID));
                      if(find_symbol(symbolTMP) != -1){
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
                  // printf("MUL - BEFORE XXX address_operand1 : %d\n", address_operand1);
            ;}
    break;

  case 93:
#line 527 "analizador.y"
    {  // printf("AGREGANDO MUL\n");
                      // printf("MUL - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      // printf("MUL - BEFORE 500 symbolTMP : %s, nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                      // printf("MUL - BEFORE 501 symbolTMP : %d\n", find_symbol(symbolTMP));
                      // printf("MUL - BEFORE 502 numberID : %d\n", numberID);
                      // printf("MUL - BEFORE 503 numberID : %d\n", find_symbol_by_number(numberID));
                      int temporal = find_symbol(symbolTMP);
                      if(temporal == -1){
                          address_operand2 = find_symbol_by_number(numberID);
                          
                      } else {
                          address_operand2 = find_symbol(symbolTMP); 
                      }
                      address_result = address_operand1;
                      // printf("MUL - BEFORE 513 address_operand2 : %d\n", address_operand2);
                      // printf("MUL - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      // add_arithmetic_instruction("MUL", address_symbol_previous, address_symbol_previous, address_symbol);   WORKING
                      add_arithmetic_instruction("MUL", address_result, address_operand1, address_operand2); 
                      in_arithmetic_operation = 1;
          ;}
    break;

  case 94:
#line 547 "analizador.y"
    { if(find_symbol(symbolTMP) != -1){
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
            ;}
    break;

  case 95:
#line 553 "analizador.y"
    {
                  int temporal = find_symbol(symbolTMP);
                  if(temporal == -1){
                      address_operand2 = find_symbol_by_number(numberID);
                      
                  } else {
                      address_operand2 = find_symbol(symbolTMP); 
                  }
                  address_result = address_operand1;
                  add_arithmetic_instruction("DIV", address_result, address_operand1, address_operand2); 
                  in_arithmetic_operation = 1;
          ;}
    break;

  case 96:
#line 565 "analizador.y"
    {  // printf("ADD - BEFORE XXX symbolTMP : %s  , nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                  // printf("ADD - BEFORE XXX symbolTMP : %d\n", find_symbol(symbolTMP)); 
                  // printf("ADD - BEFORE XXX numberID : %d\n", numberID);
                  // printf("ADD - BEFORE XXX numberID : %d\n", find_symbol_by_number(numberID));
                      if(find_symbol(symbolTMP) != -1){  
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
                  // printf("ADD - BEFORE XXX address_operand1 : %d\n", address_operand1);
            ;}
    break;

  case 97:
#line 576 "analizador.y"
    { // printf("AGREGANDO ADD\n");
                       // printf("ADD - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                       // printf("ADD - BEFORE 547 symbolTMP : %s, nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                       // printf("ADD - BEFORE 548 symbolTMP : %d\n", find_symbol(symbolTMP));
                       // printf("ADD - BEFORE 549 numberID : %d\n", numberID);
                       // printf("ADD - BEFORE 550 numberID : %d\n", find_symbol_by_number(numberID));
                      int temporal = find_symbol(symbolTMP);
                      if(temporal == -1){
                          address_operand2 = find_symbol_by_number(numberID);
                      } else {
                          address_operand2 = find_symbol(symbolTMP); 
                      }
                      address_result = address_operand1;
                      // printf("ADD - BEFORE 559 address_operand2 : %d\n", address_operand2);
                      // printf("ADD - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      // add_arithmetic_instruction("MUL", address_symbol_previous, address_symbol_previous, address_symbol);   WORKING
                      add_arithmetic_instruction("ADD", address_result, address_operand1, address_operand2); 
                      in_arithmetic_operation = 1;
          ;}
    break;

  case 98:
#line 595 "analizador.y"
    { if(find_symbol(symbolTMP) != -1){
                          
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
            ;}
    break;

  case 99:
#line 602 "analizador.y"
    {
                  int temporal = find_symbol(symbolTMP);
                  if(temporal == -1){
                      address_operand2 = find_symbol_by_number(numberID);
                      
                  } else {
                      address_operand2 = find_symbol(symbolTMP); 
                  }
                  address_result = address_operand1;
                  add_arithmetic_instruction("SUB", address_result, address_operand1, address_operand2); 
                  in_arithmetic_operation = 1;
;}
    break;

  case 100:
#line 616 "analizador.y"
    { variableTMP = "tmp"; nameIDtemporal = (yyvsp[(1) - (1)].s);
            // nameID = $1;
            // printf("nameID - TID %s\n" , nameID);
            address_variable = find_symbol((yyvsp[(1) - (1)].s));  
            // printf("TID BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol);
            address_var_TMP = address_symbol_previous;
            add_symbol(variableTMP , nameFunction, 0);            
            // printf("TID NAME %s, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);
            varFirstIF = address_symbol_previous;
            // printf("varFirstIF - TID %d\n" , varFirstIF);

            // printf("TID AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol);
            add_instruction( "COP", address_instruction, address_symbol_previous, address_variable , 0 ); 
   
            // printf("address_var_TMP : %d\n", address_var_TMP);
      ;}
    break;

  case 101:
#line 632 "analizador.y"
    { numberID = (yyvsp[(1) - (1)].i);
            // printf("TNB AFTER - nameID %s\n" , nameID);
            // printf("address_symbol before : %d\n", address_symbol);
            // printf("TNB - before address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
            // snprintf(nameID, sizeof(nameID), "%d", $1);
            add_symbol("tmp" , nameFunction, (yyvsp[(1) - (1)].i));
            // printf("argListName - Agregando tmp numberID : %d\n", numberID);
            // printf("tNB NAME %d, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);
            if(nameID != NULL){
                address_variable = find_symbol(nameID);  
            }
            // printf("TNB AFTER - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
            if(!in_arithmetic_operation && returnBool ){
                add_instruction( "AFC", address_instruction, address_symbol_previous , global_number , 0 ); 
                break;
            } 
            // printf("TNB - after address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d , in_arithmetic_operation : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number, in_arithmetic_operation);
            add_instruction( "AFC", address_instruction, address_symbol_previous , global_number , 0 ); 
            // printf("TNB - after in_arithmetic_operation : %d, args_operation : %d\n", in_arithmetic_operation , args_operation );        
            if (!in_arithmetic_operation  && !args_operation) {
            // printf("TNB - after address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d , in_arithmetic_operation : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number, in_arithmetic_operation);
                add_instruction("COP", address_instruction, address_variable, address_symbol_previous, 0); 
            }

      ;}
    break;

  case 106:
#line 665 "analizador.y"
    { add_symbol((yyvsp[(2) - (2)].s), nameFunction, 0); 
                    // printf("ARGUMENTO tID %s\n", $2);
                    var_to_delete = find_symbol((yyvsp[(2) - (2)].s));
         ;}
    break;

  case 107:
#line 669 "analizador.y"
    { add_symbol((yyvsp[(4) - (4)].s), nameFunction, 0);
                                   delete_symbol(address_symbol_previous); 
         ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2332 "testOUTPUT.c"
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


#line 674 "analizador.y"




void yyerror(const char *s) {
    fprintf(stderr, "Error: %s at line %d - ERROR JUST BEFORE SYMBOL %s\n", s, yylineno, yytext);
}


int main() {
    symbol_table = create_symbol_table();
    instruction_table = create_instruction_table();
    yyparse();
    print_symbol_table();
    print_instruction_table();
    print_arithmetic_instruction_table();
    return 0;
}

