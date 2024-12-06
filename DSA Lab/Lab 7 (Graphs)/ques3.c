#include <stdio.h>
#include <stdlib.h>

int **AdjacencyMatrix(int n, int e) {
    int **G = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        G[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            G[i][j] = 0;
        }
    }

    char x, y;
    for (int i = 0; i < e; i++) {
        printf("Enter Edge : ");
        scanf(" %c %c", &x, &y);

        G[x - 'A'][y - 'A'] = 1;
        G[y - 'A'][x - 'A'] = 1;

        printf("Edge %c%c added to the Graph\n", x, y);
    }
    return G;
}

void printGraph(int **G, int n) {
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%c ", i + 'A');
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < n; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void DFS(int **G, int n, int *visited, int start) {
    if (visited[start] == 0) {
        printf("%c ", start + 'A');
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
    printf("Enter Number of Vertices : ");
    scanf("%d", &n);
    printf("Enter Number of Edges : ");
    scanf("%d", &e);
    printf("\n");

    int **G = AdjacencyMatrix(n, e);
    printGraph(G, n);
    printf("\n");

    printf("Enter Starting Point of DFS : ");
    char start;
    scanf(" %c", &start);

    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(G, n, visited, start - 'A');

    return 0;
}
