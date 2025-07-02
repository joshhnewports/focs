#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

typedef struct NODE *TREE;
struct NODE {
    char label;
    TREE leftchild, rightchild;
};

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

BOOLEAN isleaf(TREE T) {
    if (T->leftchild == NULL && T->rightchild == NULL)
	return TRUE;
    else return FALSE;
}

int height(TREE T) {
    if (T == NULL) return 0;
    else if (isleaf(T)) return 0;
    else return 1 + max(height(T->leftchild), height(T->rightchild));
}

main()
{
    struct NODE b; b.label = 'b'; b.leftchild = NULL; b.rightchild = NULL;
    struct NODE c; c.label = 'c'; c.leftchild = NULL; c.rightchild = NULL;
    struct NODE minus; minus.label = '-'; minus.leftchild = &b; minus.rightchild = &c;
    struct NODE d; d.label = 'd'; d.leftchild = NULL; d.rightchild = NULL;
    struct NODE star; star.label = '*'; star.leftchild = &minus; star.rightchild = &d;
    struct NODE a; a.label = 'a'; a.leftchild = NULL; a.rightchild = NULL;
    struct NODE plus; plus.label = '+'; plus.leftchild = &a; plus.rightchild = &star;

    printf("%d\n", height(&plus));
}
