// https://atcoder.jp/contests/abc355/tasks/abc355_b
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
bool solve()
{
    int n,m;cin >> n >> m;
    vi a(n),b(m); cin >> a >> b;
    sort(all(a));
    sort(all(b));
    // vi c = a+b
    vi c;
    for(auto &x:a) c.pb(x);
    for(auto &x:b) c.pb(x);
    sort(all(c));
    // cout << c << endl;
    int j=-2;
    int ai=0;
    fon(i,n+m)
    {
        if(c[i]==a[ai]) 
        {
            // deb(i) deb(j)
            if(j==i-1) return 1;
            j=i;
            ai++;
        }
    }
    return 0;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "Yes" : "No") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}