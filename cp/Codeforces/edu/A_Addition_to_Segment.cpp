// https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A
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
class lazy_segtree
{
public:
    v<int> tree;
    int n;
    lazy_segtree(int n)
    {
        this->n=n;
        tree.assign(4*n,0);
    }
    void update(int l,int r,int x)
    {
        function<void(int,int,int)> upd = [&](int tid,int tl,int tr)
        {
            // no overlap
            if(tl>r || tr<l) return;
            // complete overlap
            if(l<=tl && tr<=r)
            {
                tree[tid] += x;
                return;
            }
            // partial overlap
            int tm=(tl+tr)/2;
            upd(2*tid+1,tl,tm);
            upd(2*tid+2,tm+1,tr);
        };
        upd(0,0,n-1);
    }
    int query(int idx)
    {
        function<int(int,int,int)> qry = [&](int tid,int tl,int tr)
        {
            // leaf node
            if(tl==tr) return tree[tid];
            // partial overlap
            int tm=(tl+tr)/2;
            int ans=tree[tid];
            if(idx<=tm) ans+=qry(2*tid+1,tl,tm);
            else ans+=qry(2*tid+2,tm+1,tr);
            return ans;
        };
        return qry(0,0,n-1);
    }
};
void solve()
{
    int n,q; cin >> n >> q;
    lazy_segtree st(n);
    while(q--)
    {
        int t; cin >> t;
        if(t==1)
        {
            int l,r,x; cin >> l >> r >> x;
            st.update(l,r-1,x);
        }
        else
        {
            int idx; cin >> idx;
            cout << st.query(idx) << endl;
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