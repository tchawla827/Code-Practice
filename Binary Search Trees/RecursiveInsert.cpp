#include<bits/stdc++.h>
using namespace std;

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

node * InorderSucc(node * t)
{
    if(t->rchild!=NULL)
    {
    t=t->rchild;
    while(t->lchild!=NULL)
    {
        t=t->lchild;
    }
    return t;}
    else return t;
}

node * InorderPre(node * t)
{
    if(t->lchild!=NULL)
    {
    t=t->lchild;
    while(t->rchild!=NULL)
    {
        t=t->rchild;
    }
    return t;}
    else return t;
}

node * Search(node * p , int x)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(x==p->data)
    {
        return p;
    }
    else
    {
        if(x<p->data)
        {
            Search(p->lchild,x);
        }
        else if( x> p->data)
        {
            Search(p->rchild,x);
        }
    }
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

int Height(node* t)
{
    if(t!=NULL)
    {
        int x,y;
        x=Height(t->lchild);
        y=Height(t->rchild);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

node * Delete (node * root, int key, node * p)
{
    node *q;
    if(p==NULL)
        return NULL;

    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        delete p; 
        return NULL;
    }
    if(key<p->data)
    {
        p->lchild=Delete(root,key,p->lchild);
    }
    else if(key>p->data)
    {
        p->rchild=Delete(root,key,p->rchild);
    }
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InorderPre(p);
            p->data=q->data;
            p->lchild=Delete(root,q->data,p->lchild);
        }
        else
        {
            q=InorderSucc(p);
            p->data=q->data;
            p->rchild=Delete(root,q->data,p->rchild);
        }
    }
    return p;
}

node * RInsert(node * p, int key)
{
    node *t;
    if(p==NULL)
    {
        t=new node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    else
    {
        if(key<p->data)
        {
           p->lchild= RInsert(p->lchild,key);
        }
        else if(key>p->data)
        {
           p->rchild= RInsert(p->rchild,key);
        }
    }
    return p;
}




int main()
{
    Tree * t=new Tree;
    node * p;
    t->root=NULL;
    int key;
    int x;

    do{
        cout<<"\n0. Exit\n";
        cout<<"1. Insert\n";
        cout<<"2. Inorder Traversal\n";
        cout<<"3. Search in Tree\n";
        cout<<"4. Inorder Successor\n";
        cout<<"5. Inorder Predecessor\n";
        cout<<"6. Delete\n";
        cout<<"7. Recursive Insert\n";

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
            case 3 : cout<<"Enter Key : ";
                        cin>>x;
                        p=Search(t->root,x);
                        if(p==NULL)
                        cout<<"\nDoesnt Exist\n";
                        else
                        cout<<"\nExist\n";
                        break;
            case 4 : cout<<"Enter Element : ";
                        cin>>x;
                        if(Search(t->root,x)==NULL)
                        {
                            cout<<"\nEnter Valid Element\n";
                        }
                        else
                        {
                            p=InorderSucc(Search(t->root,x));
                            cout<<"Inorder Successor of "<<x<<" : "<<p->data;
                        }
                        cout<<endl;
                        break;
            case 5 :    cout<<"Enter Element : ";
                        cin>>x;
                        if(Search(t->root,x)==NULL)
                        {
                            cout<<"\nEnter Valid Element\n";
                        }
                        else
                        {
                            p=InorderPre(Search(t->root,x));
                            cout<<"Inorder Predecessor of "<<x<<" : "<<p->data;
                        }
                        cout<<endl;
                        break;
            case 6 :    cout<<"Enter Element to Delete : ";
                        cin>>x;
                        p=Delete(t->root,x,t->root);
                        if(p==NULL)
                        {
                            cout<<"\nEnter Valid Element !\n";
                        }
                        else
                        {
                            cout<<"\nDeleted\n";
                        }
                        break;
            case 7 :    cout<<"\nEnter Value : ";
                        cin>>x;
                        t->root=RInsert(t->root,x);
                        break;
            default : cout<<"\nWrong Input, Try Again!\n";

        }
    }while(key!=0);

}