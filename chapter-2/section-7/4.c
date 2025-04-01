#include <stdio.h>

#define DefCell(EltType, CellType, ListType) \
    typedef struct CellType *ListType; \
    struct CellType { \
	EltType element; \
	ListType next; \
    }
DefCell(int, CELL, LIST);

int add(LIST L);

main()
{
}

int add(LIST L)
{
    if (L == NULL) return 0;
    else return L->element + add(L->next);
}
