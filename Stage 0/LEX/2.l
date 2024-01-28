
%{
    #include <stdio.h>
    #include <ctype.h>
    #include <stdlib.h>
    
    
%}




%%

[/][*](.|\n)*[*][/]   {printf("Multi line comment : %s",yytext);}   
[/][/].* {printf("Single line comment : %s",yytext);}
[A][a-zA-Z][a-zA-Z][" "]  {
            for (int i = 0; i < 3; ++i) {
                yytext[i] = toupper(yytext[i]); 
            
            }
            printf("%s ", yytext);
            
        }
     



. {}        
%%
int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}