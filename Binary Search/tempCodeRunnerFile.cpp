long long fastPower(int x, int n, int limit)
    {
        long long res = 1;
        while (n)
        {
            if (n & 1)
            {
                res *= x;
                if (res > limit) return res;
            }
            x *= x;
            if (x > limit) return x;
            n >>= 1;
        }
        return res;
    }