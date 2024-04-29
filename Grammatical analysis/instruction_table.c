// instruction_table.c
#include "instruction_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

InstructionTable *instruction_table = NULL; // Inizialate Table
static int address = 0;

InstructionTable* create_instruction_table() {
    InstructionTable *instruction_table = malloc(sizeof(InstructionTable));
    instruction_table->size = 0;
    instruction_table->capacity = 10; // Initial Capacity
    instruction_table->instructions = malloc(sizeof(Instruction) * instruction_table->capacity);  // assigne enough memory to stock
    return instruction_table;
}


void add_instruction(char *name, int numberRegister, int addressMemory, int valNotDefined) {
    if (instruction_table->size >= instruction_table->capacity) {
        instruction_table->capacity *= 2;
        instruction_table->instructions = realloc(instruction_table->instructions, sizeof(Instruction) * instruction_table->capacity);  // modify the size of memory assigned by malloc
    }

    Instruction new_instruction;
    // Add new instruction ASM
  
        new_instruction.name = strdup(name); // Free memory - a voir... 
        new_instruction.numberRegister = numberRegister;
        new_instruction.addressMemory = address++;
        new_instruction.valNonDefined = 0;

    instruction_table->instructions[instruction_table->size++] = new_instruction;
}


// Print Table Instruction
void print_instruction_table() {
    printf("Instruction Table:\n");
    printf("-------------------\n");
    for (int i = 0; i < instruction_table->size; ++i) {
        Instruction instruction = instruction_table->instructions[i];

  //      printf("Name: %s", instruction.name);

        printf("Name: %s, Number Register: %d, Adress Memory: %d, Val: %d\n", instruction.name, instruction.numberRegister , instruction.addressMemory, instruction.valNonDefined);

    }
    printf("-------------------\n");
}



//Symbol* find_symbol(SymbolTable *table, char *name) {
    // Implementación...
//}
