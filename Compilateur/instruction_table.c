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
        new_instruction.add_operand_1 = numberRegister;
        new_instruction.add_operand_2 = addressMemory;
        new_instruction.add_operand_3 = addressValTMP;
        address_instruction++;

    instruction_table->instructions[instruction_table->size++] = new_instruction;
}

void update_instruction(char *name, int indexInstruction, int numberRegister, int newAddressMemory, int newAddressValTMP) {
    // printf("update_instruction - BEFORE UPDATE name : %s , indexInstruction : %d , numberRegister : %d , newAddressMemory : %d , newAddressValTMP : %d\n", name,  indexInstruction,  numberRegister, newAddressMemory, newAddressValTMP);
    for (int i = 0; i < instruction_table->size; ++i) {
        Instruction *instruction = &instruction_table->instructions[i];
        // printf("update_instruction - BEFORE UPDATE FOUND name : %s , indexInstruction : %d\n", instruction->name, instruction->indexInstruction);
        if (strcmp(instruction->name, name) == 0 && instruction->indexInstruction == indexInstruction ) {
            if(instruction->add_operand_1 == numberRegister){
            instruction->add_operand_1 = numberRegister;
            instruction->add_operand_2 = newAddressMemory;
            instruction->add_operand_3 = newAddressValTMP;
            break;
            }else{
            instruction->add_operand_1 = numberRegister;
            instruction->add_operand_2 = newAddressMemory;
            instruction->add_operand_3 = newAddressValTMP;
            }
            //printf("JMP UPDATED SUCCESS\n");
            
        }
    }
    //printf("COULD NOT UPDATE JMP\n");
}

void add_JMP(){
    varFirstJMP = address_instruction;
    add_instruction( "JMP", address_instruction, -999 , 0 , 0 ); 
    address_function = address_instruction;
}

void update_jmf(){
    int jmf_index = pop(); // GET THE ADDRESS OF JMF ON THE INSTRUCTION TABLE - WHERE IF STARTS
    idJMF = jmf_index;
    if (jmf_index != -1) {
        update_instruction("JMF", jmf_index, idJMF, address_instruction, 0); 
        // UPDATE INSTRUCTION TABLE WITH THE ADDRESS WHERE IF ENDS. LOOK FOR THE JMF + jmf_index IN THE INSTRUCTION TABLE, THEN UPDATE.
    } 
}


// Print Table Instruction$
void print_instruction_table() {
    printf("|--------------------------------------------------------|\n");
    printf("|                 ASSEMBLY INSTRUCTION TABLE             |\n");
    printf("|--------------------------------------------------------|\n");
	printf("|   Instruction   |   Operand 1  |  Operand 2  |  Other  |\n");
	printf("|--------------------------------------------------------|\n");
    for (int i = 0; i < instruction_table->size; ++i) {
        Instruction instruction = instruction_table->instructions[i];

  //      printf("Name: %s", instruction.name);
        printf("|%17s|%14d|%13d|%9d|\n", instruction.name, instruction.add_operand_1 , instruction.add_operand_2, instruction.add_operand_3);
      //  printf("Name: %s, Number Register: %d, Adress Memory: %d, Val: %d\n", instruction.name, instruction.numberRegister , instruction.addressMemory, instruction.valNonDefined);

    }
    printf("|--------------------------------------------------------|\n");
    printf("| SIZE : %48d|\n", instruction_table->size);
    printf("|--------------------------------------------------------|\n");
}

void add_operation(char * operation){
    int result = address_symbol - 2; 
    int operand_1 = address_symbol - 2;
    int operand_2 = address_symbol - 1;
    add_instruction(operation, address_instruction, result, operand_1, operand_2);
    delete_symbol(address_var_TMP);  
};






/*********************************************************************************************************/
/********************************** STACK Index JMF ********************************************/
/*********************************************************************************************************/
// TO SAVE THE INDEX OF JMF (IF - WHILE), and MAIN - FILO

StackNode *jmf_stack = NULL;

// ADD A NEW INDEX TO THE STACK
void push(int index) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    new_node->index = index;
    new_node->next = jmf_stack;
    jmf_stack = new_node;
    // print_stack();
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
    // print_stack();  print the stack
    return index;
}


// Function to print the stack
void print_stack() {
    StackNode *current = jmf_stack;
    printf("Stack bucles content : ");
    while (current != NULL) {
        printf("%d -> ", current->index);
        current = current->next;
    }
    printf("NULL\n");
}