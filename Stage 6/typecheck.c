
void checkAssign(struct tnode* node){
    
}


void assignType(struct tnode* node,int type){
    //type 1 = ufnction

    //type 0 = global or local varia  ble
    Ltemp=LLookup(node->varname);
    if (Ltemp!=NULL && type==0){
        node->Lentry=Ltemp;
        node->type=Ltemp->type;
    }else{
        Gtemp=GLookup(node->varname);
        if (Gtemp!=NULL){
            node->Gentry=Gtemp;
            node->type=Gtemp->type;
            if (type==1 && Gtemp->size!=-1){
                printf("This is supposed to be function not variable ( %s )",node->varname);exit(1);
            }
        }else{
            if (type==1){
                printf("Function not defined ( %s )",node->varname);exit(1);
            }
            else{
                printf("variable not defined ( %s )",node->varname);exit(1);
            }

        }
    }
    return;
}

void assignTypeField(struct tnode *node,struct FieldList* fields){
    struct FieldList* temp=Flookup(node->varname,fields);
    if (temp==NULL){
        printf("yyerror field does not exist %s",node->varname);exit(0);
    }
    node->type=temp->type;
    return;

}

void typecheck(struct TypeTable* t1, struct TypeTable* t2, char c) {
    printf("%s  %s \n",t1->name,t2->name);
    switch(c) {
        case 'w': if(t1 != t2) {
                      printf("yyerror Expected Boolean in WHILE check\n");
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      printf("yyerror Expected Boolean in IF ELSE check\n");
                      exit(1);
                  }
                  break;
        case 'i': if(t1 != t2) {
                      printf("yyerror Expected Boolean in IF check\n");
                      exit(1);
                  }
                  break;
        case 'a': if(t1 == Tlookup("string") || t2 == Tlookup("string")) {
                      printf("yyerror Invalid type for arithmetic operation\n");
                      exit(1);
                  }
                  break;
        case 'b': if(t1 == Tlookup("string")  || t2 == Tlookup("string")) {
                      printf("yyerror Invalid type for comparing (<, >, <=..) operation\n");
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      printf("yyerror Invalid type for assignment operation\n");
                      exit(1);
                  }
                  break;
        case '!': if (t1 == Tlookup("string") || t1 == Tlookup("integer")) {
                      printf("yyerror Integer or String cannot be compared with NULL\n");
                      exit(1);
                  }
    }
}
