%option noyywrap
%option noinput
%option nounput
%{ 
#include <stdio.h>
/* Oussama Eljid */
/*  Cristian Martinez */
%}


%%


if                            { printf("tIF\n"); } 
else                          { printf("tELSE\n"); }
while                         { printf("tWHILE\n"); }
print                         { printf("tPRINT\n"); }
return                        { printf("tRETURN\n"); }
int                           { printf("tINT\n"); }
void                          { printf("tVOID\n"); }


[_a-zA-Z][a-zA-Z0-9]*          { printf("tID: '%s'\n", yytext); }


[0-9]+                        {
    int num = atoi(yytext); 		      // Convert decimal to hexadecimal
    printf("tNB: '%s[0x%x]'\n", yytext, num); // print decimal and hexadecimal.
}


0[xX][0-9a-fA-F]+             {  
    				int num;   //Convert hexadecimal to an  integer
    				sscanf(yytext, "%x", &num);
    				printf("tNB: '%u[0x%x]'\n", num, num); // print decimal and hexadecimal.
			      }

"+"                           { printf("tADD\n"); }
"-"                           { printf("tSUB\n"); }
"*"                           { printf("tMUL\n"); }
"/"                           { printf("tDIV\n"); }
"<"                           { printf("tLT\n"); }
">"                           { printf("tGT\n"); }
"!="                          { printf("tNE\n"); }
"=="                          { printf("tEQ\n"); }
">="                          { printf("tGE\n"); }
"<="                          { printf("tLE\n"); }
"="                           { printf("tASSIGN\n"); }
"&&"                          { printf("tAND\n"); }
"||"                          { printf("tOR\n"); }
"!"                           { printf("tNOT\n"); }
"{"                           { printf("tLBRACE\n"); }
"}"                           { printf("tRBRACE\n"); }
"("                           { printf("tLPAR\n"); }
")"                           { printf("tRPAR\n"); }
";"                           { printf("tSEMI\n"); }
","                           { printf("tCOMMA\n"); }


"//".*                        { /* Ignore one line comments */ }
"/*"([^*]|\*+[^*/])*"*/"      { /* Ignore multiline comments */ }



[ \t\n]+                      { /* Ignore white spaces */ }


.                             { printf("tERROR\n"); } //Ignore strange characters

%%


int main() {
    yylex();
}