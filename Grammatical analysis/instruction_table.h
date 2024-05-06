// instruction_table.h
#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H

<<<<<<< HEAD
#include "declaration_var.h"

=======
>>>>>>> c25f7d5c2148e5f11aeb63fbfb10ddaf9fa638fe
typedef struct Instruction {
    char *name; // Instruction Name
    int numberRegister;  // 
    int addressMemory;   // 
    int valNonDefined;
<<<<<<< HEAD
=======
    // char *type;   // Instruction Type

    //

>>>>>>> c25f7d5c2148e5f11aeb63fbfb10ddaf9fa638fe
} Instruction;

typedef struct InstructionTable {
    Instruction *instructions;  
    int size;         // Table Size
    int capacity;     // Capacity Table
} InstructionTable;

<<<<<<< HEAD
// VARIABLES GLOBALES
extern InstructionTable *instruction_table;
//extern int address_instruction;


InstructionTable* create_instruction_table();
void add_instruction(char *name, int numberRegister, int addressMemory, int addressValTMP);
=======
extern InstructionTable *instruction_table;

InstructionTable* create_instruction_table();
void add_instruction(char *name, int numberRegister, int addressMemory, int valNonDefined);
>>>>>>> c25f7d5c2148e5f11aeb63fbfb10ddaf9fa638fe
char* find_instruction(InstructionTable *table, char *name);
void print_instruction_table();

#endif // INSTRUCTION_TABLE_H
