//IIT2023150 Tavish Chawla
#include <stdio.h>
#include <stdlib.h>

struct customer
{
    int n;
    int count;
    int ID;
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

customer *createCustomer(int ID, int n)
{
    customer *newCustomer = (customer *)malloc(sizeof(customer));
    newCustomer->ID = ID;
    newCustomer->n = n;
    newCustomer->count = 0;
    return newCustomer;
}

void enqueue(queue *q, customer *t)
{
    node *p = (node *)malloc(sizeof(node));
    p->c = t;
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

int dequeue(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    else
    {
        int x = q->front->c->ID;
        node *t = q->front;
        q->front = q->front->next;

        if (q->front == NULL)
        {
            q->rear = NULL;
        }

        free(t->c);
        free(t);
        return x;
    }
}

void circularDQ(queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        q->front->c->n--;
        node *p = q->front;
        q->front = q->front->next;
        p->next = NULL;

        if (q->front != NULL)
        {
            q->rear->next = p;
            q->rear = p;
        }
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
            printf("ID : %d , items left %d\n", p->c->ID, p->c->n - p->c->count);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    queue q;
    q.front = NULL;
    q.rear = NULL;
    int choice;
    int x;
    customer *t;

    do
    {
        printf("\n0.Exit\n");
        printf("1.New Customer\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");

        printf("\nEnter Your Choice : ");

        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 0:
            exit(1);
            break;

        case 1:
            printf("Enter ID : ");
            scanf("%d", &x);
            printf("Enter Number of Items to Buy : ");
            scanf("%d", &choice);
            t = createCustomer(x, choice);
            enqueue(&q, t);
            break;

        case 2:
            if (q.front->c->n == 1)
            {
                x = dequeue(&q);
                printf("Dequeued ID : %d\n", x);
            }
            else
            {

                printf("ID: %d , Items Left : %d\n", q.front->c->ID, q.front->c->n - q.front->c->count);
                circularDQ(&q);
            }
            break;
        case 3:
            displayQ(q);
            break;
        }
    } while (choice != 0);
}
