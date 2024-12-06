#include<bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> n1, vector<int> n2)
{
    int l1=n1.size();
    int l2=n2.size();
    int i=0;int j=0;
    int carry=0;
    int sum=0;
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    vector<int> res;

    while(i<l1 && j<l2 )
    {
        sum=n1[i++]+n2[j++]+carry;
        res.push_back(sum%10);
        carry=sum/10;
    }

    while(i<l1)
    {
        res.push_back((carry+n1[i])%10);
        carry=(carry+n1[i++])/10;
    }

    while(j<l2)
    {
        res.push_back((carry+n2[j])%10);
        carry=(carry+n2[j++])/10;
    }
    if(carry!=0)
    res.push_back(carry);
    reverse(res.begin(),res.end());

    return res;

    
}

int main()
{
    vector <int> n1;
    vector <int> n2;
    int l1,l2,x;
    cout<<"Enter Length of First Integer : ";
    cin>>l1;
    cout<<"Enter First Number : ";
    for(int i=0;i<l1;i++)
    {
        cin>>x;
        n1.push_back(x);
    }
    cout<<"Enter Length of Second Integer : ";
    cin>>l2;
    cout<<"Enter Second Number : ";
    for(int i=0;i<l2;i++)
    {
        cin>>x;
        n2.push_back(x);
    }
    vector<int>res=add(n1,n2);

    cout<<"Sum : ";
    for(int x:res)
    {
        cout<<x<<" ";
    }
    cout<<endl;

}