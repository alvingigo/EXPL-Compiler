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

int codeGen(struct tnode *t){
    int r1,r2,r3,number,status;
    if(t==NULL){
        return -1;
    }
    else if(t->nodetype==N_CONNECTOR){
        codeGen(t->left);
        codeGen(t->right);
    }
    switch (t->nodetype){
        case N_NUM:
            r1=getReg();
            fprintf(intermediate,"MOV R%d,%d\n",r1,t->val);
            return r1;
        case N_VAR:
            r1=getReg();
            number=4096+t->varname[0]-'a';
            fprintf(intermediate,"MOV R%d,[%d]\n",r1,number);
            return r1;
        case N_ADD:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"ADD R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case N_SUB:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"SUB R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case N_MUL:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"MUL R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case N_DIV:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"DIV R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case N_ASSIGN:
            number = 4096 + t->left->varname[0] - 'a';
            r2=codeGen(t->right);
            fprintf(intermediate,"MOV [%d],R%d\n",number,r2);
            freeReg();
            return r1;
        case N_READ:
          
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status=counter;
            
            number=t->left->varname[0]-'a'+4096;
            fprintf(intermediate, "MOV R2, \"Read\"\n");
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "MOV R2, -1\n");
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate,"MOV R2,%d\n",number);
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "POP R0\n");
            fprintf(intermediate, "POP R1\n");
            fprintf(intermediate, "POP R1\n");
            fprintf(intermediate, "POP R1\n");
            fprintf(intermediate, "POP R1\n");
            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            
            break;
        case N_WRITE:
            for(int i=0;i<=counter;i++){
                fprintf(intermediate,"PUSH R%d\n",i);
            }
            status=counter;
            r1=codeGen(t->left);
            fprintf(intermediate, "MOV R2, \"Write\"\n");
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "MOV R2, -1\n");
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "PUSH R%d\n", r1);
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "PUSH R2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "POP R0\n");
            fprintf(intermediate, "POP R1\n");
            fprintf(intermediate, "POP R1\n");
            fprintf(intermediate, "POP R1\n");
            fprintf(intermediate, "POP R1\n");
            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;

            break;
    }
}

void initalise(){
    intermediate=fopen("inter.xsm","w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "ADD SP, 26\n");
}
void finalise(){
    fprintf(intermediate,"INT 10");
    fclose(intermediate);
}