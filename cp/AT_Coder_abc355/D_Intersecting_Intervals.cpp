// https://atcoder.jp/contests/abc355/tasks/abc355_d
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
void solve()
{
    // int n;cin >> n;
    // v<pii> a(n);
    // fon(i,n) cin >> a[i].ff >> a[i].ss;
    // // no of intersecting intervals
    int n; cin >> n;
    v<pii> lr(n);
    for (int i = 0; i < n; i++) cin >> lr[i].ff >> lr[i].ss;

    v<pair<int, bool>> po;
    for (auto [i,j]: lr) 
    {
        po.pb({i,0}); 
        po.pb({j,1});
    }

    sort(all(po)); 

    int count = 0, an = 0;
    for (auto [i,j] : po) 
    {
        if (j) count--;  
        else  
        {
            an+=count;
            count++;
        }
    }
    cout << an << endl;
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