#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

typedef struct NODE *TREE;
struct NODE {
    char label;
    TREE leftchild, rightchild;
};

BOOLEAN isoperator(char sym) {
    if (sym == '+' || sym == '-' || sym == '*' || sym == '/')
	return TRUE;
    else return FALSE;
}

BOOLEAN need_parentheses(char sym) {
    if (sym == '*' || sym == '/')
	return TRUE;
    else return FALSE;
}

void inorder(TREE T)
{
    if (T != NULL) {
	if (need_parentheses(T->label)) {
	    if (T->leftchild != NULL && isoperator(T->leftchild->label)) {
		putchar('(');
		inorder(T->leftchild);
		putchar(')');
	    }
	    else inorder(T->leftchild);
	    
	    printf("%c", T->label);
	    
	    if (T->rightchild != NULL && isoperator(T->rightchild->label)) {
	        putchar('(');
		inorder(T->rightchild);
		putchar(')');
	    }
	    else inorder(T->rightchild);
	}
	else {
	    inorder(T->leftchild);
	    printf("%c", T->label);
	    inorder(T->rightchild);
	}
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
    putchar('\n');
}
