// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
const int mod = 1e9+7;
int dp[1000001];
int f(int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;   
    if(dp[n]!=-1)
        return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++)
        ans=(f(n-i)%mod+ans)%mod;
    return dp[n]=ans; 
}
void solve()
{
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));
    cout << f(n) << endl;
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