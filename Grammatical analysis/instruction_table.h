// instruction_table.h
#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H

typedef struct Instruction {
    char *name; // Instruction Name
    int numberRegister;  // 
    int addressMemory;   // 
    int valNonDefined;
    // char *type;   // Instruction Type

    //

} Instruction;

typedef struct InstructionTable {
    Instruction *instructions;  
    int size;         // Table Size
    int capacity;     // Capacity Table
} InstructionTable;

extern InstructionTable *instruction_table;

InstructionTable* create_instruction_table();
void add_instruction(char *name, int numberRegister, int addressMemory, int valNonDefined);
char* find_instruction(InstructionTable *table, char *name);
void print_instruction_table();

#endif // INSTRUCTION_TABLE_H
