#include <stdio.h>

#define MAX 100
int A[MAX];
void SelectionSort(int A[], int n);

main()
{
    int i, n;
    for (n = 0; n < MAX && scanf("%d", &A[n]) != EOF; n++)
	;
    SelectionSort(A,n); 
    for (i = 0; i < n; i++)
	printf("%d\n", A[i]);
}

void SelectionSort(int A[], int n)
{
    int *i, *j, *small, temp;
    for (i = A; i < A + n-1; i++) {
	small = i;
	for (j = i+1; j < A + n; j++)
	    if (*j < *small)
		small = j;
	temp = *small;
	*small = *i;
	*i = temp;
    }
}
