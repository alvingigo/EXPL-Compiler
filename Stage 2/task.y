%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tasktree.h"
    #include "tasktree.c"
    #include "codegen.c"
    #include "evaluvate.c"
    int yylex(void);
    int yyerror(char* s);
    extern FILE *yyin;
    FILE *fp;
    FILE *intermediate;
%}

%union{
    struct tnode* no;
}
%token PLUS MINUS MUL DIV START END READ WRITE VAR NUM ASSIGN

%type <no> VAR NUM expr Stmt Slist program START END READ WRITE InputStmt OutputStmt AsgStmt
%left PLUS MINUS
%left MUL DIV

%%
program :START Slist END ';' {$$=$2;
                                evaluvate($2);
                                initalise();
                                codeGen($2);
                                finalise();
                                exit(0);
                                }
    |START END ';'  {$$=$2;exit(0);}
;
Slist : Slist Stmt {$$=createTree(0,1,N_CONNECTOR,NULL,$1,$2);}
    |Stmt   {$$=$1;}
    ;

Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    ;

InputStmt: READ '(' VAR ')' ';'{$$=createTree(0,1,N_READ,NULL,$3,NULL);}
        ;
OutputStmt: WRITE '(' expr ')' ';' {$$=createTree(0,1,N_WRITE,NULL,$3,NULL);}
        ;
AsgStmt: VAR ASSIGN expr  ';'{$$=createTree(0,1,N_ASSIGN,NULL,$1,$3);}
        ;
    

expr : expr PLUS expr   {$$=createTree(0,1,N_ADD,NULL,$1,$3);}
    |expr MINUS expr    {$$=createTree(0,1,N_SUB,NULL,$1,$3);}
    |expr MUL expr  {$$=createTree(0,1,N_MUL,NULL,$1,$3);}
    |expr DIV expr {$$=createTree(0,1,N_DIV,NULL,$1,$3);}
    |'(' expr ')'{$$=$2;}
    |NUM {$$=$1;}
    |VAR    {$$=$1;}
    ;
%%
int yyerror(char * s){
    printf("%s\n",s);
    return 0;
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
           
            yyin = fp;
        }
       
    }
    yyparse();
    return 0;
}