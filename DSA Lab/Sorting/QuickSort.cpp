#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *A, int l,int h)
{
    int i=l-1;
    int j=h+1;
    int pivot=A[l];

    while(i<j)
    {
        do{i++;}while(pivot>=A[i]);
        do{j--;}while(pivot<A[j]);

        if(i<j)
        swap(A[i],A[j]);
    }
    swap(A[j],A[l]);
    return j;

}
void QuickSort(int *A, int l, int h)
{
    int j;
    if(l<h)
    {
        j=Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
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

    QuickSort(A, 0,n-1);

    cout << "Array after sorting: ";
    display(A, n);

    delete[] A; 
}
