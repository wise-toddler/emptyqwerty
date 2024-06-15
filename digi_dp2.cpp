#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
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
int dp[18][18*9+1][10];
int f(int i,int s,int g,int l,int rs,int rg)
{
    if(i==l) return (s==rs && g==rg);
    if(dp[i][s][g]!=-1) return dp[i][s][g];
    int ans=0;
    for(int d=0;d<=9;d++)
        ans+=f(i+1,s+d,gcd(g,d),l,rs,rg);
    return dp[i][s][g]=ans;
}
void solve()
{
    // count number of numbers in range [1,1e18] with digit sum = s and digit gcd = g
    int n=18;
    int s=18;
    int g=1;
    memset(dp,-1,sizeof(dp));   
    f(0,0,0,n,s,g);
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<=s;j++)
    //     {
    //         for(int k=0;k<=g;k++)
    //         {
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    cout << f(0,0,0,n,s,g) << endl;


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