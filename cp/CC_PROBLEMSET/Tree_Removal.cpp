// https://www.codechef.com/START140B/problems/TREEREMOVAL
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
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin>>n;
    vi a(n); cin >> a;
    vvi adj(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int minn = min_element(all(a)) - a.begin();
    int root = minn;
    cout << n-1 << endl;
    // print the child then itself
    vi ans;
    function<void(int,int)> f = [&](int u,int p)
    {
        for(int v:adj[u])
        {
            if(v==p) continue;
            f(v,u);
        }
        if(u!=root) ans.pb(u+1);
    };
    f(root,-1);
    cout << ans << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}