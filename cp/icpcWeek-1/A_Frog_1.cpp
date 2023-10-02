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
signed main()
{
    IOS
    int n;cin>>n;
    vi a(n);
    for(int &i: a) cin>>i;
    vi dp(n);
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++)
        dp[i]=min(abs(a[i]-a[i-1])+dp[i-1] , abs(a[i]-a[i-2])+dp[i-2]);
    cout << dp[n-1] << endl;
}