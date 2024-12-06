#include <bits/stdc++.h>
using namespace std;

class Graphs
{
    int V;
    int E;

    list<int> *l;

public:
    Graphs(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    Graphs(int V, int E)
    {
        this->V = V;
        this->E = E;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
            l[j].push_back(i);
    }

    void printList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            for (auto x : l[i])
            {
                cout << x << ",";
            }
            cout << endl;
        }
    }

    void BFS(int source)
    {
        int *visited = new int[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        queue<int> q;
        q.push(source);
        int x, y;

        while (!q.empty())
        {
            x = q.front();
            q.pop();
            visited[x]=1;
                cout << x << " ";
                for (auto y : l[x])
                {
                    if (visited[y] == 0)
                    {
                        q.push(y);
                        visited[y]=1;
                    }
                }
            
        }
        delete[] visited;
    }

    void DFS(int source, int *visited = nullptr)
    {
        bool createdLocally = false;
        if (visited == nullptr)
        {
            visited = new int[V]();
            createdLocally = true;
        }

        if (visited[source] == 0)
        {
            cout << source << " ";
            visited[source] = 1;

            for (auto x : l[source])
            {
                if (visited[x] == 0)
                {
                    DFS(x, visited);
                }
            }
        }

        if (createdLocally)
        {
            delete[] visited;
        }
    }

    void SSSPbfs(int source, int dest)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }

        q.push(source);
        visited[source] = true;
        parent[source] = source;
        dist[source] = 0;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);

                    parent[nbr] = f;
                    dist[nbr] = dist[f] + 1;
                    visited[nbr] = true;
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            cout << "Shortest dist to " << i << " is " << dist[i] << endl;
        }

        if (dest != -1)
        {
            int temp = dest;
            while (temp != source)
            {
                cout << temp << "-- ";
                temp = parent[temp];
            }
            cout << source << endl;
        }
    }
};

int main()
{
    int v;
    cout << "Enter Number of Vertices : ";
    cin >> v;

    Graphs G(v);

    int e;
    cout << "Enter Number Of Edges : ";
    cin >> e;

    int i, j;
    cout << "Enter Edges\n";

    for (int x = 0; x < e; x++)
    {
        cin >> i >> j;
        G.addEdge(i, j);
    }
    
    G.BFS(1);
    cout<<endl;
    G.SSSPbfs(1, 5);
}