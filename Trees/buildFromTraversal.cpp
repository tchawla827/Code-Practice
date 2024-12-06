#include<bits/stdc++.h>
using namespace std;

struct nodeT
{
    struct nodeT *left;
    struct nodeT *right;
    char data;
};
typedef struct nodeT nodeT;

int search(char arr[], int start, int end, char value)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

nodeT *newNode(char data)
{
    nodeT *t = new nodeT;
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}

nodeT* buildTree(char in[], char pre[], int instart, int inend)
{
    static int preIndex = 0;
    if (instart > inend)
        return NULL;

    nodeT* tNode = newNode(pre[preIndex++]);

    if (instart == inend)
        return tNode;

    int inIndex = search(in, instart, inend, tNode->data);

    tNode->left = buildTree(in, pre, instart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inend);

    return tNode;
}


void preOrder(nodeT *root)
{
    if (root != NULL)
    {
        cout << root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Inorder(nodeT *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data<<" ";
        Inorder(root->right);
    }
}

int main()
{
    cout<<"Enter number of nodes : ";
    int n;
    cin>>n;
    char *in=new char[n];
    char *pre=new char[n];
    cout<<"Enter Inorder Traversal : ";
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    cout<<"Enter Preorder Traversal : ";
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }

    nodeT * root=buildTree(in,pre,0,n-1);
    cout<<endl;

    cout<<"PreOrder : ";
    preOrder(root);
    cout<<endl;
    cout<<"Inorder : ";
    Inorder(root);
}