// https://atcoder.jp/contests/dp/tasks/dp_c
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
signed main()
{
    IOS
    int n;cin>>n;
    vi a(n),b(n),c(n);
    for(int i =0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
    vii dp(n,vi(3));
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
    }
    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << endl;
} 