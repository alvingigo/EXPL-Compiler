struct Gsymbol* Gtemp;
struct Lsymbol* Ltemp;
struct Paramstruct* Ptemp;

int checkAvailability(char *name, int global);
void assignType(struct tnode* node, int func);
void assignTypeField(struct tnode* node,struct FieldList* fields);
void typecheck(struct TypeTable* t1, struct TypeTable* t2, char c);
void checkAssign(struct tnode* t);
