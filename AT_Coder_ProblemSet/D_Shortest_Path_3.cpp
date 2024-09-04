// https://atcoder.jp/contests/abc362/tasks/abc362_d
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    // Adjacency list of (neighbour, edge weight)
    vector<pair<int, int>> neighbors[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        neighbors[a - 1].push_back({b - 1, c});
        neighbors[b - 1].push_back({a - 1, c});
    }

    // Initially set all distances to infinity
    vector<long long> dist(n, LLONG_MAX);

    // Dijkstra's algorithm
    // using T = pair<long long, int>;
    // priority_queue<T, vector<T>, greater<T>> pq;
    set<pair<int, int>> pq;
    int start = 0;
    dist[start] = a[start];
    pq.insert({dist[start], start});
    while (!pq.empty())
    {
        // const auto [cdist, node] = pq.top();
        // pq.pop();
        auto [cdist, node] = *pq.begin();
        pq.erase(pq.begin());
        for (auto [neigh, weight] : neighbors[node])
        {
            if (dist[neigh] > cdist + weight + a[neigh])
            {
                pq.erase({dist[neigh], neigh});
                dist[neigh] = cdist + weight + a[neigh];
                pq.insert({dist[neigh], neigh});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << dist[i] << ' ';
    }
}