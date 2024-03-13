#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode* createTree(int val,int type,int nodetype, char* c,struct tnode* l,struct tnode * r,struct tnode* m){
    struct tnode * temp=(struct tnode*)malloc(sizeof(tnode));
    temp->val=val;
    temp->type=type;
    temp->left=l;
    temp->right=r;
    temp->mid=m;
    if (c!=NULL){
        temp->varname=(char*)malloc(sizeof(c));
        strcpy(temp->varname,c);
    }
    temp->nodetype=nodetype;
    return temp;
}