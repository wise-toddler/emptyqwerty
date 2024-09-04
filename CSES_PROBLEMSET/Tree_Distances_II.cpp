// https://cses.fi/problemset/task/1133
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
#define ff first
#define ss second

int contribution(pii x) {
    return x.ff + x.ss;
}

void solve()
{
    int n;cin>>n;
    vvi adj(n+1);
    fo1(i,0,n-1,1)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<pii> dp(n+1); // nd -> (downans,no of nodes)
    // dp[0]={0,0};
    // cout << " : " <<dp[0].first << ' ' << dp[0].second << endl;
    function<void(int,int)> f=[&](int nd,int pr)
    {
        for(int i:adj[nd])
        {
            if(i==pr) continue;
            f(i,nd);
            dp[nd].ff += contribution(dp[i]);
            dp[nd].ss += dp[i].ss;
        }
        dp[nd].ss++;
    };
    f(1,0);
    // cout the dp array
    // for(int i=1;i<=n;i++)
    //     cout << dp[i].first << ' '<< dp[i].second << endl;
    // nl
    vector<int> up(n+1);
    function<void(int,int)> g=[&](int nd,int pr)
    {
        if(pr)
        {
            // pr down nodes
            up[nd] = dp[pr].ff - contribution(dp[nd]) + (dp[pr].ss - dp[nd].ss);
            // pr up nodes
            up[nd] += up[pr] + n - dp[pr].ss;
        }
        for (int i : adj[nd])
        {
            if (i == pr)
                continue;
            g(i, nd);
        }
    };
    g(1,0);

    for(int i = 1; i <= n; ++i) {
        cout << dp[i].ff + up[i] << " ";
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
    }
}