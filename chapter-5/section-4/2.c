#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

typedef struct NODE *pNODE;
struct NODE {
    int label;
    pNODE leftmostchild, rightsibling;
};

BOOLEAN isleaf(pNODE n)
{
    if (n->leftmostchild == NULL && n->rightsibling == NULL) return TRUE;
    else return FALSE;
}

BOOLEAN has_child_and_sibling(pNODE n)
{
    if (n->leftmostchild != NULL && n->rightsibling != NULL) return TRUE;
    else return FALSE;
}

BOOLEAN isparent(pNODE n)
{
    if (n->leftmostchild != NULL) return TRUE;
    else FALSE;
}

int max(int a, int b)
{
    if (a >= b) return a;
    else return b;
}

// checking if n is null doesnt work well here
// n is leaf? label of n
// n must not be a leaf. therefore n has a child or sibling or both
// n has a child and sibling? compare n to the max_tree of the child and sibling
// n has only a child? compare n to the max_tree of the child
// n must have only a sibling. compare n to the max_tree of the sibling.
int max_tree(pNODE n)
{
    if (isleaf(n)) return n->label;
    else if (has_child_and_sibling(n))
	return max(n->label, max(max_tree(n->leftmostchild), max_tree(n->rightsibling)));
    else if (isparent(n)) return max(max_tree(n->leftmostchild), n->label);
    else return max(max_tree(n->rightsibling), n->label);
}

main()
{
    struct NODE o;o.label = 15; o.leftmostchild = NULL; o.rightsibling = NULL;
    struct NODE n;n.label = 14; n.leftmostchild = &o; n.rightsibling = NULL;
    struct NODE m;m.label = 13; m.leftmostchild = NULL; m.rightsibling = &n;
    struct NODE l;l.label = 12; l.leftmostchild = NULL; l.rightsibling = NULL;
    struct NODE k;k.label = 11; k.leftmostchild = NULL; k.rightsibling = &l;
    struct NODE j;j.label = 10; j.leftmostchild = &m; j.rightsibling = NULL;
    struct NODE i;i.label = 9; i.leftmostchild = NULL; i.rightsibling = NULL;
    struct NODE h;h.label = 8; h.leftmostchild = NULL; h.rightsibling = &i;
    struct NODE g;g.label = 7; g.leftmostchild = &k; g.rightsibling = NULL;
    struct NODE f;f.label = 6; f.leftmostchild = NULL; f.rightsibling = &g;
    struct NODE e;e.label = 5; e.leftmostchild = &j; e.rightsibling = &f;
    struct NODE d;d.label = 4; d.leftmostchild = &h; d.rightsibling = NULL;
    struct NODE c;c.label = 3; c.leftmostchild = &e; c.rightsibling = NULL;
    struct NODE b;b.label = 2; b.leftmostchild = &d; b.rightsibling = &c;
    struct NODE a;a.label = 1; a.leftmostchild = &b; a.rightsibling = NULL;

    printf("%d\n%d\n%d\n", max_tree(&a), max_tree(&f), max_tree(&d)); // 15, 12, 9
}
