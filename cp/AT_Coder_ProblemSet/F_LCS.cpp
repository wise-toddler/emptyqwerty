// https://atcoder.jp/contests/dp/tasks/dp_f
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
vector<string> anss;
string a, b;

void solve()
{
    cin>>a>>b; 
    // int dp[3001][3001];
    // memset(dp,-1,sizeof(dp));
    vii dp(a.size()+1,vi(b.size()+1,0));
    int n=a.size(),m=b.size();
    fo1(i,0,n+1,1)
    {
        fo1(j,0,m+1,1)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    // return;
    string ans="";
    // for(auto x:dp)
    // {
    //     for(auto y:x)
    //         cout << y << ' ';
    //     cout << endl;
    // }
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            ans+=a[i-1];
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(all(ans));
    cout << ans << endl;
    iota(all(ans),0);
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