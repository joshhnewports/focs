#include <stdio.h>

void binary(int i);
void b(int i);

main()
{
    int i;
    for (i = 0; i < 50; ++i) {
	binary(i);
	printf("\t%d\n", i);
    }
}

/* we could store the representation in memory, but we print it instead to keep the function needing
   only one argument. it had never occurred to me that bit strings always have a leading 1 if you write
   them a certain way */
void binary(int i)
{
    if (i == 0) printf("0"); /* special case */
    else b(i);
}

/* note: 1%2 = 1, 1/2 = 0 */
void b(int i)
{
    if (i <= 0) return;
    else {
	printf("%d", i%2);
	b(i/2); 
    }
}
