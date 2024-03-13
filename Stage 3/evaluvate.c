#include <stdio.h>
#include <stdlib.h>

int number;int list[26]={-1};
int evaluvate(struct tnode* t){
    int a,b;
    int val=0;
    if (t==NULL){
        return -1;
    }
    else if(t->nodetype==N_CONNECTOR){
        evaluvate(t->left);
        evaluvate(t->right);
    }
    else{
       switch(t->nodetype){
        case N_NUM:
            return t->val;
        case N_VAR:
            number=t->varname[0]-'a';
            return list[number];
        case N_ADD:
            return evaluvate(t->left)+evaluvate(t->right);
        case N_SUB:
            return evaluvate(t->left)-evaluvate(t->right);
        case N_MUL:
            return evaluvate(t->left)*evaluvate(t->right);
        case N_DIV:
            return evaluvate(t->left)/evaluvate(t->right);
        case N_READ:
            number=t->left->varname[0]-'a';
            scanf("%d",&list[number]);
            break;
        case N_WRITE:
            a=evaluvate(t->left);
            printf("%d\n",a);
            break;
        case N_ASSIGN:
            a=t->left->varname[0]-'a';
            list[a]=evaluvate(t->right);
            break;
        case N_LT:
            if(evaluvate(t->left) < evaluvate(t->right)){
                return 1;
            }else{
                return 0;
            }
        case N_GT:
            if(evaluvate(t->left) > evaluvate(t->right)){
                return 1;
            }else{
                return 0;
            }
        case N_EQ:
            if(evaluvate(t->left) == evaluvate(t->right)){
                return 1;
            }else{
                return 0;
            }
        case N_NEQ:
            if(evaluvate(t->left) != evaluvate(t->right)){
                return 1;
            }else{
                return 0;
            }
        case N_LE:
            if(evaluvate(t->left) <= evaluvate(t->right)){
                return 1;
            }else{
                return 0;
            }       
        case N_GE:
            if(evaluvate(t->left) >= evaluvate(t->right)){
                return 1;
            }else{
                return 0;
            }
        case N_IF_ELSE:
            if(evaluvate(t->left)){
                return evaluvate(t->mid);
            }else{
                return evaluvate(t->right);
            }
        case N_IF:
            if(evaluvate(t->left)){
                return evaluvate(t->mid);
            }
            break;
       }
    }
    return 0;
    
}