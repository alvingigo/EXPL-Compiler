%{
    #include <stdlib.h>
	#include <stdio.h>
    #include "labeltrans.c"
    int lineno=2048;
    int pass=0;
    int jmp,temp,Lno,Fno;
    FILE* intermediate;
%}


%%


[L][0-9]+[:][\n] {if (!pass){
                Lno=atoi(yytext+1);
                Lappend(Lno,lineno);
            }
            }
[F][0-9]+[:][\n] {if (!pass){
                Fno=atoi(yytext+1);
                Fappend(Fno,lineno);
            }
            }

MAIN[:][\n]   {if(!pass){
                Fno=-1;
                Fappend(Fno,lineno);
            }
            }

[L][0-9]+   {if(pass){
                Lno=atoi(yytext+1);
                temp=Llookup(Lno);
                jmp=2056+(temp-2056)*2;
                fprintf(intermediate,"%d",jmp);
            }
            }
[F][0-9]+   {
                if(pass){
                    Fno=atoi(yytext+1);
                    temp=Flookup(Fno);
                    jmp=2056+(temp-2056)*2;
                    fprintf(intermediate,"%d",jmp);
                }
                }

MAIN {        if (pass){
                temp=Flookup(-1);
                jmp=2056+(temp-2056)*2;
                fprintf(intermediate,"%d",jmp);
            }
}
         
\n {lineno++;
    if (pass){
        fprintf(intermediate,"\n");
    }
    }
.   {if (pass){
        fprintf(intermediate,"%s",yytext);
    }}

%%


int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("machinecode.xsm", "r");
    intermediate = fopen("inter.xsm", "w");
    yyin = file;
    yylex();
    pass = 1;
    file = fopen("machinecode.xsm", "r");
    yyin = file;
    yylex();
    return 0;
}
