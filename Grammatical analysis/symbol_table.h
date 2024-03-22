// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct Symbol {
    char *name; // El nombre del símbolo
    int type;   // Tipo de dato, p.ej. tINT
    // Agrega aquí otros detalles relevantes como alcance, direcciones, etc.
} Symbol;

typedef struct SymbolTable {
    Symbol *symbols;  // Arreglo dinámico de símbolos
    int size;         // Tamaño actual del arreglo
    int capacity;     // Capacidad total del arreglo
} SymbolTable;

extern SymbolTable *symbol_table;

SymbolTable* create_symbol_table();
void add_symbol(SymbolTable *table, char *name, int type);
Symbol* find_symbol(SymbolTable *table, char *name);
void print_symbol_table(SymbolTable *table);

#endif // SYMBOL_TABLE_H
