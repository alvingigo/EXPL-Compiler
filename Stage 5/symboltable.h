#define INT_TYPE 1
#define STR_TYPE 2
int localBindingStart=1;
#include <string.h>
#include <stdlib.h>
struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int size;         // size of the type of the variable
    int binding;      // stores the static memory address allocated to the variable
    int flabel;
    struct ParamList * param;
    struct Gsymbol *next;
}
;
struct ParamList {
    char* name;
    int type;
    struct ParamList * next;
};

struct Lsymbol{
    char * name;
    int type;
    int binding;
    struct Lsymbol* next;

};


struct Gsymbol *GLookup(char * name);            // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name, int type, int size,struct ParamList* param);  // Creates a symbol table entry.
struct Gsymbol *Ghead=NULL, *Gtail=NULL;
int flabelcount=0;
void ParamInstall(char* name,int type);
struct ParamList* Phead=NULL,*Ptail=NULL;
void InstallParamsInLocal();
void LInstall(char * name,int type);
struct Lsymbol *LLookup(char* name);
struct Lsymbol *Lhead=NULL, *Ltail=NULL;

void PrintGSymbolTable();
int bind=4096;