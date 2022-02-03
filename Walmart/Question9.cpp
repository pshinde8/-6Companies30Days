#include <bits/stdc++.h>

using namespace std;

int getMoneyAmount(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++)
    {
        int maxStart = n - len + 1;
        for (int start = 1; start <= maxStart; start++)
        {
            int end = start + len - 1;
            int temp = INT_MAX;
            for (int i = start; i <= end; i++)
            {
                if (i == start)
                {
                    temp = min(temp, i + dp[i + 1][end]);
                }
                else if (i == end)
                {
                    temp = min(temp, i + dp[start][i - 1]);
                }
                else
                {
                    temp = min(temp, i + max(dp[start][i - 1], dp[i + 1][end]));
                }
            }
            dp[start][end] = temp;
        }
    }

    return dp[1][n];
}

int main()
{
    int n;

    cin >> n;

    int res = getMoneyAmount(n);

    cout << res << endl;

    return 0;
}