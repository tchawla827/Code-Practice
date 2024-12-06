#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *next;
    int data;
}node;

typedef struct queue{
    node * front;
    node * rear;
}queue;

void enqueue(queue * q, int x)
{
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    q->front=p;
}

int dequeue(queue *q)
{
    if(q->rear==q->front)
    printf("Queue is Empty!\n");
    else{

    }
}