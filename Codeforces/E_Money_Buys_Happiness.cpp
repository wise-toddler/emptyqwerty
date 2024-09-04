// https://codeforces.com/contest/1974/problem/E
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
    int m,c;cin >> m >> c;
    int ans=0,cc=0;
    v<pii> a(m);
    int su=0;
    int inf=1e18;
    for(auto &x:a) cin >> x.ff >> x.ss,su+=x.ss;
    vi dp(su+1,inf);
    dp[0]=0;
    fon(i,m)
        for(int j=su;j>=a[i].ss;j--)
            if(dp[j-a[i].ss]+a[i].ff<=c*i)
                dp[j]=min(dp[j],dp[j-a[i].ss]+a[i].ff);
    fon_(i,su+1)
        if(dp[i]!=inf)
        {
            cout << i << endl;
            return;
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
    // fo1(i,-4,-8,-1)
        // cout << i << endl;
    // cout << " makkan "<< endl;
    
}