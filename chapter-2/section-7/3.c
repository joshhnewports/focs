#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define DefCell(EltType, CellType, ListType) \
    typedef struct CellType *ListType; \
    struct CellType { \
	EltType element; \
	ListType next; \
    }
DefCell(int, CELL, LIST);

typedef int BOOLEAN;

BOOLEAN find(LIST L, int n);
BOOLEAN find1698(LIST L);

int main()
{
}

BOOLEAN find(LIST L, int n)
{
    if (L == NULL) return FALSE;
    else if (L->element == n) return TRUE;
    else return find(L->next, n);
}

BOOLEAN find1698(LIST L)
{
    return find(L, 1698);
}
