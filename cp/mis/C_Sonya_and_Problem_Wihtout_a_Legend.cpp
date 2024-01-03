// https://codeforces.com/problemset/problem/713/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        cout << i <<" :";
        print(v[i]);
    }
}
signed main()
{
    IOS
    int n;cin >> n;
    vi a(n);
    for(int &i:a)cin >> i;
    vi b = a;
    vii g;
    g.resize(n);
    vi num(n);
    for (int i = 0; i < n; i++)
    {
        num[i] = i;
        g[i].pb(i);
    }
    print(g);
    while (true)
    {
        int ok = 1;
        for (int j=0;j<n-1;j++)
        {
            if (num[j] == num[j + 1]) continue;

            if (b[j] >= b[j + 1])
            {
                ok = 0;
                int U = num[j];
                int V = num[j + 1];
                for (int x : g[V])
                {
                    g[U].pb(x);
                    num[x] = U;
                }
                g[V].clear();
                vi cur;
                for (int x : g[U])
                {
                    cur.pb(a[x] - x);
                }
                sort(cur.begin(), cur.end());
                int sz = cur.size();
                int M = cur[sz / 2];
                for (int x : g[U])
                    b[x] = M + x;
            }
        }
        if (ok == 1)
            break;
    }
    print(b);
    print(g);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - b[i]);
    cout << ans << "\n";
}