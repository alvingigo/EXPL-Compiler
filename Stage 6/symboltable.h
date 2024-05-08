#define INT_TYPE 1
#define STR_TYPE 2
int localBindingStart=1;int flabelcount=0;int bind=4096;
#include <string.h>
#include <stdlib.h>


struct TypeTable{
    char* name;
    int size;
    struct FieldList* fields;
    struct TypeTable* next;
};


struct TypeTable* Tlookup(char* name);
void TInstall(char* name,int size,struct FieldList* fields);
struct TypeTable *Thead=NULL, *Ttail=NULL;

struct TypeTable* declarationtype;
struct TypeTable* Fdeclarationtype;


struct FieldList{
    char* name;
    int fieldIndex;
    struct TypeTable* type;
    struct FieldList* next;
};


struct FieldList* Flookup(char* name,struct FieldList* temp);
void FInstall(char* name,struct TypeTable* type);
struct FieldList *Fhead=NULL, *Ftail=NULL, *ftemp;


struct Gsymbol {
    char* name;       // name of the variable
    struct TypeTable* type;         // type of the variable
    int size;         // size of the type of the variable
    int binding;      // stores the static memory address allocated to the variable
    int flabel;
    struct ParamList * param;
    struct Gsymbol *next;
}
;

struct Gsymbol *GLookup(char * name);            // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name, struct TypeTable* type, int size,struct ParamList* param);  // Creates a symbol table entry.
struct Gsymbol *Ghead=NULL, *Gtail=NULL;


struct ParamList {
    char* name;
    struct TypeTable* type;
    struct ParamList * next;
};

void ParamInstall(char* name,struct TypeTable* type);
struct ParamList* Phead=NULL,*Ptail=NULL;
void InstallParamsInLocal();

struct Lsymbol{
    char * name;
    struct TypeTable* type;
    int binding;
    struct Lsymbol* next;

};

void LInstall(char * name,struct TypeTable* type);
struct Lsymbol *LLookup(char* name);
struct Lsymbol *Lhead=NULL, *Ltail=NULL;



void PrintGSymbolTable();



