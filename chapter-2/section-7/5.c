#include <stdio.h>

#define DefCell(EltType, CellType, ListType) \
    typedef struct CellType *ListType; \
    struct CellType { \
	EltType element; \
	ListType next; \
    }
DefCell(int, CELL, LIST);

void selectionsort(LIST L);
LIST smallest(LIST small, LIST current);

main()
{
}

void selectionsort(LIST L)
{
    LIST small;
    int temp;
    
    if (L == NULL) return;
    else {
	small = smallest(L, L->next);
	temp = L->element;
	L->element = small->element;
	small->element = temp;
	selectionsort(L->next);
    }
}

/* returns the list beginning with the cell whose element is the smallest */
LIST smallest(LIST small, LIST current)
{
    if (current == NULL) return small;
    else if (current->element < small->element) return smallest(current, current->next);
    else return smallest(small, current->next);
}
