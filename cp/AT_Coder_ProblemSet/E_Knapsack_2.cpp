// https://atcoder.jp/contests/dp/tasks/dp_e
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
void print(vi v)
{
    for(int i=0;i<30;i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        //cout << i << ' ';
        print(v[i]);
    }
}
signed main()
{
    IOS
    int n,w;cin >> n >> w;
    // vi dp(w+1,0); // w is tooo large hence it wont work

    // vi weight(n+1),value(n+1);
    // for(int i=1;i<=n;i++) cin >> weight[i]>>value[i];

    // for(int i=1;i<=n;i++)
    //     for(int j=w;j>=1;j--)
    //         if(j-weight[i] >= 0)
    //             dp[j] = max(dp[j],dp[j-weight[i]] + value[i]); 


    // cout <<endl<< dp[w];
    vi weight(n+1),value(n+1);
    for(int i=1;i<=n;i++) cin >> weight[i]>>value[i];
    vii dp(n+1,vi(1e5+1,1e18)); // dp[i][j] = minimum weight to get value j using first i items
    for(int i=0;i<=n;i++) dp[i][0] = 0;

    for(int i=1;i<=n;i++)
        for(int j=0;j<=1e5;j++) 
        {
            if(j-value[i] >= 0)
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-value[i]] + weight[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    
    int ans = 0;
    for(int i=0;i<=1e5;i++)
        if(dp[n][i] <= w)
            ans = i;
    cout << ans;

}