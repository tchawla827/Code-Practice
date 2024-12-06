#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;



int **AdjacencyMatrix(int n, int e)
{
    int **G = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i < n + 1; i++)
    {
        G[i] = (int *)malloc((n + 1) * sizeof(int));
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
        printf("Enter Edge : ");
        scanf("%d %d", &x, &y);

        G[x][y] = 1;
        G[y][x] = 1;

        printf("Edge %d %d added to the Graph\n", x, y);
    }
    return G;
}

void printGraph(int **G, int n)
{
    printf("  ");
    for (int i = 1; i < n + 1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
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
                        printf("%d ", i);
                        return 1;
                    }
                }
                else if (parent[start] != i)
                {
                    printf("%d ", i);
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
    printf("Enter Number of Vertices : ");
    scanf("%d", &n);
    printf("Enter Number of Edges : ");
    scanf("%d", &e);
    printf("\n");
    int **G = AdjacencyMatrix(n, e);
    printf("\n");
    printGraph(G, n);

    printf("\n");

    int start;
    printf("Enter Starting point  : ");
    scanf("%d", &start);
    printf("\n");

    int *visited = (int *)malloc((n + 1) * sizeof(int));
    int *parent = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
    }
    if (detectCycleUsingDFS(G, start, n, visited, parent) == 1)
        printf("\ncycle detected\n");
    else
        printf("\nNo Cycle\n");
   
}
