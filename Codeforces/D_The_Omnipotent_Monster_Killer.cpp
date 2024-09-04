// https://codeforces.com/contest/1988/problem/D
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

int dp[300001][20];
vvi adj;
vi a;
int dfs(int x, int lastSeen, int parent) 
{
    int an = dp[x][lastSeen]; 
    if (an != -1) return an;
    an = LLONG_MAX;
    for (int i = 1; i < 20; i++) 
    {
        if (i == lastSeen) 
            continue;
        int temp = i * a[x];
        for (auto y : adj[x]) 
        {
            if (y == parent) 
                continue;
            temp += dfs(y, i, x);
        }
        an = min(an, temp);
    }
    return dp[x][lastSeen] = an;
}
void solve()
{
    int n;cin >> n;
    a=vi(n);cin >> a;
    int m=n-1;
    if(n==1)
    {
        cout << a[0] << endl;
        return;
    }   
    adj=vvi(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<20;j++)
        {
            dp[i][j]=-1;
        }
    }
    // vvi dp(n,vi(20,-1));
    // jump game 1 but on trees // means if a[i] is taken then a[adj[i]] can't be taken
    cout << dfs(0,0,-1) << endl;
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
