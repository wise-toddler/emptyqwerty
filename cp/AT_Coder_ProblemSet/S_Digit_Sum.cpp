// https://atcoder.jp/contests/dp/tasks/dp_s
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
int dp[10001][2][2][101];
int f(int i,int t,int l,int s,int d,string &a)
{
    if(i==a.size()) return s%d==0 and !l;
    int &ans = dp[i][t][l][s]; if(ans!=-1) return ans;
    ans=0;
    int mn=0,mx=t?a[i]-'0':9;
    fo1(j,mn,mx+1,1) 
    {
        ans+=f(i+1,t&&(j==mx),l && j==0,(s+j)%d,d,a);
        ans%=1000000007;
    }
    return ans;
}
void solve()
{
    string k;int d;cin>>k>>d;
    memset(dp,-1,sizeof(dp));
    cout << f(0,1,1,0,d,k) << endl;
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