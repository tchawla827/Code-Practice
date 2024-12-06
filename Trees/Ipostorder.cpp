#include <iostream>
using namespace std;

struct nodeTree {
    struct nodeTree *left;
    struct nodeTree *right;
    int data;
};

typedef struct nodeTree nodeTree;

struct nodeStack {
    struct nodeStack *next;
    void* data;
};

typedef struct nodeStack nodeStack;

struct stack {
    nodeStack *tos;
};

typedef struct stack stack;

void push(stack *s, void* n) {
    nodeStack *p = new nodeStack;
    p->data = n;
    p->next = s->tos;
    s->tos = p;

    cout << *(int*)n << " pushed to the stack successfully!\n";
}

void* pop(stack *s) {
    if (s->tos == NULL) {
        cout << "Stack Underflow!\n";
        return NULL;
    }
    else {
        void* t = s->tos->data;
        nodeStack *q = s->tos;
        s->tos = q->next;
        delete q; // Free memory
        return t;
    }
}

void IPostorder(nodeTree* root) {
    stack s;
    s.tos = NULL;

    nodeTree* t = root;
    long int temp;

    while (t != NULL || s.tos != NULL) {
        if (t != NULL) {
            push(&s, (void*)t);
            t = t->left;
        }
        else {
            temp = (long int)pop(&s);
            if (temp > 0) {
                push(&s, (void*)(-temp));
                t = ((nodeTree*)temp)->right;
            }
            else {
                cout << ((nodeTree*)-temp)->data << " ";
                t = NULL;
            }
        }
    }
}