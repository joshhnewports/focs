#define DefCell(EltType, CellType, ListType) \
    typedef struct CellType *ListType; \
    struct CellType { \
	EltType element; \
	ListType next; \
    }
DefCell(char, CELL, LIST); /* char */

main()
{
}

/* thank you 2.2.3 */
BOOLEAN lesser(LIST W, LIST X)
{
    if (X == NULL) return FALSE;
    else if (W == NULL) return TRUE;
    else if (W->element == X->element)
	return lesser(W->next, X->next);
    else return (W->element < X->element); 
}
