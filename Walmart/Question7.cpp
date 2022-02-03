#include <bits/stdc++.h>

using namespace std;

vector<int> find3Numbers(vector<int> a, int n)
{
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
            s.pop();
        s.push(a[i]);
        if (s.size() == 3)
            break;
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    if (ans.size() != 3)
        return {};
    return ans;
}

int main()
{
    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> result = find3Numbers(v, n);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}