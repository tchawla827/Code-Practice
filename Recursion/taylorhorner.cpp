#include<iostream>
using namespace std;

double taylor(double x,double n)
{
    static double sum=0;
    if(n==0)
    return sum+1;
    sum=(sum+1)*(x/n);
     return taylor(x,n-1);
}
int main()
{
    cout<<"ENTER NUMBER OF TERMS OF TAYLOR SERIES : ";
    int n;
    n=4;
    double x;
    cout<<"ENTER VALUE OF X : ";
    x=4;

    cout<<"TAYLOR SERIES SUM = "<<taylor(x,n)<<endl;
   
    /*static double sum=0;
    for(int i=n;i>=0;i--)
    {
        if(i==0)
        sum+=1;
        else{
            sum=(sum+1)*(x/i);
        }
    }
    cout<<"SUM : LOOP : "<<sum;*/
}
