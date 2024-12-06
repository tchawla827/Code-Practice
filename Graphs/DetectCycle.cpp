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

    int x,y;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter Edge : ";
        cin>>x>>y;

        G[x][y]=1;
        G[y][x]=1;

        cout<<"Edge "<<x<<y<<" added to the Graph\n";
    }
    return G;
}

void printGraph(int **G,int n)
{
    cout<<"  ";
    for(int i=1;i<n+1;i++)
    {
        cout<<(i) <<" " ;
    }
    cout<<endl;
    
    for(int i=1;i<=n;i++)
    {   
        
        cout<<i <<" ";
        for(int j=1;j<=n;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Union(int u, int v,int *S)
{
    if(S[u]<S[v])
    {
        S[u]+=S[v];
        S[v]=u;
    }
    else
    {
        S[v]+=S[u];
        S[u]=v;
    }
}

int Find(int u, int *S)
{
    int x=u;
    int v=0;

    while(S[x]>0)
    {
        x=S[x];
    }
    while(u!=x)
    {
        v=S[u];
        S[u]=x;
        u=v;
    }
    return x;
}

int DetectCycle(int **G, int n)
{
    int cycles=0;
    int u,v;
    int *set=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        set[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(G[i][j]==1)
            {
                u=Find(i,set);
                v=Find(j,set);
                if(u==v)
                {
                    cycles++;
                }
                else
                {
                    Union(u,v,set);
                }
            }
        }
    }
    return cycles;
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
    cout<<endl;
    printGraph(G,n);

    cout<<endl<<DetectCycle(G,n)<<" Cycles Detected! \n";
}