%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "tasktree.h"
   #include "symboltable.h"  
    #include "symboltable.c"
    #include "typecheck.h"
    #include "tasktree.c"
    #include "codegen.c"
    #include "evaluvate.c"
    #include "typecheck.c"
    int yydebug=0;
    int yylex(void);
    int g=0;
    void yyerror(char const *s);
    extern FILE *yyin;
    FILE *fp;
    FILE *intermediate;
    struct tnode* tempNode;
    struct ParamList* argList1=NULL,*argList2=NULL;
%}

%union{
    struct tnode* no;
    
}
%token PLUS MINUS MUL DIV START END READ WRITE VAR STRVAL NUM ASSIGN MOD
%token IF ELSE WHILE THEN ENDIF ENDWHILE DO BREAK CONTINUE
%token LT GT LE GE EQ NEQ AND OR 
%token DECL ENDDECL INT STR NILL
%token RETURN MAIN 
%token TYPE ENDTYPE
%token ALLOC FREE INIT
%token NEQNILL DEQNILL

%type <no> VAR NUM START END READ WRITE STRVAL DECL ENDDECL INT STR MAIN RETURN
%type <no> expr Stmt Slist Program InputStmt OutputStmt AsgStmt
%type <no> IF ELSE THEN ENDIF WHILE DO ENDWHILE BREAK CONTINUE ALLOC NEQNILL DEQNILL NILL
%type <no> Ifstmt Whilestmt Breakstmt Contstmt 
%type <no> GDeclBlock GDeclList GDecl Type id GId GIdList
%type <no> FdefBlock Fdef FType ParamList IdList
%type <no> LdeclBlock LdeclList Ldecl 
%type <no> Body RetStmt func ArgList
%type <no> MainBlock
%type <no> TypeDefBlock TypeDefList TypeDef TypeName UserDefType  
%type <no> FieldDecl FieldListDecl Field
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT GT LE GE AND OR
%right EQ NEQ ','

%%

//  Grammar

Program :TypeDefBlock GDeclBlock FdefBlock MainBlock {finalise();}
;


TypeDefBlock : TYPE TypeDefList ENDTYPE
            |TYPE ENDTYPE
            ;
        
TypeDefList : TypeDefList TypeDef
            | TypeDef
            ;

TypeDef : UserDefType '{' FieldListDecl '}' {TInstall($1->varname,1,Fhead);}
        ;
    
UserDefType : VAR   {tempNode=$1;
                    $$=$1;}

FieldListDecl : FieldListDecl FieldDecl
            | FieldDecl
            ;

FieldDecl : TypeName VAR ';'   {FInstall($2->varname,declarationtype);}
            ;


TypeName : INT  {declarationtype=Tlookup("integer");}
        | STR   {declarationtype=Tlookup("string");}
        | VAR   {declarationtype=Tlookup($1->varname);
                    if (declarationtype==NULL){

                        if(!strcmp(tempNode->varname,$1->varname)){
                            declarationtype=Tlookup("dummy");
                        }else{
                            yyerror("Undefined user type\n");
                        }
                    }
                }
        ;


// Global Declarations

GDeclBlock: DECL GDeclList ENDDECL  {initialise();}
        | DECL ENDDECL {initialise();}
        |                                ;

GDeclList: GDeclList GDecl {}
        | GDecl {}
        ;
        
GDecl: Type GIdList ';' {}
        ;

Type: INT {declarationtype=Tlookup("integer");}
    | STR {declarationtype=Tlookup("string");}
    | VAR {declarationtype=Tlookup($1->varname);
            if (declarationtype==NULL){
                yyerror("Undefined user type\n");
            }
          }
    ;
FType: INT   {Fdeclarationtype = Tlookup("integer");}
     | STR   {Fdeclarationtype = Tlookup("string");}
     | VAR {Fdeclarationtype=Tlookup($1->varname);
            if (Fdeclarationtype==NULL){
                yyerror("Type Not Defined");
            }
          }     
    ;

GIdList: GIdList ',' GId
       | GId
       ;

