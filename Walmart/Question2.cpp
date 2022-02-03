#include <bits/stdc++.h>

using namespace std;

bool stoneGame(vector<int> &piles)
{
    int e = piles.size() - 1;
    int n = (e + 1) / 2;
    int s = 0;
    int bob = 0, alice = 0;
    for (int i = 0; i <= (e + 1) / 2; i++)
    {
        if (piles[s] >= piles[e])
        {
            alice += piles[s];
            s++;

            if (piles[s] < piles[e])
            {
                bob += piles[s];
                s++;
            }
            else
            {
                bob += piles[e];
                e--;
            }
        }

        else
        {
            alice += piles[e];
            e--;

            if (piles[s] < piles[e])
            {
                bob += piles[s];
                s++;
            }
            else
            {
                bob += piles[e];
                e--;
            }
        }
    }
    return (alice > bob);
}

int main()
{
    int n;

    cin >> n;

    vector<int> s(n);

    for (int i = 0; i < n; i++)
        cin >> s[i];

    bool result = stoneGame(s);

    cout << result << endl;

    return 0;
}