#include<bits/stdc++.h>
using namespace std;

void generateBrackets(int n,int open,int close,int pos,char *result)
{
    if(open==n && close==n)
    {
        for(int i=0;i<2*n;i++)
        {
            cout<<result[i];
        }
        cout<<endl;
        return;
    }
    
    if(open>close)
    {
        result[pos]=')';
        generateBrackets(n,open,close+1,pos+1,result);
    }

    if(open<n)
    {
        result[pos]='(';
        generateBrackets(n,open+1,close,pos+1,result);
    }

}

int main()
{
    int n;
    cin>>n;
    char *res=new char[2*n];
    generateBrackets(n,0,0,0,res);
}