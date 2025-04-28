#include <stdio.h>
#include <stdlib.h>

#define DefCell(EltType, CellType, ListType) \
    typedef struct CellType *ListType; \
    struct CellType { \
	EltType element; \
	ListType next; \
    }
DefCell(int, CELL, LIST);

int length(LIST list);
LIST merge(LIST list1, LIST list2);
LIST split(LIST list, int n);
LIST kmergesort(LIST list, int k);
LIST kmerge(LIST list, int len, int k, int n);
void PrintList(LIST list);
LIST MakeList();

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

int length(LIST list)
{
    if (list == NULL) return 0;
    else return 1 + length(list->next);
}

LIST split(LIST list, int n)
{
    LIST rest;

    if (n == 0) {
        rest = list->next;
        list->next = NULL;
        return rest;
    }       
    else return split(list->next, n-1);
}

LIST kmergesort(LIST list, int k)
{
    if (k < 2) return list; /* must split list by at least half */
    else if (list == NULL) return NULL;
    else if (list->next == NULL) return list;
    else return kmerge(list, length(list), k, k-1);
}

LIST kmerge(LIST list, int len, int k, int n)
{
    LIST SecondList;
    
    if (list == NULL) return NULL;
    else if (list->next == NULL) return list;
    else {
	/* we cannot write a call to split as an argument to kmergesort. we expect list to be
	   mutated first then the call to kmerge happens after. but "the order of evaluation of
	   function parameters is unspecified", so we must force the split first. */
	SecondList = split(list, n*len/k);
	return merge(kmergesort(SecondList, k),
		     kmerge(list, len, k, --n));
    }
}

void PrintList(LIST list)
{
    while (list != NULL) {
	printf("%d\n", list->element);
	list = list->next;
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
    PrintList(kmergesort(a, 2));
}
