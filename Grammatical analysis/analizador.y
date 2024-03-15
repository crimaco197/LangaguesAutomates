%{
#include <stdio.h>
#include <stdlib.h>

 int yylex(void); 
 int yyerror(char *s); 
%}

%union { char *s;
         int i;
}

%token <s> tTEXT tID
%token <i> tINT tNB
%token tVOID
%token tCDIV tSPAN tCSPAN
%token tIF tELSE tWHILE
%token tADD tSUB tMUL tDIV
%token tLT tGT tNE tEQ tGE tLE tASSIGN
%token tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA
%token tERROR tPRINT tRETURN


%%

Program : fun1
        | fun1 Program
;

fun1 : tINT tID;

fun : 
   tVOID tID tLPAR args tRPAR tLBRACE tRBRACE 
   |tINT tID tLPAR args tRPAR tLBRACE tRBRACE 
;

args: tVOID
    | arg
    | args tCOMMA args
;

arg : tINT tID  
;




%%

int yyerror(char *s){
    printf("Syntax Error on line %s\n", s);
    return 0;
}

int main() {
    yyparse();
    return 0;
}







