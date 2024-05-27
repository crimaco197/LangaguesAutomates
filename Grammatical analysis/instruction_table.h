// instruction_table.h
#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H

#include "declaration_var.h"

typedef struct Instruction {
    char *name; // Instruction Name
    int numberRegister;  // 
    int addressMemory;   // 
    int valNonDefined;
} Instruction;

typedef struct InstructionTable {
    Instruction *instructions;  
    int size;         // Table Size
    int capacity;     // Capacity Table
} InstructionTable;

// VARIABLES GLOBALES
extern InstructionTable *instruction_table;
//extern int address_instruction;

// TABLE TO STOCK INSTRUCTIONS
InstructionTable* create_instruction_table();
void add_instruction(char *name, int numberRegister, int addressMemory, int addressValTMP);
char* find_instruction(InstructionTable *table, char *name);
void print_instruction_table();

// TABLE TO STOCK ARTIHMETIC INSTRUCTIONS 
void add_arithmetic_instruction(char *name, int operand1, int operand2, int result);
void process_arithmetic_instructions();

#endif // INSTRUCTION_TABLE_H
