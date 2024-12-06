
#include<stdio.h>
#include<stdlib.h>

struct nodeTree{
    struct nodeTree * left;
    int value;
    struct nodeTree * right;
};
typedef struct nodeTree nodeTree;

void preOrder(nodeTree *t)
{
    if(t!=NULL)
    {
        printf("%d ",t->value);
        preOrder(t->left);
        preOrder(t->right);
    }
}

int main()
{
    nodeTree * root=(nodeTree*)malloc(sizeof(nodeTree));
    root->value=17;

    nodeTree* lev11=(nodeTree*)malloc(sizeof(nodeTree));
    lev11->value=15;

    nodeTree *lev12=(nodeTree *)malloc(sizeof(nodeTree));
    lev12->value=13;
    
    nodeTree *lev21=(nodeTree*)malloc(sizeof(nodeTree));
    lev21->value=9;

    nodeTree *lev22=(nodeTree *)malloc(sizeof(nodeTree));
    lev22->value=6;

    nodeTree *lev23=(nodeTree *)malloc(sizeof(nodeTree));
    lev23->value=5;

    nodeTree* lev24=(nodeTree *)malloc(sizeof(nodeTree));
    lev24->value=10;

    nodeTree *lev31=(nodeTree *)malloc(sizeof(nodeTree));
    lev31->value=4;

    nodeTree* lev32=(nodeTree *)malloc(sizeof(nodeTree));
    lev32->value=8;

    nodeTree *lev33=(nodeTree *)malloc(sizeof(nodeTree));
    lev33->value=3;

    nodeTree *lev34=(nodeTree *)malloc(sizeof(nodeTree));
    lev34->value=1;

    root->left=lev11;
    root->right=lev12;

    lev11->left=lev21;
    lev11->right=lev22;

    lev21->left=lev31;
    lev21->right=lev32;

    lev22->left=lev33;
    lev22->right=lev34;

    lev12->left=lev23;
    lev12->right=lev24;
    

    lev31->left=lev31->right=lev32->left=lev32->right=lev33->left=lev33->right=lev34->left=lev34->right=NULL;
    lev23->left=lev23->right=lev24->left=lev24->right=NULL;
    return 0;
}
