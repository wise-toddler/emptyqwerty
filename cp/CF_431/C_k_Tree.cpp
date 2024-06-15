// https://codeforces.com/problemset/problem/431/C
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
v<pii> dp;
int n,k,d;
int m=1e9+7;
pii rec(int sum)
{
    if(sum==0) return {0,1};
    if(sum<0) return {0,0};
    if(dp[sum].ff != -1) return dp[sum];
    int dans=0,nodans=0;
    // int nodans=0;
    fo1(i,1,k+1,1)
    {
        auto [dd,nd] = rec(sum-i);
        if(i>=d) dans+=dd+nd;
        else
        {
            dans+=dd;
            nodans+=nd;
        }
    }
    return dp[sum]={dans%m,nodans%m};
}

void solve()
{
    cin >> n >> k >> d;
    dp.assign(101,{-1,-1});
    // deb(n)
    // deb(k)
    // deb(d) nl 
    auto [dd,nd] = rec(n);
    // for(auto [i,c]:dp)
    // {
    //     cout << i << " " << c << endl;
    // }
    cout << dd << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}