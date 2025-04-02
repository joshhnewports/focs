#include <stdio.h>

main()
{
}

void recSS(T A[], int i, int n)
{
    int j, small;
    T temp;
    if (i < n-1) {
	small = i;
	for (j = i+1; j < n; j++)
	    if (lt(key(A[j]), key(A[small])))
		small = j;
	temp = A[small];
	A[small] = A[i];
	A[i] = temp;
	recSS(A, i+1, n);
    }
}
