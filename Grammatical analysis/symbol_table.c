// symbol_table.c
#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

SymbolTable *symbol_table = NULL; // Inizialate Table
static int address = 0;

SymbolTable* create_symbol_table() {
    SymbolTable *symbol_table = malloc(sizeof(SymbolTable));
    symbol_table->size = 0;
    symbol_table->capacity = 10; // Initial Capacity
    symbol_table->symbols = malloc(sizeof(Symbol) * symbol_table->capacity);
    return symbol_table;
}


void add_symbol(char *name, char *type) {
    if (symbol_table->size >= symbol_table->capacity) {
        symbol_table->capacity *= 2;
        symbol_table->symbols = realloc(symbol_table->symbols, sizeof(Symbol) * symbol_table->capacity);
    }
    Symbol new_symbol;
    // Add new symbol
    if (strcmp(name, "tmp") == 0){
        char symbolTMP [100];
        snprintf(symbolTMP, sizeof(symbolTMP), "%s%d", name, address);  // Concantenate String and Int
        new_symbol.name = strdup(symbolTMP); // Free memory - a voir... 
        new_symbol.type = strdup(type);
        new_symbol.address = address++;
    }else{
        new_symbol.name = strdup(name); // Free memory - a voir... 
        new_symbol.type = strdup(type);
        new_symbol.address = address++;
    }
    
    
    symbol_table->symbols[symbol_table->size++] = new_symbol;
}


// Print Table Symbol
void print_symbol_table() {
    printf("Symbol Table:\n");
    printf("-------------------\n");
    for (int i = 0; i < symbol_table->size; ++i) {
        Symbol symbol = symbol_table->symbols[i];
        printf("Name: %s, Type: %s\n", symbol.name, symbol.type);
    }
    printf("-------------------\n");
}



//Symbol* find_symbol(SymbolTable *table, char *name) {
    // Implementación...
//}
