#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int *A, int n)
{
    int j;
    int key;
    for (int i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (A[j] > key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size of Array: ";
    cin >> n;
    int *A = new int[n];
    cout << "Enter Elements\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Array before sorting: ";
    display(A, n);

    InsertionSort(A, n);

    cout << "Array after sorting: ";
    display(A, n);

    delete[] A; 
}
