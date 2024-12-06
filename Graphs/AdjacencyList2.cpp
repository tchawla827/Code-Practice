#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    string name;
    list<string> nbrs;  
    Node (string name)
    {
        this->name=name;
    }
};

class Graph{
    
    unordered_map<string,Node*> m;
    public:
    Graph(vector<string> cities)
    {
        for(auto city:cities)
        {
            m[city]=new Node(city);
        }
    }

    void addEdge(string i,string j, bool undir=true)
    {
        m[i]->nbrs.push_back(j);
        if(undir)
        m[j]->nbrs.push_back(i);
    }

    void printList()
    {
        for(auto x:m)
        {
            cout<<x.first<<"-->";
            for(auto y :x.second->nbrs)
            {
                cout<<y<<",";
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
    vector<string> cities(v);
    cout<<"Enter Cities\n";
    for(int i=0;i<v;i++)
    {
        cin>>cities[i];
    }

    Graph G(cities);
    
    int e;
    cout<<"Enter Number Of Edges : ";
    cin>>e;

    string i,j;
    cout<<"Enter Edges\n";

    for(int x=0;x<e;x++)
    {
        cin>>i>>j;
        G.addEdge(i,j);
    }

    G.printList();
}
