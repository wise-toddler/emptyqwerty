// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

// https://codeforces.com/contest/1955/problem/G
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// #define int long long
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define all(x) x.begin(),x.end()
#define pii pair<int, int>

const int N = 1e6;
v<int> factors[N + 1];

void pre()
{
    for(int i = 1; i <= N; ++i)
    {
        for(int j = i; j <= N; j += i)
        {
            factors[j].push_back(i);
        }
    }

    for(int i = 1; i <= N; ++i)
    {
        reverse(all(factors[i]));
    }
}


int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve()
{
    int n,m;cin >> n >> m;
    vvi a(n,vi(m));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    auto &factors1 = factors[gcd(a[0][0],a[n-1][m-1])];
    v<v<int>> vis(n,v<int>(m,0));
    vis[0][0] = 1;
    for(int f:factors1)
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(i or j) vis[i][j] = 0;
                if(a[i][j] % f) {
                    continue;
                }
                if(i) {
                    vis[i][j] |= vis[i - 1][j];
                }
                if(j) {
                    vis[i][j] |= vis[i][j - 1];
                }
            }
        }
        if(vis[n - 1][m - 1]) {
            cout << f << endl;
            return;
        }
    }
}
signed main()
{
    pre();
    IOS
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}