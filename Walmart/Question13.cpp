#include <bits/stdc++.h>

using namespace std;

struct compare
{
    bool operator()(string a, string b)
    {
        if (a.length() != b.length())
            return a.length() > b.length();
        return a > b;
    }
};
string kthLargestNumber(vector<string> &nums, int k)
{
    priority_queue<string, vector<string>, compare> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i].size() != pq.top().size())
        {
            if (nums[i].size() > pq.top().size())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        else if (nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}

int main()
{
    int n;

    cin >> n;

    vector<string> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int k;
    cin >> k;
    string result = kthLargestNumber(v, k);

    cout << result << endl;

    return 0;
}