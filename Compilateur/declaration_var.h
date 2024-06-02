// DECLARATION_VAR.h
#ifndef DECLARATION_VAR_H
#define DECLARATION_VAR_H

// VARIABLES GLOBALES
extern int address_symbol;          // Address symbol on Table Symbol
extern int address_instruction;     // Address Instruction on Table Instruction
extern int idJMF;
extern int varFirstBucle;
extern int var_to_delete;
extern int varFirstJMP;

extern int varFirstWhile;
extern int varFirstIF;

extern int address_symbol_previous;
extern int address_variable;
extern int address_var_TMP;
extern int address_function;
extern int address_main;
extern char symbolTMP [100];
extern char *nameID;   // to save the last variable operated
extern int numberID;   // to save the last variable TMP operated

extern char *nameFunction;

extern int address_operand1;
extern int address_operand2;
extern int address_result;
extern int address_POINTER;

extern int in_arithmetic_operation;



extern char *yytext;                // last ID read
extern int yylineno;                // number line of program


#endif /* DECLARATION_VAR_H */
