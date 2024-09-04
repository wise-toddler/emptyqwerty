// https://atcoder.jp/contests/dp/tasks/dp_d
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
    for(int i=0;i<v.size();i++)
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
    int n,w;cin>>n>>w;
    // vii dp(n+1,vi(w+1,0));
    vi dp(w+1,0);
    vi weight(n+1),value(n+1);
    for(int i=1;i<=n;i++)cin>>weight[i]>>value[i];
    
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=w;j++) // j is the weight
    //     {
    //         if(j-weight[i]>=0) // if we can take the ith item
    //         {
    //             dp[i][j]=max(dp[i-1][j] , dp[i-1][j-weight[i]]+value[i]); // max of not taking the item and taking the item
    //         }
    //         else 
    //         {
    //             dp[i][j]=dp[i-1][j]; // if we can't take the item
    //         }
    //     }
    // }
    // cout << dp[n][w] << endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=w;j>=1;j--)  
            if(j-weight[i]>=0)
                dp[j]=max(dp[j] , dp[j-weight[i]] + value[i]); 
        // print(dp);
    }
        
    
    cout << dp[w] << endl;
    // print(weight);
    cout << endl;
    // print(value);
    // cout << endl;
    // print(dp);
    // cout << endl;
}