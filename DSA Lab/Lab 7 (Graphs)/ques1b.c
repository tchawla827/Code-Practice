#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

struct node **AdjacencyList(int n)
{
    struct node **L = (struct node **)malloc(n * sizeof(struct node *));

    for (int i = 0; i < n; i++)
    {
        L[i] = (struct node *)malloc(sizeof(struct node));
        L[i]->next = NULL;
    }
    return L;
}

void insertEdge(struct node **L, char v, char u)
{
    struct node *t1 = (struct node *)malloc(sizeof(struct node));
    t1->data = u;
    t1->next = NULL;
    struct node *p = L[v - 'A'];

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = t1;

    struct node *t2 = (struct node *)malloc(sizeof(struct node));
    t2->data = v;
    t2->next = NULL;
    p = L[u - 'A'];

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = t2;
    printf("Edge %c%c Added!\n", v, u);
}

void printList(struct node **L, int n)
{
    struct node *p;
    for (int i = 0; i < n; i++)
    {
        printf("%c->>", (char)(i + 'A'));
        p = L[i]->next;
        while (p != NULL)
        {
            printf("%c", p->data);
            if (p->next != NULL)
                printf("->");
            p = p->next;
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

    struct node **L = AdjacencyList(n);

    char x, y;
    for (int i = 0; i < e; i++)
    {
        printf("\nEnter Edge : ");
        scanf(" %c %c", &x, &y);
        insertEdge(L, x, y);
    }

    printf("\n");

    printList(L, n);
}
