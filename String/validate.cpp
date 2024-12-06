#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<"A STRING IS VALID ONLY IF IT CONTAINS LETTERS AND NUMBERS BOTH AND MUST BE MINIMUM OF 8 CHARACTERS"<<endl;
    string s;
    cout << "ENTER STRING : ";
    getline(cin, s);
    
    int cno=0;
    int calpha=0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>=48 && s[i]<=57)
        cno++;
        else if((s[i]>=65 && s[i]<=90) ||(s[i]>=97 && s[i]<=122) )
        calpha++;
    }

    if(cno>0 && calpha>0 && cno+calpha>=8)
    cout<<"STRING IS VALID "<<endl;
    else
    cout<<"STRING IS INVALID "<<endl;

}