//IIT2023150
//Ques2

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


typedef struct {
    char items[MAX_SIZE]; 
    int size;            
} MaxHeap;


void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}


void maxHeapify(MaxHeap *heap, int i) {
    int largest = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if (lchild < heap->size && heap->items[lchild] > heap->items[largest])
        largest = lchild;

    if (rchild < heap->size && heap->items[rchild] > heap->items[largest])
        largest = rchild;

    if (largest != i) {
        swap(&heap->items[i], &heap->items[largest]);
        maxHeapify(heap, largest);
    }
}


void insert(MaxHeap *heap, char value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    int i = heap->size++;
    heap->items[i] = value;

    
    while (i != 0 && heap->items[i] > heap->items[(i - 1) / 2]) {
        swap(&heap->items[i], &heap->items[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


char removeMax(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap underflow\n");
        return '\0';
    }

    char max = heap->items[0];
    heap->items[0] = heap->items[--heap->size];
    maxHeapify(heap, 0);

    return max;
}


void fun(char *c, int length) {
    MaxHeap heap;
    heap.size = 0;

    for (int i = 0; i < length; i++) {
        if (c[i] == '*') {
            char max = removeMax(&heap);
            if (max != '\0') {
                printf("%c ", max);
            }
        } else {
            insert(&heap, c[i]);
        }
    }
}

int main() {
    char c[] = {'P', 'R', 'I', 'O', '*', 'R', '*', '*', 'I', '*', 'T', '*', 'Y', '*', '*', '*', 'Q', 'U', 'E', '*', '*', '*', 'U', '*', 'E'};
    int length = sizeof(c) / sizeof(c[0]);

    printf("Sequence of values returned by remove-maximum operations: ");
    fun(c, length);

    return 0;
}
