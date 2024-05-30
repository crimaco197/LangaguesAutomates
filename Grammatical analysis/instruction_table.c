// instruction_table.c
#include "instruction_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol_table.h"
#include "declaration_var.h"


/*********************************************************************************************************/
/*************************************** INSTRUCTION TABLE ***********************************************/
/*********************************************************************************************************/
// IT IS USED TO STOCK THE ASSEMBLEUR INSTRUCTIONS

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
    printf("|--------------------------------------------------------|\n");
    printf("|                 ASSEMBLY INSTRUCTION TABLE             |\n");
    printf("|--------------------------------------------------------|\n");
	printf("|   Instruction   |   Operand 1  |  Operand 2  |  Other  |\n");
	printf("|--------------------------------------------------------|\n");
    for (int i = 0; i < instruction_table->size; ++i) {
        Instruction instruction = instruction_table->instructions[i];

  //      printf("Name: %s", instruction.name);
        printf("|%17s|%14d|%13d|%9d|\n", instruction.name, instruction.numberRegister , instruction.addressMemory, instruction.valNonDefined);
      //  printf("Name: %s, Number Register: %d, Adress Memory: %d, Val: %d\n", instruction.name, instruction.numberRegister , instruction.addressMemory, instruction.valNonDefined);

    }
    printf("|--------------------------------------------------------|\n");
    printf("| SIZE : %48d|\n", instruction_table->size);
    printf("|--------------------------------------------------------|\n");
}




/*********************************************************************************************************/
/********************************** ARITHMETIC INSTRUCTION TABLE *****************************************/
/*********************************************************************************************************/
// IT IS USED TO STOCK THE ARITHMETIC INSTRUCTION IN THE ORDER WHICH IS READ, THEN WHEN ALL THE
// VARIABLES ARE READ, IT EMPTY THE LIST ADDING TO THE INSTRUCTION TABLE THE INSTRUCTIONS 
// FROM THE RIGHT TO THE LEFT.


// TABLE TO STOCK ARTIHMETIC INSTRUCTIONS 
ArithmeticInstruction *arithmetic_instructions = NULL;

// TODO - COMMENTS AND UNDERSTAND HOW IT WORKS.
//void add_arithmetic_instruction(char *name, int operand1, int operand2, int result) { 
void add_arithmetic_instruction(char *name, int result, int operand1, int operand2) {
    ArithmeticInstruction *new_instruction = malloc(sizeof(ArithmeticInstruction));
//    delete_symbol(result);

    // printf("AGREGANDO OPERACION - NAME : %s , result : %d , operand1 : %d , operand2 : %d\n", name  , result , operand1, operand2);
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
    int operand2 = 0;
    while (current != NULL) {
        last_operand1_value = current->operand1; // Almacenar el valor de operand1
        // result = current->result;
        operand2 = current->operand2;
       //  printf("Operand1 Value: %d\n", last_operand1_value);
        
        // add_instruction(current->name, 0, current->operand1, current->operand2, current->result);
        add_instruction(current->name, 0 , current->result, current->operand1, current->operand2);
        ArithmeticInstruction *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
        // printf("DELETING TMP : %d\n" , operand2);
        delete_symbol(operand2);  // comentado
        //delete_symbol(result);  // it is gonna delete all the tmp but not the last one, the last tmp is deleted after doing COP
    }
    

    // Asigna el último valor de operand1 a address_symbol_previous
    address_symbol_previous = last_operand1_value;
    
    
    // printf("Final address_symbol_previous: %d\n", address_symbol_previous);

    arithmetic_instructions = NULL;
}

// Print Arithmetic Instructions
void print_arithmetic_instruction_table() {
    ArithmeticInstruction *current = arithmetic_instructions;
    printf("|---------------------------------------------------------|\n");
    printf("|               ARITHMETIC INSTRUCTION TABLE              |\n");
    printf("|---------------------------------------------------------|\n");
	printf("|   Instruction   |   Operand 1  |  Operand 2  |  Result  |\n");
	printf("|---------------------------------------------------------|\n");
    while (current != NULL) {
        printf("|%17s|%14d|%13d|%10d|\n", current->name, current->operand1, current->operand2, current->result);
        current = current->next;
    }
    printf("|---------------------------------------------------------|\n");
}



/*********************************************************************************************************/
/********************************** STACK ADDRESSES JMF - JMP ********************************************/
/*********************************************************************************************************/
// TO SAVE THE INDEX OF JMF (IF - WHILE) - FILO

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

// Function to print the stack
void print_stack() {
    StackNode *current = jmf_stack;
    printf("Stack content : ");
    while (current != NULL) {
        printf("%d -> ", current->index);
        current = current->next;
    }
    printf("NULL\n");
}