#include <bits/stdc++.h>

using namespace std;

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    vector<vector<pair<int, double>>> g(n);
    for (int i = 0; i < edges.size(); i++)
    {
        g[edges[i][0]].push_back({edges[i][1], succProb[i]});
        g[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    vector<double> prob(n, 0.0);
    prob[start] = 1.0;
    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start});
    while (!pq.empty())
    {
        int ne = pq.top().second;
        pq.pop();
        for (auto &e : g[ne])
        {
            if (prob[ne] * e.second > prob[e.first])
            {
                prob[e.first] = prob[ne] * e.second;
                pq.push({prob[e.first], e.first});
            }
        }
    }
    return prob[end];
}

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> edge(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            cin >> edge[i][j];
    }

    vector<double> sp(n);

    for (int i = 0; i < n; i++)
        cin >> sp[i];

    int start, end;
    cin >> start >> end;

    double result = maxProbability(n, edge, sp, start, end);

    cout << result << endl;

    return 0;
}
