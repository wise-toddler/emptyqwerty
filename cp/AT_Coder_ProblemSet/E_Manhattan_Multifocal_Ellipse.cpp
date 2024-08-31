// https://atcoder.jp/contests/abc366/tasks/abc366_e
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
void solve()
{
    int n,d;cin >> n >> d;
    v<pii> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].ff >> a[i].ss;
    }
    // manhattan distance of each point from each other
    v<pii> diffx,diffy; // diffx = sum of x coordinates greater than or equal to x1 and less than or equal to x2
    vi xs,ys;
    for(auto [x1,y1] : a)
    {
        xs.pb(x1);
        ys.pb(y1);
    }
    sort(all(xs));
    sort(all(ys));
    deb(xs)deb(ys)  

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