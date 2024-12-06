#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout << "ENTER STRING : ";
    getline(cin, s);

    int cspace = 0;
    
    int alpha=0;
    int flag=-1;
   
    for (int i = 0; s[i]!='\0'; i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {alpha++;break;}
    }
    

    for (int i = 1; s[i] != '\0'; i++)
    {
        flag=-1;
        if (s[i] == ' ' && s[i - 1] != ' ')
            flag=1;

        if(flag==1)
        {for(int j=i+1;s[j]!='\0';j++)
        {
            if ((s[j] >= 65 && s[j] <= 90) || (s[j] >= 97 && s[j] <= 122))
            {cspace++;break;}
        }}
    }

    

    if (cspace  ==0 && alpha==0)
        cout << "NUMBER OF WORDS = 0" << endl;
    
    else if(cspace==0 && alpha>0)
    {
         cout << "NUMBER OF WORDS = 1" << endl;
    }
    else
    {
        cout << "NUMBER OF WORDS = " << cspace + 1  << endl;
    }

    return 0;
}
