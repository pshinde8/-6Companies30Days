#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int start=0;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                ans = min(ans, i+1-start);
                sum = sum - nums[start++];
            }
        }
        if(ans==INT_MAX)
            return 0;
        else
            return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int target;
        vector<int> v;
        int n;
        cin>>target;
        cin>>n;
        int num;
        for(int i=0; i<n; i++)
        {
        	cin>>num;
        	v.push_back(num);
		}
        
        Solution ob;
        cout<<ob.minSubArrayLen(target, v)<<"\n";
    }
    return 0;
} 
