#include <stdio.h>

#define MAX 100

struct STUDENT {
    int studentID;
    char *name;
    char grade;
} A[MAX];

void SelectionSort(struct STUDENT A[], int n);

main()
{
    int i, n;
    for (n = 0; n < MAX && scanf("%d", &(A[n].studentID)) != EOF; n++)
	;
    SelectionSort(A,n); 
    for (i = 0; i < n; i++)
	printf("%d\n", A[i].studentID);
}

void SelectionSort(struct STUDENT A[], int n)
{
    int i, j, small;
    struct STUDENT temp;
    for (i = 0; i < n-1; i++) {
	small = i;
	for (j = i+1; j < n; j++)
	    if (A[j].studentID < A[small].studentID)
		small = j;
	temp = A[small];
	A[small] = A[i];
	A[i] = temp;
    }
}
