#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int *C = (int *)malloc((h - l + 1) * sizeof(int));

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            C[k++] = A[i++];
        } else {
            C[k++] = A[j++];
        }
    }

    while (i <= mid)
        C[k++] = A[i++];
    while (j <= h)
        C[k++] = A[j++];

    for (int i = l; i <= h; i++) {
        A[i] = C[i - l];
    }

    free(C);
}

void MergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main() {
    int n;
    printf("Enter size of List: ");
    scanf("%d", &n);
    int A[n];
    printf("\nEnter Elements of List:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    MergeSort(A, 0, n - 1);
    printf("\nMerge Sorted!\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}
