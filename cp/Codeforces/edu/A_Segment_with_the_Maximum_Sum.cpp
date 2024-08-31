// https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A
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
template<typename T>
class segtree
{
public:
    v<T> tree;
    T idn;
    int n;
    T merge(T a,T b)
    {
        int ts=a.ts+b.ts;
        int mx_pref=max(a.mx_pref,a.ts+b.mx_pref);
        int mx_suf=max(b.mx_suf,b.ts+a.mx_suf);
        int mx_sub=max({a.mx_sub,b.mx_sub,a.mx_suf+b.mx_pref});
        return {ts,mx_pref,mx_suf,mx_sub};
    }
    segtree(int n,T idn)
    {
        this->n=n;
        this->idn=idn;
        tree.assign(4*n,idn);
    }
    void upt(int qidx,T val)
    {
        function <void(int,int,int)> update=[&](int idx,int st,int en)
        {
            if(st==en)
            {
                tree[idx]=val;
                return;
            }
            int mid=(st+en)/2;
            if(qidx<=mid) update(2*idx+1,st,mid);
            else update(2*idx+2,mid+1,en);
            tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
        };
        update(0,0,n-1);
    }
    T qry(int l,int r)
    {
        function <T(int,int,int)> query=[&](int idx,int st,int en)
        {
            if(l>en || r<st) return idn; // out of range
            if(l<=st && en<=r) return tree[idx]; // in range
            int mid=(st+en)/2;
            return merge(query(2*idx+1,st,mid),query(2*idx+2,mid+1,en));
        };
        return query(0,0,n-1);
    }
};
class node
{
public:
    int ts,mx_pref,mx_suf,mx_sub;
};
void solve()
{
    int n,m;cin >> n >> m;
    vi a(n);cin >> a;
    segtree<node> st(n,{0,0,0,0});
    for(int i=0;i<n;i++)
    {
        st.upt(i,{a[i],a[i],a[i],a[i]});
    }
    cout << max(0LL,st.qry(0,n-1).mx_sub) << endl;
    while(m--)
    {
        int id,val;cin >> id >> val;
        st.upt(id,{val,val,val,val});
        cout << max(0LL,st.qry(0,n-1).mx_sub) << endl;
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