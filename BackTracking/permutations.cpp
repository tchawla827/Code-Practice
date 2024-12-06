#include <bits/stdc++.h>
using namespace std;

void permutations(string s, int l, int r)
{
    if(l==r)
    {
        cout<<s<<endl;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            permutations(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}

int main()
{

    string s;
    cin>>s;

    permutations(s, 0, s.size()-1);
}