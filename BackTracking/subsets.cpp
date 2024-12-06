#include<bits/stdc++.h>
using namespace std;

void subsets(char * input, char * output,int i,int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        if(output[0]=='\0')
        cout<<"NULL"<<endl;
        for(int k=0;output[k]!='\0';k++)
        {
            cout<<output[k];
        }
        cout<<endl;
        return;
    }

    output[j]=input[i];
    //include i
    subsets(input,output,i+1,j+1);
    //exclude i
    subsets(input,output,i+1,j);
}

int main()
{
    int n;
    cin>>n;
    char * input=new char[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>input[i];
    }
    input[n]='\0';
  
  
    char * output=new char[n+1];

    subsets(input,output,0,0);
}