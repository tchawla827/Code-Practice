//IIT2023150 Tavish Chawla
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

typedef struct node node;

struct queue
{
    node *front;
    node *rear;
};

typedef struct queue queue;

void enqueue(queue *q, char x)
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

char dequeue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty!\n");
        exit(1);
    }
    else
    {
        char x = q->front->data;
        node *t = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        free(t);
        return x;
    }
}

void displayQ(queue q)
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
            printf("%c ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    queue q1, q2;
    q1.front = q1.rear = NULL;
    q2.front = q2.rear = NULL;
    printf("Enter your string here : ");
    char A[100];
    scanf("%s", A);
    int i;
    int flag = 0;

    int l = 0;
    for (l; A[l] != '\0'; l++)
    {
    }

    if (l % 2 != 0)
    {
        printf("String is not of the type wwr\n");
        exit(1);
    }
    else
    {
        for (i = 0; i < l / 2; i++)
        {
            enqueue(&q1, A[i]);
        }
        for (i = l - 1; i >= l / 2; i--) 
        {
            enqueue(&q2, A[i]);
        }

        flag = 0;
        char a, b;
        while (q1.front != NULL && q2.front != NULL)
        {
            a = dequeue(&q1);
            b = dequeue(&q2);
            if (a != b)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1 || (q1.front != NULL || q2.front != NULL))
        {
            printf("\nString is not of the type wwr\n");
        }
        else
        {
            printf("\nString is of the type wwr\n");
        }

        return 0;
    }
}
