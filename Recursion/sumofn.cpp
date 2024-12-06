#include<iostream>
using namespace std;

int sum(int n,int s)
{
    if(n>0)
    {
        s+=n;
        sum(n-1,s);
    }
    else
    return s;
}

int sum2(int n)
{
    if(n==0)
    return 0;
    else{
        return sum2(n-1)+n;
    }
}


int main()
{
    cout<<"SUM OF N NATURAL NUMBERS"<<endl;
    cout<<"ENTER N : ";
    int N;
    cin>>N;
    cout<<"SUM OF FIRST "<<N<<" NATURAL NUMBERS BY LOGIC 1 = "<<sum(N,0)<<endl;
    cout<<"SUM OF FIRST "<<N<<" NATURAL NUMBERS BY LOGIC 2 = "<<sum2(N)<<endl;
}