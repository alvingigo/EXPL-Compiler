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

struct TypeTable* Tlookup(char* name){
    struct TypeTable* temp=Thead;
    while(temp!=NULL){
        if (!strcmp(temp->name,name)){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

struct FieldList* Flookup(char* name,struct FieldList* temp){
   
    while(temp!=NULL){
        if (strcmp(temp->name,name)==0){
            break;
        }
        temp=temp->next;
    }
    return temp;
}

void TInstall(char* name,int size,struct FieldList* fields){
    
    struct TypeTable* temp=Tlookup(name);
    if (temp!=NULL){
        printf("yyerror Type Reinitialized");
        exit(1);
    }
    temp=malloc(sizeof(struct TypeTable));
    temp->name=(char*)malloc(sizeof(name));
    strcpy(temp->name,name);
    
    temp->size=size;
    if(Thead==NULL){
        Thead=temp;
        
    }else{
        Ttail->next=temp;    
    }

    Ttail=temp;
    
    temp->next=NULL;
    int c=0;
    ftemp=fields;
    while(ftemp!=NULL){
        ftemp->fieldIndex=c++;
        if (!strcmp(ftemp->type->name,"dummy")){
            ftemp->type=temp;
        }
        ftemp=ftemp->next;
    }
    temp->fields=fields;
    temp->size=c;

    Fhead=NULL;
    Ftail=NULL;
    return;
}


void FInstall(char* name,struct TypeTable* type){
    struct FieldList* temp=malloc(sizeof(struct FieldList));
    temp->name=(char*)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type=type;

    if (Fhead==NULL){
        Fhead=temp;
    }else{
        Ftail->next=temp;
    }
    Ftail=temp;
    
    temp->next=NULL;

    
}

void GInstall(char *name, struct TypeTable* type, int size,struct ParamList* param){
    struct Gsymbol * temp=GLookup(name);
    if (temp!=NULL){
        printf("yyerror Variable reinitialised");
        exit(1);
    }

    temp=(struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name=(char*)malloc(sizeof(name));
    strcpy(temp->name,name);
    temp->type=type;
    temp->size=size;
    temp->binding=bind;
    if (size!=-1)
        bind+=size;
        
    if (param==NULL){
        temp->flabel=-1;   
        temp->param=NULL; 
    }else{
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



void ParamInstall(char* name, struct TypeTable* type){
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



void LInstall(char* name, struct TypeTable* type){
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