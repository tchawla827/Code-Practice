#include<bits/stdc++.h>
using namespace std;

int BSFirstOccur(vector<int>&a,int key)
{
    int s=0;
    int e=a.size()-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            ans=mid;
            e=mid-1;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}

int BSLastOccur(vector<int>&a,int key)
{
    int s=0;
    int e=a.size()-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            ans=mid;
            s=mid+1;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int key;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"key : ";
    cin>>key;
    sort(a.begin(),a.end());
    int fo=BSFirstOccur(a,key);
    int lo=BSLastOccur(a,key);
    if(fo==-1)
    {
        cout<<"0"<<endl;
    }
    else
    {
        cout<<lo-fo+1<<endl;
    }
}