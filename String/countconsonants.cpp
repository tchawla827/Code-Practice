#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout << "ENTER STRING : ";
    getline(cin, s);
    int c=0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
        continue;
        else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
        c++;
    }
    cout<<"NUMBER OF CONSONANTS : "<<c<<endl;
}