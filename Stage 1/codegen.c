#include <stdlib.h>
#include <stdio.h>
// #include "exptree.h"
int counter=-1;
extern FILE *intermediate;
int getReg(){
    if(counter<19){
        return ++counter;

    }
    printf("Out of Register\n");
    exit(1);
}

void freeReg(){
    if (counter>=0)
        counter--;
}



int rcount;
int codeGen(struct tnode* t) {
    if(t==NULL){
        return -1;
    }
    else if (t->op==NULL){
        rcount=getReg();
        fprintf(intermediate,"MOV R%d,%d\n",rcount,t->val);
        return rcount;
    }
    int r1=codeGen(t->left);
    int r2=codeGen(t->right);

    switch(*(t->op)){
        case '+' :  fprintf(intermediate,"ADD R%d,R%d\n",r1,r2);
                    freeReg();
                    return r1;   
        case '-' :  fprintf(intermediate,"SUB R%d,R%d\n",r1,r2);
                    freeReg();
                    return r1;   
        case '*' :  fprintf(intermediate,"MUL R%d,R%d\n",r1,r2);
                    freeReg();
                    return r1;   
        case '/' :  fprintf(intermediate,"DIV R%d,R%d\n",r1,r2);
                    freeReg();
                    return r1;   
    }  
    return 0;
}
