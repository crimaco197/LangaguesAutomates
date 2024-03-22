// symbol_table.c
#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

SymbolTable *symbol_table = NULL; // Definición e inicialización

SymbolTable* create_symbol_table() {
    SymbolTable *table = malloc(sizeof(SymbolTable));
    table->size = 0;
    table->capacity = 10; // Comienza con un tamaño inicial
    table->symbols = malloc(sizeof(Symbol) * table->capacity);
    return table;
}


void add_symbol(SymbolTable *table, char *name, int type) {
    // Revisa si necesitas expandir el arreglo
    if (table->size >= table->capacity) {
        table->capacity *= 2;
        table->symbols = realloc(table->symbols, sizeof(Symbol) * table->capacity);
    }

    // Agrega el nuevo símbolo
    Symbol new_symbol;
    new_symbol.name = strdup(name); // Asegúrate de liberar esta memoria más tarde
    new_symbol.type = type;
    table->symbols[table->size++] = new_symbol;
}


// Función para imprimir el contenido de la tabla de símbolos
void print_symbol_table(SymbolTable *table) {
    printf("Symbol Table:\n");
    printf("-------------------\n");
    for (int i = 0; i < table->size; ++i) {
        Symbol symbol = table->symbols[i];
        printf("Name: %s, Type: %d\n", symbol.name, symbol.type);
        // Agregar aquí más detalles si es necesario
    }
    printf("-------------------\n");
}



//Symbol* find_symbol(SymbolTable *table, char *name) {
    // Implementación...
//}
