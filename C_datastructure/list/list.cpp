// 2013.11.20
// the implement of list in C

struct Node {

    int Element;
    Position Next;
};
List MakeEmpty(List L) {
	Position Tmp;    
    while (L->Next != NULL) {

	Tmp = L->Next;
	free(L);
	L = Tmp;
    }
}

int IsEmpty(List L) {
    return List->Next == NULL;
}

int IsLast(Position p, List L) {
    
    return p->Next == NULL;
}

Position Find(int x, List L) {

    Position Tmp;
    Tmp = L;
    while (Tmp->Next != NULL && Tmp->Element != x)
	Tmp = Tmp->Next;

    return Tmp;
}

Position FindPrevious(int x, List L) {
    
    Position Tmp;
    Tmp = L;
    while (Tmp->Next != NULL && Tmp->Next->Element != x)
	Tmp = Tmp->Next;

    return Tmp;
}

void Delete(int x, List L) {

    Position p, Tmp;
    p = FindPrevious(x, L);
    
    if (!IsLast(p, L)) {
	Tmp = p->Next;
	p->Next = Tmp->Next;
	free(Tmp);
    }
}

void Insert(int x, List L, Position p) {
    
    Position Tmp;
    Tmp = malloc(sizeof(struct Node));
    if (Tmp == NULL)
	printf("Out of space!");
    
    Tmp->Element = x;
    Tmp->Next = p->Next;
    p->Next = Tmp;
}
