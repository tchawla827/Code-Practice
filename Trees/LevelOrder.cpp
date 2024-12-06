#include<bits/stdc++.h>
using namespace std;

struct nodeTree
{
    struct nodeTree *left;
    struct nodeTree *right;
    int data;
};
typedef struct nodeTree nodeTree;

struct node{
    nodeTree* data;
    struct node *next;
};

typedef struct node node;

struct queuee{
    node *front;
    node *rear;
};

typedef struct queuee queuee;

void enqueue(queuee * q, nodeTree* x)
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

nodeTree*  dequeue(queuee*q)
{
    if(q->front==NULL)
    {
        printf("queue is Empty!\n");
        return;
    }
    else{
    nodeTree * x=q->front->data;
    node *t=q->front;
    q->front=q->front->next;
    free(t);
    return x;}
}


void LevelOrder(nodeTree* root)
{
    queuee q;
    q.front=NULL;
    q.rear=NULL;
    cout<<root->data<<" ";
    enqueue(&q,root);

    while(q.front!=NULL)
    {
        root=dequeue(&q);

        if(root->left)
        {
            cout<<root->left->data<<" ";
            enqueue(&q,root->left);
        }
        if(root->right)
        {
            cout<<root->right->data<<" ";
            enqueue(&q,root->right);
        }
    }
}
