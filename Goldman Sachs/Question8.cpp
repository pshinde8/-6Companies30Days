// Total Decoding Messages

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    long long int mod=1000000007;
		    int n = str.length();
		    int dp[n+1];
		    dp[0]=1;
		    if(str[0]=='0')
		        return 0;
		    dp[1]=1;
		    for(int i=2; i<=n; i++)
		    {
		        int c1=0, c2=0;
		        if(str[i-1]>'0')
		            c1 = dp[i-1];
		        if(str[i-2]=='1' || str[i-2]=='2' && str[i-1]<'7')
		            c2 = dp[i-2];
		        dp[i] = (c1 + c2) % mod;
		    }
		    return dp[n];
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
