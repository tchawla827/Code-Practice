#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"ENTER STRING : ";
    getline(cin,s);

    int length;
    for(length=0;s[length]!='\0';length++)
    {

    }
    for(int i=0;i<length/2;i++)
    {
        swap(s[i],s[length-1-i]);
    }
    
    cout<<"REVERSED STRING : "<<s<<endl;
}