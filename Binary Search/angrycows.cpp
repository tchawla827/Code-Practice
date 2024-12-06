#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int> &a, int sep,int C)
{
    int cnt=1;
    int loc=0;
    int currloc;
    for(int i=1;i<a.size();i++)
    {
        currloc=i;
        if(a[currloc]-a[loc]>=sep)
        {
            cnt++;
            loc=currloc;
        }
        if(cnt==C)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, C;
        cin >> N >> C;
        vector<int> a(N);
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int e = (a[N - 1] - a[0]);
        int s = 0;

        int mid = (s + e) / 2;
        int ans = 0;

        while (s <= e)
        {
            mid = (s + e) / 2;
            if (canPlaceCows(a, mid,C))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }

        }
        cout<<ans<<endl;
    }
   
}