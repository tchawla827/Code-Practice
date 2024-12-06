#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"ENTER STRING : ";
    getline(cin,s);
    cout<<endl<<"LENGTH OF STRING IS : "<<s.length()<<endl;

    int i;
    for(i=0;s[i]!='\0';i++)
    {

    }
    cout<<"LENGTH OF STRING IS : "<<i<<" USING LOOP"<<endl;
}
