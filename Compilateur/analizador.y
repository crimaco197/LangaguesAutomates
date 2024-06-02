%{
/* Oussama Eljid */
/*  Cristian Martinez */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "instruction_table.h"
#include "declaration_var.h"


int address_symbol_previous;
int address_variable;
int address_var_TMP;
int address_function = -1;
int address_main = 0;

char* nameID;
int numberID;
int in_arithmetic_operation = 0; // variable test add COP or NOT in tNB
int idJMF = 0;
int varFirstIF = 0;

int whileIndex = 0;
int varFirstWhile = 0;

int var_to_delete_arg = 0;
int varFirstJMP = 0;
int returnBool = 0;

int mainBool = 0;


int address_POINTER = 0;
int pointer_bool = 0;




char* nameFunction;





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
%token tVOID tINT tMAIN tPOINTER
%token tCDIV tSPAN tCSPAN
%token tIF tELSE tWHILE

%left tADD tSUB 
%left tMUL tDIV
%left tASSIGN

%token tLT tGT tNE tEQ tGE tLE 
%token tAND tOR tNOT
%token tLBRACE tRBRACE tLPAR tRPAR tSEMI tCOMMA 
%token tERROR tPRINT tRETURN

%type<s> idName
%type<i> idNumber

%%
Program : 
        | main
        | fun Program
;

main: type tMAIN { printf("Function MAIN Found : %s\n", yytext); 
                   mainBool = 1;
                   nameFunction = "main"; 
                   add_symbol("?ADR", nameFunction, 0);
                   add_symbol("?VAL", nameFunction, 0);
                   address_main = address_instruction;
        }  
         tLPAR args tRPAR tLBRACE { returnBool = 0;} 
         BodyMain tRBRACE {  
                            delete_adr_val();
                            add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                            update_instruction("JMP", varFirstJMP, address_main, 0,0 ); 
                            add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  
                            mainBool = 0;
}
;

BodyMain :  structure 
          | structure returnStatement
;


type : tVOID  { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); } 
     | tINT   { add_instruction( "RET", address_instruction, 0 , 0 , 0 ); } 
;

fun : tVOID tID {  printf("Function VOID Found : %s\n", yytext); nameFunction = "int"; } Body 
    | tINT tID { printf("Function INT Found : %s\n", yytext);
                 nameFunction = "int";
                 add_symbol("?ADR", nameFunction, 0);  // OK
                 add_symbol("?VAL", nameFunction, 0); 
      } 
      tLPAR args tRPAR { varFirstJMP = address_instruction;
                         add_instruction( "JMP", address_instruction, -999 , 0 , 0 ); 
                         address_function = address_instruction; } 
      functionBodyReturn  tRBRACE { delete_adr_val(); delete_last_symbol(var_to_delete_arg); }
;

Body : tLPAR args tRPAR tLBRACE structure tRBRACE { add_instruction( "NOP", address_instruction, 0 , 0 , 0 );  }
;



functionBodyReturn : tLBRACE structure returnStatement ;

