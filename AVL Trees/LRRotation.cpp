#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    node* left;
    node* right;
    int data;
    int height;
}node;

int nodeHeight(node *p)
{
    int hl,hr;

    if(p!=NULL && p->left!=NULL)
    {
        hl=p->left->height;
    }
    else
        hl=0;
    
    if(p!=NULL && p->right!=NULL)
    {
        hr=p->right->height;
    }
    else hr=0;

    if(hl>hr)
        return hl+1;
    else
        return hr+1;
}

int balancefactor(node *p)
{
    if(p==NULL)
        return 0;

    int hl, hr;
    hl=nodeHeight(p->left);
    hr=nodeHeight(p->right);
    
    return hl-hr;
}

node * LRRotation(node* root, node *A)
{
    node *B = A->left;
    node *C = B->right;

    B->right = C->left;
    A->left = C->right;
    C->left = B;
    C->right = A;

    A->height = nodeHeight(A);
    B->height = nodeHeight(B);
    C->height = nodeHeight(C);

    
    if (root == A)
        root = C;

    return C;
}
