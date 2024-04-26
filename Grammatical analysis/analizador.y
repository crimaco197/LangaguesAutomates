%{
/* Oussama Eljid */
/*  Cristian Martinez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "instruction_table.h"


// EXTERN VARIABLES
extern char *yytext;
extern int yylineno;
extern SymbolTable *symbol_table;
extern InstructionTable *instruction_table;
extern int address;

// DECLARATING FUNCTIONS
void yyerror(const char *s);
int yylex(void); 
%}

%union { 
    char *s;
    int i;
}

%token <s> tTEXT tID tSTRING
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
      tVOID tID { printf("Function VOID Found : %s\n", yytext); } tLPAR args tRPAR tLBRACE structure tRBRACE 
    | tINT tID { printf("Function INT Found : %s\n", yytext); } tLPAR args tRPAR functionBody  
;

functionBody:
    tLBRACE structure returnStatement tRBRACE
;

returnStatement:
    tRETURN resultat tSEMI
;

structure : 
          | context structure     
;

context : 
         action 
;

action : 
         declaration tSEMI
       | print tSEMI
       | bucles
       | functionName tSEMI
;

print : tPRINT tLPAR tID tRPAR
      | tPRINT tLPAR tSTRING tID tSTRING tRPAR
      | tPRINT tLPAR resultat tRPAR
;

bucles: if
      | while
;

while: tWHILE tLPAR condition tRPAR tLBRACE structure tRBRACE
;

if: tIF tLPAR condition tRPAR tLBRACE structure tRBRACE
  | tIF tLPAR condition tRPAR tLBRACE structure tRBRACE tELSE tLBRACE structure tRBRACE
  | tIF tLPAR condition tRPAR tLBRACE structure tRBRACE functionBody
  | tIF tLPAR condition tRPAR tLBRACE structure tRBRACE tELSE tLBRACE functionBody tRBRACE


condition : var
          | tNOT tID { add_symbol($2, "int"); }
          | var tAND condition 
          | var tNOT condition
          | var tLE condition
          | var tGE condition
          | var { add_symbol("tmp", "int"); } tEQ condition
          | var tNE condition
          | var tGT condition
          | var tLT condition
          | var tOR condition 
          | tLPAR condition tRPAR
;

declaration1: tINT tID { add_symbol($2, "int"); };

declaration:
            declaration1
           | declaration1 tCOMMA declaration
           | declaration1 tASSIGN resultat tCOMMA declaration
           | declaration1 tASSIGN resultat
           | declaration1 tASSIGN functionName
           | tID tASSIGN { add_instruction("COP", 0, 0, 0); }  resultat 
           | tID tCOMMA declaration
           | tID { add_symbol($1, "int"); add_instruction( "COP", 0 , 0 , 0 );  }
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
           var { add_symbol("tmp" , "int"); }
          | resultat tMUL var { add_symbol("tmp" , "int"); }
          | resultat tDIV var { add_symbol("tmp" , "int"); }
          | resultat tADD var { add_symbol("tmp" , "int"); }
          | resultat tSUB var { add_symbol("tmp", "int"); }
;

var:
     tID //{ add_symbol($1, "int"); }
    | tNB 
    | functionName
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
    fprintf(stderr, "Error: %s at line %d - ERROR JUST BEFORE SYMBOL %s\n", s, yylineno, yytext);
}

int main() {
    symbol_table = create_symbol_table();
    instruction_table = create_instruction_table();
    yyparse();
    print_symbol_table();
    print_instruction_table();
    return 0;
}