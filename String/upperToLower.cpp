#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout<<"ENTER STRING IN UPPER CASE : ";
    getline(cin,s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=65 && s[i]<=90)
        {
            s[i]+=32;
        }
    }
    cout<<"CONVERTED TO LOWER CASE!"<<endl;
    cout<<s<<endl;
}