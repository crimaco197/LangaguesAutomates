%option noyywrap
%option noinput
%option nounput
%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

/* Oussama Eljid */
/*  Cristian Martinez */

void showError();

%}

alpha             ([a-zA-Z][a-zA-Z0-9])*
number           ([0-9])+
hex_number        (0[xX][0-9a-fA-F])+


%%

{alpha} {
    yylval.s = strdup(yytext);
    return tID;
}

{number} {
    yylval.i = atoi(yytext);
    return tNB;
}

{hex_number} {
    yylval.i = (int)strtol(yytext, NULL, 16);
    return tNB;
}

"if"      { return tIF; }
"else"    { return tELSE; }
"while"   { return tWHILE; }
"print"   { return tPRINT; }
"return"  { return tRETURN; }
"int"     { return tINT; }
"void"    { return tVOID; }
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


.                             { showError(); return(tERROR); } //Ignore strange characters

%%

void showError (){
        printf("Other Input");
}

