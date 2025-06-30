#include <stdio.h>

typedef struct NODE *TREE;
struct NODE {
    char label;
    TREE leftchild, rightchild;
};

void inorder(TREE T)
{
    if (T != NULL) {
	inorder(T->leftchild);
	printf("%c\n", T->label);
	inorder(T->rightchild);
    }
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

    inorder(&plus);
}
