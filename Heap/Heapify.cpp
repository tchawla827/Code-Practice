#include <bits/stdc++.h>
using namespace std;

void HeapifyMax(int *A, int i, int n)
{
    int largest = i;
    while (true)
    {
        int left = 2 * largest;
        int right = 2 * largest + 1;

        if (left <= n && A[left] > A[largest])
        {
            largest = left;
        }

        if (right <= n && A[right] > A[largest])
        {
            largest = right;
        }

        if (largest == i)
        {
            break;
        }

        swap(A[i], A[largest]);

        i = largest;
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
    cout << "Enter number of elements: ";
    cin >> n;

    int *A = new int[n + 1];
    cout << "Enter elements: ";
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

    

    return 0;
}
