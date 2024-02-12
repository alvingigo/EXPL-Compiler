%{
    #include <stdlib.h>
	#include <stdio.h>
    #include "y.tab.h"
    #include "tasktree.h"
%}

var [a-z]
digit [0-9]


%%
begin   {return START;}
end     {return END;}
read   {return READ;}
write   {return WRITE;}
{var}   {yylval.no=createTree(0,1,N_VAR,yytext,NULL,NULL);return VAR;}
{digit}+   {yylval.no=createTree(atoi(yytext),0,N_NUM,NULL,NULL,NULL);return NUM;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"=" {return ASSIGN;}
[ \t\n]	    {}
[();]       {return *yytext;}
.   {printf("invalid charater");exit(1);}
%%

int yywrap(){
    return 0;
}
 