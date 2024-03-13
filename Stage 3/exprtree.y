%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tasktree.h"
    #include "tasktree.c"
    #include "codegen.c"
    #include "evaluvate.c"
   
    int yylex(void);
     void yyerror(char const *s);
     void typecheck(int t1,int t2,char c);
    extern FILE *yyin;
    int decount=0;
    FILE *fp;
    FILE *intermediate;
%}

%union{
    struct tnode* no;
}
%token PLUS MINUS MUL DIV START END READ WRITE VAR NUM ASSIGN IF ELSE WHILE THEN ENDIF ENDWHILE DO LT GT LE GE EQ NEQ BREAK CONTINUE

%type <no> VAR NUM expr Stmt Slist program START END READ WRITE InputStmt OutputStmt AsgStmt 
%type <no> Ifstmt Whilestmt Breakstmt Contstmt IF ELSE THEN ENDIF WHILE DO ENDWHILE BREAK CONTINUE
%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT LE GE
%right EQ NEQ

%%
program :START Slist END ';' {$$=$2;
                                //evaluvate($2);
                                initalise();
                                codeGen($2);
                                finalise();
                                exit(0);
                                }
    |START END ';'  {$$=$2;exit(0);}
;

Slist : Slist Stmt {$$=createTree(0,1,N_CONNECTOR,NULL,$1,$2,NULL);}
    |Stmt   {$$=$1;}
    ;

Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    | Ifstmt             {$$=$1;}
    | Whilestmt          {$$=$1;}
    | Breakstmt          {$$=$1;}
    | Contstmt          {$$=$1;}
    ;
InputStmt: READ '(' VAR ')' ';'{$$=createTree(0,voidtype,N_READ,NULL,$3,NULL,NULL);}
        ;
OutputStmt: WRITE '(' expr ')' ';' {$$=createTree(0,voidtype,N_WRITE,NULL,$3,NULL,NULL);}
        ;
AsgStmt: VAR ASSIGN expr  ';'{  typecheck($1->type,$3->type,'=');
                                
                                $$=createTree(0,voidtype,N_ASSIGN,NULL,$1,$3,NULL);}
        ;
Ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  { typecheck($3->type,booltype,'e');
                                                            $$=createTree(0,voidtype,N_IF_ELSE,NULL,$3,$8,$6);}
        | IF '(' expr ')' THEN Slist ENDIF ';'    { typecheck($3->type,booltype,'i');
                                                $$=createTree(0,voidtype,N_IF,NULL,$3,$6,NULL);}
        ;
Whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE ';' { typecheck($3->type,booltype,'w');
                                                        $$=createTree(0,voidtype,N_WHILE,NULL,$3,$6,NULL);}
        |DO Slist WHILE '(' expr ')' ENDWHILE ';'   { typecheck($5->type,booltype,'w');
                                                        $$=createTree(0,voidtype,N_DOWHILE,NULL,$2,$5,NULL);}
        ;
Breakstmt: BREAK ';'    {$$=createTree(0,voidtype,N_BREAK,NULL,NULL,NULL,NULL);}
        ;
Contstmt: CONTINUE ';'  {$$=createTree(0,voidtype,N_CONT,NULL,NULL,NULL,NULL);}
        ;

    

expr : expr PLUS expr   { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,inttype,N_ADD,NULL,$1,$3,NULL);}
    |expr MINUS expr    { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,inttype,N_SUB,NULL,$1,$3,NULL);}
    |expr MUL expr  { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,inttype,N_MUL,NULL,$1,$3,NULL);}
    |expr DIV expr { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,inttype,N_DIV,NULL,$1,$3,NULL);}
    |expr LT expr { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,booltype,N_LT,NULL,$1,$3,NULL);}
    |expr GT expr { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,booltype,N_GT,NULL,$1,$3,NULL);}
    |expr EQ expr   { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,booltype,N_EQ,NULL,$1,$3,NULL);}
    |expr NEQ expr  { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,booltype,N_NEQ,NULL,$1,$3,NULL);}
    |expr GE expr   { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,booltype,N_GE,NULL,$1,$3,NULL);}
    |expr LE expr   { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,booltype,N_LE,NULL,$1,$3,NULL);}
    |'(' expr ')'{$$=$2;}
    |NUM {$$=$1;}
    |VAR    {$$=$1;}
    ;
%%

void yyerror(char const *s){
    printf("yyerror %s",s);
    return;
}

void typecheck(int t1, int t2, char c) {
    switch(c) {
        case 'w': if(t1 != t2) {
                      yyerror("Expected Boolean in WHILE check\n");
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      yyerror("Expected Boolean in IF ELSE check\n");
                      exit(1);
                  }
                  break;
        case 'i': if(t1 != t2) {
                      yyerror("Expected Boolean in IF check\n");
                      exit(1);
                  }
                  break;
        case 'a': if(t1 != inttype || t2 != inttype) {
                      yyerror("Invalid type for arithmetic operation\n");
                      exit(1);
                  }
                  break;
        case 'b': if(t1 != inttype  || t2 != inttype) {
                      yyerror("Invalid type for comparing (<, >, <=..) operation\n");
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      yyerror("Invalid type for assignment operation\n");
                      exit(1);
                  }
                  break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an input filename\n");
        exit(1);
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            printf("Invalid input file specified\n");
            exit(1);
        } else {
            printf("%d",++decount);
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}