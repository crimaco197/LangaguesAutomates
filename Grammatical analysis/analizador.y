%{
/* Oussama Eljid */
/*  Cristian Martinez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "instruction_table.h"
#include "declaration_var.h"


int global_number;
int address_symbol_previous;
int address_variable;
int address_var_TMP;
int address_function = 0;
int address_main = 0;
char* variableTMP;
char* nameID;
int numberID;
int in_arithmetic_operation = 0; // variable test add COP or NOT in tNB
int idJMF = 0;
int varFirstIF = 0;
int var_to_delete = 0;
int varFirstJMP = 0;
int returnBool = 0;
int args_operation = 0;
int mainBool = 0;

int address_operand1 = 0;
int address_operand2 = 0;
int address_result = 0;

char* nameIDtemporal;


char *nameFunction;





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
%token tVOID tINT tMAIN
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
Program : main 
        | fun
        | fun Program
;

main: type tMAIN { printf("Function MAIN Found : %s\n", yytext); 
                   mainBool = 1;
                   nameFunction = "main"; 
                   add_symbol("?ADR", nameFunction, 0);
                   add_symbol("?VAL", nameFunction, 0);
                   // printf("MAIN - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                   // printf("main - tNB NAME ?ADR, ADDRESS %d, NameTMP %s\n" , address_symbol-1, symbolTMP);
                   // printf("main - tNB NAME ?VAL, ADDRESS %d, NameTMP %s\n" , address_symbol-1, symbolTMP);
                  address_main = address_instruction + 1;
        }  
        BodyMain tRBRACE {  int val = find_symbol("?VAL");
                            int adr = find_symbol("?ADR");
                          
                            delete_symbol(address_variable);  // DELETE LAST VARIABLE OR TEMPORAL
                            address_symbol_previous = address_variable;

                            if(address_symbol_previous > address_symbol){
                                address_variable = address_symbol;
                            }
                            else{
                                address_variable = val;
                            }
                            add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                            add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                            add_instruction( "RET", address_instruction, 0 , 0 , 0 );

                            delete_symbol(val);       // DELETE ?VAL
                            delete_last_symbol(adr);  // DELETE ?ADR

                            update_instruction("JMP", varFirstJMP, address_main, 0,0 );  // todo - encontrar la direccion del MAIN
                            add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  
                            mainBool = 0;
}
;

type : tVOID  { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); } 
     | tINT   { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); } 
;

fun : tVOID tID {  printf("Function VOID Found : %s\n", yytext); nameFunction = $2; } Body 
    | tINT tID { printf("Function INT Found : %s\n", yytext);
                 nameFunction = $2;
                 add_symbol("?ADR", nameFunction, 0);  // OK
                 add_symbol("?VAL", nameFunction, 0); 
      } 
      tLPAR args tRPAR { varFirstJMP = address_instruction;
                         add_instruction( "JMP", address_instruction, -999 , 0 , 0 ); 
                         address_function = address_instruction;
      } 
      functionBodyReturn  tRBRACE {
      
      int val = find_symbol("?VAL");
      int adr = find_symbol("?ADR");
      // printf("functionBodyReturn - BEFORE val : %d, adr : %d \n", val, adr);
      delete_symbol(val);
      delete_symbol(adr);
      delete_last_symbol(var_to_delete);   
}
;

Body : tLPAR args tRPAR tLBRACE structure tRBRACE { add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  }
;

BodyMain : tLPAR args tRPAR tLBRACE structure { int adr = find_symbol("!ADR");
                                                int val = find_symbol("!VAL");
                                                // printf("structure - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                                if(adr == -1 && val == -1){
                                                    adr = 0;
                                                    //val = 0;
                                                    delete_symbol(address_symbol_previous);
                                                    add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                                                    add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                                                    add_instruction( "POP", address_instruction, adr, 0 , 0 );
                                                    add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                                break;
                                                }
                                                
                                                address_variable = adr;
                                                // printf("BodyMain - BEFORE val : %d, adr : %d \n", val, adr);
                                                delete_symbol(val);  // DELETE !VAL
                                                delete_symbol(adr);  // DELETE !ADR
                                                // printf("structure - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                                delete_symbol(address_symbol_previous);
                                                add_symbol("tmp", nameFunction, 0);
                                                address_symbol_previous = address_symbol;
                                                // printf("structure - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d  , address_instruction : %d , adr : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number, address_instruction , adr);
                                                add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                                                add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                                                add_instruction( "POP", address_instruction, adr, 0 , 0 );
                                                add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                                delete_symbol(address_variable);
            } 
    //      | tLPAR args tRPAR tLBRACE structure returnStatement
          | tLPAR args tRPAR tLBRACE {args_operation = 0; returnBool = 0;} 
            structure returnStatement { 
                              int adr = find_symbol("!ADR");
                              int val = find_symbol("!VAL");
                              // printf("BodyMain - BEFORE val : %d, adr : %d \n", val, adr);
                              //printf("structure - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                              address_variable = adr;
                              delete_symbol(val);       // DELETE ?VAL
                              delete_symbol(adr);  // DELETE ?ADR
                              //printf("structure - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                              delete_symbol(address_symbol_previous);
                              add_symbol("tmp", nameFunction, 0);
                              address_symbol_previous = address_symbol;
                              //printf("structure - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                              add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                              add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                              add_instruction( "POP", address_instruction, adr, 0 , 0 );
                              add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
} 
;

functionBodyReturn : tLBRACE structure returnStatement
                   | tLBRACE returnStatement 
;

returnStatement : tRETURN { 
                            returnBool = 1; 
                  } 
                  resultat tSEMI {
                                    address_variable = find_symbol("?VAL");  

                                    // printf("returnStatement - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                    if(in_arithmetic_operation){
                                        process_arithmetic_instructions();
                                        delete_symbol(address_result);
                                        in_arithmetic_operation = 0;
                                    }

                                    // printf("returnStatement - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                    
                                    if (returnBool && args_operation){
                                        address_symbol_previous = address_var_TMP;
                                        add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                        delete_symbol(address_symbol_previous);
                                        break;
                                    }
                                    if(returnBool && !mainBool){
                                        add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                    }
}
;

structure : 
          | context
          | context structure     
;

context : 
         action 
;

action : 
        declaration
       | print tSEMI
       | bucles
       | functionName tSEMI
;

print : tPRINT tLPAR tSTRING tID tSTRING tRPAR { add_instruction("PRI", address_instruction,numberID,0,0); }
      | tPRINT tLPAR resultat tRPAR { add_instruction("PRI", address_instruction, numberID,0,0);    // On ajoute l'instruction PRI
}
;

bucles : if
      | while
;

while : tWHILE tLPAR condition tRPAR { //int jmf_index = instruction_table->size - 1;
                      //                   printf("WHILE - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      //                   printf("WHILE - BEFORE address_symbol  %d\n", address_symbol);
                      //                   printf("WHILE - BEFORE address_instruction %d\n", address_instruction);
                      //                   printf("WHILE - BEFORE idJMF %d\n", idJMF);
                      //                   printf("WHILE - BEFORE varFirstIF %d\n", varFirstIF);
                                      
                                      
                                      //printf("address_instruction AGREGANDO %d\n", address_instruction);
                                      add_instruction( "JMF", address_instruction, address_symbol_previous , -999 , 0 );
                                      idJMF = address_symbol_previous;
                                      if (varFirstIF  >= idJMF && address_symbol != 0){
                      //                   printf("WHILE - AFTER address_symbol %d\n", address_symbol);
                      //                   printf("WHILE - AFTER address_instruction %d\n", address_instruction);
                      //                   printf("WHILE - AFTER idJMF %d\n", idJMF);
                      //                   printf("WHILE - AFTER varFirstIF %d\n", varFirstIF);
                                      delete_symbol(address_instruction);  
                      //                   printf("WHILE - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      }
                                      push(instruction_table->size - 1);
        } whileStructure tRBRACE { int jmf_index = pop(); // GET THE ADDRESS OF JMF ON THE INSTRUCTION TABLE - WHERE IF STARTS
                                              if (jmf_index != -1) {
                                                  update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // UPDATE INSTRUCTION TABLE WITH THE ADDRESS WHERE IF ENDS. LOOK FOR THE JMP + jmf_index IN THE INSTRUCTION, THEN UPDATE.
                                              } 
                                              if (idJMF >=  varFirstIF && address_symbol != 0 ){  // DELETE ALL TEMPORAL VARIABLE OF THIS IF SECTION
                                              delete_symbol(address_symbol_previous);
                                              }
                //                                  printf("ifStructure - AFTER AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
}
 ;
 
 whileStructure : tLBRACE structure /* { int jmf_index = pop(); // GET THE ADDRESS OF JMF ON THE INSTRUCTION TABLE - WHERE IF STARTS
              //                                  printf("WHILE UPDATE - AFTER jmf_index %d\n", jmf_index);
                                              if (jmf_index != -1) {
                                                  update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // UPDATE INSTRUCTION TABLE WITH THE ADDRESS WHERE IF ENDS. LOOK FOR THE JMP + jmf_index IN THE INSTRUCTION, THEN UPDATE.
                                              } 
                                              if (idJMF >=  varFirstIF && address_symbol != 0 ){  // DELETE ALL TEMPORAL VARIABLE OF THIS IF SECTION
                                              delete_symbol(address_symbol_previous);
                                              }
              //                                   printf("ifStructure - AFTER AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                  } */
                | tLBRACE returnStatement 
;

if: tIF tLPAR condition tRPAR { //int jmf_index = instruction_table->size - 1;
                                //  printf("IF - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                //  printf("IF - BEFORE address_symbol  %d\n", address_symbol);
                                //  printf("IF - BEFORE address_instruction %d\n", address_instruction);
                                //  printf("IF - BEFORE idJMF %d\n", idJMF);
                                //  printf("IF - BEFORE varFirstIF %d\n", varFirstIF);
                                
                                
                                //printf("address_instruction AGREGANDO %d\n", address_instruction);
                                add_instruction( "JMF", address_instruction, address_symbol_previous , -999 , 0 );
                                idJMF = address_symbol_previous;
                                if (varFirstIF  >= idJMF && address_symbol != 0){
                                //  printf("IF - AFTER address_symbol %d\n", address_symbol);
                                //    printf("IF - AFTER address_instruction %d\n", address_instruction);
                                //    printf("IF - AFTER idJMF %d\n", idJMF);
                                //    printf("IF - AFTER varFirstIF %d\n", varFirstIF);
                                 delete_symbol(address_instruction);  
                                //    printf("IF - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                }
                                push(instruction_table->size - 1);
    } ifStructure
;

ifStructure : tLBRACE structure tRBRACE { int jmf_index = pop(); // Obtener el índice de la instrucción JMF
                                          //printf("jmf_index UPDATE %d\n", jmf_index);
                                          //printf("address_instruction UPDATE %d\n", address_instruction);
                                          if (jmf_index != -1) {
                                              // printf("ACTUALIZANDO JMF...\n");
                                              update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // Actualizar la instrucción JMF
                                          } 
                                          

                                          if (idJMF >=  varFirstIF && address_symbol != 0 ){
                                       //       printf("ifStructure - AFTER address_symbol  %d\n", address_symbol);
                                       //       printf("ifStructure - AFTER jmf_index  %d\n", jmf_index);
                                       //       printf("ifStructure - AFTER idJMF %d\n", idJMF);
                                       //       printf("ifStructure - AFTER varFirstIF %d\n", varFirstIF);
                                           delete_symbol(address_symbol_previous);
                                       //       printf("ifStructure - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                          }
                                          }
            | tLBRACE structure tRBRACE tELSE tLBRACE { int jmf_index = pop(); // Obtener el índice de la instrucción JMF
                                          if (jmf_index != -1) {
                                              // printf("ACTUALIZANDO JMF...\n");
                                              update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // Actualizar la instrucción JMF
                                          } 
                                          
                                          if (idJMF >=  varFirstIF && address_symbol != 0 ){
                                           delete_symbol(address_symbol_previous);
                                          }
                                          } structure tRBRACE
            | tLBRACE structure tRBRACE functionBodyReturn
            | tLBRACE structure tRBRACE tELSE tLBRACE { int jmf_index = pop(); // Obtener el índice de la instrucción JMF
                                          if (jmf_index != -1) {
                                              // printf("ACTUALIZANDO JMF...\n");
                                              update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // Actualizar la instrucción JMF
                                          } 
                                          
                                          if (idJMF >=  varFirstIF && address_symbol != 0 ){
                                           delete_symbol(address_symbol_previous);
                                          }
                                          } functionBodyReturn tRBRACE
            | tLBRACE structure returnStatement tRBRACE
            | tLBRACE returnStatement tRBRACE { int jmf_index = pop(); // GET THE ADDRESS OF JMF ON THE INSTRUCTION TABLE - WHERE IF STARTS
                                                if (jmf_index != -1) {
                                                    update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); // UPDATE INSTRUCTION TABLE WITH THE ADDRESS WHERE IF ENDS. LOOK FOR THE JMP + jmf_index IN THE INSTRUCTION, THEN UPDATE.
                                                } 
                                                if (idJMF >=  varFirstIF && address_symbol != 0 ){  // DELETE ALL TEMPORAL VARIABLE OF THIS IF SECTION
                                                delete_symbol(address_symbol_previous);
                                                }
                                                // rintf("ifStructure - AFTER AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
}
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


declaration : tINT assignation tSEMI
            | tINT assignationAux tSEMI 
            | tINT tID tASSIGN { nameID = $2; add_symbol($2, nameFunction, 0);  } resultat tSEMI { delete_symbol(address_symbol_previous); // agregado
 }
            | assignation tSEMI
            | assignationAux tSEMI {
                                    // printf("AGREGANDO OPERACIONES ARITMETICAS\n");
                                    if(in_arithmetic_operation){
                                          process_arithmetic_instructions();
                                          delete_symbol(address_result);  // delete last tmp after arithmetic operation
                                          in_arithmetic_operation = 0;
                                          // printf("functionName XxXXX - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                          // printf("nameID - variable %s\n", nameID);
                                          add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                          break;      
                                    }
                                    delete_symbol(address_symbol_previous);

            }
;

assignation : tID { 
                    nameID = $1;
                    add_symbol($1, nameFunction, 0); 
              }
              tCOMMA assignation
            | tID { 
                    nameID = $1;
                    add_symbol($1, nameFunction, 0); 
              }
            | tID {  nameID = $1;  }  tCOMMA assignationAux
:

assignationAux : tID {  nameID = $1;  }  tASSIGN resultat 
               | assignationAux tCOMMA assignationAux
; 

functionName : tID tLPAR { add_symbol("!ADR", nameFunction, 0);   // !ADR et !VAL antes
                          add_symbol("!VAL", nameFunction, 0); 
                          // printf("ADR y VAL AGREGADAS xxxxxxxxxx\n");
               }
               argsName  tRPAR { 
                                // printf("functionName XxXXX returnBool : %d, args_operation %d\n", returnBool,  args_operation);
                                // printf("functionName XxXXX - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                if(returnBool && args_operation){
                                      int adr = find_symbol("!ADR");
                                      int val = find_symbol("!VAL");
                                      // printf("functionName - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      address_variable = adr;
                                      delete_symbol(val);  // DELETE !VAL
                                      delete_symbol(adr);  // DELETE !ADR
                                      // printf("structure - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      
                                      add_symbol("tmp", nameFunction, 0);
                                      address_symbol_previous = address_symbol;
                                      // printf("functionName - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
                                      add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
                                      add_instruction( "POP", address_instruction, adr, 0 , 0 );
                                      add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );
                                      //printf("argsfunctionName - AFTER AFTER Name address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                      break;
                                }
                                // printf("functionName XxXXX - HALF address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                if(returnBool){
                                    int adr = find_symbol("!ADR");
                                    // int val = find_symbol("!VAL");
                                    // printf("functionName XXXX - returnBool - BEFORE val : %d, adr : %d \n", val, adr);
                                    // printf("functionName XXXX - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                    address_variable = adr;
                                    // printf("functionName XXXX - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                }
                                // printf("functionName XxXXX - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_symbol("tmp" , nameFunction, 0); 
                                // printf("functionName - tTMP NAME %s, ADDRESS %d, NameTMP %s\n" , nameID, address_symbol-1, symbolTMP);
                                // printf("argsName address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_instruction( "AFC", address_instruction, address_symbol_previous , global_number , 0 );  // AFC BEFORE PUSH
}
;

