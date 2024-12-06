#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tournamentSort(int arr[], int n) {
    // Build the tournament structure
    for (int i = n / 2 - 1; i >= 0; i--) {
        // Find the winner of the current level
        int j = 2 * i + 1; // left child
        int k = 2 * i + 2; // right child
        int winner = i;
        if (j < n && arr[j] < arr[winner]) {
            winner = j;
        }
        if (k < n && arr[k] < arr[winner]) {
            winner = k;
        }

        // Promote the winner to parent node
        if (winner != i) {
            swap(&arr[i], &arr[winner]);
        }
    }

    // Extract minimum element iteratively
    for (int i = n - 1; i >= 0; i--) {
        // Move minimum element to the end
        swap(&arr[0], &arr[i]);

        // Rebuild tournament for remaining elements
        int j = 0;
        while (2 * j + 1 < i) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int winner = j;
            if (left < i && arr[left] < arr[winner]) {
                winner = left;
            }
            if (right < i && arr[right] < arr[winner]) {
                winner = right;
            }
            if (winner != j) {
                swap(&arr[j], &arr[winner]);
            }
            j = winner;
        }
    }
}

int main() {
    int arr[] = {5, 3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    tournamentSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}