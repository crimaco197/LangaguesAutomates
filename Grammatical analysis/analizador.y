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
      tVOID tID { printf("Function VOID Found : %s\n", yytext); } tLPAR args tRPAR tLBRACE structure tRBRACE { add_instruction( "NOP", 0 , 0 , 0 );  }
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
         declaration // tSEMI 
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

declaration1: tINT tID { add_symbol($2, "int"); } // tSEMI // 
;

declaration:
            declaration1 tSEMI
           | declaration1 tCOMMA declaration tSEMI
           | declaration1 tASSIGN resultat tCOMMA declaration tSEMI {
                                              //                   
           }
           | declaration1 tASSIGN resultat tSEMI {
                                           //      
           }
           | declaration1 tASSIGN functionName tSEMI
           | tID tASSIGN var tSEMI {
                                      address_variable = find_symbol($1);  
                                      delete_symbol(address_symbol_previous);  
                                      add_instruction( "COP", address_variable , address_symbol_previous , 0 );
                                      
           }
           | tID tASSIGN resultat tSEMI {   address_variable = find_symbol($1);  
                                            //add_symbol($1, "int"); 
                                          //  printf("address_variable : %d\n", address_variable);
                                         //   printf("find_symbol($1) : %s\n", $1);
                                            process_arithmetic_instructions();
                             //               printf("address_variable : %d\n", address_variable);
                           //                 printf("address_symbol_previous : %d\n", address_symbol_previous);
                                      //       
                                            add_instruction( "COP", address_variable , address_symbol_previous , 0 );
                                            delete_symbol(address_symbol_previous); 
                                            
                                        }                             
           | tID tCOMMA declaration tSEMI
           | tID {  address_variable = find_symbol($1);  
                    add_symbol($1, "int"); 
                  //  printf("address_variable : %d\n", address_variable);
                  //  printf("find_symbol($1) : %s\n", $1);
                 }
            // tSEMI 
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
                      //      printf("symbolTMP %s \n" , symbolTMP);
                           // add_instruction( "MUL", address_symbol_previous  , address_symbol_previous , address_symbol ); 
                            add_arithmetic_instruction("MUL", address_symbol_previous, address_symbol_previous, address_symbol); 
                       //     delete_symbol(address_symbol);
                          } 
            var 
          | resultat tDIV {
                            add_arithmetic_instruction("DIV", address_symbol_previous, address_symbol_previous, address_symbol); 
          }
            var
          | resultat tADD { 
                            address_symbol_previous = find_symbol(symbolTMP);
                      //      printf("symbolTMP %s \n" , symbolTMP);
                            // add_instruction( "ADD", address_symbol_previous  , address_symbol_previous , address_symbol ); 
                            add_arithmetic_instruction("ADD", address_symbol_previous, address_symbol_previous, address_symbol); 
                     //     delete_symbol(address_symbol);
                          } 
            var 
          | resultat tSUB {
                            add_arithmetic_instruction("SUB", address_symbol_previous, address_symbol_previous, address_symbol); 
          } 
          var 
;

var:
     tID  { variableTMP = "tmp";
            printf("COP 1 BEFORE - ID : %s address_symbol : %d, address_symbol_previous : %d\n", $1, address_symbol  , address_symbol_previous);
            address_symbol_previous = find_symbol($1); 
            address_var_TMP = address_symbol_previous;
         //   delete_symbol(address_var_TMP);
         printf("COP 1 - address_symbol : %d, address_symbol_previous : %d\n", address_symbol  , address_symbol_previous);
         //   add_instruction( "COP", address_symbol  , address_symbol_previous , 0 ); 
            
            add_symbol(variableTMP , "int");
      //      printf("address_var_TMP : %d\n", address_var_TMP);
          }
    | tNB { 
       //     printf("address_symbol before : %d\n", address_symbol);
            
            printf("address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d \n", address_symbol_previous, address_variable , address_var_TMP);
            
            add_symbol("tmp" , "int");
           //  address_symbol_previous = address_symbol; 
            add_instruction( "AFC", address_symbol_previous , global_number , 0 ); 
        //    add_instruction( "COP", address_variable  , address_symbol_previous , 0 ); 
            

        //    snprintf(varTMP, sizeof(varTMP), "%s%d", "tmp", address_symbol);
      //      address_symbol_previous = find_symbol(symbolTMP);
           printf("AFC - symbolTMP : %s, address_symbol_previous : %d\n", symbolTMP,  address_symbol_previous);
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