// Largest Mountain

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return 0;
        int count=0;
        for(int i=1; i<arr.size(); i++)
        {
            int left = i-1;
            int right = i+1;
            int cl=0, cr=0;
            int j=i;
            int k=i;
            while(arr[j]>arr[left] && left>=0)
            {
                cl++;
                left--;
                j--;
            }
            while(arr[k]>arr[right] && right <=n)
            {
                cr++;
                right++;
                k++;
            }
            if(cl!=0 && cr!=0)
			{
            int ans = cl+cr+1;
            count = max(count, ans);
        	}
        }
        return count;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0; i<n; i++)
		{
			int k;
			cin>>k;
			v.push_back(k);
		}
		Solution ob;
		cout<<ob.longestMountain(v)<<endl;
	}
}
