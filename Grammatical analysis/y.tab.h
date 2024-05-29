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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 48 "analizador.y"
{ 
    char *s;
    int i;
}
/* Line 1529 of yacc.c.  */
#line 130 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

