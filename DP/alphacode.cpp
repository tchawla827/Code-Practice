#include<bits/stdc++.h>
using namespace std;

int c=0;

void acode(vector<int> &a, int i,vector<char>& res,int j)
{
    c++;
    if(i>=a.size())
    {
        for(int k=0;k<j;k++)
        {
            cout<<res[k];
        }
        cout<<endl;
        return;
    }

    if(i+1<a.size() && a[i+1]==0 && (a[i]==1 || a[i]==2))
    {
        res[j]=96+a[i]*10;
        acode(a,i+2,res,j+1);
    }
    else
    {
        if(a[i]>0)
        {
            res[j]=96+a[i];
            acode(a,i+1,res,j+1);
        }
        if(i+1<a.size() && a[i+1]!=0 && a[i]*10 + a[i+1]<=26)
        {
            res[j]=a[i]*10+a[i+1]+96;
            acode(a,i+2,res,j+1);
        }
    }

    
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<char>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    acode(a,0,res,0);
    cout<<c<<endl;
}