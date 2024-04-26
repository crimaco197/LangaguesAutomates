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
     tCDIV = 264,
     tSPAN = 265,
     tCSPAN = 266,
     tIF = 267,
     tELSE = 268,
     tWHILE = 269,
     tADD = 270,
     tSUB = 271,
     tMUL = 272,
     tDIV = 273,
     tLT = 274,
     tGT = 275,
     tNE = 276,
     tEQ = 277,
     tGE = 278,
     tLE = 279,
     tASSIGN = 280,
     tAND = 281,
     tOR = 282,
     tNOT = 283,
     tLBRACE = 284,
     tRBRACE = 285,
     tLPAR = 286,
     tRPAR = 287,
     tSEMI = 288,
     tCOMMA = 289,
     tERROR = 290,
     tPRINT = 291,
     tRETURN = 292
   };
#endif
/* Tokens.  */
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "analizador.y"
{ 
    char *s;
    int i;
}
/* Line 1529 of yacc.c.  */
#line 128 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

