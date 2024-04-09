#include <string.h>
#include <stdlib.h>
struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int size;         // size of the type of the variable
    int binding;      // stores the static memory address allocated to the variable
    int isarr;
    struct Gsymbol *next;
}
;
#define INT_TYPE 1
#define STR_TYPE 2

struct Gsymbol *GLookup(char * name);            // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name, int type, int size,int isarr);   // Creates a symbol table entry.
void PrintSymbolTable();
struct Gsymbol *Ghead=NULL, *Gtail=NULL;
void PrintGTable();
int bind=4096;