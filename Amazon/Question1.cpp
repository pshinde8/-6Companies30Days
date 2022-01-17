// Maximum Profit

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
      int maxProfit(int K, int N, int A[])
    {
        // code here
        int dp[K+1][N];
        for(int i = 0; i <= K; i++)
            dp[i][0] = 0;
        for(int j = 0; j < N; j++)
            dp[0][j] = 0;
        for(int i = 1; i <= K; i++)
        {
            int maxi = INT_MIN;
            for(int j = 1; j < N; j++)
            {
                maxi = max(maxi, dp[i-1][j-1] - A[j-1]);
                dp[i][j] = max(maxi + A[j], dp[i][j-1]);
            }
        }
        return dp[K][N-1];  
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  
