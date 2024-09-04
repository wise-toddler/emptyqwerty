// https://cses.fi/problemset/task/1734
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
class t
{
public:
    v<t*> c;
    vi ids;
    t() { c.resize(2); }
    int cnt(int l,int r)
    {
        auto rr=lower_bound(all(ids),r+1);
        auto ll=lower_bound(all(ids),l);
        if(rr==ids.begin() or ll==ids.end()) return 0;
        return rr-ll;
    }
};

t *rr=new t();
void in(int n,int id)
{
    t *c=rr;
    c->ids.pb(id);
    for(int i=30;i>=0;i--)
    {
        int b=(n>>i)&1;
        if(!c->c[b])
        {
            c->c[b]=new t();
        }
        c=c->c[b];
        c->ids.pb(id);
    }
}
int ser(int l,int r)
{
    // l to r less than l
    t *c=rr;
    int ans=0;
    for(int i=30;i>=0;i--)
    {
        int b=(l>>i)&1;
        if(b==0)
        {
            if(c->c[1])
                ans+=c->c[1]->cnt(l,r);
            if(!c->c[0]) break;
            c=c->c[0];
        }
        else
        {
            if(!c->c[1]) break;
            c=c->c[1];
        }
    }
    return r-l+1-ans;
}
void solve()
{
    int n,q;cin>>n>>q;
    vi a(n);cin>>a;
    vi b(n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        b[i] = mp[a[i]];
        mp[a[i]] = i+1;
    }
    // deb(b)
    for(int i=0;i<n;i++)
    {
        in(b[i],i);
    }
    while(q--)
    {
        int l,r;cin>>l>>r;
        cout << ser(l-1,r-1) << endl;
    }

    // now clear the memory
    function<void(t*)> del=[&](t *c)
    {
        for(auto x : c->c)
        {
            if(x) del(x);
        }
        delete c;
    };
    del(rr);
    rr=new t();
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