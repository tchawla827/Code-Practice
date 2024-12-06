#include <stdio.h>
#include <stdlib.h>
//merge two arrays into a third one
int *merge(int A[], int B[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    int *C = (int *)malloc((m + n) * sizeof(int));
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while (i < m)
        C[k++] = A[i++];
    while (j < n)
        C[k++] = B[j++];
    return C;
}

void sort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main()
{
    int n, m;

    printf("Enter size of first array : ");
    scanf("%d", &m);
    int A[m];
    printf("\nEnter elements of first array\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);

    printf("\nEnter size of second array : ");
    scanf("%d", &n);
    int B[n];
    printf("\nEnter elements of second array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    sort(A, m);
    printf("Sorted Array A : ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ", A[i]);
    }

    sort(B, n);
    printf("Sorted Array B : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", B[i]);
    }

    int *P = merge(A, B, m, n);
    printf("\n\nMerge Sorted!\n\nMerged Array\n");

    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", P[i]);
    }
}