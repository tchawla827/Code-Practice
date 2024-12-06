#include <iostream>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node node;

void preOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int *retPreOrder(node *root, int size)
{
    static int i = 0;
    static int *A = new int[size];
    if (i == size)
    {
        return A;
    }
    else
    {
        if(root!=NULL)
        {
        int x = root->data;
        A[i++] = x;
        retPreOrder(root->left, size);
        retPreOrder(root->right, size);
        }
    }
}