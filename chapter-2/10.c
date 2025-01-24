#include <stdio.h>

#define MAX 100
int A[MAX];
void SelectionSort(int A[], int n);
void printdistinct(int A[], int n);

main()
{
    int i, n;
    for (n = 0; n < MAX && scanf("%d", &A[n]) != EOF; n++)
	;
    SelectionSort(A,n);
    printdistinct(A,n);
}

void SelectionSort(int A[], int n)
{
    int i, j, small, temp;
    for (i = 0; i < n-1; i++) {
	small = i;
	for (j = i+1; j < n; j++)
	    if (A[j] < A[small])
		small = j;
	temp = A[small];
	A[small] = A[i];
	A[i] = temp;
    }
}

void printdistinct(int A[], int n)
{
    int i, recent;
    if (n > 0) { /* first element is printed if it exists */
	printf("%d\n", A[0]);
	recent = A[0];
    }
    for (i = 1; i < n; i++) { /* the distinct elements of the rest are printed if they exist */
	if (A[i] != recent)
	    printf("%d\n", A[i]);
	recent = A[i];
    }
}
