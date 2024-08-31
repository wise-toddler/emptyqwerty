// https://atcoder.jp/contests/dp/tasks/dp_a
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
int dp[100001];
int n;
int f(int i,vi &a) // i is the index of the array
{
    if(i==n-1) return 0;
    if(i>=n) return INT_MAX;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=min(abs(a[i+1]-a[i])+f(i+1,a),abs(a[i+2]-a[i])+f(i+2,a));
}
void solve()
{
    cin >> n;
    vi a(n);
    for (int &i : a)
        cin >> i;
    memset(dp, -1, sizeof(dp));
    cout << f(0, a) << endl;
}
// void solve()
// {
//     int n;cin>>n;
//     vi a(n);
//     for(int &i: a) cin>>i;
//     vi dp(n);
//     dp[0]=0;
//     dp[1]=abs(a[1]-a[0]);
//     for(int i=2;i<n;i++)
//         dp[i]=min(abs(a[i]-a[i-1])+dp[i-1] , abs(a[i]-a[i-2])+dp[i-2]);
//     cout << dp[n-1] << endl;
// }

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
