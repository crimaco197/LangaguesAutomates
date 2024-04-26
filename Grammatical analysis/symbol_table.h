// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct Symbol {
    char *name; // Symbol Name
    char *type;   // Symbol Type
    int address;
} Symbol;

typedef struct SymbolTable {
    Symbol *symbols;  
    int size;         // Table Size
    int capacity;     // Capacity Table
} SymbolTable;

extern SymbolTable *symbol_table;

SymbolTable* create_symbol_table();
void add_symbol(char *name, char *type);
Symbol* find_symbol(SymbolTable *table, char *name);
void print_symbol_table();

#endif // SYMBOL_TABLE_H
