%{
    #include <stdlib.h>
	#include <stdio.h>
    #include "y.tab.h"
    #include "tasktree.h"
    int c;
%}

var [A-Za-z]+[0-9]*
digit [0-9]
str \"(\\.|[^\\\"])*\"

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
decl   {return DECL;}
enddecl {return ENDDECL;}
int     {return INT;}
str     {return STR;}
{var}   {yylval.no=createTree(0,inttype,N_VAR,yytext,NULL,NULL,NULL);return VAR;}
{digit}+   {yylval.no=createTree(atoi(yytext),inttype,N_NUM,NULL,NULL,NULL,NULL);return NUM;}
{str}       {
               
                yylval.no = createTree( 0,strtype,N_STRVAL, yytext, NULL, NULL, NULL);
                return STRVAL;
            }
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
","     {return *yytext;}
"[" {return *yytext;}
"]" {return *yytext;}
[ \t]   {}
\n	    {++c;printf("%d\n",c);}
[();]       {return *yytext;}
.   {printf("invalid charater");exit(1);}
%%

int yywrap(){
    return 1;
}
 