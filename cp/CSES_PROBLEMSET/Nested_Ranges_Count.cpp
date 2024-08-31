// https://cses.fi/problemset/task/2169
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
        // write your merge function here
        return a+b;
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
void solve()
{
    int n;cin >> n;
    vvi a(n,vi(3));
    fon(i,n)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2]=i;
    }
    vi a1(n),a2(n);
    {    
        v<int> comp;
        for(auto &x:a) comp.pb(x[1]),comp.pb(x[0]);
        sort(all(comp));
        comp.resize(unique(all(comp))-comp.begin());
        for(auto &x:a)
        {
            x[0]=lower_bound(all(comp),x[0])-comp.begin();
            x[1]=lower_bound(all(comp),x[1])-comp.begin();
        }
    } // for freeing memory

    sort(all(a),[](vi &x,vi &y){
        // sort by r
        if(x[1]!=y[1]) return x[1]<y[1];
        // sort by l
        return x[0]>y[0];
    });
    // for(auto &x:a) cout << x << endl;   

    vi ls(2*n);
    v<pii> rs;
    fon(i,n)
    {
        // ls[a[i][0]]++;
        rs.pb({a[i][0],a[i][2]});
    }
    // for(auto [l,i]:rs) cout << l << " " << i << endl;
    segtree<int> st(2*n,0);
    for(auto [l,i]:rs)
    {
        a1[i]=st.qry(l,2*n-1);
        st.upt(l,st.qry(l,l)+1);
    }
    for(auto [l,i]:rs)
    {
        st.upt(l,st.qry(l,l)-1);
        a2[i]=st.qry(0,l);
    }
    cout << a1 << endl;
    cout << a2 << endl;
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

/*
0 0 0 0 0 0 0 2 0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 2 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 2 0 0 0 0 1 0 
0 0 1 2 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 2 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 

0 0 0 0 0 0 0 2 0 0 0 0 1 0 1 0 1 0 0 1 0 0 0 2 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 
0 0 1 2 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 

*/