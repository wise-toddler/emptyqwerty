// https://codeforces.com/gym/514183/problem/B
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
int mod = 1e9+7;
vi a;
// int ans=0;
const int N = 2e5 + 10;
int dp[2][2][2][N];
int rec(bool p1, bool p2, bool p3,int id) // 0-> harsh 1-> shah 2-> bogle
{
    if(id==a.size()) return 1;

    int &ans = dp[p1][p2][p3][id]; if(ans != -1) return ans;

    if(a[id]==1)
    {
        if(!p1) ans = 0;
        else ans = rec(1,!p2,!p3,id+1);
    }
    else
    {
        ans = 0;
        if(p1) ans += rec(1,!p2,!p3,id+1);
        if(p2) ans += rec(!p1,1,!p3,id+1);
        if(p3) ans += rec(!p1,!p2,1,id+1);
    }
    ans %= mod;
    return ans;
}
void solve()
{
    int n,m; cin >> n >> m;
    a = vi(n);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<n;l++)
                {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    fon(i,m)
    {
        int x; cin >> x;
        a[x-1] = 1;
    }
    int ans = rec(1, 1, 0, 0);
    cout << ans << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}