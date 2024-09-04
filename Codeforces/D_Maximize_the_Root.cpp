// https://codeforces.com/contest/1997/problem/D
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
    int n;cin >> n;
    vi a(n);cin >> a;
    vi p(n-1);cin >> p;
    vvi adj(n);
    fon(i,n-1)
    {
        p[i]--;
        adj[p[i]].pb(i+1);
        adj[i+1].pb(p[i]);
    }
    // print adj
    // fon(i,n)
    // {
    //     cout << i << ": ";
    //     for(auto x:adj[i]) cout << x << ' ';
    //     cout << endl;
    // }
    // nl
    function<int(int,int)> dfs=[&](int u,int p)
    {
        if(adj[u].size()==1 && u!=0) return a[u];
        int ans=a[u];
        int aa=INT_MAX;
        for(auto v:adj[u])
        {
            if(v==p) continue;
            aa=min(aa,dfs(v,u));
        }
        if(u==0) return ans+aa; 
        
        if(aa>ans) ans=(ans+aa)/2;
        else ans=aa;

        return ans;
    };
    cout << dfs(0,-1) << endl;  
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