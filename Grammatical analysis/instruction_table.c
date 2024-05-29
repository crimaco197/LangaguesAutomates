// instruction_table.c
#include "instruction_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"
#include "declaration_var.h"

InstructionTable *instruction_table = NULL; // Inizialate Table
int address_instruction = 0;

InstructionTable* create_instruction_table() {
    InstructionTable *instruction_table = malloc(sizeof(InstructionTable));
    instruction_table->size = 0;
    instruction_table->capacity = 10; // Initial Capacity
    instruction_table->instructions = malloc(sizeof(Instruction) * instruction_table->capacity);  // assigne enough memory to stock
    return instruction_table;
}


void add_instruction(char *name,int indexInstruction, int numberRegister, int addressMemory, int addressValTMP) {
    if (instruction_table->size >= instruction_table->capacity) {
        instruction_table->capacity *= 2;
        instruction_table->instructions = realloc(instruction_table->instructions, sizeof(Instruction) * instruction_table->capacity);  // modify the size of memory assigned by malloc
    }

    Instruction new_instruction;
    // Add new instruction ASM
  
        new_instruction.name = strdup(name); // Free memory - a voir... 
        new_instruction.indexInstruction = indexInstruction;
        new_instruction.numberRegister = numberRegister;
        new_instruction.addressMemory = addressMemory;
        new_instruction.valNonDefined = addressValTMP;
        address_instruction++;

    instruction_table->instructions[instruction_table->size++] = new_instruction;
}

void update_instruction(char *name, int indexInstruction, int numberRegister, int newAddressMemory, int newAddressValTMP) {
    for (int i = 0; i < instruction_table->size; ++i) {
        Instruction *instruction = &instruction_table->instructions[i];
        if (strcmp(instruction->name, name) == 0 && instruction->indexInstruction == indexInstruction) {
            instruction->numberRegister = numberRegister;
            instruction->addressMemory = newAddressMemory;
            instruction->valNonDefined = newAddressValTMP;
            break;
        }
    }
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
    printf("SIZE : %d\n", instruction_table->size);
    printf("-------------------\n");
}


// TABLE TO STOCK ARTIHMETIC INSTRUCTIONS 
ArithmeticInstruction *arithmetic_instructions = NULL;

// TODO - COMMENTS AND UNDERSTAND HOW IT WORKS.
void add_arithmetic_instruction(char *name, int operand1, int operand2, int result) {
    ArithmeticInstruction *new_instruction = malloc(sizeof(ArithmeticInstruction));
//    delete_symbol(result);

  printf("address_symbol_previous: %d, address_symbol: %d\n", operand1, result);
    new_instruction->name = strdup(name);
    new_instruction->operand1 = operand1;
    new_instruction->operand2 = operand2;
    new_instruction->result = result;
    new_instruction->next = arithmetic_instructions;
    arithmetic_instructions = new_instruction;
    
}

void process_arithmetic_instructions() {
    ArithmeticInstruction *current = arithmetic_instructions;
    int last_operand1_value = 0; // Variable para almacenar el último valor de operand1
    int result = 0;
    while (current != NULL) {
        last_operand1_value = current->operand1; // Almacenar el valor de operand1
        result = current->result;
       //  printf("Operand1 Value: %d\n", last_operand1_value);
        
        add_instruction(current->name, 0, current->operand1, current->operand2, current->result);
        ArithmeticInstruction *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
        delete_symbol(result);  // it is gonna delete all the tmp but not the last one, the last tmp is deleted after doing COP
    }
    

    // Asigna el último valor de operand1 a address_symbol_previous
    address_symbol_previous = last_operand1_value;
    
    
    // printf("Final address_symbol_previous: %d\n", address_symbol_previous);

    arithmetic_instructions = NULL;
}


// STACK TO SAVE THE INDEX OF JMF (IF - WHILE) - FILO



StackNode *jmf_stack = NULL;

// ADD A NEW INDEX TO THE STACK
void push(int index) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    new_node->index = index;
    new_node->next = jmf_stack;
    jmf_stack = new_node;
    print_stack();
}

// DELETE DE LAST ELEMENT AND RETURN THE NEW INDEX
int pop() {
    if (jmf_stack == NULL) {
        return -1; // STACK EMPTY
    }
    StackNode *temp = jmf_stack;
    int index = temp->index;
    jmf_stack = jmf_stack->next;
    free(temp);
    print_stack();
    return index;
}

// Función para imprimir la pila
void print_stack() {
    StackNode *current = jmf_stack;
    printf("Stack content:\n");
    while (current != NULL) {
        printf("%d -> ", current->index);
        current = current->next;
    }
    printf("NULL\n");
}


