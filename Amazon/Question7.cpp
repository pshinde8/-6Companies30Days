// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int freq[26];
		    memset(freq, 0, sizeof freq);
		    vector <char> v;
		    string ans = "";
		    for(int i=0; i<A.length(); i++)
		    {
		        if(freq[A[i]-'a']==0)
		        {
		            v.push_back(A[i]);
		        }
		        freq[A[i]-'a']++;
		        int k=0; 
		        int n = v.size();
		        for(int j=0; j<n; j++)
		        {
		            if(freq[v[j]-'a']==1)
		            {
		                ans = ans + v[j];
		                k=1;
		                break;
		            }
		        }
		        if(k==0)
		        {
		            ans = ans + "#";
		        }
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
