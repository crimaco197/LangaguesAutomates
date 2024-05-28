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


// VARIABLES GLOBALES
extern SymbolTable *symbol_table;
// extern int address_symbol; // Déclaration de la variable globale


SymbolTable* create_symbol_table();
void add_symbol(char *name, char *type);
int find_symbol(const char *name);
void delete_symbol(int index);
void delete_last_symbol(int index);
void print_symbol_table();

#endif // SYMBOL_TABLE_H
