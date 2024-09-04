// https://codeforces.com/contest/1418/problem/C
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
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
vi a;
v<vvi> dp;// id,turn,number of moves
int f(int i,int t,int m)
{
    if(i==a.size()) return 0;
    if(dp[i][t][m]!=-1) return dp[i][t][m];
    int ans = 0;
    if(m<2)
        ans+=min(f(i+1,1-t,1),f(i+1,t,m+1));
    else
        ans+=f(i+1,1-t,1);
    return dp[i][t][m]=ans+(t==0 && a[i]==1);
}
void solve()
{
    int n;cin >> n;
    a.resize(n);cin >> a;
    dp.assign(n,vvi(2,vi(3,-1)));
    cout << f(0,0,0) << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}