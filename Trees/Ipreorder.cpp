#include<iostream>
using namespace std;

struct nodeTree
{
    struct nodeTree *left;
    struct nodeTree *right;
    int data;
};
typedef struct nodeTree nodeTree;

struct nodeStack
{
    struct nodeStack * next;
    nodeTree* data;
};
typedef struct nodeStack nodeStack;

struct stack
{
    nodeStack * tos;
};
typedef struct stack stack;

void push(stack *s, nodeTree* n)
{
    nodeStack *p = new nodeStack;
    p->data = n;
    p->next = s->tos;
    s->tos = p;

    printf("%d pushed to the stack successfully!\n", n);
}

nodeTree * pop(stack *s)
{
    if (s->tos == NULL)
    {
        printf("Stack Underflow!\n");
        return NULL;
    }
    else
    {
        nodeTree* t = s->tos->data;
        nodeStack *q = s->tos;
        s->tos = q->next;
        free(q);
        return t;
    }
}

void IPreorder(nodeTree* root)
{
    stack s;
    nodeTree*t=root;
    while(t!=NULL || s.tos!=NULL)
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            push(&s,t);
            t=t->left;
        }
        else
        {
            t=pop(&s);
            t=t->right;
        }
    }
}
