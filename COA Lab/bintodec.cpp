#include<iostream>
#include<math.h>
using namespace std;

int bintodec(int a)
{
    int number=0;
    int c=0;

    while(a>0)
    { 
        c++;
        if(a%10==1)
        {
            number=number+ pow(2,c-1);
        }
        a=a/10;
    }
    return number;
}

int main()
{
    int a;
    cout<<"ENTER BINARY NUMBER : ";
    cin>>a;
    cout<<"DECIMAL : "<<bintodec(a);
}