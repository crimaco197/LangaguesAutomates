// symbol_table.c
#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

SymbolTable *symbol_table = NULL; // Inizialate Table

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

    // Add new symbol
    Symbol new_symbol;
    new_symbol.name = strdup(name); // Free memory - a voir... 
    new_symbol.type = strdup(type);
    symbol_table->symbols[symbol_table->size++] = new_symbol;
}


// Print Table Symbol
void print_symbol_table() {
    printf("Symbol Table:\n");
    printf("-------------------\n");
    for (int i = 0; i < symbol_table->size; ++i) {
        Symbol symbol = symbol_table->symbols[i];
        printf("Name: %s, Type: %d\n", symbol.name, symbol.type);
    }
    printf("-------------------\n");
}



//Symbol* find_symbol(SymbolTable *table, char *name) {
    // Implementación...
//}
