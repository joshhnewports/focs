#include <stdio.h>

#define MAX 100
T A[MAX]; /* assume T is defined */
void SelectionSort(T A[], T n);

main()
{
    int i, n;
    for (n = 0; n < MAX && scanf("%d", &A[n]) != EOF; n++)
	;
    SelectionSort(A,n); 
    for (i = 0; i < n; i++)
	printf("%d\n", A[i]);
}

void SelectionSort(T A[], int n)
{
    int i, j, small;
    T temp;
    for (i = 0; i < n-1; i++) {
	small = i;
	for (j = i+1; j < n; j++)
	    if (lt(key(A[j]), key(A[small]))) /* assume lt, key exist */
		small = j;
	temp = A[small];
	A[small] = A[i];
	A[i] = temp;
    }
}
