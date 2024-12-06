//IIT2023150 Tavish Chawla
#include <stdio.h>
#include <stdlib.h>

struct customer
{
    int id;
    int token;
};

typedef struct customer customer;

struct node
{
    customer *c;
    struct node *next;
};

typedef struct node node;

struct queue
{
    node *front;
    node *rear;
};

typedef struct queue queue;

void priorityEnqueue(queue *q, customer *t)
{
    node *p = (node *)malloc(sizeof(node));
    p->c = t;
    p->next = NULL;

    if (q->front == NULL)
    {
        q->front = q->rear = p;
    }
    else
    {
        node *s = q->front, *r = NULL;
        while (s != NULL && t->token > s->c->token)
        {
            r = s;
            s = s->next;
        }
        if (r == NULL)
        {
            p->next = q->front;
            q->front = p;
        }
        else
        {
            r->next = p;
            p->next = s;
        }
    }
}

int dequeue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else
    {
        int x = q->front->c->token;
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
            printf("Token : %d\n", p->c->token);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    queue q;
    q.front = q.rear = NULL;
    int choice;
    customer *t;
    do
    {
        printf("\n0.Exit\n");
        printf("1.New Customer\n");
        printf("2.Display\n");
        printf("3.Dequeue Customer\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            t = (customer *)malloc(sizeof(customer));
            printf("Enter CustomerID : ");
            scanf("%d", &t->id);
            printf("Enter Token : ");
            scanf("%d", &t->token);
            priorityEnqueue(&q, t);
            printf("Queued Successfully!\n");
            break;
        case 2:
            displayQ(q);
            break;
        case 3:
        {
            int x = dequeue(&q);
            if (x != -1)
            {
                printf("Token No. : %d Dequeued\n", x);
            }
            break;
        }
        case 0:
            exit(0);
        default:
            printf("Enter Valid Choice, please try again!\n");
        }
    } while (choice != 0);
    return 0;
}
