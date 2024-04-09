
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

void typecheck(int t1, int t2, char c) {
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
        case 'a': if(t1 == strtype || t2 == strtype) {
                      printf("yyerror Invalid type for arithmetic operation\n");
                      exit(1);
                  }
                  break;
        case 'b': if(t1 == strtype  || t2 == strtype) {
                      printf("yyerror Invalid type for comparing (<, >, <=..) operation\n");
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      printf("yyerror Invalid type for assignment operation\n");
                      exit(1);
                  }
                  break;
    }
}
