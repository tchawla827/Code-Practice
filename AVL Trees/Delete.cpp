#include <iostream>
using namespace std;

struct node
{
    node *left;
    node *right;
    int data;
    int height;
};

int nodeHeight(node *p)
{
    if (p == nullptr)
        return 0;
    int hl = (p->left != nullptr) ? p->left->height : 0;
    int hr = (p->right != nullptr) ? p->right->height : 0;
    return max(hl, hr) + 1;
}

int balancefactor(node *p)
{
    if (p == nullptr)
        return 0;
    return nodeHeight(p->left) - nodeHeight(p->right);
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
    if (p == nullptr)
    {
        node *t = new node;
        t->data = key;
        t->left = t->right = nullptr;
        t->height = 1;
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
    if (p == nullptr || p->data == x)
        return p;
    if (x < p->data)
        return Search(p->left, x);
    return Search(p->right, x);
}

void inorder(node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

node *InorderSucc(node *t)
{
    if (t->right != NULL)
    {
        t = t->right;
        while (t->left != NULL)
        {
            t = t->left;
        }
        return t;
    }
    else
        return t;
}

node *InorderPre(node *t)
{
    if (t->left != NULL)
    {
        t = t->left;
        while (t->right != NULL)
        {
            t = t->right;
        }
        return t;
    }
    else
        return t;
}

int Height(node *t)
{
    if (t != NULL)
    {
        int x, y;
        x = Height(t->left);
        y = Height(t->right);

        if (x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

node *Delete(node *root, int key, node *p)
{
    node *q;
    if (p == NULL)
        return NULL;

    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if (key < p->data)
    {
        p->left = Delete(root, key, p->left);
    }
    else if (key > p->data)
    {
        p->right = Delete(root, key, p->right);
    }
    else
    {
        if (Height(p->left) > Height(p->right))
        {
            q = InorderPre(p);
            p->data = q->data;
            p->left = Delete(root, q->data, p->left);
        }
        else
        {
            q = InorderSucc(p);
            p->data = q->data;
            p->right = Delete(root, q->data, p->right);
        }
    }

    int bf = balancefactor(p);

    if (bf == 2 && balancefactor(p->left) == 1)
        return LLRotation(root, p);
    else if (bf == 2 && (balancefactor(p->left) == -1 || balancefactor(p->left) == 0))
        return LRRotation(root, p);
    else if (bf == -2 && balancefactor(p->right) == -1)
        return RRRotation(root, p);
    else if (bf == -2 && (balancefactor(p->right) == 1 || balancefactor(p->right) == 0))
        return RLRotation(root, p);

    return p;
}

int main()
{
    node *root = nullptr;
    int key, choice;
    do
    {
        cout << "\nAVL Tree Menu:\n";
        cout << "-1. Exit\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Balance Factor\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Delete\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case -1:
            cout << "Exiting program...\n";
            exit(0);
        case 1:
            cout << "Enter the key to insert: ";
            cin >> key;
            root = RInsert(root, key, root);
            cout << "Node inserted successfully.\n";
            break;
        case 2:
            cout << "\nEnter Key : ";
            cin >> key;
            if (Search(root, key) == nullptr)
                cout << "Doesn't Exist\n";
            else
                cout << "Exists\n";
            break;
        case 3:
            cout << "\nEnter Key : ";
            cin >> key;
            if (Search(root, key) == nullptr)
                cout << "Enter Valid Key\n";
            else
                cout << "Balance Factor of " << key << " : " << balancefactor(Search(root, key)) << endl;
            break;
        case 4:
            cout << "\nInorder Traversal : ";
            inorder(root);
            cout << endl;
            break;
        case 5:
            cout << "\nEnter Key to delete: ";
            cin >> key;
            root = Delete(root, key, root);
            cout << "Node deleted successfully.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != -1);

    return 0;
}
