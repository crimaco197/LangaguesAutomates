// instruction_table.h
#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H

#include "declaration_var.h"

typedef struct Instruction {
    char *name;             // Instruction Name
    int add_operand_1;      // Address Operand 1
    int add_operand_2;      // Address Operand 2
    int add_operand_3;      // Address Operand 3
    int indexInstruction;   // Address Instruction
} Instruction;

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

void print_instruction_table();
void add_operation(char * operation);

void add_JMP();
void update_jmf();


typedef struct StackNode {
    int index;
    struct StackNode *next;
} StackNode;

void push(int index);
int pop();
void print_stack();


#endif // INSTRUCTION_TABLE_H
