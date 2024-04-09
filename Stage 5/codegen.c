#include <stdlib.h>
#include <stdio.h>

int counter=-1;
int labelcounter=0;
extern FILE *intermediate;
extern int bind;
int WhileStart=-1;
int WhileEnd=-1;
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

int getlabel(){
    return labelcounter++;
}

void pushArguments(struct tnode* t){
    int r;
    while(t!=NULL){
        r=codeGen(t);
        fprintf(intermediate,"PUSH R%d\n",r);
        t=t->argList;
    }
    return;
}

void popArguments(struct tnode* t){
    int r=getReg();
    while(t!=NULL){
        fprintf(intermediate,"POP R%d\n",r);
        t=t->argList;
    }
    freeReg();
}


int GetMemoryAddress(struct tnode* t){
    int r1;
    
    if (t->nodetype==N_VAR){
        r1= getReg();
        if (t->Lentry!=NULL){
            fprintf(intermediate,"MOV R%d,%d\n",r1,t->Lentry->binding);
            fprintf(intermediate,"ADD R%d,BP\n",r1);
            return r1;
        }
        
        fprintf(intermediate, "MOV R%d, %d\n", r1, t->Gentry->binding);
        return r1;
    }else if(t->nodetype==N_ARRAY){
        r1=codeGen(t->right);
        fprintf(intermediate,"ADD R%d,%d\n",r1,t->left->Gentry->binding);
        return r1;
    }else{
        return -1;
    }
}

int codeGen(struct tnode *t){
    int r1,r2,r3,number,status,l1,l2,l3;
    int prevWhileStart=-1,prevWhileEnd=-1;
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
        case N_STRVAL:
            r1=getReg();
            fprintf(intermediate,"MOV R%d,%s\n",r1,t->varname);
            return r1;
        case N_VAR:
            r1=GetMemoryAddress(t);
            fprintf(intermediate,"MOV R%d,[R%d]\n",r1,r1);
            return r1;
        case N_ARRAY:
            r1=GetMemoryAddress(t);
            fprintf(intermediate,"MOV R%d,[R%d]\n",r1,r1);
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
            r1=GetMemoryAddress(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"MOV [R%d],R%d\n",r1,r2);
            freeReg();
            freeReg();
            break;

        case N_EQ:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"EQ R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case N_NEQ:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"NE R%d,R%d\n",r1,r2);
            freeReg();
            return r1;

        case N_LE:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"LE R%d,R%d\n",r1,r2);
            freeReg();
            return r1;

        case N_GE:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"GE R%d,R%d\n",r1,r2);
            freeReg();
            return r1;

        case N_LT:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"LT R%d,R%d\n",r1,r2);
            freeReg();
            return r1;

        case N_GT:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"GT R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        case N_AND:
            r1=codeGen(t->left);
            r2=codeGen(t->right);
            fprintf(intermediate,"MUL R%d,R%d\n",r1,r2);
            freeReg();
            return r1;
        
        case N_OR:
            break;
        case N_READ:
            
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Read\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1
            number = GetMemoryAddress(t->left);
            fprintf(intermediate, "PUSH R%d\n", number); //Argument 1
            freeReg();
            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case N_WRITE:
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Write\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-2\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = codeGen(t->left);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();
            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case N_IF:
            l1=getlabel();
            r1=codeGen(t->left);
            fprintf(intermediate,"JZ R%d,L%d\n",r1,l1);
            number=codeGen(t->right);
            fprintf(intermediate,"L%d:\n",l1);
            freeReg();
            break;
        case N_IF_ELSE:
            l1=getlabel();
            l2=getlabel();
            r1=codeGen(t->left);
            fprintf(intermediate,"JZ R%d,L%d\n",r1,l1);
            number=codeGen(t->mid);
            fprintf(intermediate,"JMP L%d\n",l2);
            fprintf(intermediate,"L%d:\n",l1);
            number=codeGen(t->right);
            fprintf(intermediate,"JMP L%d\n",l2);
            fprintf(intermediate,"L%d:\n",l2);
            freeReg();
            break;
        case N_WHILE:
            l1=getlabel();
            l2=getlabel();
            prevWhileStart=WhileStart;prevWhileEnd=WhileEnd;
            WhileStart=l1;
            WhileEnd=l2;
            fprintf(intermediate,"L%d:\n",l1);
            r1=codeGen(t->left);
            fprintf(intermediate,"JZ R%d,L%d\n",r1,l2);
            r2=codeGen(t->right);
            fprintf(intermediate,"JMP L%d\n",l1);
            fprintf(intermediate,"L%d:\n",l2);
            freeReg();
            freeReg();
            WhileEnd=prevWhileEnd;
            WhileStart=prevWhileStart;
            break;
        case N_DOWHILE:
            l1=getlabel();
            l2=getlabel();
            l3=getlabel();
            prevWhileStart=WhileStart;prevWhileEnd=WhileEnd;
            WhileStart=l1;
            WhileEnd=l3;
            fprintf(intermediate,"JMP L%d\n",l1);
            fprintf(intermediate,"L%d:\n",l1);
            r1=codeGen(t->left);
            // fprintf(intermediate,"JZ R%d,L%d\n",r1,l2);
            fprintf(intermediate,"L%d:\n",l2);
            r2=codeGen(t->right);
            fprintf(intermediate,"JZ R%d,L%d\n",r2,l3);
            fprintf(intermediate,"JMP L%d\n",l1);
            fprintf(intermediate,"L%d:\n",l3);
            freeReg();
            freeReg();
            WhileEnd=prevWhileEnd;
            WhileStart=prevWhileStart;
            break;

        case N_BREAK:
            if (WhileEnd!=-1){
                fprintf(intermediate,"JMP L%d\n",WhileEnd);
            }
            break;
        case N_CONT:
            if (WhileStart!=-1){
                fprintf(intermediate,"JMP L%d\n",WhileStart);
            }
            break;
        case N_FUNC:
             for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;


            //push arguments
            pushArguments(t->left);


            fprintf(intermediate,"PUSH R0\n");
            fprintf(intermediate,"CALL F%d\n",t->Gentry->flabel);

            r1=getReg();
            fprintf(intermediate,"POP R%d\n",r1);

            //popArguments
            popArguments(t->left);





            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;

            break;
        case N_RET:
            r1=getReg();
            r2=codeGen(t->left);
            fprintf(intermediate,"MOV R%d,BP\n",r1);
            fprintf(intermediate,"ADD R%d,-2\n",r1);
            fprintf(intermediate,"MOV [R%d],R%d\n",r1,r2);
            freeReg();
            freeReg();
            Ltemp=Lhead;
            while(Ltemp!=NULL){
                if (Ltemp->binding>0)
                    fprintf(intermediate,"POP R0\n");
                Ltemp=Ltemp->next;
            }
            fprintf(intermediate,"POP BP\n");
            fprintf(intermediate,"RET\n");
            break;
        default:
            break;
    }
    
    
}

void initialise() {
    intermediate = fopen("machinecode.xsm", "w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "MOV SP, %d\n", bind-1);
    fprintf(intermediate, "PUSH R0\n");
    fprintf(intermediate, "CALL MAIN\n");
    fprintf(intermediate, "MOV R0, 10\nPUSH R0\nINT 10\n");
}
void finalise(){
    fprintf(intermediate,"INT 10");
    fclose(intermediate);
}