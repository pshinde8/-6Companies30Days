// Maximum of all subarrays of size k 

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> v;
        multiset<int, greater<int>> ms;
        for(int i=0; i<k; i++)
        {
            ms.insert(arr[i]);
        }
        v.push_back(*ms.begin());
        for(int i=k; i<n; i++)
        {
            ms.erase(ms.lower_bound(arr[i-k]));
            ms.insert(arr[i]);
            v.push_back(*ms.begin());
        }
        return v;
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
