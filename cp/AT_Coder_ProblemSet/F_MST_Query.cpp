// https://atcoder.jp/contests/abc355/tasks/abc355_f
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
#define ff first
#define ss second
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}

struct DSU
{
    vi par,sz;
    DSU(int n)
    {
        par.resize(n);
        sz.resize(n);
        fon(i,n) par[i]=i,sz[i]=1;
    }
    int find(int x)
    {
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unite(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        par[y]=x;
        sz[x]+=sz[y];
    }
};


void solve()
{
    int n,m;cin >> n >> m;
    vector<DSU> dsu(11, DSU(n + 1));
    
    int ans = 0;
    for(int i = 1; i < n; ++i)
    {
        int u, v, w; cin >> u >> v >> w;
        for(int j = w; j < 11; j++)
        {
            dsu[j].unite(u, v);
        }
        ans += w;
    }

    while(m--)
    {
        int u, v, w; cin >> u >> v >> w;
        bool done = false;
        if(dsu[w].find(u) == dsu[w].find(v))
        {
            cout << ans << endl;
            continue;
        }
        ans += w;
        for(int i = w; i < 11; i++)
        {
            if(dsu[i].find(u) == dsu[i].find(v))
            {
                ans -= i;
                break;
            }
        } 
        for(int i = w; i < 11; i++)
        {
            dsu[i].unite(u, v);
        }
        cout << ans << endl;
    }
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
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}