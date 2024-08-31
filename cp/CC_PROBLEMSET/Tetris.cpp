// https://www.codechef.com/START110B/problems/SPCP6
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
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
int dp[100005][2][5];
int m=1e9+7;
// int f(int n)
// {
//     if(n<=4)
//         return dp[n];
//     if(dp[n]!=-1)
//         return dp[n];
//     dp[n] = ((f(n-1)%m+f(n-2)%m)%m+(f(n-3)%m+f(n-4)%m)%m)%m;
//     return dp[n];

// }
int rec(int n, bool ch, int l)
{
    if(n <= 0 && ch && l == 4) return 1;
    if(n <= 0) return 0;

    if(dp[n][ch][l] != -1) return dp[n][ch][l];

    int ans = 0;
    for(int i = 1 ; i <= 4 ; i++)
    {
        if(i == 1) ans += rec(n-i,!ch,i) % m;
        else{
            ans += rec(n-i,ch,i) % m;
        } 
    }
    return dp[n][ch][l] = ans % m;
}
void solve()
{
    int l;cin >> l;
    cout << rec(l,1,0) << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        solve();
    }

}