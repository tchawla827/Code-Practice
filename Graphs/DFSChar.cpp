#include <iostream>
using namespace std;

int **AdjacencyMatrix(int n, int e) {
    int **G = new int *[n];
    for (int i = 0; i < n; i++) {
        G[i] = new int[n];
        for (int j = 0; j < n; j++) {
            G[i][j] = 0;
        }
    }

    char x, y;
    for (int i = 0; i < e; i++) {
        cout << "Enter Edge : ";
        cin >> x >> y;

        G[x - 'A'][y - 'A'] = 1;
        G[y - 'A'][x - 'A'] = 1;

        cout << "Edge " << x << y << " added to the Graph\n";
    }
    return G;
}

void printGraph(int **G, int n) {
    cout << "  ";
    for (int i = 0; i < n; i++) {
        cout << char(i + 'A') << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << char(i + 'A') << " ";
        for (int j = 0; j < n; j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int **G, int n, int *visited, int start) {
    if (visited[start] == 0) {
        cout << char(start + 'A') << " ";
        visited[start] = 1;

        for (int i = 0; i < n; i++) {
            if (G[start][i] == 1 && visited[i] == 0) {
                DFS(G, n, visited, i);
            }
        }
    }
}

int main() {
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
    char start;
    cin >> start;

    int *visited = new int[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(G, n, visited, start - 'A');

    

    return 0;
}
