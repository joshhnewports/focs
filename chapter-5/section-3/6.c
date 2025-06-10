#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

typedef struct NODE *pNODE;
struct NODE { // all nodes lead to the root
    int num;
    pNODE parent;
};

pNODE lca(pNODE x, pNODE y);
BOOLEAN path_exists(pNODE x, pNODE y);

main()
{
    // sorry 
    struct NODE a;a.num = 1;a.parent = NULL;
    struct NODE b;b.num = 2;b.parent = &a;
    struct NODE c;c.num = 3;c.parent = &a;
    struct NODE d;d.num = 4;d.parent = &b;
    struct NODE e;e.num = 5;e.parent = &c;
    struct NODE f;f.num = 6;f.parent = &c;
    struct NODE g;g.num = 7;g.parent = &c;
    struct NODE h;h.num = 8;h.parent = &d;
    struct NODE i;i.num = 9;i.parent = &d;
    struct NODE j;j.num = 10;j.parent = &e;
    struct NODE k;k.num = 11;k.parent = &g;
    struct NODE l;l.num = 12;l.parent = &g;
    struct NODE m;m.num = 13;m.parent = &j;
    struct NODE n;n.num = 14;n.parent = &j;
    struct NODE o;o.num = 15;o.parent = &n;

    printf("%d\n%d\n", lca(&o, &h)->num, lca(&h, &o)->num); // 15, 8 -> 1
    printf("%d\n%d\n", lca(&o, &l)->num, lca(&l, &o)->num); // 15, 12 -> 3
    printf("%d\n%d\n", lca(&m, &j)->num, lca(&j, &m)->num); // 13, 10 -> 10
    printf("%d\n%d\n", lca(&m, &m)->num, lca(&m, &m)->num); // 13, 13 -> 13
    printf("%d\n%d\n", lca(&m, &e)->num, lca(&e, &m)->num); // 13, 5 -> 5
    printf("%d\n%d\n", lca(&i, &b)->num, lca(&b, &i)->num); // 9, 2 -> 2
    printf("%d\n%d\n", lca(&n, &l)->num, lca(&l, &n)->num); // 14, 12 -> 3
}

// x is NULL? not in the same tree
// path from x to y? x
// lca of x going toward the root, and y
pNODE lca(pNODE x, pNODE y) {
    if (x == NULL) return NULL;
    else if (path_exists(x, y)) return x;
    else return lca(x->parent, y);
}

// y is NULL? no path
// y == x? path exists
// find the path from x to the parent of y
BOOLEAN path_exists(pNODE x, pNODE y) {
    if (y == NULL) return FALSE;
    else if (y == x) return TRUE;
    else return path_exists(x, y->parent);
}
