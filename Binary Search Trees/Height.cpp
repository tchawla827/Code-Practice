#include<bits/stdc++.h>
using namespace std;

int Height(node* t)
{
    if(t!=NULL)
    {
        int x,y;
        x=Height(t->left);
        y=Height(t->right);

        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}