argsName : /* Not Arguments */
        | argListName 
;

argListName : tID { add_symbol("tmp" , nameFunction, 0);
                   nameID = $1;
                   address_variable = find_symbol($1);
                   // printf("argListName - tID NAME %s, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);  
              }
            | tNB { add_symbol("tmp" , nameFunction, $1);
                    numberID = $1;
                    // printf("argListName - Agregando tmp numberID : %d\n", numberID);
                    delete_symbol(address_symbol_previous);
                    if(nameID != NULL){
                        address_variable = find_symbol(nameID);  
                    }
                    // printf("argListName - tNB NAME %d, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);
              }
            | functionName
            | argListName tCOMMA argListName
            | argListName { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); } 
              tDIV argListName { 
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                add_instruction("DIV", address_instruction, address_symbol_previous, address_symbol_previous, address_symbol);
              }
            | argListName { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); } 
              tMUL argListName { 
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                add_instruction("MUL", address_instruction, address_symbol_previous, address_symbol_previous, address_symbol);
              }
            | argListName { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); } 
              tSUB argListName { 
                                //printf("SUB BEFORE - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                //printf("SUB HALF - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                                add_instruction("SUB", address_instruction, address_symbol, address_symbol, global_number);
                                //printf("SUB AFTER - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
              }
            | argListName { add_instruction("COP", address_instruction, address_symbol_previous, address_variable,  0); } 
              tADD argListName { 
                                add_instruction("AFC", address_instruction, address_symbol_previous, global_number,  0);
                                global_number = address_symbol_previous;
                                args_operation = 1;
                                delete_symbol(address_symbol_previous);
                                add_instruction("ADD", address_instruction, address_symbol_previous, address_symbol_previous, address_symbol);
        }
