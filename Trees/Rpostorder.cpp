#include <iostream>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node node;

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

int *retPostorder(node *root, int size)
{
    static int i = 0;
    static int *A = new int[size];
    if (i == size)
    {
        return A;
    }
    else
    {
        if (root != NULL)
        {
            retPostorder(root->left, size);
            retPostorder(root->right, size);
            int x = root->data;
            A[i++] = x;
        }
    }
}