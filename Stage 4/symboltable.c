
void GInstall(char *name, int type, int size,int isarr){
    struct Gsymbol * temp=GLookup(name);
    if (temp!=NULL){
        printf("yyerror Variable reinitialised");
        exit(1);
    }else if(size<1){
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
    temp->next=NULL;   
    if (isarr==1){
        temp->isarr=1;
    }else{
        temp->isarr=0;
    }
    
    if (Ghead==NULL){
        Ghead=temp;

    }
    if (Gtail!=NULL){
        Gtail->next=temp;
    }
    Gtail=temp;
   
    return;
}


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


void PrintSymbolTable(){
    struct Gsymbol* temp=Ghead;
    while (temp!=NULL)
    {
        printf("%s %d %d\n",temp->name,temp->binding,temp->size);
        temp=temp->next;
    }
    return;
    
}