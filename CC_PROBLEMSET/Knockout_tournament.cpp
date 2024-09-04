// https://www.codechef.com/START146B/problems/KNOCKOUT
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
    vi a(16);cin >> a;
    v<pii> b;
    int n=16;
    fon(i,n)b.pb({a[i],i+1});
    sort(all(b));
    vi c(16);
    fon(i,n)
    {
        c[b[i].ss-1]=log2(i+1);
    }
    cout << c << endl;
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
    }
    return 0;
}
// 22 16 36 18 4 21 28 2 7 35 9 15 5 23 10 20
// 3 3 4 3 1 3 3 0 2 3 2 2 1 3 2 3
// 
// 2 4 5 7 9 10 15 16 18 20 21 22 23 28 35 36
// 0 1 1 2 2  2  2  3  3  3  3  3  3  3  3  4
// 0 1 2 3 4  5  6  7  8  9 10 11 12 13 14 15