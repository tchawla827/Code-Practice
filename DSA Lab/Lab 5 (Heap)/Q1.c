//IIT2023150
//Ques1

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int maxsize;
    int size;
} MaxHeap;

MaxHeap* createMaxHeap(int maxsize) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->maxsize = maxsize;
    heap->size = 0;
    heap->a = (int*)malloc(maxsize * sizeof(int));
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap* heap, int i) {
    int largest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if (lchild < heap->size && heap->a[lchild] > heap->a[largest])
        largest = lchild;

    if (rchild < heap->size && heap->a[rchild] > heap->a[largest])
        largest = rchild;

    if (largest != i) {
        swap(&heap->a[i], &heap->a[largest]);
        maxHeapify(heap, largest);
    }
}

void insert(MaxHeap* heap, int value) {
    if (heap->size == heap->maxsize) {
        printf("Heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->a[i] = value;

    while (i != 0 && heap->a[(i - 1) / 2] < heap->a[i]) {
        swap(&heap->a[i], &heap->a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(MaxHeap* heap) {
    if (heap->size <= 0)
        return -1;

    if (heap->size == 1) {
        heap->size--;
        return heap->a[0];
    }

    int root = heap->a[0];
    heap->a[0] = heap->a[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return root;
}

int kthLargest(int arr[], int n, int k) {
    MaxHeap* heap = createMaxHeap(n);

    for (int i = 0; i < n; i++) {
        insert(heap, arr[i]);
    }

    for (int i = 0; i < k - 1; i++) {
        extractMax(heap);
    }

    return heap->a[0];
}

int main() {
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter Elements\n");
    int *arr=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    int k;
    printf("Enter k : ");
    scanf("%d",&k);
    if(k>n)
    {
        printf("k should be less than n, try again!\n");
        exit(1);
    }

    printf("kth largest element : %d\n", kthLargest(arr, n, k));

    return 0;
}
