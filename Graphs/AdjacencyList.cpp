#include<bits/stdc++.h>
using namespace std;

class Graphs
{
    int V;
    int E;

    list<int> *l;

    public:
    Graphs(int V)
    {
        this->V=V;
        l=new list<int> [V];
    }
    Graphs(int V,int E)
    {
        this->V=V;
        this->E=E;
        l=new list<int> [V];
    }

    void addEdge(int i,int j, bool undir=true)
    {
        l[i].push_back(j);
        if(undir)
        l[j].push_back(i);
    }

    void printList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"-->";
            for(auto x:l[i])
            {
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
};


int main()
{
    int v;
    cout<<"Enter Number of Vertices : ";
    cin>>v;

    Graphs G(v);
    
    int e;
    cout<<"Enter Number Of Edges : ";
    cin>>e;

    int i,j;
    cout<<"Enter Edges\n";

    for(int x=0;x<e;x++)
    {
        cin>>i>>j;
        G.addEdge(i,j);
    }

    G.printList();
}