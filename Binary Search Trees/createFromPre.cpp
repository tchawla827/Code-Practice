#include <iostream>

using namespace std;

struct nodeT {
    struct nodeT *lchild;
    struct nodeT *rchild;
    int data;
};

typedef struct nodeT nodeT;

typedef struct node {
    struct node *next;
    nodeT *data;
} node;

typedef struct {
    node *tos;
} stacks;

void push(stacks *s, nodeT *n) {
    node *p = new node;
    p->data = n;
    p->next = s->tos;
    s->tos = p;
}

nodeT *pop(stacks *s) {
    if (s->tos == NULL) {
        cout << "Stack Underflow!" << endl;
        return NULL;
    } else {
        nodeT *t = s->tos->data;
        node *q = s->tos;
        s->tos = q->next;
        delete q;
        return t;
    }
}

nodeT *createFromPre(int *pre, int n) {
    int i = 0;
    nodeT *root = new nodeT;
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;

    nodeT *t;
    nodeT *p = root;
    stacks s;
    s.tos=NULL;

    while (i < n) {
        if (pre[i] < p->data) {
            t = new nodeT;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&s, p);
            p = t;
        } else {
            if (pre[i] > p->data && (s.tos == NULL || pre[i] < s.tos->data->data)) {
                t = new nodeT;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            } else {
                p = pop(&s);
            }
        }
    }
    return root;
}

void inorder(nodeT *root) {
    if (root != NULL) {
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
}

int main() {
    int *pre;
    int n;
    cout << "Enter size of BST : ";
    cin >> n;
    pre = new int[n];
    cout << "Enter Preorder of BST : ";
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }

    nodeT *root = createFromPre(pre, n);

    cout << endl << "BST constructed successfully!" << endl;

    cout << "Inorder traversal of the constructed BST: ";
    inorder(root);
    cout << endl;

    // Free dynamically allocated memory
    delete[] pre;

    return 0;
}

