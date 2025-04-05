#include <stdio.h>

#define DefCell(EltType, CellType, ListType)	\
    typedef struct CellType *ListType; \
    struct CellType { \
	EltType element; \
	ListType next; \
    }
DefCell(int, CELL, LIST);

LIST sort(LIST L);
LIST smallest(LIST small, LIST current);
LIST beforesmallest(LIST small, LIST head);

main()
{
}

/* discovered only through heavy experimentation */
LIST sort(LIST L)
{
    LIST small, before;
    if (L == NULL) return NULL;
    else {
	small = smallest(L, L->next);
	before = beforesmallest(small, L);
	if (small == L) /* if the sorted list has caught up to the list we must sort through */
	    L = L->next; /* then we must sort through the rest of list */
	before->next = small->next;
	small->next = sort(L); /* small followed by the sort of the rest is a sorted list */
	return small;
    }
}

LIST smallest(LIST small, LIST current)
{
    if (current == NULL) return small;
    else if (current->element < small->element)
	return smallest(current, current->next);
    else return smallest(small, current->next);
}

LIST beforesmallest(LIST small, LIST head)
{
    if (head == NULL) return NULL; /* shouldnt happen */
    else if (head->next == NULL) return small; /* list of one element */
    else if (head->next == small) return head; /* ideal case */
    else if (head == small) return head; /* uncommon case */
    else return beforesmallest(small, head->next); /* typical case */
}