GId:  VAR '[' NUM ']' {GInstall($1->varname,declarationtype,$3->val,NULL);}
    | VAR {GInstall($1->varname,declarationtype,1,NULL);}
    | VAR '(' ParamList ')' {GInstall($1->varname,declarationtype,-1,Phead);
                                    Phead=NULL;
                                    Ptail=NULL;
                                }
    ;

// Function Declarations

FdefBlock : FdefBlock Fdef 
        | Fdef  
        |
        ;
    
Fdef :  Type VAR '(' ParamList ')' '{' LdeclBlock Body '}'  {Gtemp=GLookup($2->varname);
                                                            
                                                             
                                                                if(Gtemp==NULL){
                                                                    printf("Please properly declare your functions ( %s )",$2->varname);
                                                                    exit(1);
                                                                }  
                                                                else if((Gtemp->flabel)<0){
                                                                    printf("when defining function make sure you declare it as a function ( %s )",$2->varname);exit(1);
                                                                }else if (Gtemp->type!=declarationtype){
                                                                    printf("Type Mismatch (%s)",$2->varname);exit(1);
                                                                }
                                                                
                                                            argList1=Gtemp->param;
                                                            argList2=Phead;

                                                            while(argList1!=NULL || argList2!=NULL){
                                                                if (argList1==NULL){
                                                                    printf("function def arguments bad ( %s )",$2->varname);exit(1);
                                                                }
                                                                if (argList2==NULL){
                                                                    printf("function def arguments bad ( %s )",$2->varname);exit(1);
                                                                }    
                                                                if(argList1->type!=argList2->type){
                                                                    printf("function call arguments bad (type error) ( %s )",$2->varname);exit(1);
                                                                }
                                                                argList1=argList1->next;
                                                                argList2=argList2->next;
                                                            }
                                                            


                                                            fprintf(intermediate,"F%d:\n",Gtemp->flabel);
                                                            
                                                            
                                                            fprintf(intermediate,"PUSH BP\n");
                                                            fprintf(intermediate,"MOV BP,SP\n");
                                                            Ltemp=Lhead;

                                                            while(Ltemp!=NULL){
                                                                if (Ltemp->binding>0){
                                                                    fprintf(intermediate,"PUSH R0\n");
                                                                }
                                                                Ltemp=Ltemp->next;
                                                            }
                                                            

                                    
                                                            codeGen($8);
                                                            Lhead=NULL;
                                                            Ltail=NULL;
                                                            Phead=NULL;
                                                            Ptail=NULL;
                                                            }
    ;

ParamList : ParamList ',' Param
    | Param
    |
    ;

Param  : FType VAR {ParamInstall($2->varname,Fdeclarationtype);}
    ;


LdeclBlock : DECL LdeclList ENDDECL  {InstallParamsInLocal();}
    |DECL ENDDECL    {InstallParamsInLocal();}
    |                   {InstallParamsInLocal();}
    ;

LdeclList : LdeclList Ldecl
        | Ldecl

Ldecl : FType IdList ';'   {}
    ;

IdList : IdList ',' IdList
        | VAR   {LInstall($1->varname,Fdeclarationtype);}
        ;


Body : START Slist RetStmt END   {$$=createTree(0,Tlookup("void"),N_CONNECTOR,NULL,$2,$3,NULL);}
    | START RetStmt END {$$=$2;}
    ;

RetStmt : RETURN expr ';'   {   
                                if (declarationtype == $2->type){
                                    $$=createTree(0,Tlookup("void"),N_RET,NULL,$2,NULL,NULL);
                                }else{
                                    yyerror("return type mismatch (  )");
                                }
                            }
    ;

MainBlock : Type MAIN '(' ')' '{' LdeclBlock Body '}'  { if(declarationtype != Tlookup("integer")) {
                                                            yyerror("Main return type should be of integer type\n");
                                                        }
                                                        fprintf(intermediate, "MAIN:\n");
                                                        fprintf(intermediate, "PUSH BP\n");
                                                        fprintf(intermediate, "MOV BP,SP\n");

                                                        Ltemp=Lhead;
                                                        while(Ltemp!=NULL){
                                                            fprintf(intermediate,"PUSH R0\n");
                                                            Ltemp=Ltemp->next;
                                                        }
                                                        codeGen($7);
                                                        Lhead=NULL;
                                                        Ltail=NULL;
                                                    }
    ;

