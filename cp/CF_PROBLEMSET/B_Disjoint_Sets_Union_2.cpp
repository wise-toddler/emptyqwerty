// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
// ostream& operator<<(ostream& os, pair<char,int> p){os << p.ff << ' ' << p.ss<<endl;return os;}
class dsu
{
public:
    vi par,sz;
    v<pii> mimx;
    // int minn,maxx;
    dsu(int n)
    {
        par.resize(n+1);
        sz.resize(n+1,1);
        mimx.resize(n+1,{0,0});
        fon(i,n+1)
        {
            par[i]=i;
            mimx[i]={i,i};
        }
    }
    int get(int x)
    {
        return par[x]=(par[x]==x?x:get(par[x]));
    }
    void unite(int x, int y)
    {
        x=get(x); y=get(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        par[y]=x;
        sz[x]+=sz[y];
        mimx[x].ff=min(mimx[x].ff,mimx[y].ff);
        mimx[x].ss=max(mimx[x].ss,mimx[y].ss);
    }
};
void solve()
{
    int n,m; cin >> n >> m;
    dsu d(n);
    while(m--)
    {
        string s; cin >> s;
        if(s=="union")
        {
            int x,y; cin >> x >> y;
            d.unite(x,y);
        }
        else
        {
            int x; cin >> x;
            x=d.get(x);
            cout << d.mimx[x].ff << ' ' << d.mimx[x].ss << ' ' << d.sz[x] << endl;
        }
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