#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

typedef struct NODE *pNODE;
struct NODE {
    int label; // not necessary
    pNODE leftmostchild, rightsibling;
};

int number_of_nodes(pNODE n)
{
    if (n == NULL) return 0;
    else return 1 + number_of_nodes(n->leftmostchild) + number_of_nodes(n->rightsibling);
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

    printf("%d\n%d\n%d\n", number_of_nodes(&a), number_of_nodes(&c), number_of_nodes(&m)); // 15, 10, 3
}
