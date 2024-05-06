%{
/* Oussama Eljid */
/*  Cristian Martinez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "instruction_table.h"
#include "declaration_var.h"


// VARIABLES GLOBALES
//extern char *yytext;
//extern int yylineno;
//extern char variableTMP;
//extern int global_number;

int global_number;
int address_symbol_previous;
int address_variable;
int address_var_TMP;
char* variableTMP;


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
    | tLBRACE returnStatement tRBRACE
;

returnStatement:
    tRETURN resultat tSEMI
;

structure : context
          | context structure     
;

context : 
         action 
;

action : 
         declaration // tSEMI // { add_instruction( "COP", 1 , address_symbol , 0 );  }
      // | declaration
       | print tSEMI
       | bucles
       | functionName tSEMI
;

print : tPRINT tLPAR tSTRING tID tSTRING tRPAR /*tPRINT tLPAR tID tRPAR*/
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

declaration1: tINT tID { add_symbol($2, "int"); } // tSEMI // { add_instruction( "COP", 1 , address_symbol , 0 );  }
;

declaration:
            declaration1 tSEMI
           | declaration1 tCOMMA declaration tSEMI
           | declaration1 tASSIGN resultat tCOMMA declaration tSEMI
           | declaration1 tASSIGN resultat tSEMI
           | declaration1 tASSIGN functionName tSEMI
           | tID tASSIGN resultat tSEMI {   address_variable = find_symbol($1);  
                                            //add_symbol($1, "int"); 
                                          //  printf("address_variable : %d\n", address_variable);
                                         //   printf("find_symbol($1) : %s\n", $1);
                                            add_instruction( "COP", address_variable , address_symbol_previous , 0 );
                                            delete_symbol(address_symbol_previous);  
                                        } 
           | tID tCOMMA declaration tSEMI
           | tID {  address_variable = find_symbol($1);  
                    add_symbol($1, "int"); 
                  //  printf("address_variable : %d\n", address_variable);
                  //  printf("find_symbol($1) : %s\n", $1);
                 }
            // tSEMI // { add_instruction( "COP", 1 , address_symbol , 0 );  } 
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
          | resultat tMUL { 
                            address_symbol_previous = find_symbol(symbolTMP);
                            printf("symbolTMP %s \n" , symbolTMP);
                            add_instruction( "MUL", address_symbol_previous  , address_symbol_previous , address_symbol ); 
                            delete_symbol(address_symbol_previous);
                          } 
            var 
          | resultat tDIV var
          | resultat tADD { 
                            address_symbol_previous = find_symbol(symbolTMP);
                            printf("symbolTMP %s \n" , symbolTMP);
                            add_instruction( "ADD", address_symbol_previous  , address_symbol_previous , address_symbol ); 
                         //  delete_symbol(address_symbol_previous);
                          } 
            var 
          | resultat tSUB var 
;

var:
     tID  { variableTMP = "tmp";
            add_symbol(variableTMP , "int");
            address_symbol_previous = find_symbol($1); 
            address_var_TMP = address_symbol_previous;
            add_instruction( "COP", address_symbol  , address_symbol_previous , 0 ); 
            //printf("AFC : %d\n", global_number);
          }
    | tNB { add_symbol("tmp" , "int");
            address_symbol_previous = address_symbol; 
            add_instruction( "AFC", address_symbol  , global_number , 0 ); 
            //printf("AFC : %d\n", global_number);
          }
    | functionName { add_symbol("tmp" , "int"); }
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