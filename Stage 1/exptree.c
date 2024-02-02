#include <stdio.h>
#include <stdlib.h>

struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t){
    if(t->op == NULL)
    {
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}


// expr : expr PLUS expr  {$$ = makeOperatorNode('+',$1,$3);}
//   |  expr MINUS expr  {$$ = makeOperatorNode('-',$1,$3);}
//   | expr MUL expr {$$ = makeOperatorNode('*',$1,$3);}
//   | expr DIV expr {$$ = makeOperatorNode('/',$1,$3);}
//   | '(' expr ')'  {$$ = $2;}
//   | NUM   {$$ = $1;}
//   ;

void postfix(struct tnode *t){
    if(t->op == NULL)
    {
        printf("%d ",t->val);
    }
    else{
        switch(*(t->op)){
            case '+' : postfix(t->left);postfix(t->right);printf("+ ");
                       break;
            case '-' : postfix(t->left);postfix(t->right);printf("- ");
                       break;
            case '*' : postfix(t->left);postfix(t->right);printf("* ");
                       break;
            case '/' : postfix(t->left);postfix(t->right);printf("/ ");
                       break;
        }
    }
    
}

void prefix(struct tnode *t){
    if(t->op == NULL)
    {
        printf("%d ",t->val);
    }
    else{
        switch(*(t->op)){
            case '+' : printf("+ ");prefix(t->left);prefix(t->right);
                       break;
            case '-' : printf("- ");prefix(t->left);prefix(t->right);
                       break;
            case '*' : printf("* ");prefix(t->left);prefix(t->right);
                       break;
            case '/' : printf("/ ");prefix(t->left);prefix(t->right);
                       break;
        }
    }
    
}
