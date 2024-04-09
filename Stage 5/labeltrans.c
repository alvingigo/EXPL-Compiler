struct Llist{
    int Lno;
    int lineno;
    struct Llist* next;
};
struct Llist* labels=NULL;

struct Flist{
    int Fno;
    int lineno;
    struct Flist* next;
};
struct Flist* funcs=NULL;

void Lappend(int Lno,int lineno){
    struct Llist * curr=(struct Llist *)malloc(sizeof(struct Llist));
    curr->Lno=Lno;
    curr->lineno=lineno;
    curr->next=labels;
    labels=curr;


}
void Fappend(int Fno,int lineno){
    struct Flist* curr=(struct Flist*)malloc(sizeof(struct Flist));
    curr->Fno=Fno;
    curr->lineno=lineno;
    curr->next=funcs;
    funcs=curr;
}

int Llookup(int number){
    struct Llist* head=labels;
    while(head!=NULL){
        if (head->Lno==number){
            return head->lineno;
        }
        head=head->next;
    }
    return -1;

}
int Flookup(int number){
    struct Flist* head=funcs;
    while(head!=NULL)
    {
        if (head->Fno==number){
            return head->lineno;
        }
        head=head->next;
    }
    return -2;
}