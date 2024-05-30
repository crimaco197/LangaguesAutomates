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
//static char variableTMP ;

SymbolTable* create_symbol_table() {
    SymbolTable *symbol_table = malloc(sizeof(SymbolTable));
    symbol_table->size = 0;
    symbol_table->capacity = 10; // Initial Capacity
    symbol_table->symbols = malloc(sizeof(Symbol) * symbol_table->capacity);
    return symbol_table;
}


void add_symbol(char *name, char *type, int valorr) {  // ajouter la valeur de chaque variable ?? 
    if (symbol_table->size >= symbol_table->capacity) {
        symbol_table->capacity *= 2;
        symbol_table->symbols = realloc(symbol_table->symbols, sizeof(Symbol) * symbol_table->capacity);
    }

    Symbol new_symbol;
    // Add new symbol
    if (strcmp(name, "tmp") == 0){
        
        snprintf(symbolTMP, sizeof(symbolTMP), "%s%d", name, address_symbol);  // Concantenate String and Int
        new_symbol.name = strdup(symbolTMP); // Free memory - a voir... 
        new_symbol.type = strdup(type);
        address_symbol_previous = address_symbol; 
        new_symbol.address = address_symbol++;
        new_symbol.valor = valorr;
        
    }else{
        new_symbol.name = strdup(name); // Free memory - a voir... 
        new_symbol.type = strdup(type);
        new_symbol.address = address_symbol++;
        new_symbol.valor = valorr;
    }

    symbol_table->symbols[symbol_table->size++] = new_symbol;
}

int find_symbol(const char *name) {
    for (int i = 0; i < symbol_table->size; ++i) {
        Symbol symbol = symbol_table->symbols[i];  // we get the symbol stocked in i
        if (strcmp(symbol.name, name) == 0) {
            return symbol.address;
        }
    }
    // Symbol NOT found, return -1
    return -1;
}

int find_symbol_by_number(int valorr) {
    if (!symbol_table) {  // Verificar si la tabla de símbolos está inicializada
        printf("Symbol table is not initialized.\n");
        return -1;
    }

    printf("RETURN find_symbol_by_number - valor %d\n", valorr);
    for (int i = 0; i < symbol_table->size; ++i) {
        Symbol symbol = symbol_table->symbols[i];  // we get the symbol stocked in i
        if (symbol.valor == valorr) {
            printf("RETURN ADDRESS - %d\n", symbol.address);
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
