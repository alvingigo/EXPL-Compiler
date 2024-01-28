%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex(void);
    int yyerror();
%}

%union{
    char* c;
};

%left '+' '-'
%left '*' '/'

%token VAR NL

%type <c> expr

%%
start : expr NL{exit(0);printf("%s",$<c>1);}
    ;

expr: expr '+' expr {$<c>$=$<c>2+$<c>1+$<c>3;}
    |expr '/' expr  {$<c>$=$<c>2+$<c>1+$<c>3;}
    |expr '*' expr  {$<c>$=$<c>2+$<c>1+$<c>3;}
    |expr '-' expr  {$<c>$=$<c>2+$<c>1+$<c>3;}
    |'(' expr ')'   {}
    |VAR    {$<c>$=$<c>1;}
    ;
%%


int yyerror(){
    printf("not in grammar\n");
    return 0;
}

int main(){
    yyparse();
    return 0;
}