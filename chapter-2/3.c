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

main()
{
    
}

BOOLEAN lexless(LIST A, LIST B)
{
    if (A == NULL && B != NULL) /* A is a proper prefix of B */
	return TRUE;
    else if (B == NULL) /* B is a proper prefix of A or A and B are the empty string and are equal */
	return FALSE; /* hence A is not less than B */
    else if (A->element < B->element)
	return TRUE;
    else if (B->element < A->element)
	return FALSE;
    else /* the elements of A so far form a proper prefix of B */
	return lexless(A->next, B->next);
}
