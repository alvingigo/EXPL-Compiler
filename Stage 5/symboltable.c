struct Gsymbol* GLookup(char *name){
    struct Gsymbol* temp=Ghead;
    while(temp!=NULL){
        if (!strcmp(temp->name,name)){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}


void GInstall(char *name, int type, int size,struct ParamList* param){
    struct Gsymbol * temp=GLookup(name);
    if (temp!=NULL){
        printf("yyerror Variable reinitialised");
        exit(1);
    }else if(size<1 && param==NULL){
        printf("Invalid Variable Size");
        exit(1);
    }
    

    temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name=(char*)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type=type;
    temp->size=size;
    temp->binding=bind;
    bind+=size;
    if (param==NULL){
        temp->flabel=-1;   
        temp->param=NULL; 
    }else{
        printf("hi\n");
        temp->param=param;
        temp->flabel=flabelcount++;
    }

    
    temp->next=NULL;   
 
    
    if (Ghead==NULL){
        Ghead=temp;

    }
    if (Gtail!=NULL){
        Gtail->next=temp;
    }
    Gtail=temp;
   

}



void ParamInstall(char* name, int type){
    struct ParamList *temp=(struct ParamList*)malloc(sizeof(struct ParamList));

     temp->name=(char*)malloc(sizeof(name));

    strcpy(temp->name,name);
    temp->type=type;
    temp->next=NULL;
    if (Phead!=NULL){
        Ptail->next=temp;
    }else{
        Phead=temp;
        Ptail=temp;
    }

}

struct Lsymbol* LLookup(char* name){
    
    struct Lsymbol* temp=Lhead;
    while(temp!=NULL){
        if (!strcmp(temp->name,name)){
            break;

        }
        temp=temp->next;
    }
    return temp;
}



void LInstall(char* name, int type){
    struct Lsymbol* temp=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    temp->type=type;
    temp->next=NULL;
        temp->name=(char*)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->binding=localBindingStart++;
   if (Lhead!=NULL){
        Ltail->next=temp;
        Ltail=temp;
    }else{
        Lhead=temp;
        Ltail=temp;
    }
}


void InstallParamsInLocal(){
    struct ParamList* temp=Phead;
    int count=0;
    while (temp!=NULL){
        count++;
        temp=temp->next;
    }
    localBindingStart=-1*count-2;

    temp=Phead;

    while(temp!=NULL){
        LInstall(temp->name,temp->type);
        
        temp=temp->next;

    }
    localBindingStart=1;
    return;

}



void PrintGSymbolTable(){
    struct Gsymbol* temp=Ghead;
    while (temp!=NULL)
    {
        printf("%s %d %d\n",temp->name,temp->binding,temp->size);
        temp=temp->next;
    }
    return;
    
}