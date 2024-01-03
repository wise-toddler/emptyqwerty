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
int dp[1000];

int f(int n)
{
    if(n==1)return 1;
    if(n<1)return 0;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1)+f(n-2)+f(n-3);
}
signed main()
{
    IOS
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));
    cout <<f(n)<<endl;
}