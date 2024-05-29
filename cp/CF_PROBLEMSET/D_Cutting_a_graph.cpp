// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
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
template<typename T,typename U>istream& operator>>(istream& is, pair<T,U>& p){is >> p.ff >> p.ss;return is;}
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
class dsu 
{
    public:
    vi parent;
    dsu(int n)
    {
        parent.resize(n);
        fo1(i,0,n,1) parent[i]=i;
    }
    int find(int x)
    {
        return parent[x]==x ? x : parent[x]=find(parent[x]);
    }
    void unite(int x,int y)
    {
        x=find(x);
        y=find(y);
        if(x==y) return;
        parent[x]=y;
    }
};
void solve()
{
    int n,m,k;cin >> n >> m >> k; // no of vertices, edges, operations
    v<pii> edges(m);cin >> edges;
    v<pair<string,pii>> operations(k);
    for(auto &x : operations) 
    {
        cin >> x.ff >> x.ss.ff >> x.ss.ss;
        x.ss.ff--;
        x.ss.ss--;
    }
    dsu d(n);
    v<bool> ans;
    fon_(i,k)
    {
        if(operations[i].ff=="ask") 
            ans.pb(d.find(operations[i].ss.ff)==d.find(operations[i].ss.ss));
        else
            d.unite(operations[i].ss.ff,operations[i].ss.ss);
    }
    reverse(all(ans));
    for(auto x : ans)
    {
        cout << (x ? "YES" : "NO") << endl;
    }
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
    }
}