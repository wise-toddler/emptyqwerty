// https://atcoder.jp/contests/abc327/tasks/abc327_d
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

bool isBipartite(vector<vector<int>> &edges, int n)
{
    vector<int> colors(n, 0); // 0: not colored, 1: color A, -1: color B

    for (int i = 0; i < n; i++)
    {
        if (colors[i] == 0)
        {
            colors[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : edges[node])
                {
                    if (colors[neighbor] == 0)
                    {
                        colors[neighbor] = -colors[node];
                        q.push(neighbor);
                    }
                    else if (colors[neighbor] == colors[node])
                    {
                        return false; // Conflict, not bipartite
                    }
                }
            }
        }
    }

    return true; // No conflicts, bipartite
}

void solve()
{
    int n;cin>>n;
    int m;cin>>m;
    vi a(m),b(m);
    vii edges(n);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        b[i]--;
    }
    for(int i=0;i<m;i++)
    {
        edges[a[i]].pb(b[i]);
        edges[b[i]].pb(a[i]);
    }
    cout << (isBipartite(edges,n)?"Yes":"No") << endl;
    
    
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}