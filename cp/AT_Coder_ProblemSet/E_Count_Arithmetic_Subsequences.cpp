// https://atcoder.jp/contests/abc362/tasks/abc362_e
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
    map<int,int> dp[n][n]; // dp[i][l][j] = number of subsequences ending at i with difference j and length l
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            int diff = a[i]-a[j];
            for(int l=1;l<i;l++)
            {
                dp[i][l][diff]+=dp[j][l-1][diff];
            }
            dp[i][1][diff]++;
        }
    }
    int ans=0;
    // print dp
    for(int i=0;i<n;i++)
    {
        for(int l=0;l<n;l++)
        {
            for(auto [diff,cnt] : dp[i][l])
            {
                cout << i << " " << l << " " << diff << " " << cnt << endl;
            }
        }
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}