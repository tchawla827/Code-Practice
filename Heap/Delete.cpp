#include <bits/stdc++.h>
using namespace std;

struct Heap{
    int *A;
    int size;
};

typedef struct Heap Heap;

void HeapifyMax(Heap * h,int i )
{
    int largest = i;
    while (true)
    {
        int left = 2 * largest;
        int right = 2 * largest + 1;

        if (left <= h->size&& h->A[left] > h->A[largest])
        {
            largest = left;
        }

        if (right <= h->size && h->A[right] > h->A[largest])
        {
            largest = right;
        }

        if (largest == i)
        {
            break;
        }

        swap(h->A[i], h->A[largest]);

        i = largest;
    }
}

void BuildMaxHeap(Heap *h)
{
    for (int i = h->size / 2; i >= 1; i--)
    {
        HeapifyMax(h, i);
    }
}

void Delete(Heap * h)
{
    int x=h->A[h->size];
    int val=h->A[1];

    h->A[1]=x;
    h->size--;

    HeapifyMax(h,1);
}



int main()
{
    Heap *h=new Heap;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    h->size=n;

    h->A=new int[h->size+1];
    cout << "Enter elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> h->A[i];
    }

    BuildMaxHeap(h);

    cout << "Max-Heap: ";
    for (int i = 1; i <= h->size; i++)
    {
        cout << h->A[i] << " ";
    }

    Delete(h);
    cout<<"\ndeleted\n";
    Delete(h);
    cout<<"deleted\n";

    cout << "Max-Heap: ";
    for (int i = 1; i <= h->size; i++)
    {
        cout << h->A[i] << " ";
    }

}
