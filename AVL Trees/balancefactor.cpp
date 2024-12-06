#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    node *left;
    node *right;
    int data;
    int height;
} node;

int nodeHeight(node *p)
{

    if(p==NULL)//new
        return 0;
    
    int hl, hr;


    if (p != NULL && p->left != NULL)
    {
        hl = p->left->height;
    }
    else
        hl = 0;

    if (p != NULL && p->right != NULL)
    {
        hr = p->right->height;
    }
    else
        hr = 0;

    if (hl > hr)
        return hl + 1;
    else
        return hr + 1;


}

int balancefactor(node *p)
{
    if (p == NULL)
        return 0;

    int hl, hr;
    hl = nodeHeight(p->left);
    hr = nodeHeight(p->right);

    return hl - hr;
}

node *LLRotation(node *root, node *A)
{
    node *B = A->left;
    A->left = B->right;
    B->right = A;

    A->height = nodeHeight(A);
    B->height = nodeHeight(B);

    if (root == A)
        root = B;

    return B;
}

node *RRRotation(node *root, node *A)
{
    node *B = A->right;
    A->right = B->left;
    B->left = A;

    A->height = nodeHeight(A);
    B->height = nodeHeight(B);

    if (A == root)
        root = B;

    return B;
}

node *LRRotation(node *root, node *A)
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

node *RLRotation(node *root, node *A)
{
    node *B = A->right;
    node *C = B->left;

    B->left = C->right;
    A->right = C->left;
    C->right = B;
    C->left = A;

    A->height = nodeHeight(A);
    B->height = nodeHeight(B);
    C->height = nodeHeight(C);

    if (root == A)
        root = C;

    return C;
}

node *RInsert(node *p, int key, node *root)
{
    node *t = NULL;

    if (p == NULL)
    {
        t = new node;
        t->data = key;
        t->left = t->right = NULL;
        t->height = nodeHeight(t);
        return t;
    }

    if (key < p->data)
    {
        p->left = RInsert(p->left, key, root);
    }
    else if (key > p->data)
    {
        p->right = RInsert(p->right, key, root);
    }

    p->height = nodeHeight(p);

    int bf = balancefactor(p);

    if (bf == 2 && balancefactor(p->left) == 1)
        return LLRotation(root, p);
    else if (bf == 2 && balancefactor(p->left) == -1)
        return LRRotation(root, p);
    else if (bf == -2 && balancefactor(p->right) == -1)
        return RRRotation(root, p);
    else if (bf == -2 && balancefactor(p->right) == 1)
        return RLRotation(root, p);

    return p;
}


node *Search(node *p, int x)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (x == p->data)
    {
        return p;
    }
    else
    {
        if (x < p->data)
        {
            return Search(p->left, x);
        }
        else if (x > p->data)
        {
            return Search(p->right, x);
        }
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    node *root = NULL;
    node *p;
    int key;
    int choice;
    do
    {

        cout << "\nAVL Tree Menu:\n";
        cout << "-1. Exit\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout<< "3. Balance Factor\n";
        cout<< "4. Inorder Traversal\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case -1:
            cout << "Exiting program...\n";
            exit(0);
            break;
        case 1:
            
            cout << "Enter the key to insert: ";
            cin >> key;
            root = RInsert(root, key, root);
            cout << "Node inserted successfully.\n";
            break;
        case 2:
            cout<<"\nEnter Key : ";
            cin>>key;
            p=Search(root,key);
            if(p==NULL)
                cout<<"Doesnt Exist\n";
            else
                cout<<"Exists\n";
            break;
        case 3: 
            cout<<"\nEnter Key : ";
            cin>>key;
            p=Search(root,key);
            if(p==NULL)
                cout<<"Enter Valid Key\n";
            else
                cout<<"Balance Factor of "<<key<<" : "<<balancefactor(p)<<endl;
                break;
        case 4:
            cout<<"\nInorder Traversal : ";
            inorder(root);
            cout<<endl;
            break;
            
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != -1);

    return 0;
}