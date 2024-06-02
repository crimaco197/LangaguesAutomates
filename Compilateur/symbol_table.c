// symbol_table.c
#include "symbol_table.h"
#include "declaration_var.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instruction_table.h"


SymbolTable *symbol_table = NULL; // Inizialate Table
int address_symbol = 0;
char symbolTMP [100];

SymbolTable* create_symbol_table() {
    SymbolTable *symbol_table = malloc(sizeof(SymbolTable));
    symbol_table->size = 0;
    symbol_table->capacity = 10; // Initial Capacity
    symbol_table->symbols = malloc(sizeof(Symbol) * symbol_table->capacity);
    return symbol_table;
}


void add_symbol(char *name, char *type, int valorTMP) {
    if (symbol_table->size >= symbol_table->capacity) {
        symbol_table->capacity *= 2;
        symbol_table->symbols = realloc(symbol_table->symbols, sizeof(Symbol) * symbol_table->capacity);
    }


    Symbol new_symbol;
    if (find_symbol(name) == -1 && strcmp(name, "tmp") != 0) {
        new_symbol.name = strdup(name); // Asegurarse de liberar esta memoria más tarde
        new_symbol.type = strdup(type);
        new_symbol.address = address_symbol++;
        new_symbol.valor = valorTMP;

    } else {
        if (strcmp(name, "tmp") == 0) {
            snprintf(symbolTMP, sizeof(symbolTMP), "%s%d", name, address_symbol);  // Concatenar String e Int
            new_symbol.name = strdup(symbolTMP); // Usar strdup para evitar sobrescribir
            new_symbol.type = strdup(type);
            new_symbol.address = address_symbol++;
            new_symbol.valor = valorTMP;

            

            add_instruction("AFC", address_instruction, new_symbol.address, valorTMP, 0);

                if(nameID != NULL){address_variable = find_symbol(nameID);}

        } else {
            snprintf(symbolTMP, sizeof(symbolTMP), "%s%d", "tmp", address_symbol);  // Concatenar String e Int
            new_symbol.name = strdup(symbolTMP); // Usar strdup para evitar sobrescribir
            new_symbol.type = strdup(type);
            new_symbol.address = address_symbol++;
            new_symbol.valor = valorTMP;
            int address_variable = find_symbol(name);

            add_instruction("COP", address_instruction, new_symbol.address, address_variable, 0);

        }
        
        address_var_TMP = new_symbol.address;
        
    }

    symbol_table->symbols[symbol_table->size++] = new_symbol;
}


int find_symbol(const char *name) {
    for (int i = 0; i < symbol_table->size; ++i) {
        Symbol symbol = symbol_table->symbols[i];  // we get the symbol stocked in i
        if (strcmp(symbol.name, name) == 0) {
            address_POINTER = symbol.valor;

            return symbol.address;
        }
    }
    // Symbol NOT found, return -1
    return -1;
}

void fin_main(){  { 
    //       int adr = find_symbol("!ADR");
    //       int val = find_symbol("!VAL");
    int adr = find_symbol("?ADR");
    int val = find_symbol("?VAL");
    address_variable = adr;
    delete_symbol(val);       // DELETE ?VAL
    delete_symbol(adr);  // DELETE ?ADR
    delete_last_symbol(address_var_TMP);
    //                     add_symbol("tmp", nameFunction, 0);
    address_symbol_previous = address_symbol;
    add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
    add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
    add_instruction( "POP", address_instruction, adr, 0 , 0 );
    add_instruction( "COPkkk", address_instruction, address_variable , address_symbol_previous , 0 );
} 
}

void add_adr_val(){
    add_symbol("!ADR", nameFunction, 0); 
    add_symbol("!VAL", nameFunction, 0); 
    // printf("ADR y VAL AGREGADAS xxxxxxxxxx\n");
}

void delete_adr_val(){
    int val = find_symbol("?VAL");
    int adr = find_symbol("?ADR");
    delete_symbol(val);       // DELETE ?VAL
    delete_last_symbol(adr);  // DELETE ?ADR
}

void fin_function(){                 
    int adr = find_symbol("!ADR");
    int val = find_symbol("!VAL");

    address_variable = adr;
    delete_symbol(val);  // DELETE !VAL
    delete_symbol(adr);  // DELETE !ADR

    address_symbol_previous = address_symbol;

    add_instruction( "PUSH", address_instruction, adr , 0 , 0 ); 
    add_instruction( "CALL", address_instruction, address_function , 0 , 0 );
    add_instruction( "POP", address_instruction, adr, 0 , 0 );
    add_instruction( "COP", address_instruction, address_variable , address_symbol_previous , 0 );

    address_var_TMP = address_variable;
    address_variable = adr;
    // delete_symbol(address_var_TMP);
}

int find_symbol_by_number(int valorr) {
    if (!symbol_table) {  // Verificar si la tabla de símbolos está inicializada
        printf("Symbol table is not initialized.\n");
        return -1;
    }

    // printf("RETURN find_symbol_by_number - valor %d\n", valorr);
    for (int i = 0; i < symbol_table->size; ++i) {
        Symbol symbol = symbol_table->symbols[i];  // we get the symbol stocked in i
        if (symbol.valor == valorr) {
            // printf("RETURN ADDRESS - %d\n", symbol.address);
            address_POINTER = symbol.valor;
            return symbol.address;
        }
    }
    printf("RETURN ADDRESS NOT FOUND - %d\n", -1);
    // Symbol NOT found, return -1
    return -1;
}

void delete_symbol(int index) {
   //  int index = find_symbol(name); 
   if (symbol_table->size == 1) {
        printf("Last element on the Symbol Table can not be deleted.\n");
        return;
    }

    // If symbol is found, delete it. 
    if (index != -1) {
        for (int i = index; i < symbol_table->size - 1; ++i) {
            // We move all elements in i+1 to position i. Then we reduce the table size
            // symbol_table->symbols[i], we get the element i of symbol_table.
            symbol_table->symbols[i] = symbol_table->symbols[i + 1];
        }
        symbol_table->size--; // Reduce table size
        address_symbol--;
     //   address_symbol_previous--;
    } else {
        printf("Symbol \"%d\" not found.\n", index);
    }
}

void delete_last_symbol(int index) {
   //  int index = find_symbol(name); 

    // If symbol is found, delete it. 
    if (index != -1) {
        for (int i = index; i < symbol_table->size - 1; ++i) {
            // We move all elements in i+1 to position i. Then we reduce the table size
            // symbol_table->symbols[i], we get the element i of symbol_table.
            symbol_table->symbols[i] = symbol_table->symbols[i + 1];
        }
        symbol_table->size--; // Reduce table size
        address_symbol--;
     //   address_symbol_previous--;
    } else {
        printf("Symbol \"%d\" not found.\n", index);
    }
}



// Print Table Symbol
void print_symbol_table() {
    printf("|----------------------------------------------|\n");
    printf("|                  SYMBOL TABLE                |\n");
    printf("|----------------------------------------------|\n");
	printf("|   Name   |   Adresse  |  Function  |  Valor  |\n");
	printf("|----------------------------------------------|\n");
    for (int i = 0; i < symbol_table->size; ++i) {
        Symbol symbol = symbol_table->symbols[i];
    printf("|%10s|%12d|%12s|%9d|\n", symbol.name, symbol.address , symbol.type, symbol.valor );
    //        printf("Name: %s, Type: %s\n", symbol.name, symbol.type);

    //    printf("Name: %s, Type: %s, Adress: %d\n", symbol.name, symbol.address , symbol.type );

    }
    printf("|----------------------------------------------|\n");
}
