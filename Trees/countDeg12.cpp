#include<bits/stdc++.h>
using namespace std;

struct nodeTree {
    struct nodeTree *left;
    struct nodeTree *right;
    int data;
};

struct node {
    nodeTree *data;
    struct node *next;
};

typedef struct node node;

struct queuee {
    node *front;
    node *rear;
};

typedef struct queuee queuee;

void enqueue(queuee *q, nodeTree *x) {
    node *p = new node;
    p->data = x;
    p->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = p;
    } else {
        q->rear->next = p;
        q->rear = p;
    }
}

nodeTree *dequeue(queuee *q) {
    if (q->front == NULL) {
        cout << "Queue is Empty!" << endl;
        return NULL;
    } else {
        nodeTree *x = q->front->data;
        node *t = q->front;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        delete t;
        return x;
    }
}

nodeTree *createTree() {
    nodeTree *p;
    nodeTree *t;
    int x;
    queuee q;
    q.front = NULL;
    q.rear = NULL;
    nodeTree *root = new nodeTree;

    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x; // Fix: Assign the input value correctly
    root->left = nullptr;
    root->right = nullptr;
    enqueue(&q, root);

    while (q.front != NULL) {
        p = dequeue(&q);

        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new nodeTree;
            t->data = x; // Fix: Assign the input value correctly
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            enqueue(&q, t);
        }

        cout << "Enter right child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            t = new nodeTree;
            t->data = x; // Fix: Assign the input value correctly
            t->left = nullptr;
            t->right = nullptr;
            p->right = t;
            enqueue(&q, t);
        }
    }
    return root;
}

void preOrder(nodeTree *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int countDeg12(nodeTree * root)
{
    int lcount;
    int rcount;

    if(root!=NULL)
    {
        lcount=countDeg12(root->left);
        rcount=countDeg12(root->right);

        if( (root->left != NULL || root->right != NULL))
        return lcount+rcount+1;
        else
        return lcount+rcount;
    }
    return 0;
}

int main()
{
    nodeTree * root=createTree();
    preOrder(root);
    cout<<endl<<"number of Nodes : "<<countDeg12(root);
}