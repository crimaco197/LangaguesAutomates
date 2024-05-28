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
char* nameID;
int in_arithmetic_operation = 0; // variable test add COP or NOT in tNB
int idJMF = 0;
int varFirstIF = 0;
int in_bucle_if = 0;






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
%left tADD tSUB 
%left tMUL tDIV
%left tASSIGN
%token tLT tGT tNE tEQ tGE tLE 
%token tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA 
%token tERROR tPRINT tRETURN

%%
Program : fun
        | fun Program
;

fun: 
      tVOID tID { printf("Function VOID Found : %s\n", yytext); } tLPAR args tRPAR tLBRACE structure tRBRACE { add_instruction( "NOP", 0, 0 , 0 , 0 );  }
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
    //  | declaration3
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

if: tIF tLPAR condition tRPAR { //int jmf_index = instruction_table->size - 1;
                                  printf("IF - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                  printf("IF - BEFORE address_symbol  %d\n", address_symbol);
                                  printf("IF - BEFORE address_instruction %d\n", address_instruction);
                                  printf("IF - BEFORE idJMF %d\n", idJMF);
                                  printf("IF - BEFORE varFirstIF %d\n", varFirstIF);
                                
                                in_bucle_if = 1;
                                //printf("address_instruction AGREGANDO %d\n", address_instruction);
                                add_instruction( "JMF", address_instruction, address_symbol_previous , -999 , 0 );
                                idJMF = address_symbol_previous;
                                if (varFirstIF  >= idJMF && address_symbol != 0){
                                  printf("IF - AFTER address_symbol %d\n", address_symbol);
                                  printf("IF - AFTER address_instruction %d\n", address_instruction);
                                  printf("IF - AFTER idJMF %d\n", idJMF);
                                  printf("IF - AFTER varFirstIF %d\n", varFirstIF);
                                 delete_symbol(address_symbol_previous);
                                  printf("IF - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                }
                                push(instruction_table->size - 1);
 } ifStructure
;

ifStructure : tLBRACE structure tRBRACE { int jmf_index = pop(); // Obtener el índice de la instrucción JMF
                                          // delete_symbol(address_symbol_previous);
                                          //printf("jmf_index UPDATE %d\n", jmf_index);
                                          //printf("address_instruction UPDATE %d\n", address_instruction);
                                          if (jmf_index != -1) {
                                              //printf("ACTUALIZANDO...");
                                              update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // Actualizar la instrucción JMF
                                          } 
                                          in_bucle_if = 1;
                                            printf("ifStructure - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                            printf("ifStructure - BEFORE address_symbol  %d\n", address_symbol);
                                            printf("ifStructure - BEFORE jmf_index %d\n", jmf_index);
                                            printf("ifStructure - BEFORE idJMF %d\n", idJMF);
                                            printf("ifStructure - BEFORE varFirstIF %d\n", varFirstIF);
                                          if (idJMF >=  varFirstIF && address_symbol != 0 ){
                                            printf("ifStructure - AFTER address_symbol  %d\n", address_symbol);
                                            printf("ifStructure - AFTER jmf_index  %d\n", jmf_index);
                                            printf("ifStructure - AFTER idJMF %d\n", idJMF);
                                            printf("ifStructure - AFTER varFirstIF %d\n", varFirstIF);
                                           delete_symbol(address_symbol_previous);
                                            printf("ifStructure - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                          }
                                          }
            | tLBRACE structure tRBRACE tELSE tLBRACE structure tRBRACE
            | tLBRACE structure tRBRACE functionBody
            | tLBRACE structure tRBRACE tELSE tLBRACE functionBody tRBRACE
            ;

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

declaration1: tINT tID { 
   nameID = $2;
  add_symbol($2, "int"); } // tSEMI // 
;

declaration3: tASSIGN var tSEMI
             |  tASSIGN resultat tSEMI {
                       //   address_variable = find_symbol($1);  
                                            //add_symbol($1, "int"); 
                                          //  printf("address_variable : %d\n", address_variable);
                                         //   printf("find_symbol($1) : %s\n", $1);
                                         process_arithmetic_instructions();
                                     //    delete_symbol(address_symbol_previous);
                                          add_instruction( "COP", 0, address_variable , address_symbol_previous , 0 );
                                          in_arithmetic_operation = 0;
                                  // comment          delete_symbol(address_symbol); 
            }
            ;



declaration:
            declaration1 tSEMI
           | declaration1 tCOMMA declaration tSEMI
           | declaration1 tASSIGN resultat tCOMMA declaration tSEMI 
           | declaration1 tASSIGN resultat tSEMI 
         //  | declaration1 tASSIGN functionName tSEMI
           | tID {  nameID = $1;  } declaration3
           | tID tCOMMA declaration tSEMI
           | tID { // nameID = $1;
           // printf("nameID - tID seul %s\n" , nameID);
          //  address_variable = find_symbol($1);  
                    add_symbol($1, "int"); 
                  //  printf("address_variable : %d\n", address_variable);
                  //  printf("find_symbol($1) : %s\n", $1);
                 }
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
          | resultat { 
                            address_symbol_previous = find_symbol(symbolTMP);
                  //         printf("symbolTMP %s \n" , symbolTMP);
                           // add_instruction( "MUL", address_symbol_previous  , address_symbol_previous , address_symbol ); 
// printf("MUL - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                  
                            add_arithmetic_instruction("MUL", address_symbol_previous, address_symbol_previous, address_symbol); 
                            in_arithmetic_operation = 1;
                        //    delete_symbol(address_symbol_previous);
                       //     address_symbol_previous--;
               //             printf("MUL - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);

                       //     delete_symbol(address_symbol);
                          }  tMUL 
            var 
          | resultat tDIV {
            address_symbol_previous = find_symbol(symbolTMP);
                            add_arithmetic_instruction("DIV", address_symbol_previous, address_symbol_previous, address_symbol); 
                            in_arithmetic_operation = 1;
                       //     delete_symbol(address_symbol_previous);
                     //       address_symbol_previous--;
          }
            var
          | resultat { 
            // printf("ADD - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);

                           address_symbol_previous = find_symbol(symbolTMP);
             //              printf("symbolTMP %s \n" , symbolTMP);
                            // add_instruction( "ADD", address_symbol_previous  , address_symbol_previous , address_symbol ); 
                            add_arithmetic_instruction("ADD", address_symbol_previous, address_symbol_previous, address_symbol); 
                            in_arithmetic_operation = 1;
                     //       delete_symbol(address_symbol_previous);
                         //   address_symbol_previous--;
           //                             printf("ADD - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);

                     //     delete_symbol(address_symbol);
                          }  tADD 
            var 
          | resultat tSUB {
                            address_symbol_previous = find_symbol(symbolTMP);
                            add_arithmetic_instruction("SUB", address_symbol_previous, address_symbol_previous, address_symbol); 
                            in_arithmetic_operation = 1;
                      //      delete_symbol(address_symbol_previous);
                       //     address_symbol_previous--;
          } 
          var 
;

var:
     tID  { variableTMP = "tmp";
     // nameID = $1;
  //   printf("nameID - TID %s\n" , nameID);
     address_variable = find_symbol($1);  
     //    printf("TID BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol);
        //    address_symbol_previous = find_symbol($1); 
            address_var_TMP = address_symbol_previous;
            add_symbol(variableTMP , "int");
          varFirstIF = address_symbol_previous;
          printf("varFirstIF - TID %d\n" , varFirstIF);
            //    delete_symbol(address_var_TMP);
            
         //   delete_symbol(address_symbol_previous);
        //    delete_symbol(address_var_TMP);
       //  printf("TID AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol);
            add_instruction( "COP", 0, address_symbol_previous, address_variable , 0 ); 
      //     
   //   if (!in_arithmetic_operation) {
       //         delete_symbol(address_symbol_previous);
       //     }
            
      //      printf("address_var_TMP : %d\n", address_var_TMP);
          }
    | tNB { 
      printf("TNB AFTER - nameID %s\n" , nameID);
       //     printf("address_symbol before : %d\n", address_symbol);
         //          printf("TNB - before address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
add_symbol("tmp" , "int");
if(nameID != NULL){
            address_variable = find_symbol(nameID);  
}
      printf("TNB AFTER - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
      printf("TNB AFTER - in_bucle_if %d\n" , in_bucle_if);

delete_symbol(address_symbol_previous);
              
     //                  printf("TNB - after address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
add_instruction( "AFC", 0, address_symbol_previous , global_number , 0 ); 
          //   address_symbol_previous = address_symbol; 
            
        if (!in_arithmetic_operation) {
                add_instruction("COP", 0, address_variable, address_symbol_previous, 0); 
            }

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
