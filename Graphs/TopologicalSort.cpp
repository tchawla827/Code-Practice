#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    struct node * next;
    int data;
} node;

typedef struct {
    node * tos;
} stacks;


void push(stacks *s, int n)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = n;
    p->next = s->tos;
    s->tos = p;

    
}

int pop(stacks *s)
{
    if (s->tos == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int t = s->tos->data;
        node *q = s->tos;
        s->tos = q->next;
        free(q);
        return t;
    }
}


int **AdjacencyMatrix(int n, int e)
{
    int **G = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        G[i] = new int[n + 1]();
    }

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter Edge: ";
        cin >> x >> y;

        G[x][y] = 1;

        cout << "Edge " << x << "->" << y << " added to the graph\n";
    }
    return G;
}


void topologicalSort(int **G, int n, int *visited, int start, stacks *s)
{
    if (visited[start] == 0)
    {
        visited[start] = 1;

        for (int i = 1; i <= n; i++)
        {
            if (G[start][i] == 1 && visited[i] == 0)
            {
                topologicalSort(G, n, visited, i, s);
            }
        }
        push(s, start);  
    }
}

int main()
{
    int n, e;
    cout << "Enter Number of Vertices: ";
    cin >> n;
    cout << "Enter Number of Edges: ";
    cin >> e;

    int **G = AdjacencyMatrix(n, e);

    stacks s;  
    s.tos = NULL;  
    
    int *visited = new int[n + 1]();
    
    
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            topologicalSort(G, n, visited, i, &s);
        }
    }
    
    
    cout << "\nTopological Order: ";
    while (s.tos != NULL)
    {
        cout << pop(&s) << " ";
    }
    cout << endl;

    return 0;
}
