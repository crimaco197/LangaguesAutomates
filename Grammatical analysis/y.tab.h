/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tTEXT = 258,                   /* tTEXT  */
    tID = 259,                     /* tID  */
    tSTRING = 260,                 /* tSTRING  */
    tNB = 261,                     /* tNB  */
    tVOID = 262,                   /* tVOID  */
    tINT = 263,                    /* tINT  */
    tCDIV = 264,                   /* tCDIV  */
    tSPAN = 265,                   /* tSPAN  */
    tCSPAN = 266,                  /* tCSPAN  */
    tIF = 267,                     /* tIF  */
    tELSE = 268,                   /* tELSE  */
    tWHILE = 269,                  /* tWHILE  */
    tADD = 270,                    /* tADD  */
    tSUB = 271,                    /* tSUB  */
    tMUL = 272,                    /* tMUL  */
    tDIV = 273,                    /* tDIV  */
    tLT = 274,                     /* tLT  */
    tGT = 275,                     /* tGT  */
    tNE = 276,                     /* tNE  */
    tEQ = 277,                     /* tEQ  */
    tGE = 278,                     /* tGE  */
    tLE = 279,                     /* tLE  */
    tASSIGN = 280,                 /* tASSIGN  */
    tAND = 281,                    /* tAND  */
    tOR = 282,                     /* tOR  */
    tNOT = 283,                    /* tNOT  */
    tLBRACE = 284,                 /* tLBRACE  */
    tRBRACE = 285,                 /* tRBRACE  */
    tLPAR = 286,                   /* tLPAR  */
    tRPAR = 287,                   /* tRPAR  */
    tSEMI = 288,                   /* tSEMI  */
    tCOMMA = 289,                  /* tCOMMA  */
    tERROR = 290,                  /* tERROR  */
    tPRINT = 291,                  /* tPRINT  */
    tRETURN = 292                  /* tRETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tTEXT 258
#define tID 259
#define tSTRING 260
#define tNB 261
#define tVOID 262
#define tINT 263
#define tCDIV 264
#define tSPAN 265
#define tCSPAN 266
#define tIF 267
#define tELSE 268
#define tWHILE 269
#define tADD 270
#define tSUB 271
#define tMUL 272
#define tDIV 273
#define tLT 274
#define tGT 275
#define tNE 276
#define tEQ 277
#define tGE 278
#define tLE 279
#define tASSIGN 280
#define tAND 281
#define tOR 282
#define tNOT 283
#define tLBRACE 284
#define tRBRACE 285
#define tLPAR 286
#define tRPAR 287
#define tSEMI 288
#define tCOMMA 289
#define tERROR 290
#define tPRINT 291
#define tRETURN 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "analizador.y"
 
    char *s;
    int i;

#line 146 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
