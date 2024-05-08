#define N_READ 0
#define N_WRITE 1
#define N_ADD 2
#define N_SUB 3
#define N_MUL 4
#define N_DIV 5
#define N_NUM 6
#define N_CONNECTOR 7
#define N_VAR 8
#define N_ASSIGN 9
#define N_EQ 10
#define N_NEQ 11
#define N_GT 12
#define N_LT 13
#define N_LE 14
#define N_GE 15
#define N_IF_ELSE 16
#define N_IF 17
#define N_WHILE 18
#define N_BREAK 19
#define N_CONT 20
#define N_DOWHILE 21
#define N_REPUNTIL 22
#define N_STRVAL 23
#define N_ARRAY 24
#define N_RET 25
#define N_FUNC 26
#define N_AND 27
#define N_OR 28
#define N_INIT 29 
#define N_ALLOC 30
#define N_FREE 31
#define N_FIELD 32
#define N_NILL 33
#define N_MOD 34


#define voidtype -1
#define booltype 0
#define inttype 1
#define strtype 2




typedef struct tnode{
    int val;        // value of a number for NUM nodes.
    struct TypeTable* type;    // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode* argList;
    struct Gsymbol* Gentry; // pointer to GST entry for global variables and functions
    struct Lsymbol* Lentry; // pointer to local variable
    struct tnode *left,*mid,*right;  // left and right branches
}tnode;

struct tnode* createTree(int val,struct TypeTable* type,int nodetype, char* c,tnode* l,tnode * r,tnode* mid);
int codeGen(struct tnode* temp);