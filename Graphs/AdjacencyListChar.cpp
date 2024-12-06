#include<bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node* next;
};

node** AdjacencyList(int n)
{
    node** L = new node*[n];
    
    for(int i = 0; i < n; i++)
    {
        
        L[i] = new node;
        L[i]->next = NULL;
    }
    return L;
}

void insertEdge(node** L, char v, char u)
{
    node* t1 = new node;
    t1->data = u;
    t1->next = NULL;
    node* p = L[v - 'A']; 
    
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = t1;

    node* t2 = new node;
    t2->data = v;
    t2->next = NULL;
    p = L[u - 'A']; 
    
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = t2;
    cout<<"Edge "<<v<<u<<" Added!\n";
}

void printList(node** L, int n)
{
    node* p;
    for(int i = 0; i < n; i++)
    {
        cout << char(i + 'A') << "->>";
        p = L[i]->next;
        while(p != NULL)
        {
            cout << p->data;
            if(p->next != NULL)
                cout << "->";
            p = p->next;
        }
        cout << endl;
    }
}


int main()
{
    int n, e;
    cout << "Enter Number of Vertices : ";
    cin >> n;
    cout << "Enter Number of Edges : ";
    cin >> e;

    node** L = AdjacencyList(n);
    
    char x, y;
    for(int i = 0; i < e; i++)
    {
        cout << "\nEnter Edge : ";
        cin >> x >> y;
        insertEdge(L, x, y);
    }

    cout << endl;

    printList(L, n);

    

    return 0;
}
