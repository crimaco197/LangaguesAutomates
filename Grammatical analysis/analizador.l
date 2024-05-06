%option noyywrap
%option noinput
%option nounput
%option yylineno
%{
/* Oussama Eljid */
/*  Cristian Martinez */

#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "symbol_table.h"
#include "instruction_table.h"
<<<<<<< HEAD
#include "declaration_var.h"


=======


extern InstructionTable *instruction_table;
extern int address;

>>>>>>> c25f7d5c2148e5f11aeb63fbfb10ddaf9fa638fe

void showError(const char *text);

%}

alpha         [_a-zA-Z][a-zA-Z0-9]*
number        [0-9]+
hex_number    0[xX][0-9a-fA-F]+


%%

"if"      { return tIF; }
"else"    { return tELSE; }
"while"   { return tWHILE; }
"print"   { return tPRINT; }
"return"  { return tRETURN; }
"int"     { return tINT; }
"void"    { return tVOID; }

{alpha} {
    yylval.s = strdup(yytext);
    return tID;
}

{number} {
<<<<<<< HEAD
    yylval.i = atoi(yytext);\
    global_number = yylval.i;
=======
    yylval.i = atoi(yytext);
>>>>>>> c25f7d5c2148e5f11aeb63fbfb10ddaf9fa638fe
    return tNB;
}

{hex_number} {
    yylval.i = (int)strtol(yytext, NULL, 16);
<<<<<<< HEAD
    global_number = yylval.i;
=======
>>>>>>> c25f7d5c2148e5f11aeb63fbfb10ddaf9fa638fe
    return tNB;
}


"+"       { return tADD; }
"-"       { return tSUB; }
"*"       { return tMUL; }
"/"       { return tDIV; }
"<"       { return tLT; }
">"       { return tGT; }
"!="      { return tNE; }
"=="      { return tEQ; }
">="      { return tGE; }
"<="      { return tLE; }
"="       { return tASSIGN; }
"&&"      { return tAND; }
"||"      { return tOR; }
"!"       { return tNOT; }
"{"       { return tLBRACE; }
"}"       { return tRBRACE; }
"("       { return tLPAR; }
")"       { return tRPAR; }
";"       { return tSEMI; }
","       { return tCOMMA; }


"//".*                        { /* Ignore one line comments */ }
"/*"([^*]|\*+[^*/])*"*/"      { /* Ignore multiline comments */ }



[ \t\n]+                      { /* Ignore white spaces */ }


.                             { showError(yytext); 
    return tERROR;} //Ignore strange characters

%%

void showError (const char *text){
        fprintf(stderr, "Error Symbol NOT EXPECTED: %s at line %d\n", text, yylineno);
}

