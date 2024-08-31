// https://codeforces.com/contest/1980/problem/E
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
bool solve()
{
    int n,m;cin>>n>>m;
    vvi a(n,vi(m)),b(n,vi(m));
    cin >> a >> b;
    set<set<int>> r1,r2;
    set<set<int>> c1,c2;
    for(auto i:a) 
    {
        set<int> t;
        for(auto j:i)  
            t.insert(j);
        r1.insert(t);
    }
    for(auto i:b) 
    {
        set<int> t;
        for(auto j:i)  
            t.insert(j);
        r2.insert(t);
    }
    fon(j,m)
    {
        set<int> t;
        fon(i,n)
            t.insert(a[i][j]);
        c1.insert(t);
    }
    fon(j,m)
    {
        set<int> t;
        fon(i,n)
            t.insert(b[i][j]);
        c2.insert(t);
    }
    return r1==r2 && c1==c2;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}