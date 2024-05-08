%{
    #include <stdlib.h>
	#include <stdio.h>
    #include "y.tab.h"
    #include "tasktree.h"
    int c=0;
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
int     {printf("intt\n");return INT;}
str     {return STR;}
main    {printf("main\n");return MAIN;}
return  {return RETURN;}
and {return AND;}
or  {return OR;}
type {return TYPE;}
endtype {return ENDTYPE;}
initialise  {return INIT;}
alloc {yylval.no=createTree(0,NULL,N_ALLOC,NULL,NULL,NULL,NULL);return ALLOC;}
free {return FREE;}
null {printf("where %d\n ",c);yylval.no=createTree(0,NULL,N_NILL,NULL,NULL,NULL,NULL);return NILL;}
"." {printf(". ");return *yytext;}
{var}   {printf("%s\n",yytext);yylval.no=createTree(0,NULL,N_VAR,yytext,NULL,NULL,NULL);return VAR;}
{digit}+   {yylval.no=createTree(atoi(yytext),NULL,N_NUM,NULL,NULL,NULL,NULL);return NUM;}
{str}       {
               
                yylval.no = createTree( 0,NULL,N_STRVAL, yytext, NULL, NULL, NULL);
                return STRVAL;
            }
"=="[ ]*"null" 	{
                    yylval.no = createTree(0,NULL, N_NILL, NULL, NULL, NULL, NULL);
                    return DEQNILL;
		}
"!="[ ]*"null" 	{
                    yylval.no = createTree(0,NULL, N_NILL, NULL, NULL, NULL, NULL);
                    return NEQNILL;
                }
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"%" {return MOD;}
"=" {printf("= where %d",c);return ASSIGN;}
">" {return GT;}
"<" {return LT;}
"<=" {return LE;}
">="    {return GE;}
"=="    {return EQ;}
"!="    {return NEQ;}
","     {return *yytext;}
"[" {return *yytext;}
"]" {return *yytext;}
"(" {return *yytext;}
")" {return *yytext;}
[ \t]   {}
\n	    {c++;printf("%d\n",c);}
[; {}]       {return *yytext;}
.   {printf("invalid charater %s",yytext);exit(1);}
%%

int yywrap(){
    return 1;
}
 