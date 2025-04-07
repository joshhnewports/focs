#include <stdio.h>
#include <stdlib.h>

#define DefCell(EltType, CellType, ListType) \
    typedef struct CellType *ListType; \
    struct CellType { \
	EltType element; \
	ListType next; \
    }
DefCell(int, CELL, LIST);

void PrintList(LIST list)
{
    while (list != NULL) {
	printf("%d\n", list->element);
	list = list->next;
    }
}

int length(LIST list)
{
    if (list == NULL) return 0;
    else return 1 + length(list->next);
}

/* count down the length to cut off the tail and make a new head */
LIST split(LIST list, int n)
{
    LIST rest;
    
    if (n == 0) { /* MergeSort handles the cases where we would check for null here */
	rest = list->next;
	list->next = NULL;
	return rest;
    }
    else return split(list->next, n-1);
}

/* no change */
LIST merge(LIST list1, LIST list2)
{
    if (list1 == NULL) return list2;
    else if (list2 == NULL) return list1;
    else if (list1->element <= list2->element) {
	list1->next = merge(list1->next, list2);
	return list1;
    }
    else {
	list2->next = merge(list1, list2->next);
	return list2;
    }
}

LIST MergeSort(LIST list)
{
    LIST SecondList, ThirdList;
    int len;
    
    if (list == NULL) return NULL;
    else if (list->next == NULL) return list;
    else {
	len = length(list);
	ThirdList = split(list, 2 * len / 3);
	SecondList = split(list, len / 3);
	return merge(MergeSort(list),
		     merge(MergeSort(SecondList),
			   MergeSort(ThirdList)));
    }
}

LIST MakeList()
{
    int x;
    LIST pNewCell;
    if (scanf("%d", &x) == EOF) return NULL;
    else {
	pNewCell = (LIST) malloc(sizeof(struct CELL));
	pNewCell->next = MakeList();
	pNewCell->element = x;
	return pNewCell;
    }
}

main()
{
    LIST a;
    a = MakeList();
    PrintList(MergeSort(a));
}
