struct Llist{
    int Lno;
    int lineno;
    struct Llist* next;
};
struct Llist* labels=NULL;

void Lappend(int Lno,int lineno){
    struct Llist * curr=(struct Llist *)malloc(sizeof(struct Llist));
    curr->Lno=Lno;
    curr->lineno=lineno;
    curr->next=labels;
    labels=curr;


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