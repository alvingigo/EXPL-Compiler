%{
#include <stdlib.h>
#include <stdio.h>
#include "exptree.h"
#include "exptree.c"
#include "codegen.c"
 int yylex(void);
 void yyerror(char const *s);
 void print(int r);
 FILE *intermediate;
%}

%union{
 struct tnode *no;

}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END {
    $$ = $2;
    int r=codeGen($1);
    printf("%d\n",evaluate($1));
    print(r);
    postfix($1);
    printf("\n");
    prefix($1);
    
    exit(1);
   }
  ;

expr : PLUS expr expr  {$$ = makeOperatorNode('+',$2,$3);}
  | MINUS expr expr  {$$ = makeOperatorNode('-',$2,$3);}
  | MUL expr expr {$$ = makeOperatorNode('*',$2,$3);}
  | DIV expr expr {$$ = makeOperatorNode('/',$2,$3);}
  | '(' expr ')'  {$$ = $2;}
  | NUM   {$$ = $1;}
  ;

%%

 void yyerror(char const *s)
{
    printf("yyerror %s",s);
}
void print(int r) {
    fprintf(intermediate, "MOV R2, \"Write\"\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "MOV R2, -1\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R%d\n", r);
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "CALL 0\n");
    fprintf(intermediate, "POP R0\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "POP R1\n");
    fprintf(intermediate, "MOV R2, \"Exit\"\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "PUSH R2\n");
    fprintf(intermediate, "CALL 0");
}

int main(void) {
    intermediate=fopen("inter.xsm","w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    yyparse();
    return 0;
}