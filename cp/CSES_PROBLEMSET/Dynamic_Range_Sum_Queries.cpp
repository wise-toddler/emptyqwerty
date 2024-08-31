// https://cses.fi/problemset/task/1648
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

class segtee
{
public:
    int n;
    int idn;
    vi tree;
    segtee(int n,int idn)
    {
        this->n=n;
        this->idn=idn;
        tree.assign(4*n,idn);
    }
    int merge(int a,int b)
    {
        return a+b;
    }
    int query(int l,int r)
    {
        function<int(int,int,int)> query=[&](int id,int st,int en)
        {
            if(l>en || r<st) return idn;
            if(l<=st && en<=r) return tree[id];
            int mid=(st+en)/2;
            return merge(query(2*id+1,st,mid),query(2*id+2,mid+1,en));
        };
        return query(0,0,n-1);
    }
    void up(int i,int v)
    {
        function<void(int,int,int)> up = [&](int id,int st,int en)
        {
            if(st==en)
            {
                tree[id]=v;
                return;
            }
            int mid=(st+en)/2;
            if(i<=mid) up(2*id+1,st,mid);
            else up(2*id+2,mid+1,en);
            tree[id]=merge(tree[2*id+1],tree[2*id+2]);
        };
        up(0,0,n-1);
    }
};
void solve()
{
    int n,q;cin>>n>>q;
    vi a(n);cin>>a;
    segtee st(n,0);
    // segtree<int> st(n,0);
    fo1(i,0,n,1) st.up(i,a[i]);
    // fo1(i,0,n,1) st.upt(i,a[i]);
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int k,u;cin>>k>>u;
            k--;
            st.up(k,u);
        }
        else
        {
            int l,r;cin>>l>>r;
            l--,r--;
            cout << st.query(l,r) << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}