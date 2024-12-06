#include <bits/stdc++.h>
using namespace std;

int chartoint(char x)
{
    return x - '0';
}
char inttochar(int x)
{
    return x + '0';
}

string multiply(string a, int b)
{
    reverse(a.begin(),a.end());
    string res;

    int prod=0;
    int carry=0;

    for(int i=0;i<a.size();i++)
    {
        prod=(chartoint(a[i])*b)+carry;
        res.push_back(inttochar((prod)%10));
        carry=prod/10;
    }

    while(carry!=0)
    {
        res.push_back(inttochar((carry%10)));
        carry=carry/10;
    }

    reverse(res.begin(),res.end());

    return res;
}

int main()
{
    string s; int x;
    cin>>s;
    cin>>x;
    cout<<endl;
    cout<<multiply(s,x)<<endl;
}