// https://atcoder.jp/contests/dp/tasks/dp_b
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
int n;
int dp[100001];
void solve()
{  
    int k;cin>>n>>k;
    vi a(n);
    for(int &i: a) cin>>i;
    dp[n]=0;

    
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
// signed main()
// {
//     IOS
//     int n,k;cin>>n>>k;  
//     vi a(n);
//     for(int &i: a) cin>>i;
//     vi dp(n);
//     dp[0]=0;
//     dp[1]=abs(a[1]-a[0]);
//     for(int i =2;i<n;i++)
//     {
//         dp[i]=abs(a[i]-a[i-1])+dp[i-1];
//         for(int j=2;j<=k && j<=i;j++)
//             dp[i]=min(dp[i],abs(a[i]-a[i-j])+dp[i-j]);
//     }
//     cout << dp[n-1] << endl;
// }