/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tTEXT = 258,
     tID = 259,
     tNB = 260,
     tVOID = 261,
     tINT = 262,
     tCDIV = 263,
     tSPAN = 264,
     tCSPAN = 265,
     tIF = 266,
     tELSE = 267,
     tWHILE = 268,
     tADD = 269,
     tSUB = 270,
     tMUL = 271,
     tDIV = 272,
     tLT = 273,
     tGT = 274,
     tNE = 275,
     tEQ = 276,
     tGE = 277,
     tLE = 278,
     tASSIGN = 279,
     tAND = 280,
     tOR = 281,
     tNOT = 282,
     tLBRACE = 283,
     tRBRACE = 284,
     tLPAR = 285,
     tRPAR = 286,
     tSEMI = 287,
     tCOMMA = 288,
     tERROR = 289,
     tPRINT = 290,
     tRETURN = 291
   };
#endif
/* Tokens.  */
#define tTEXT 258
#define tID 259
#define tNB 260
#define tVOID 261
#define tINT 262
#define tCDIV 263
#define tSPAN 264
#define tCSPAN 265
#define tIF 266
#define tELSE 267
#define tWHILE 268
#define tADD 269
#define tSUB 270
#define tMUL 271
#define tDIV 272
#define tLT 273
#define tGT 274
#define tNE 275
#define tEQ 276
#define tGE 277
#define tLE 278
#define tASSIGN 279
#define tAND 280
#define tOR 281
#define tNOT 282
#define tLBRACE 283
#define tRBRACE 284
#define tLPAR 285
#define tRPAR 286
#define tSEMI 287
#define tCOMMA 288
#define tERROR 289
#define tPRINT 290
#define tRETURN 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "analizador.y"
{ 
    char *s;
    int i;
}
/* Line 1529 of yacc.c.  */
#line 126 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

