#include <stdio.h>

typedef struct NODE *pNODE;
struct NODE {
    char label;
    pNODE leftmostchild, rightsibling;
};

// i gave in and wrote a loop, now it works. this is magical.
void circumnavigate(pNODE n)
{
    pNODE c;
    
    if (n == NULL) return;
    printf("%c ", n->label);
    c = n->leftmostchild;
    while (c != NULL) {
	circumnavigate(c);
	printf("%c ", n->label);
	c = c->rightsibling;
    }
}

main()
{
    // bad spacing im sorry
    struct NODE d;     d.label = 'd';     d.leftmostchild = NULL;      d.rightsibling = NULL;
    struct NODE c;     c.label = 'c';     c.leftmostchild = NULL;      c.rightsibling = NULL;
    struct NODE b;     b.label = 'b';     b.leftmostchild = NULL;      b.rightsibling = &c;
    struct NODE minus; minus.label = '-'; minus.leftmostchild = &b;    minus.rightsibling = &d;
    struct NODE star;  star.label = '*';  star.leftmostchild = &minus; star.rightsibling = NULL;
    struct NODE a;     a.label = 'a';     a.leftmostchild = NULL;      a.rightsibling = &star;
    struct NODE plus;  plus.label = '+';  plus.leftmostchild = &a;     plus.rightsibling = NULL;
    circumnavigate(&plus); // + a + * - b - c - * d * +
    putchar('\n');
}
