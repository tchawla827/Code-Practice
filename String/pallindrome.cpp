#include<iostream>
#include<string>
using namespace std;
int main()
{
    int flag=-1;
    string s;
    cout<<"ENTER STRING : ";
    getline(cin,s);

    int length;
    for(length=0;s[length]!='\0';length++)
    {

    }
    for(int i=0;i<length/2;i++)
    {
        if(s[i]!=s[length-1-i])
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
    cout<<"IT IS NOT A PALLINDROME"<<endl;
    else
    cout<<"IT IS A PALLINDROME"<<endl;
}