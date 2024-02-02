%option noyywrap

%{
    #include "y.tab.h"

%}


variable [a-zA-Z][a-zA-Z0-9]*

%%
{variable} {return CHAR;}
[0-9]   {return DIGIT;}
. {return yytext[0];}
\n {return 0;}
%%