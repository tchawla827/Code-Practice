#include <bits/stdc++.h>
using namespace std;

void HeapifyMax(int *A, int i, int n)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && A[left] > A[largest])
    {
        largest = left;
    }

    if (right <= n && A[right] > A[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(A[i], A[largest]);
        HeapifyMax(A, largest, n);
    }
}

void BuildMaxHeap(int *A, int n)
{

    for (int i = n / 2; i >= 1; i--)
    {
        HeapifyMax(A, i, n);
    }
}

int main()
{
    int n;
    cout << "Enter Number of elements: ";
    cin >> n;

    int *A = new int[n + 1];
    cout << "Enter Elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    BuildMaxHeap(A, n);

    cout << "Max-Heap: ";
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }

    delete[] A;

    return 0;
}