Field : Field '.' VAR {
                        assignTypeField($3,$1->type->fields);
                        $$=createTree(0,$3->type,N_FIELD,NULL,$1,$3,NULL);}
    | VAR '.' VAR   {
                    assignType($1,0);
                    assignTypeField($3,$1->type->fields);
                    $$=createTree(0,$3->type,N_FIELD,NULL,$1,$3,NULL); 
                    }
    ;        


Slist : Slist Stmt {$$=createTree(0,Tlookup("void"),N_CONNECTOR,NULL,$1,$2,NULL);}
    |Stmt   {$$=$1;}
    ;


Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    | Ifstmt             {$$=$1;}
    | Whilestmt          {$$=$1;}
    | Breakstmt          {$$=$1;}
    | Contstmt          {$$=$1;}
    | func ';'          {$$=$1;}
    | INIT '(' ')'';'    {$$=createTree(0,Tlookup("void"),N_INIT,NULL,NULL,NULL,NULL);}
    | FREE '(' id ')' ';' {$$=createTree(0,Tlookup("void"),N_FREE,NULL,$3,NULL,NULL);}
    | FREE '(' Field ')' ';' {$$=createTree(0,Tlookup("void"),N_FREE,NULL,$3,NULL,NULL);}
    ;



InputStmt: READ '(' id ')' ';'{$$=createTree(0,Tlookup("void"),N_READ,NULL,$3,NULL,NULL);}
        | READ '(' Field ')' ';'    {$$=createTree(0,Tlookup("void"),N_READ,NULL,$3,NULL,NULL);}
        ;
OutputStmt: WRITE '(' expr ')' ';' {$$=createTree(0,Tlookup("void"),N_WRITE,NULL,$3,NULL,NULL);}
        ;
AsgStmt:  Field ASSIGN expr  ';'{typecheck($1->type,$3->type,'=');
                                
                                $$=createTree(0,Tlookup("void"),N_ASSIGN,NULL,$1,$3,NULL);}
        | id ASSIGN ALLOC '(' ')' ';' { $$=createTree(0,Tlookup("void"),N_ASSIGN,NULL,$1,$3,NULL);}
                                    
        | Field ASSIGN ALLOC '(' ')' ';' {$$=createTree(0,Tlookup("void"),N_ASSIGN,NULL,$1,$3,NULL);
                                            }

        | id ASSIGN expr ';' {   typecheck($1->type,$3->type,'=');
                                    $$=createTree(0,Tlookup("void"),N_ASSIGN,NULL,$1,$3,NULL);}

        | Field ASSIGN NILL ';' {$$=createTree(0,Tlookup("void"),N_ASSIGN,NULL,$1,$3,NULL);}
        
        | id ASSIGN NILL ';'    {printf("hello\n");$$=createTree(0,Tlookup("void"),N_ASSIGN,NULL,$1,$3,NULL);}
        ;
Ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  { typecheck($3->type,Tlookup("boolean"),'e');
                                                            $$=createTree(0,Tlookup("void"),N_IF_ELSE,NULL,$3,$8,$6);}
        | IF '(' expr ')' THEN Slist ENDIF ';'    { typecheck($3->type,Tlookup("boolean"),'i');
                                                $$=createTree(0,Tlookup("void"),N_IF,NULL,$3,$6,NULL);}
        ;
Whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE ';' { typecheck($3->type,Tlookup("boolean"),'w');
                                                        $$=createTree(0,Tlookup("void"),N_WHILE,NULL,$3,$6,NULL);}
        |DO Slist WHILE '(' expr ')' ENDWHILE ';'   { typecheck($5->type,Tlookup("boolean"),'w');
                                                        $$=createTree(0,Tlookup("void"),N_DOWHILE,NULL,$2,$5,NULL);}
        ;
