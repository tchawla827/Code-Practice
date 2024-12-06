#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

typedef struct node node;

struct queue{
    node *front;
    node *rear;
};

typedef struct queue queue;

void enqueue(queue * q, int x)
{
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    if(q->rear==NULL)
    {
        q->front=q->rear=p;
    }
    else
    {
        q->rear->next=p;
        q->rear=p;
    }
}

int dequeue(queue*q)
{
    if(q->front==NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }
    else{
    int x=q->front->data;
    node *t=q->front;
    q->front=q->front->next;
    free(t);
    return x;}
}

void displayQ(queue q)
{
    if(q.front==NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }
    else
    {
        node *p=q.front;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}


int main()
{
    queue q;
    q.front=q.rear=NULL;
    int ch;
    int x;
    do{
        printf("\n0.Exit\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");

        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0: exit(1);
                    break;
            case 1 : printf("\nEnter data : ");
                     scanf("%d",&x);
                     enqueue(&q,x);
                     printf("Successful\n");
                     break;
            case 2 : x=dequeue(&q);
                     printf("Dequeued element : %d\n",x);
                     break;
            case 3 : displayQ(q);
                        break;
            default: printf("Invalid Choice, please try again\n");
    
        }    
    }while(ch!='0');

}