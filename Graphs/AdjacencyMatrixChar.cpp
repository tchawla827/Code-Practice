#include<bits/stdc++.h>
using namespace std;

int ** AdjacencyMatrix(int n, int e)
{
    int ** G= new int *[n+1];
    for(int i=0;i<n+1;i++)
    {
        G[i]=new int[n+1];
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            G[i][j]=0;
        }
    }

    char x,y;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter Edge : ";
        cin>>x>>y;

        G[x-64][y-64]=1;
        G[y-64][x-64]=1;

        cout<<"Edge "<<x<<y<<" added to the Graph\n";
    }
    return G;
}

void printGraph(int **G,int n)
{
    cout<<"  ";
    for(char i=1;i<n+1;i++)
    {
        cout<<char(i+64) <<" " ;
    }
    cout<<endl;
    char c;
    for(int i=1;i<=n;i++)
    {   
        c=i;
        cout<<char(c+64) <<" ";
        for(int j=1;j<=n;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n,e;
    cout<<"Enter Number of Vertices : ";
    cin>>n;
    cout<<"Enter Number of Edges : ";
    cin>>e;
    cout<<endl;
    int **G=AdjacencyMatrix(n,e);
    printGraph(G,n);
}