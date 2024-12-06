#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int length(char *c)
{
    int i;
    for(i=0;c[i]!='\0';i++)
    {

    }
    return i;
}

void permut(string c, int k,int r)
{
    static int A[10]={0};
    static char Res[10];
    int i;
    if(k==r)
    {
        Res[k]='\0';
        for(int i=0;i<r;i++)
        cout<<Res[i];
        cout<<endl;
    }
    else
    {
        for(i=0;c[i]!='\0';i++)
        {if(A[i]==0)
        {
            A[i]=1;
            Res[k]=c[i];
            permut(c,k+1,r);
            A[i]=0;
        }}
    }
}
    
int main()
{
    cout<<"Enter string : ";
    string c;
    cin>>c;
    int R;
    cout<<"Enter R : ";
    cin>>R;
    permut(c,0,R);
}