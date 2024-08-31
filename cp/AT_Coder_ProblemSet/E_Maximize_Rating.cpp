// https://atcoder.jp/contests/abc327/tasks/abc327_e
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
vector<vector<double>> dp(5001,vector<double>(5001,-1.0));
double p[5001];
double pp[5001];
double solve(int n,int k,vi& a)
{
    if(k==0)return 0.0;
    if(n==a.size())return 0.0;
    if(dp[n][k]!=-1.0)return dp[n][k];
    double take=(solve(n+1,k-1,a)+p[k-1]*a[n]);
    double not_take = solve(n+1,k,a);
    return dp[n][k]=((take)>(not_take))?take:not_take;
}
void solve()
{
    int n;cin>>n;
    vi a(n);   
    fo1(i,0,n,1)cin>>a[i];
    fo1(i,0,5001,1)fo1(j,0,5001,1)dp[i][j]=-1.0;
    double aa=1;
    p[0]=pp[0]=1;
    fo1(i,1,5001,1)
    {
        aa*=0.9;
        p[i]=aa;
        pp[i]=aa+pp[i-1];
    }
    // for(auto i:p)cout << i << " ";
    double ans=0;
    double ans2=numeric_limits<double>::lowest();
    fo1(i,0,n,1)
    {
        // ans=max(ans,solve(n,j-i,a));    
        double temp=solve(0,n-i,a);
        // cout << temp/pp[n-i] << endl;
        ans2=max(ans2,(temp/pp[n-i-1]-(1200.0/sqrtl(n-i))));
    }
    cout<<fixed<<setprecision(20)<<ans2<<endl;
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