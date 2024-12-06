#include<bits/stdc++.h>
using namespace std;

struct node
{
    struct node * lchild;
    struct node * rchild;
    int data;
};
typedef struct node node;

struct Tree
{
    node* root;
};
typedef struct Tree Tree;

void Insert(Tree * t, int x)
{
    node *p=new node;
    p->data=x;
    p->lchild=NULL;
    p->rchild=NULL;
    
    if(t->root==NULL)
    {
        t->root=p;
        cout<<endl<<x<<" Added to the Tree\n";
    }
    else
    {
        int flag=0;
        node *q=t->root;
        node *r;
        while(q!=NULL)
        {
            r=q;
            if(x<q->data)
            {
                q=q->lchild;
            }
            else if(x>q->data)
            {
                q=q->rchild;
            }
            else if(x==q->data)
                {flag=1;
                break;}
        }

        if(flag==1)
        {
            cout<<x<<" is already in the TREE \n";
        }
        else{
        if(x<r->data)
            r->lchild=p;
        else if(x>r->data)
            r->rchild=p;
            cout<<endl<<x<<" Added to the Tree\n";
    }}
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        cout<<root->data<< " ";
        inorder(root->rchild);
    }
}

int main()
{
    Tree * t=new Tree;
    t->root=NULL;
    int key;
    int x;

    do{
        cout<<"\n0. Exit\n";
        cout<<"1. Insert\n";
        cout<<"2. Inorder Traversal\n";

        cout<<"\nEnter Your Choice : ";
        cin>>key;
        
        switch(key)
        {
            case 0 : cout<<"\nThankYou\n";
                        exit(1);break;
            case 1 : cout<<"\nEnter Value : ";
                     cin>>x;
                     Insert(t,x);
                     
                     break;
            case 2 : cout<<"\nInorder Traversal of Tree : ";
                        inorder(t->root);
                        cout<<endl;
                        break;
            default : cout<<"\nWrong Input, Try Again!\n";

        }
    }while(key!=0);

}