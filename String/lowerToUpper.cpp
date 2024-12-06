#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout<<"ENTER STRING IN LOWER CASE : ";
    getline(cin,s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=97 && s[i]<=122)
        {
            s[i]-=32;
        }
    }
    cout<<"CONVERTED TO UPPER CASE!"<<endl;
    cout<<s<<endl;
}
