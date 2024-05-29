// instruction_table.h
#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H

#include "declaration_var.h"

typedef struct Instruction {
    char *name; // Instruction Name
    int numberRegister;  // 
    int addressMemory;   // 
    int valNonDefined;
    int indexInstruction;
} Instruction;

// TABLE TO STOCK INSTRUCTIONS
typedef struct ArithmeticInstruction {
    char *name;
    int operand1;
    int operand2;
    int result;
    struct ArithmeticInstruction *next;
} ArithmeticInstruction;

typedef struct ArithmeticInstructionTable {
    ArithmeticInstruction *instructions;  
    int size;         // Table Size
    int capacity;     // Capacity Table
} ArithmeticInstructionTable;

typedef struct InstructionTable {
    Instruction *instructions;  
    int size;         // Table Size
    int capacity;     // Capacity Table
} InstructionTable;



// VARIABLES GLOBALES
extern InstructionTable *instruction_table;
//extern int address_instruction;



InstructionTable* create_instruction_table();
void add_instruction(char *name, int indexInstruction, int numberRegister, int addressMemory, int addressValTMP);
void update_instruction(char *name,int indexInstruction, int numberRegister, int newAddressMemory, int newAddressValTMP);
char* find_instruction(InstructionTable *table, char *name);
void print_instruction_table();

// TABLE TO STOCK ARTIHMETIC INSTRUCTIONS 
void add_arithmetic_instruction(char *name, int operand1, int operand2, int result);
void process_arithmetic_instructions();
void print_arithmetic_instruction_table();



typedef struct StackNode {
    int index;
    struct StackNode *next;
} StackNode;

void push(int index);
int pop();
void print_stack();
#endif // INSTRUCTION_TABLE_H
