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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 52 "analizador.y"
{ 
    char *s;
    int i;
}
/* Line 1529 of yacc.c.  */
#line 132 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

