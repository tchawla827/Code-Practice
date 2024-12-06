#include<iostream>
using namespace std;

void permut(char s[], int r, int l, int h)
{
    int i;
    if(l==h)
    {
        for(int i=0;s[i]!='\0';i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            char temp=s[l];
            s[l]=s[i];
            s[i]=temp;
            permut(s,r,l+1,h);
             char temp=s[l];
            s[l]=s[i];
            s[i]=temp;
        }
    }
}