#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

struct queuee
{
    node *front;
    node *rear;
};

typedef struct queuee queuee;

void enqueue(queuee *q, int x)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = p;
    }
    else
    {
        q->rear->next = p;
        q->rear = p;
    }
}

int dequeue(queuee *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        int x = q->front->data;
        node *t = q->front;
        q->front = q->front->next;
        free(t);
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        return x;
    }
}

void displayQ(queuee q)
{
    if (q.front == NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }
    else
    {
        node *p = q.front;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

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
        cout << i << " ";
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

void BFS(int **G, int n, int start)
{
    queuee q;
    q.front = NULL;
    q.rear = NULL;
    static int *visited = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }

    enqueue(&q, start);
    visited[start] = 1;
    cout << start << " ";

    int x;
    while (q.front != NULL)
    {
        x = dequeue(&q);
        for (int i = 1; i <= n; i++)
        {
            if (G[x][i] == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
}

int detectCycleUsingDFS(int **G, int start, int n, int *visited, int *parent)
{
    
    if (visited[start] == 0)
    {
        visited[start] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (G[start][i] == 1)
            {
                if (visited[i] == 0)
                {
                    parent[i] = start;
                    if (detectCycleUsingDFS(G, i, n, visited, parent) == 1)
                       {
                        cout<<i<<" ";
                       } return 1;
                }
                else if (parent[start] != i)
                {
                    cout<<i<<" ";
                    return 1;
                }
            }
        }
    }
    return 0;
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
    cout << endl;
    printGraph(G, n);

    cout << endl;

    int start;
    cout << "Enter Starting point of BFS : ";
    cin >> start;
    cout << endl;
    

    int *visited = new int[n + 1];
    int *parent = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }
    if (detectCycleUsingDFS(G, start, n, visited, parent) == 1)
        cout << "\ncycle detected" << endl;
    else
        cout<<"\nNo Cycle\n";
}
