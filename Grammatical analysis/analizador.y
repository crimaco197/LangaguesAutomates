%{
#include <stdio.h>
#include <stdlib.h>

extern char *yytext; // Acceso a yytext de Flex
void yyerror(const char *s);
int yylex(void); 
%}

%union { 
    char *s;
    int i;
}

%token <s> tTEXT tID
%token <i> tNB
%token tVOID tINT
%token tCDIV tSPAN tCSPAN
%token tIF tELSE tWHILE
%token tADD tSUB tMUL tDIV
%token tLT tGT tNE tEQ tGE tLE tASSIGN
%token tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA
%token tERROR tPRINT tRETURN

%%
Program : 
        | Program fun
;

fun: 
    tVOID tID tLPAR args tRPAR tLBRACE structure tRBRACE { printf("Function Found : void\n"); }
    | tINT tID tLPAR args tRPAR tLBRACE structure tRBRACE { printf("Function Found : int\n"); }
;

structure : context 
          | context structure     
;

context : action 
;

action : 
        declaration tSEMI
;


declaration:
            tINT tID
           | tINT tID tCOMMA declaration
           | tINT tID tASSIGN resultat tCOMMA declaration
           | tINT tID tASSIGN resultat
;

resultat  : 
           var
          | resultat tMUL var
          | resultat tDIV var
          | resultat tADD var
          | resultat tSUB var
;

var:
     tID
    | tNB
;

args:
    /* Not Arguments */
    | argList
;

argList:
    tINT tID                 /* Only one argument */
    | argList tCOMMA tINT tID /* Several arguments, divided by commas */
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s SYMBOL NOT EXPECTED %s\n", s, yytext);
}

int main() {
    yyparse();
    return 0;
}
