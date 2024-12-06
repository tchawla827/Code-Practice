#include<bits/stdc++.h>
using namespace std;

typedef struct{
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