// https://atcoder.jp/contests/dp/tasks/dp_m
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
int m=1e9+7;

int dp[101][100001]; // dp[i][j] = number of ways to distribute j candies among first i children
void solve()
{
    int n,k;cin >> n >> k;
    vi a(n);cin >> a;
    // cout << f(n,k) << endl;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    fo1(i,1,n+1,1)
    { 
        vi pref(k+1,0);
        pref[0]=dp[i-1][0];
        fo1(j,1,k+1,1) pref[j]=(pref[j-1]+dp[i-1][j])%m;
        fo1(j,0,k+1,1)
        {
            dp[i][j]=pref[j];
            if(j-a[i-1]-1>=0) 
                dp[i][j]=(dp[i][j]-pref[j-a[i-1]-1]+m)%m;
        }
    }
    cout << dp[n][k] << endl;

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
    }
    return 0;
}