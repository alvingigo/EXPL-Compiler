%option noyywrap
%{
    #include <stdio.h>

    #include <stdlib.h>

    int cline=0;
    int cword=0;
    int cchar=0;
    int cint=0,cfloat=0;

%}
/*define*/

cara [a-zA-Z0-9]*
number [0-9]
float [0-9]+[.][0-9]+    

/*rules*/
%%
{number}+  {cint++;cchar+=yyleng;cword++;}
{float}     {cfloat++;cchar+=yyleng;cword++;}
{cara}  {cword++; cchar += yyleng; }
[ \t] {cchar++;}




\n    {cline++; }
%%

int main(){
    yylex();
    printf("CharCount = %d\n",cchar);
    printf("WordCount = %d\n",cword);
    printf("LineCount = %d\n",cline);
    printf("intCount = %d\n",cint);
    printf("floatCount = %d\n",cfloat);

    return 1;
}