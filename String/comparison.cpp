



















#include<iostream>
using namespace std;
#include<string>

int main()
{
    string s1;
    string s2;
    cout<<"ENTER STRING 1 : ";
    cin>>s1;
    cout<<"ENTER STRING 2 : ";
    cin>>s2;
    int length1;
    int length2;

    for(length1=0;s1[length1]!='\0';length1++)
    {

    }
    for(length2=0;s2[length2]!='\0';length2++)
    {

    }
    int i=0,j=0;
    int flag=-1;
    if(length1==length2)
    {
        for(int k=0;k<length1;k++)
        {   flag=-1;
            if(s1[i]>s2[j])
            {
                cout<<"STRING 1 IS LARGER"<<endl;
                flag=0;
                break;
            }
            else if(s1[i]<s2[j])
            {
                flag=0;
                cout<<"STRING 2 IS LARGER"<<endl;
                break;
            }
            else{
                i++;j++;
            }
        }
        if(flag==-1)
        {
            cout<<"STRINGS ARE EQUAL"<<endl;
        }
    }
}