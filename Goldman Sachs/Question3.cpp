// Count the subarrays having product less than k

#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long int pro = 1, count = 0;
        int i = 0, j = 0;
        while(j < n) {
            pro = pro * a[j];
            while(i <= j && pro >= k) {
                pro = pro / a[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
