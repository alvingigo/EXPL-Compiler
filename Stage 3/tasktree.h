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

#define voidtype -1
#define booltype 0
#define inttype 1




typedef struct tnode{
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*mid,*right;  // left and right branches
}tnode;

struct tnode* createTree(int val,int type,int nodetype, char* c,tnode* l,tnode * r,tnode* mid);
int codeGen(struct tnode* temp);