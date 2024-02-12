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
       }
    }
    return 0;
    
}