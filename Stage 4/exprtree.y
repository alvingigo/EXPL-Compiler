%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "symboltable.h"
    #include "symboltable.c"
    #include "tasktree.h"
    #include "tasktree.c"
    #include "codegen.c"
    #include "evaluvate.c"

    int c=0;
    int yylex(void);
     void yyerror(char const *s);
     void typecheck(int t1,int t2,char c);
    extern FILE *yyin;
    FILE *fp;
    FILE *intermediate;
    int declarationtype;
%}

%union{
    struct tnode* no;
    
}
%token PLUS MINUS MUL DIV START END READ WRITE VAR STRVAL NUM ASSIGN
%token IF ELSE WHILE THEN ENDIF ENDWHILE DO BREAK CONTINUE
%token LT GT LE GE EQ NEQ
%token DECL ENDDECL INT STR

%type <no> VAR NUM START END READ WRITE STRVAL DECL ENDDECL INT STR
%type <no> expr Stmt Slist program InputStmt OutputStmt AsgStmt
%type <no> IF ELSE THEN ENDIF WHILE DO ENDWHILE BREAK CONTINUE
%type <no> Ifstmt Whilestmt Breakstmt Contstmt id
%type <no> DeclareStmt DeclList Decl Type VarList 
%left PLUS MINUS
%left MUL DIV ']' '['
%nonassoc LT GT LE GE
%right EQ NEQ ASSIGN ',' 
%%
program :DeclareStmt START Slist END ';' {$$=$3;
                                //evaluvate($2);
                                PrintSymbolTable();
                                initalise();
                                codeGen($3);
                                finalise();
                                exit(0);
                                }
    |DeclareStmt START END ';'  {$$=$3;exit(0);}
;

DeclareStmt: DECL DeclList ENDDECL ';' {}
        | DECL ENDDECL ';'{}
        ;

DeclList: DeclList Decl {}
        | Decl {}
        ;
Decl: Type VarList ';' {}
        ;
Type: INT {declarationtype=INT_TYPE;}
    | STR {declarationtype=STR_TYPE;}
    ;
VarList: VarList ',' VarList  {}
        |VAR '[' NUM ']' {GInstall($1->varname,declarationtype,$3->val,1);}
        | VAR {GInstall($1->varname,declarationtype,1,0);}
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





InputStmt: READ '(' id ')' ';'{$$=createTree(0,voidtype,N_READ,NULL,$3,NULL,NULL);}
        ;
OutputStmt: WRITE '(' expr ')' ';' {$$=createTree(0,voidtype,N_WRITE,NULL,$3,NULL,NULL);}
        ;
AsgStmt: id ASSIGN expr  ';'{  typecheck($1->type,$3->type,'=');
                                
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
                           // printf("%d",++c);
                           printf("plus\n");
                            $$=createTree(0,inttype,N_ADD,NULL,$1,$3,NULL);}
    |expr MINUS expr    { 
                            printf("minus\n");
                            typecheck($1->type,$3->type,'a');
                            //printf("%d",++c);
                            $$=createTree(0,inttype,N_SUB,NULL,$1,$3,NULL);}
    |expr MUL expr  { typecheck($1->type,$3->type,'a');
                            printf("mul\n");//printf("%d",++c);
                            $$=createTree(0,inttype,N_MUL,NULL,$1,$3,NULL);}
    |expr DIV expr { typecheck($1->type,$3->type,'a');
                            //printf("%d",++c);
                            printf("div\n");
                            $$=createTree(0,inttype,N_DIV,NULL,$1,$3,NULL);}
    |expr LT expr { typecheck($1->type,$3->type,'b');
                            printf("lt\n");
                            $$=createTree(0,booltype,N_LT,NULL,$1,$3,NULL);}
    |expr GT expr { typecheck($1->type,$3->type,'b');
                            printf("gt\n");
                            $$=createTree(0,booltype,N_GT,NULL,$1,$3,NULL);}
    |expr EQ expr   { typecheck($1->type,$3->type,'b');
                            printf("eq\n");
                            $$=createTree(0,booltype,N_EQ,NULL,$1,$3,NULL);}
    |expr NEQ expr  { typecheck($1->type,$3->type,'b');
                            printf("neq\n");$$=createTree(0,booltype,N_NEQ,NULL,$1,$3,NULL);}
    |expr GE expr   { typecheck($1->type,$3->type,'b');
                            printf("ge\n");
                            $$=createTree(0,booltype,N_GE,NULL,$1,$3,NULL);}
    |expr LE expr   { typecheck($1->type,$3->type,'b');
                            printf("le\n");
                            $$=createTree(0,booltype,N_LE,NULL,$1,$3,NULL);}
    |'(' expr ')'{$$=$2;}
    |NUM {$$=$1;}
    |id {$$=$1;}
    |STRVAL {$$=$1;}
    ;

id  : VAR    {   $1->Gentry=GLookup($1->varname);
                if($1->Gentry==NULL){
                    printf("yyerror Variable Name Not Declared (%s) pls get help\n",$1->varname);exit(1);
                }else if($1->Gentry->isarr==1){
                    printf("yyerror (%s) is an array pls call it accordingly\n",$1->varname);exit(1);
                }
                $1->type=$1->Gentry->type;
                $$=$1;
    }
    |VAR '[' expr ']'  {$1->Gentry=GLookup($1->varname);
                if($1->Gentry==NULL){
                    printf("yyerror Variable Name Not Declared (%s) pls get help\n",$1->varname);exit(1);
                }else if($1->Gentry->size <=$3->val || $3->val < 0){
                    printf("yyerror Out of Range array (%s) pls kys",$1->varname);exit(1);
                }
                $1->type=$1->Gentry->type;
                $$=createTree(0,$1->type,N_ARRAY,$1->varname,$1,$3,NULL);
    }
    |VAR '[' id ']'  {$1->Gentry=GLookup($1->varname);
                if($1->Gentry==NULL){
                    printf("yyerror Variable Name Not Declared (%s) pls get help\n",$1->varname);exit(1);
                }
                $1->type=$1->Gentry->type;
                if($3->type!=INT_TYPE){
                    printf("yyerror Tyize of (%s) should be an integer (%s) Type Mismatch Wat dis bro\n",$1->varname,$3->varname);exit(1);
                }else if($1->Gentry->isarr==0){
                    printf("yyerror (%s) is an not array pls call it accordingly\n",$1->varname);exit(1);
                }else if($1->Gentry->size <=$3->val || $3->val < 0){
                    printf("yyerror Out of Range array (%s) pls kys",$1->varname);exit(1);
                }
                $$=createTree(0,$1->type,N_ARRAY,$1->varname,$1,$3,NULL);

    }
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
        case 'a': if(t1 != inttype || t2 != inttype ) {
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
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}