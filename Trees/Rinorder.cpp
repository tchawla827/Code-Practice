#include <iostream>
using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node node;

void Inorder(node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data;
        Inorder(root->right);
    }
}

int *retInorder(node *root, int size)
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
            retInorder(root->left, size);
            int x = root->data;
            A[i++] = x;
            retInorder(root->right, size);
        }
    }
}

int *retInorder(node *root, int size)
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
            retInorder(root->left, size);
            int x = root->data;
            A[i++] = x;
            retInorder(root->right, size);
        }
    }
}