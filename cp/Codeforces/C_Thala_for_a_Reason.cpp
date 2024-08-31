// https://codeforces.com/gym/517983/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
int x,y;
int dp[101][11][7];
int dx[] = {0,1,2,3,4,6,0};
int dy[] = {0,0,0,0,0,0,-1};
int f(int x,int y,int balls)
{
    if(x<=0) return 1;
    if(balls==0) return 0;
    if(y==0) return 0;
    if(dp[x][y][balls] != -1) return dp[x][y][balls];
    int ans = 0;
    for(int i = 0; i < 7; ++i)
    {
        ans += f(x-dx[i],y+dy[i],balls-1);
    }
    return dp[x][y][balls] = ans;
}
void solve()
{
    cin >> x >> y;
    // in 1 over india needs x runs to win and have y wickets in hand
    // print the number of ways india can win
    memset(dp,-1,sizeof dp);
    // return;
    cout << f(x,y,6) << endl;
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