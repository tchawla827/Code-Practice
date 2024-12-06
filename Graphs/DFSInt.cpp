#include <iostream>
using namespace std;

int **AdjacencyMatrix(int n, int e)
{
    int **G = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        G[i] = new int[n + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            G[i][j] = 0;
        }
    }

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter Edge : ";
        cin >> x >> y;

        G[x][y] = 1;
        G[y][x] = 1;

        cout << "Edge " << x << y << " added to the Graph\n";
    }
    return G;
}

void printGraph(int **G, int n)
{
    cout << "  ";
    for (int i = 1; i < n + 1; i++)
    {
        cout << (i) << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {

        cout << i << " ";
        for (int j = 1; j <= n; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int **G, int n, int *visited, int start)
{
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (G[start][i] == 1 && visited[i] == 0)
            {
                DFS(G, n, visited, i);
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter Number of Vertices : ";
    cin >> n;
    cout << "Enter Number of Edges : ";
    cin >> e;
    cout << endl;

    int **G = AdjacencyMatrix(n, e);
    printGraph(G, n);
    cout << endl;

    cout << "Enter Starting Point of DFS : ";
    int start;
    cin >> start;

    int *visited = new int[n];
    for (int i = 1; i  <= n; i++)
        visited[i] = 0;

    DFS(G, n, visited, start);

    return 0;
}
