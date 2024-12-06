#include <iostream>
#include <stdlib.h>
using namespace std;

class Array
{
private:
    int *A;
    int length = 0;
    int size;

public:
    Array()
    {
        length = 0;
        size = 10;
    }
    Array(int sz)
    {
        A = new int[sz];
        length = 0;
        size = sz;
    }
    ~Array()
    {
        delete[] A;
    }
    void display();
    void set(int i, int x);
    int get(int i);
    void append();
    void insert(int i, int x);
    void del(int i);
    int *LinearSearch(int key);
    void Sort();
    int BinarySearch(int key);
    int isSorted();
    int Max();
    int Min();
    int Sum();
    float Average();
    void Reverse();
    int InsertInSorted(int x);
    void negativerearrange();
    friend void SortedMerge(Array *arr, Array *arr1);
    friend void Union(Array *arr, Array *arr1);
    friend void Intersection(Array *arr, Array *arr1);
    friend void setDifference(Array *arr, Array *arr1);
    void leftshift();
    void rotate(int n);
};

void Array::display()
{
    if (length == 0)
        cout << "ARRAY IS EMPTY!" << endl;
    else
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
    }
}
void Array::set(int i, int x)
{
    if (i < 0 || i >= size)
    {
        cout << "INDEX OUT OF BOUNDS" << endl;
    }
    else
    {
        A[i] = x;
        if (i >= length)
            length++;
        cout << "SET!" << endl;
    }
}
int Array::get(int i)
{
    if (i >= length)
        return -1;
    return A[i];
}
void Array::append()
{

    if (length == size)
        cout << "CANNOT APPEND ELEMENT, ARRAY SIZE INSUFFICIENT" << endl;
    else
    {
        int x;
        cout << "ENTER ELEMENT TO APPEND : ";
        cin >> x;
        A[length] = x;
        length++;
        cout << "APPENDED!" << endl;
    }
}
void Array::insert(int i, int x)
{
    if (length == size)
    {
        cout << "CANNOT INSERT ELEMENT, ARRAY SIZE INSUFFICIENT" << endl;
    }
    else
    {
        for (int j = length - 1; j >= i; j--)
        {
            A[j + 1] = A[j];
        }
        A[i] = x;
        cout << "INSERTED SUCCESSFULLY!" << endl;
        length++;
    }
}
void Array::del(int i)
{
    if (i < 0 || i >= length)
        cout << "INDEX OUT OF BOUNDS" << endl;
    else
    {
        for (int j = i; j < length - 1; j++)
        {
            A[j] = A[j + 1];
        }
        length--;
    }
}
int *Array::LinearSearch(int key)
{
    int *index = new int[length];
    for (int i = 0; i < length; i++)
    {
        index[i] = -1;
    }
    int count = 0;
    for (int j = 0; j < length; j++)
    {
        if (A[j] == key)
        {
            index[count] = j;
            count++;
        }
    }
    return index;
}
void Array::Sort()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    cout << "ARRAY SORTED SUCCESSFULLY!" << endl;
}
int Array::BinarySearch(int key)
{
    Sort();
    int l = 0, h = length - 1;
    int mid = (l + h) / 2;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int Array::isSorted()
{

    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return -1; // not sorted
    }
    return 1; // sorted
}
int Array::Max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
int Array::Min()
{
    if (isSorted() == 1)
        return 0;
    else
    {
        int min = A[0];
        for (int i = 0; i < length; i++)
        {
            if (A[i] < min)
                min = A[i];
        }
        return min;
    }
}
int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    return sum;
}
float Array::Average()
{
    return (float)Sum() / length;
}
void Array::Reverse()
{
    for (int i = 0; i < length / 2; i++)
    {
        int temp = A[i];
        A[i] = A[length - 1 - i];
        A[length - 1 - i] = temp;
    }
    cout << "ARRAY REVERSED SUCCESSFULLY!" << endl;
}
int Array::InsertInSorted(int x)
{
    if (length == size)
    {
        cout << "CANNOT INSERT, ARRAY SIZE FULL" << endl;
        return -1;
    }
    else if (isSorted() == -1)
    {
        Sort();
        cout << "ARRAY SORTED!" << endl;
    }
    int j;
    for (int i = length - 1; A[i] > x; i--)
    {
        A[i + 1] = A[i];
        j = i;
    }
    A[j + 1] = x;
    length++;
    return 0;
}
void Array::negativerearrange()
{
    int i = 0, j = length - 1;
    while (i <= j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] > 0)
            j--;
        if (i < j)
        {
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    cout << "NEGATIVE AND POSITIVE NUMBERS SEPARATED!" << endl;
}
void SortedMerge(Array *arr, Array *arr1)
{
    // NO SAME NUMBER IN ARRAYS
    if (arr1->isSorted() == -1)
        arr1->Sort();
    if (arr->isSorted() == -1)
        arr->Sort();
    int *C = new int[arr->length + arr1->length];

    int i = 0, j = 0, k = 0;
    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
        {
            C[k] = arr->A[i];
            i++;
            k++;
        }
        else if (arr->A[i] > arr1->A[j])
        {
            C[k] = arr1->A[j];
            j++;
            k++;
        }
    }
    while (i < arr->length)
    {
        C[k] = arr->A[i];
        i++;
        k++;
    }
    while (j < arr1->length)
    {
        C[k] = arr1->A[j];
        j++;
        k++;
    }

    cout << "AFTER MERGESORTING" << endl;
    for (int i = 0; i < arr->length + arr1->length; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
}
void Union(Array *arr, Array *arr1)
{
    int i = 0, j = 0, k = 0;
    int *p = new int[arr->length + arr1->length];

    while (i < arr->length && j < arr1->length)
    {
        if (arr->A[i] < arr1->A[j])
        {
            p[k++] = arr->A[i++];
        }
        else if (arr->A[i] > arr1->A[j])
        {
            p[k++] = arr1->A[j++];
        }
        else
        {

            p[k++] = arr->A[i++];
            j++;
        }
    }

    while (i < arr->length)
    {
        p[k++] = arr->A[i++];
    }

    while (j < arr1->length)
    {
        p[k++] = arr1->A[j++];
    }

    cout << "UNIONISED ARRAY : " << endl;
    for (int m = 0; m < k; m++)
    {
        cout << p[m] << " ";
    }
    cout << endl;

    delete[] p;
}
void Intersection(Array *arr, Array *arr1)
{
    int size;
    if (arr->length > arr1->length)
        size = arr->length;
    else
        size = arr1->length;
    int k = 0;
    int *p = new int[size];
    for (int i = 0; i < arr->length; i++)
    {
        for (int j = 0; j < arr1->length; j++)
        {
            if (arr->A[i] == arr1->A[j])
            {
                p[k++] = arr->A[i];
                break;
            }
        }
    }
    cout << "INTERSECTION OF ARRAYS : ";
    for (int i = 0; i < k; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    delete[] p;
    p = nullptr;
}
void setDifference(Array *arr, Array *arr1)
{
    int i = 0, j = 0, k = 0;

    int *p = new int[arr->length];
    for (int i = 0; i < arr->length; i++)
    {
        int flag = 0;
        for (int j = 0; j < arr1->length; j++)
        {
            if (arr->A[i] == arr1->A[j])
            {
                flag = 1; // dont copy
                break;
            }
        }
        if (flag != 1)
            p[k++] = arr->A[i];
    }
}

void Array::leftshift()
{
    for (int i = 1; i < length; i++)
    {
        A[i - 1] = A[i];
    }
    length--;
    cout << "LEFT SHIFT SUCCESSFUL!";
    cout << endl;
}

void Array::rotate(int n)
{

    for (int j = 0; j < n; j++)
    {
        int temp = A[0];
        for (int i = 1; i < length; i++)
        {
            A[i - 1] = A[i];
        }
        A[length - 1] = temp;
    }
    cout << "ARRAY ROTATED!" << endl;
}

int main()
{
    cout << "ARRAY ADT PROGRAM!" << endl;
    Array *arr;
    int sz;
    cout << "ENTER SIZE OF ARRAY : ";
    cin >> sz;
    arr = new Array(sz);
    int ch;
    int *y;
    do
    {
        int i, x;
        cout << "\nMENU\n";
        cout << "1.DISPLAY\n";
        cout << "2.SET\n";
        cout << "3.GET\n";
        cout << "4.APPEND\n";
        cout << "5.INSERT\n";
        cout << "6.SORT\n";
        cout << "7.LINEAR SEARCH\n";
        cout << "8.BINARY SEARCH\n";
        cout << "9.isSORTED?\n";
        cout << "10.MAX\n";
        cout << "11.MIN\n";
        cout << "12.SUM\n";
        cout << "13.AVERAGE\n";
        cout << "14.REVERSE\n";
        cout << "15.INSERT IN SORTED ARRAY\n";
        cout << "16.REARRANGE NEGATIVE AMD POSITIVE\n";
        cout << "17.DELETE\n";
        cout << "18.SORTED MERGE\n";
        cout << "19.UNION\n";
        cout << "20.INTERSECTION\n";
        cout << "21.SET DIFFERENCE\n";
        cout << "22.LEFT SHIFT\n";
        cout << "23.ROTATE\n";
        cout << endl
             << "CHOOSE ONE OPTION : ";
        cin >> ch;
        int *p;
        Array *arr2;

        switch (ch)
        {
        case 1:
            arr->display();
            break;
        case 2:
            cout << "ENTER INDEX : ";
            cin >> i;
            cout << "ENTER ELEMENT TO ADD : ";
            cin >> x;
            arr->set(i, x);
            break;
        case 3:
            cout << "ENTER INDEX : ";
            cin >> i;
            x = arr->get(i);
            if (x == -1)
                cout << "INDEX " << i << " IS EMPTY" << endl;
            else
            {
                cout << "ELEMENT AT INDEX = " << x << endl;
            }
            break;
        case 4:

            arr->append();
            break;
        case 5:
            cout << "ENTER INDEX : ";
            cin >> i;
            cout << "ENTER ELEMENT TO INSERT : ";
            cin >> x;
            arr->insert(i, x);
            break;
        case 6:
            arr->Sort();
            break;
        case 7:
            cout << "ENTER KEY : ";
            cin >> x;
            p = arr->LinearSearch(x);
            if (p[0] == -1)
                cout << "KEY NOT FOUND\n";
            else
            {
                for (int j = 0; p[j] != -1; j++)
                    cout << "KEY FOUND AT INDEX : " << p[j] << " ";
                cout << endl;
            }
            break;
        case 8:
            cout << "ENTER KEY : ";
            cin >> x;
            i = arr->BinarySearch(x);
            if (i == -1)
                cout << "KEY NOT FOUND\n";
            else
                cout << "KEY FOUND AT : " << i << endl;
            break;
        case 9:
            i = arr->isSorted();
            if (i == 1)
                cout << "ARRAY IS SORTED\n";
            else if (i == -1)
                cout << "ARRAY IS NOT SORTED\n";
            break;
        case 10:
            cout << "MAX ELEMENT : " << arr->Max() << endl;
            break;
        case 11:
            cout << "MIN ELEMENT : " << arr->Min() << endl;
            break;
        case 12:
            cout << "SUM OF ALL ELEMENTS : " << arr->Sum() << endl;
            break;
        case 13:
            cout << "AVERAGE OF ALL ELEMENTS : " << arr->Average() << endl;
            break;
        case 14:
            arr->Reverse();
            break;
        case 15:
            cout << "ENTER ELEMENT TO ADD : ";
            cin >> x;
            i = arr->InsertInSorted(x);
            if (i == 0)
                cout << "INSERTED IN SORTED ARRAY!\n";
            break;
        case 16:
            arr->negativerearrange();
            break;
        case 17:
            cout << "ENTER INDEX TO DELETE : ";
            cin >> i;
            arr->del(i);
            cout << "DELETED!" << endl;
            break;
        case 18:
            cout << "ENTER SIZE OF ARRAY : ";
            cin >> x;
            arr2 = new Array(x);
            cout << "ENTER ALL ELEMENTS!\n";
            for (int j = 0; j < x; j++)
            {
                arr2->append();
            }
            SortedMerge(arr, arr2);
            break;

        case 19:
            cout << "ENTER SIZE OF ARRAY : ";
            cin >> x;
            arr2 = new Array(x);
            cout << "ENTER ALL ELEMENTS!\n";
            for (int j = 0; j < x; j++)
            {
                arr2->append();
            }
            Union(arr, arr2);
            break;
        case 20:
            cout << "ENTER SIZE OF ARRAY : ";
            cin >> x;
            arr2 = new Array(x);
            cout << "ENTER ALL ELEMENTS!\n";
            for (int j = 0; j < x; j++)
            {
                arr2->append();
            }
            Intersection(arr, arr2);
            break;
        case 21:
            cout << "ENTER SIZE OF ARRAY : ";
            cin >> x;
            arr2 = new Array(x);
            cout << "ENTER ALL ELEMENTS!\n";
            for (int j = 0; j < x; j++)
            {
                arr2->append();
            }
            setDifference(arr, arr2);
            break;
        case 22:

            arr->leftshift();
            break;
        case 23:
            cout << "ENTER HOW MANY ELEMENTS TO ROTATE : " << endl;
            cin >> x;
            arr->rotate(x);
            break;
        default:
            cout << "WRONG INPUT, TRY AGAIN : ";
        }
    } while (ch != 19);
}