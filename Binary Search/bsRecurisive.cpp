#include<bits/stdc++.h>
using namespace std;

int BSRecursive(vector<int>&a,int key,int s, int e)
{
    if(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]>key)
        
        {
            return BSRecursive(a,key,s,mid-1);
        }
        else if(a[mid]<key)
        {
            return BSRecursive(a,key,mid+1,e);
        }
        else
        {
            return mid;
        }
    }
    return -1;

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
    cout<<BSRecursive(a,key,0,n-1)<<endl;
}