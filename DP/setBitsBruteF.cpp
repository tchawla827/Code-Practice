#include <bits/stdc++.h>
using namespace std;

int c = 0;
int setBits(int n)
{
    c++;
    if (n == 0)
        return 0;
    if (n & 1)
        return setBits(n / 2) + 1;
    else
        return setBits(n / 2);
}

int main()
{
    int n;
    cin >> n;

    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i<<" : "<<setBits(i) << endl;
    }
    cout << c << endl;
}