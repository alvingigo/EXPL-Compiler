%option noyywrap
%{
   #include "y.tab.h"




%}

variable [a-zA-Z]
op [+-/*()]

%%
{variable}  {yylval.c=yytext[0];return VAR;}
{op}    {yylval.c=yytext[0];return yytext[0];}
.   {return yytext[0];}
\n  {return NL;}
%%

