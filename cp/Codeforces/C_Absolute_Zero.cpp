// https://codeforces.com/contest/1991/problem/C
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
    int n;cin >> n;
    vi a(n);cin >> a;
    if(n==count(all(a),0))
    {
        cout << 0 << endl << endl;
        return;
    }
    vi aa;
    int op=0;
    while(op++<40)
    {
        int laar = *max_element(all(a));
        bool f = *min_element(all(a)) == laar;
        if(f) {aa.pb(laar);break;}
        else 
        {   
            aa.pb(laar/2);
            for(int &i:a) i = abs(i-laar/2);
        }
    }
    if(op==41)
    {
        cout << -1 << endl;
        return;
    }
    cout << aa.size() << endl << aa << endl;
    
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