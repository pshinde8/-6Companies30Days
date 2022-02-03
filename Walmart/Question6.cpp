#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long power(long long x, long long y)
{
    long long result = 1;
    while (y > 0)
    {
        if (y % 2 == 0)
        {
            x = (x % mod * x % mod) % mod;
            y = y / 2;
        }
        else
        {
            result = (result % mod * x % mod) % mod;
            y = y - 1;
        }
    }
    return result % mod;
}

int main()
{
    long long m, n;
    cin >> m >> n;

    long long res = power(m, n);

    cout << res << endl;

    return 0;
}