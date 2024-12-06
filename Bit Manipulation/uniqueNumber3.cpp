#include <bits/stdc++.h>
using namespace std;

void updateSum(vector<int>& sum, int x)
{
    int i = 0;
    while (x)
    {
        if (x & 1)
        {
            sum[i]++;
        }
        x >>= 1;
        i++;
    }
}

int numFromBits(vector<int> sum)
{
    int num = 0;
    for (int i = 0; i < 32; i++)
    {
        num += (sum[i] * (1 << i));
    }
    return num;
}

int uniqueNumber(vector<int> a)
{
    vector<int> sum(32, 0);

    for (auto x : a)
    {
        updateSum(sum, x);
    }

    for (auto& x : sum)
    {
        x = x % 3;
    }

    return numFromBits(sum);
}

int main()
{
    int n;
    cout << "How many Integers : ";
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    cout << "Unique Number : " << uniqueNumber(a) << endl;

    return 0;
}
