/*  Problem Statement - Calculate Maximum Profit */

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int N, int A[]) {
        // code here
        int profit[k+1][N+1];
        for(int i=0; i<=k; i++)
        {
            profit[i][0]=0;
        }
        for(int i=0; i<=N; i++)
        {
            profit[0][i]=0;
        }
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<N; j++)
            {
               int maximum = INT_MIN;
               for(int n=0; n<j; n++)
               {
                   maximum = max(maximum, A[j]-A[n]+profit[i-1][n]);
               }
               profit[i][j] = max(profit[i][j-1], maximum);
            }
        }
        return profit[k][N - 1];
    }
};

// { Driver Code Starts.

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
}  // } Driver Code Ends
