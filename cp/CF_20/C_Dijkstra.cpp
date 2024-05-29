// https://codeforces.com/problemset/problem/20/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
void solve()
{
    int n,m;cin >> n >> m;
    // m edged (u,v,w) graph
    vvi adj(n+1);
    map<pii,int> dist;
    fon(i,m)
    {
        int u,v,w;cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        dist[{u,v}] = w;
        dist[{v,u}] = w;
    }

    vi d(n+1,LLONG_MAX); // distance from 1 to i
    vi p(n+1,-1); // parent of i
    d[1] = 0;
    set<pii> q; // {distance,vertex}
    q.insert({0,1});
    while(!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int u : adj[v])
        {
            int w = dist[{v,u}];
            if(d[v] + w < d[u])
            {
                q.erase({d[u],u});
                d[u] = d[v] + w;
                p[u] = v;
                q.insert({d[u],u});
            }
        }
    }
    // if d[n] == LLONG_MAX, then there is no path from 1 to n
    if(d[n] == LLONG_MAX)
    {
        cout << -1 << endl;
        return;
    }
    vi path;
    for(int v=n;v!=-1;v=p[v])
        path.pb(v);
    reverse(all(path));
    cout << path << endl;
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