Breakstmt: BREAK ';'    {$$=createTree(0,Tlookup("void"),N_BREAK,NULL,NULL,NULL,NULL);}
        ;
Contstmt: CONTINUE ';'  {$$=createTree(0,Tlookup("void"),N_CONT,NULL,NULL,NULL,NULL);}
        ;

ArgList : ArgList ',' expr  {$3->argList=$1;
                            $$=$3;  
                            }
        | expr     {$$=$1;}
        |           {$$=NULL;}
        ;


expr : expr PLUS expr   { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,Tlookup("integer"),N_ADD,NULL,$1,$3,NULL);}
    |expr MINUS expr    { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,Tlookup("integer"),N_SUB,NULL,$1,$3,NULL);}
    |expr MUL expr  { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,Tlookup("integer"),N_MUL,NULL,$1,$3,NULL);}
    |expr DIV expr { typecheck($1->type,$3->type,'a');
                            $$=createTree(0,Tlookup("integer"),N_DIV,NULL,$1,$3,NULL);}
    |expr MOD expr  {typecheck($1->type,$3->type,'a');
                            $$=createTree(0,Tlookup("integer"),N_MOD,NULL,$1,$3,NULL);}
    |expr LT expr { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_LT,NULL,$1,$3,NULL);}
    |expr GT expr { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_GT,NULL,$1,$3,NULL);}
    |expr EQ expr   { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_EQ,NULL,$1,$3,NULL);}
    |expr NEQ expr  { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_NEQ,NULL,$1,$3,NULL);}
    |expr GE expr   { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_GE,NULL,$1,$3,NULL);}
    |expr LE expr   { typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_LE,NULL,$1,$3,NULL);}
    |expr AND expr {typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_AND,NULL,$1,$3,NULL);}
    |expr OR expr   {typecheck($1->type,$3->type,'b');
                            $$=createTree(0,Tlookup("boolean"),N_AND,NULL,$1,$3,NULL);}
    | Field DEQNILL    {
                            typecheck($1->type, NULL, '!');
                            $$ = createTree(0,Tlookup("boolean"), N_EQ, NULL,$1, $2, NULL);
                        }
     | Field NEQNILL    {
                            typecheck($1->type, NULL, '!');
                            $$ = createTree(0,Tlookup("boolean"), N_NEQ, NULL,$1, $2, NULL);
                        }
     | id DEQNILL       {
                            assignType($1, 0);
                            $$ = createTree(0,Tlookup("boolean"), N_EQ, NULL,$1, $2, NULL);
                        }
     | id NEQNILL       {
                            assignType($1, 0);
                            $$ = createTree(0,Tlookup("boolean"), N_NEQ, NULL, $1, $2,NULL);
                        }
    |'(' expr ')'{$$=$2;}
    |NUM {$1->type=Tlookup("integer");
        $$=$1;}
    |id {$$=$1;}
    |func  {$$=$1;}
    |STRVAL {$1->type=Tlookup("string");
        $$=$1;}
    |Field {$$=$1;}
    ;


func : VAR '(' ArgList ')'  {   assignType($1,1);

                                $1->nodetype=N_FUNC;
                                $1->left=reverseList($3);
                                $$=$1;}
    ;




id  : VAR {  assignType($1,0);
                $$=$1;
                }
    |VAR '[' expr ']'  {assignType($1,2);
                        
                        $$=createTree(0,$1->type,N_ARRAY,$1->varname,$1,$3,NULL);
    }
    |VAR '[' id ']'  {assignType($1,2);

                    $$=createTree(0,$1->type,N_ARRAY,$1->varname,$1,$3,NULL);

    }
    ;

%%

void yyerror(char const *s){
    printf("yyerror %s",s);exit(1);
    return;
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

    TInstall("integer",1,NULL);
    TInstall("string",1,NULL);
    TInstall("boolean",1,NULL);
    TInstall("void",0,NULL);
    TInstall("dummy",0,NULL);
    yyparse();
    return 0;
}