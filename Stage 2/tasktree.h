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




typedef struct tnode{
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.
    struct tnode *left,*right;  // left and right branches
}tnode;

struct tnode* createTree(int val,int type,int nodetype, char* c,tnode* l,tnode * r);
void infix(struct tnode * temp);
int codeGen(struct tnode* temp);