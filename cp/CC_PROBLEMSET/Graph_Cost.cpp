// https://www.codechef.com/START135B/problems/GRAPHCOST
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
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    // weight of egde btw i and j is abs(i-j)*max(ai,aj)

    // make the adj 
    vvi adj(n);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            adj[i].pb(j);
        
    map<pii,int> mp;
    for(int i=0;i<n;i++)
        for(auto &x:adj[i])
            mp[{i,x}]=(x-i)*max(a[i],a[x]);

    // find the minimum cost of path from 1 to n
    vi dp(n,LLONG_MAX);
    dp[0]=0;
    // dp[i] is the minimum cost to reach i
    // for(int i=1;i<n;i++)
    //     for(int j=0;j<i;j++)
    //         dp[i]=min(dp[i],dp[j]+abs(i-j)*max(a[i],a[j]));
    // cout << dp[n-1] << endl;

    priority_queue<pii,v<pii>,greater<pii>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        auto [c,i]=pq.top();
        pq.pop();
        if(i==n-1)
        {
            cout << c << endl;
            return;
        }
        for(int j=i+1;j<n;j++)
        {
            int nc=c+abs(i-j)*max(a[i],a[j]);
            if(dp[j]>nc)
            {
                dp[j]=nc;
                pq.push({nc,j});
            }
        }
    }
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
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}