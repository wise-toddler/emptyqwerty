// https://cses.fi/problemset/task/1131
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
    int n;cin>>n;
    vvi adj(n+1);
    fo1(i,0,n-1,1)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int res=0;
    int dp[n+1];
    function<int(int,int)> f=[&](int nd,int pr)
    {
        int &a=dp[nd];if(a!=-1) return a;
        int a1=0,a2=0;
        for(int i:adj[nd])
        {
            if(i==pr) continue;
            int c=f(i,nd);
            if(c>a1)
            {
                a2=a1;
                a1=c;
            }
            else if(c>a2)
                a2=c;
        }
        res=max(res,a1+a2+1);
        return a=a1+1;
    };
    memset(dp,-1,sizeof dp);
    f(1,0);
    cout << res-1 << endl;
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