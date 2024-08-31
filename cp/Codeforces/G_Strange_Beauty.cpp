// https://codeforces.com/problemset/problem/1475/g
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
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
vvi factors(2e5+1);
void sieve()
{
    for(int i=1;i<=2e5;i++)
    {
        for(int j=i;j<=2e5;j+=i)
        {
            factors[j].pb(i);
        }
    }
}
void solve()
{
    int n;cin>>n;
    vi a(n); cin >> a;
    sort(all(a));
    cout << a << endl;
    vector<int> dp(a.back()+1,0);   
    for(int x:a)
    {
        int maxx =0;
        for(int f:factors[x])
            maxx = max(maxx,dp[f]+1);
        dp[x] = maxx;
        // cout << maxx << " ";
    }
    // nl
    cout << dp << endl;
    cout << n - *max_element(all(dp)) << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    sieve();
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}

