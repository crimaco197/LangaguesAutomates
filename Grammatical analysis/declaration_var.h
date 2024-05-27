// DECLARATION_VAR.h
#ifndef DECLARATION_VAR_H
#define DECLARATION_VAR_H

// VARIABLES GLOBALES
extern int address_symbol;          // Address symbol on Table Symbol
extern int address_instruction;     // Address Instruction on Table Instruction

extern int address_symbol_previous;
extern int address_variable;
extern int address_var_TMP;
extern char symbolTMP [100];
extern char varTMP [100];


extern char *yytext;                // last ID read
extern int yylineno;                // number line of program
extern char *variableTMP;            // 
extern int global_number;           // last number read

#endif /* DECLARATION_VAR_H */
