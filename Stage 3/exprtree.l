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
if      {return IF;}
then {return THEN;}
else    {return ELSE;}
endif   {return ENDIF;}
while   {return WHILE;}
do  {return DO;}
break {return BREAK;}
continue {return CONTINUE;}
endwhile {return ENDWHILE;}
{var}   {yylval.no=createTree(0,inttype,N_VAR,yytext,NULL,NULL,NULL);return VAR;}
{digit}+   {yylval.no=createTree(atoi(yytext),inttype,N_NUM,NULL,NULL,NULL,NULL);return NUM;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"=" {return ASSIGN;}
">" {return GT;}
"<" {return LT;}
"<=" {return LE;}
">="    {return GE;}
"=="    {return EQ;}
"!="    {return NEQ;}
[ \t\n]	    {}
[();]       {return *yytext;}
.   {printf("invalid charater");exit(1);}
%%

int yywrap(){
    return 1;
}
 