#include<bits/stdc++.h>
using namespace std;

int BSIterative(vector<int>&a,int key)
{
    int s=0;
    int e=a.size()-1;
    int mid=(s+e)/2;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
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
    cout<<BSIterative(a,key)<<endl;
}