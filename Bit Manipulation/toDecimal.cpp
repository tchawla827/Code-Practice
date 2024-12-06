#include<bits/stdc++.h>
using namespace std;

int toDecimal(int n)
{
    int ans=0;
    int lastbit;
    int pow=1;
    while(n>0)
    {
        lastbit=n%10;
        n=n/10;
        ans+=(lastbit*pow);
        pow=pow*2;
    }
    return ans;
}



int main()
{
    int n;
    cout<<"Enter Integer : ";
    cin>>n;
    
    

    cout<<endl<<"DECIMAL : "<<toDecimal(n)<<endl;
}