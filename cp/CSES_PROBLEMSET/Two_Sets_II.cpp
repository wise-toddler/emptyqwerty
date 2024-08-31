// https://cses.fi/problemset/task/1093
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
int pow(int a,int b,int c)
{
    if(b==0) return 1;
    int aa = pow(a,b/2,c);
    aa=(aa*aa)%c;
    if(b&1) aa=(aa*a)%c;
    return aa;
}
int dp[1000001];
int mod = 1e9+7;
int f(int a,int t)
{
    if(t==0) return 1;
    if(t<0 || a==0) return 0;
    // if(dp[t]!=-1) return dp[t];
    return dp[t]=(f(a-1,t-a)+f(a-1,t))%mod;
}
void solve()
{
    int n;cin>> n;
    int ts = n*(n+1)/2;
    if(ts/2*2!=ts)
    {
        cout<<0<<endl;
        return;
    }
    int rs = ts/2;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    fo1(i,1,n+1,1)
    {
        fo1(j,rs,0,-1)
        {
            if(j>=i)
                dp[j]=(dp[j]+dp[j-i])%mod;
        }
    }
    cout << (dp[rs]*pow(2,mod-2,mod))%mod;
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