;

resultat : var 
          | resultat{  // printf("MUL - BEFORE XXX symbolTMP : %s  , nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                  // printf("MUL - BEFORE XXX symbolTMP : %d\n", find_symbol(symbolTMP)); 
                  // printf("MUL - BEFORE XXX numberID : %d\n", numberID);
                  // printf("MUL - BEFORE XXX numberID : %d\n", find_symbol_by_number(numberID));
                      if(find_symbol(symbolTMP) != -1){
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
                  // printf("MUL - BEFORE XXX address_operand1 : %d\n", address_operand1);
            }
          tMUL var {  // printf("AGREGANDO MUL\n");
                      // printf("MUL - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      // printf("MUL - BEFORE 500 symbolTMP : %s, nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                      // printf("MUL - BEFORE 501 symbolTMP : %d\n", find_symbol(symbolTMP));
                      // printf("MUL - BEFORE 502 numberID : %d\n", numberID);
                      // printf("MUL - BEFORE 503 numberID : %d\n", find_symbol_by_number(numberID));
                      int temporal = find_symbol(symbolTMP);
                      if(temporal == -1){
                          address_operand2 = find_symbol_by_number(numberID);
                          
                      } else {
                          address_operand2 = find_symbol(symbolTMP); 
                      }
                      address_result = address_operand1;
                      // printf("MUL - BEFORE 513 address_operand2 : %d\n", address_operand2);
                      // printf("MUL - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      // add_arithmetic_instruction("MUL", address_symbol_previous, address_symbol_previous, address_symbol);   WORKING
                      add_arithmetic_instruction("MUL", address_result, address_operand1, address_operand2); 
                      in_arithmetic_operation = 1;
          }  
          | resultat { if(find_symbol(symbolTMP) != -1){
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
            } 
          tDIV var {
                  int temporal = find_symbol(symbolTMP);
                  if(temporal == -1){
                      address_operand2 = find_symbol_by_number(numberID);
                      
                  } else {
                      address_operand2 = find_symbol(symbolTMP); 
                  }
                  address_result = address_operand1;
                  add_arithmetic_instruction("DIV", address_result, address_operand1, address_operand2); 
                  in_arithmetic_operation = 1;
          }
          | resultat {  // printf("ADD - BEFORE XXX symbolTMP : %s  , nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                  // printf("ADD - BEFORE XXX symbolTMP : %d\n", find_symbol(symbolTMP)); 
                  // printf("ADD - BEFORE XXX numberID : %d\n", numberID);
                  // printf("ADD - BEFORE XXX numberID : %d\n", find_symbol_by_number(numberID));
                      if(find_symbol(symbolTMP) != -1){  
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
                  // printf("ADD - BEFORE XXX address_operand1 : %d\n", address_operand1);
            }
          tADD var { // printf("AGREGANDO ADD\n");
                       // printf("ADD - BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                       // printf("ADD - BEFORE 547 symbolTMP : %s, nameIDtemporal : %s\n", symbolTMP , nameIDtemporal);
                       // printf("ADD - BEFORE 548 symbolTMP : %d\n", find_symbol(symbolTMP));
                       // printf("ADD - BEFORE 549 numberID : %d\n", numberID);
                       // printf("ADD - BEFORE 550 numberID : %d\n", find_symbol_by_number(numberID));
                      int temporal = find_symbol(symbolTMP);
                      if(temporal == -1){
                          address_operand2 = find_symbol_by_number(numberID);
                      } else {
                          address_operand2 = find_symbol(symbolTMP); 
                      }
                      address_result = address_operand1;
                      // printf("ADD - BEFORE 559 address_operand2 : %d\n", address_operand2);
                      // printf("ADD - AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
                      // add_arithmetic_instruction("MUL", address_symbol_previous, address_symbol_previous, address_symbol);   WORKING
                      add_arithmetic_instruction("ADD", address_result, address_operand1, address_operand2); 
                      in_arithmetic_operation = 1;
          }  
          | resultat { if(find_symbol(symbolTMP) != -1){
                          
                          address_operand1 = find_symbol(symbolTMP);
                      } else if(find_symbol(symbolTMP) == -1) {
                          address_operand1 = find_symbol_by_number(numberID);
                      } 
            }
          tSUB var {
                  int temporal = find_symbol(symbolTMP);
                  if(temporal == -1){
                      address_operand2 = find_symbol_by_number(numberID);
                      
                  } else {
                      address_operand2 = find_symbol(symbolTMP); 
                  }
                  address_result = address_operand1;
                  add_arithmetic_instruction("SUB", address_result, address_operand1, address_operand2); 
                  in_arithmetic_operation = 1;
}
;

var : tID  { variableTMP = "tmp"; nameIDtemporal = $1;
            // nameID = $1;
            // printf("nameID - TID %s\n" , nameID);
            address_variable = find_symbol($1);  
            // printf("TID BEFORE address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol);
            address_var_TMP = address_symbol_previous;
            add_symbol(variableTMP , nameFunction, 0);            
            // printf("TID NAME %s, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);
            varFirstIF = address_symbol_previous;
            // printf("varFirstIF - TID %d\n" , varFirstIF);

            // printf("TID AFTER address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol);
            add_instruction( "COP", address_instruction, address_symbol_previous, address_variable , 0 ); 
   
            // printf("address_var_TMP : %d\n", address_var_TMP);
      }
    | tNB { numberID = $1;
            // printf("TNB AFTER - nameID %s\n" , nameID);
            // printf("address_symbol before : %d\n", address_symbol);
            // printf("TNB - before address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
            // snprintf(nameID, sizeof(nameID), "%d", $1);
            add_symbol("tmp" , nameFunction, $1);
            // printf("argListName - Agregando tmp numberID : %d\n", numberID);
            // printf("tNB NAME %d, ADDRESS %d, NameTMP %s\n" , $1, address_symbol-1, symbolTMP);
            if(nameID != NULL){
                address_variable = find_symbol(nameID);  
            }
            // printf("TNB AFTER - address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number);
            if(!in_arithmetic_operation && returnBool ){
                add_instruction( "AFC", address_instruction, address_symbol_previous , global_number , 0 ); 
                break;
            } 
            // printf("TNB - after address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d , in_arithmetic_operation : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number, in_arithmetic_operation);
            add_instruction( "AFC", address_instruction, address_symbol_previous , global_number , 0 ); 
            // printf("TNB - after in_arithmetic_operation : %d, args_operation : %d\n", in_arithmetic_operation , args_operation );        
            if (!in_arithmetic_operation  && !args_operation) {
            // printf("TNB - after address_symbol_previous : %d, address_variable : %d, address_var_TMP : %d , address_symbol : %d , global_number : %d , in_arithmetic_operation : %d \n", address_symbol_previous, address_variable , address_var_TMP, address_symbol, global_number, in_arithmetic_operation);
                add_instruction("COP", address_instruction, address_variable, address_symbol_previous, 0); 
            }

      }
    | functionName
;

args : /* Not Arguments */
    | argList
;

argList : tVOID
       | tINT tID { add_symbol($2, nameFunction, 0); 
                    // printf("ARGUMENTO tID %s\n", $2);
                    var_to_delete = find_symbol($2);
         } /* Only one argument */
       | argList tCOMMA tINT tID { add_symbol($4, nameFunction, 0);
                                   delete_symbol(address_symbol_previous); 
         } /* Several arguments, divided by commas */
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
    print_arithmetic_instruction_table();
    return 0;
}
