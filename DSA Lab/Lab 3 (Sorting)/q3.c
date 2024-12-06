
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = 0;

FILE *input()
{
    FILE *fptr;
    fptr = fopen("Input.txt", "w");
    if (fptr == NULL)
    {
        printf("ERROR IN FILE CREATION!\n");
        exit(1);
    }
    printf("ENTER NUMBER OF RANDOM NUMBERS TO CREATE : ");

    scanf("%d", &n);
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        int value = rand();
        fprintf(fptr, "%d\n", value);
    }
    printf("CREATED SUCCESSFULLY!\n");
    fclose(fptr);
    return fptr;
}

int *ArrayCreation(FILE *f)
{
    int *A = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &A[i]);
    }
    return A;
}

void merge(int *A, int l, int mid, int h)
{
    int *B = (int *)malloc(sizeof(int) * (h - l + 1));
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while (i <= mid)
    {
        B[k++] = A[i++];
    }

    while (j <= h)
    {
        B[k++] = A[j++];
    }

    for (i = 0; i < k; i++)
    {
        A[l + i] = B[i];
    }

    free(B);
}

void mwaymerge(int **A, int *result, int m)
{
    for (int i = 1; i < m; i++)
    {
        merge(result, 0, (1000 * i) - 1, 1000 * i - 1);
    }
}

void mergesort(int *A, int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(A, l, mid);
        mergesort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main()
{
    FILE *f = input();
    int *A = ArrayCreation(f);

    for (int i = 0; i < n / 1000; i++)
    {
        mergesort(A + i * 1000, 0, 999);
    }

    int *result = A;

    mwaymerge(&A, result, n / 1000);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    free(A);

    return 0;
}