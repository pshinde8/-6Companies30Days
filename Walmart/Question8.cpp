#include <bits/stdc++.h>

using namespace std;

int height(int N)
{
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        if (((i * (i + 1)) / 2) > N)
            break;
    }
    return i - 1;
}

int main()
{
    int n;

    cin >> n;

    int res = height(n);

    cout << res << endl;

    return 0;
}