returnStatement : tRETURN { 
                            returnBool = 1; 
                  } 
                  operationArith tSEMI {
                                    address_variable = find_symbol("?VAL");  
                                    if (returnBool){
                                        delete_symbol(address_var_TMP);
                                        add_instruction( "COP", address_instruction, address_variable , address_symbol , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                        
                                        break;
                                    }
                                    if(returnBool && !mainBool){
                                        add_instruction( "COPrrr", address_instruction, address_variable , address_symbol , 0 );
                                        add_instruction( "RET", address_instruction, 0 , 0 , 0 );
                                    }
}
;

structure : 
          | structure context      
;

context : 
         action 
;

action : 
        declaration tSEMI
       | print tSEMI
       | bucles
       | functionBody tSEMI
;

print : tPRINT tLPAR tSTRING tID tSTRING tRPAR { add_instruction("PRI", address_instruction,numberID,0,0);  delete_symbol(address_var_TMP);  }
      | tPRINT tLPAR operationArith tRPAR { add_instruction("PRI", address_instruction, numberID,0,0);  delete_symbol(address_var_TMP);    // On ajoute l'instruction PRI
}
;

bucles : if
      | while
;

while : tWHILE tLPAR condition tRPAR {  delete_symbol(address_var_TMP); 
                                      varFirstWhile++;
                                      whileIndex = address_instruction;
                                      add_instruction( "JMF", 2, varFirstWhile , -999 , 0 );
                                      idJMF = varFirstWhile;
                                      push(idJMF);
        } tLBRACE whileStructure tRBRACE { update_jmf(); add_instruction( "JMP", address_instruction, whileIndex , 0 , 0 ); }
 ;
 
 whileStructure : structure
                | returnStatement 
;

if: tIF tLPAR condition tRPAR { delete_symbol(address_var_TMP); 
                                varFirstIF++;
                                add_instruction( "JMF", 1, varFirstIF , -999 , 0 );
                                idJMF = varFirstIF;
                                push(idJMF);
    }  tLBRACE structure ifStructure
;

ifStructure : tRBRACE { update_jmf();}
            | tRBRACE { update_jmf();} functionBodyReturn
            | tRBRACE tELSE tLBRACE { update_jmf();} structure tRBRACE
            | tRBRACE tELSE tLBRACE { update_jmf();} functionBodyReturn tRBRACE
            | returnStatement tRBRACE { update_jmf();}
;

condition : var
          | tNOT var
          | condition tAND condition 
          | condition tNOT condition
          | condition tLE condition
          | condition tGE condition
          | condition tEQ condition
          | condition tNE condition
          | condition tGT condition
          | condition tLT condition
          | condition tOR condition 
;


declaration : tINT assignationAuxList 
            | tINT tMUL tID tASSIGN tPOINTER tID { nameID = $3; add_symbol($3, "POINTER", find_symbol($6)); }    // accept Pointer            
            | tINT tID tASSIGN { nameID = $2; add_symbol($2, nameFunction, 0);  } operationArith { address_variable = find_symbol($2); 
                                                                                                    delete_symbol(address_var_TMP);
                                                                                                 //  if(address_main){address_var_TMP = address_var_TMP - 2; }; 
                                                                                                    add_instruction("COP", address_instruction, address_variable, address_var_TMP, 0);  
                                                                                                    // printf("DELETING add_operation  : %d\n", address_var_TMP); 
                                                                                                    
                                                                                                     }    // 
            | assignationAux 
;


assignationAuxList : assignationAux
                   | assignationAuxList tCOMMA assignationAux
;

assignationAux : tID {  nameID = $1;  } tASSIGN operationArith { 
                    delete_symbol(address_var_TMP); 
                    address_variable = find_symbol($1); 
                    add_instruction("COP", address_instruction, address_variable, address_symbol, 0); 
                 }
               | tMUL tID tASSIGN tNB {  
                    find_symbol($2);
                    add_instruction("ACF", address_instruction, address_POINTER, $4, 0); 
                 }     // POINTER
               | tID {  add_symbol($1, nameFunction, 0); }
;

functionArgs : operationArith { fin_function(); }
             | args { fin_function(); }
; 

functionBody : tID tLPAR { add_adr_val(); } functionArgs tRPAR ;


operationArith : var
               | operationArith tADD operationArith { in_arithmetic_operation = 1; add_operation("ADD"); }
               | operationArith tSUB operationArith { in_arithmetic_operation = 1; add_operation("SUB"); }
               | operationArith tDIV operationArith { in_arithmetic_operation = 1; add_operation("DIV"); }
               | operationArith tMUL operationArith { in_arithmetic_operation = 1; add_operation("MUL"); }


idName : tID {  add_symbol($1 , nameFunction, 0);  } 
;

idNumber : tNB { numberID = $1; add_symbol("tmp" , nameFunction, $1);}
;

var : idName 
    | idNumber 
    | functionBody
;

args : /* Not Arguments */
    | argList
;

argVar : var
       | arg

argList : argVar tCOMMA argList 
        | argVar
;

arg : tVOID
    | tINT tID {  add_symbol($2, nameFunction, 0); 
                  var_to_delete_arg = find_symbol($2);
         } /* Only one argument */
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
