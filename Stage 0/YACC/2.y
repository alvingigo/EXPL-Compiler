%{
    #include <stdlib.h>
    #include <stdio.h>
    int yylex(void);
    int yyerror();
   // int valid=1;

%}

%token DIGIT CHAR

%%
start : CHAR s
s : CHAR s
    |DIGIT s
    |
    ;

%%

int yyerror(){
    printf("It is not an Identifier \n");
    //valid=0;
    return 1;
}

int main() {
    printf("\nEnter:");
    yyparse();
    if(!yyerror()) {
        printf("\nIt is a identifier!\n");
    }
}