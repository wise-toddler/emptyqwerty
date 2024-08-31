// https://codeforces.com/problemset/problem/580/C
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
    vvi adj(n+1);   
    vi c(n+1);
    fo1(i,1,n+1,1) cin >> c[i];
    fon(i,n-1)
    {
        int a,b;cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans=0;
    function<void(int,int,int)> dfs=[&](int u,int p,int cnt)
    {
        if(c[u]) cnt++;
        else cnt=0;
        // if(u==3) deb(cnt);
        if(cnt>m) 
            return;
        if(adj[u].size()==1 && u!=1)
        {
            ans++;
            return;
        }
        for(auto v : adj[u])
        {
            if(v==p) continue;
            dfs(v,u,cnt);
        }
    };
    dfs(1,0,0);
    cout << ans << endl;
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