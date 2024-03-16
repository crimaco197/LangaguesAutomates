%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
Program : fun
        | fun Program
;

fun: 
      tVOID tID { printf("Function VOID Found : %s\n", yytext); } tLPAR args tRPAR tLBRACE structure tRBRACE  { printf("ERROR in VOID Found : %s\n", yytext); }
    | tINT tID { printf("Function INT Found : %s\n", yytext); } tLPAR args tRPAR functionBody  
;

functionBody:
    tLBRACE structure returnStatement tRBRACE
  | tLBRACE returnStatement tRBRACE
  | tLBRACE error tRBRACE {
      yyerror("Syntax Error, Token EXPECTED return.");
    }
;

returnStatement:
    tRETURN var tSEMI
;

structure : context 
          | context structure     
;

context : 
         action 
;

action : 
         declaration tSEMI
       | print tSEMI
       | bucles
;

print : tPRINT tLPAR tID tRPAR
;

bucles: if
      | while
;

while: tWHILE tLPAR condition tRPAR tLBRACE structure tRBRACE
;

if: tIF tLPAR condition tRPAR tLBRACE structure tRBRACE
  | tIF tLPAR condition tRPAR tLBRACE structure tRBRACE tELSE tLBRACE structure tRBRACE


condition : var
          | tNOT tID
          | var tAND condition 
          | var tNOT condition
          | var tLE condition
          | var tGE condition
          | var tEQ condition
          | var tNE condition
          | var tGT condition
          | var tLT condition
          | var tOR condition 
          | tLPAR condition tRPAR
;

declaration:
            tINT tID
           | tINT tID tCOMMA declaration
           | tINT tID tASSIGN resultat tCOMMA declaration
           | tINT tID tASSIGN resultat
           | tINT tID tASSIGN functionName
           | tID tASSIGN resultat
           | tID tCOMMA declaration
           | tID
;

functionName: tID tLPAR argsName tRPAR
;

argsName: 
          /* Not Arguments */
        | argListName
;

argListName:
     var                        /* Only one argument */
    | argListName tCOMMA resultat
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
      tVOID
    | tINT tID                 /* Only one argument */
    | argList tCOMMA tINT tID /* Several arguments, divided by commas */
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s SYMBOL FOUND %s\n", s, yytext);
}

int main() {
    yyparse();
    return 0;
}

int hola(){
    return 1;
}