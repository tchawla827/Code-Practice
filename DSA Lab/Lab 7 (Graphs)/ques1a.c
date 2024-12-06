#include <stdio.h>
#include <stdlib.h>

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

    char x, y;
    for (int i = 0; i < e; i++)
    {
        printf("Enter Edge : ");
        scanf(" %c %c", &x, &y);

        G[x - 64][y - 64] = 1;
        G[y - 64][x - 64] = 1;

        printf("Edge %c%c added to the Graph\n", x, y);
    }
    return G;
}

void printGraph(int **G, int n)
{
    printf("  ");
    for (char i = 1; i < n + 1; i++)
    {
        printf("%c ", i + 64);
    }
    printf("\n");
    char c;
    for (int i = 1; i <= n; i++)
    {
        c = i;
        printf("%c ", c + 64);
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
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
    return 0;
}
