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

BOOLEAN lexless(LIST A, LIST B);
char normalizecase(char c);

main()
{
}

BOOLEAN lexless(LIST A, LIST B)
{
    if (A == NULL && B != NULL) /* A is a proper prefix of B */
	return TRUE;
    else if (B == NULL) /* B is a proper prefix of A or A and B are the empty string and are equal */
	return FALSE; /* hence A is not less than B */
    else if (normalizecase(A->element) < normalizecase(B->element))
	return TRUE;
    else if (normalizecase(B->element) < normalizecase(A->element))
	return FALSE;
    else /* the elements of A so far form a proper prefix of B */
	return lexless(A->next, B->next);
}

char normalizecase(char c)
{
    int difference;
    difference = 'a' - 'A';
    if (c >= 'A' && c <= 'Z')
	return c + difference;
    else
	return c;
}
