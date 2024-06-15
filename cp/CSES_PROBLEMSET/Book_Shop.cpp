// https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
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
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,x;cin>>n>>x;
    vvi a(n,vi(2));
    fon(i,n)cin>>a[i][0];
    fon(i,n)cin>>a[i][1];
    vvi dp(n+1,vi(x+1,-1));
    function<int(int,int)> f = [&](int i,int x)
    {
        if(i==n || x==0)return 0ll;
        int &an = dp[i][x]; if(an!=-1)return an;
        an = f(i+1,x);
        if(a[i][0]<=x)an = max(an,f(i+1,x-a[i][0])+a[i][1]);
        return an;    
    };
    cout<<f(0,x)<<endl;
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
    }
    return 0;
}