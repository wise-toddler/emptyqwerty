// https://cses.fi/problemset/task/1638
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
    v<string> grid(n);cin >> grid;
    vvi dp(n,vi(n,0));
    dp[0][0]=grid[0][0]!='*';
    fo1(i,1,n,1) dp[0][i]=dp[0][i-1] && grid[0][i]!='*';
    fo1(i,1,n,1) dp[i][0]=dp[i-1][0] && grid[i][0]!='*';
    fo1(i,1,n,1)
    {
        fo1(j,1,n,1)
        {
            if(grid[i][j]=='*') dp[i][j]=0;
            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    }
    cout << dp[n-1][n-1] << endl;
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