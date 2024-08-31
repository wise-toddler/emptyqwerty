// https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/E
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
// int mod=1e9+7;
class lazy_segtree
{
public:
    int n;
    vi tree,lazy_vals;
    v<bool> lazy;
    lazy_segtree(int n)
    {
        this->n=n;
        tree.assign(4*n,0);
        lazy.assign(4*n,false);
        lazy_vals.assign(4*n,0);
    }
    void propogate(int tid,int tl,int tr)
    {
        if(!lazy[tid]) return;
        if(tr!=tl)
        {
            lazy_vals[2*tid+1]=lazy_vals[tid];
            lazy_vals[2*tid+2]=lazy_vals[tid];

            // lazy_vals[2*tid+1]%=mod;
            // lazy_vals[2*tid+2]%=mod;
            
            lazy[2*tid+1]=true;
            lazy[2*tid+2]=true;
        }
        tree[tid]=lazy_vals[tid];
        lazy[tid]=false;
        lazy_vals[tid]=0;
    }
    void update(int l,int r,int x)
    {
        function<void(int,int,int)> upd=[&](int tid,int tl,int tr)
        {
            propogate(tid,tl,tr);
            if(tl>r || tr<l) return;
            if(l<=tl && tr<=r)
            {
                lazy[tid]=true;
                lazy_vals[tid]=x;
                // lazy_vals[tid]%=mod;
                propogate(tid,tl,tr);
                return;
            }
            int tm=(tl+tr)/2;
            upd(2*tid+1,tl,tm);
            upd(2*tid+2,tm+1,tr);
            tree[tid]=min(tree[2*tid+1],tree[2*tid+2]);
            // tree[tid]%=mod;
        };
        upd(0,0,n-1);
    }
    // void update(int i,int x)
    // {
    //     function<void(int,int,int)> upd = [&](int tid,int tl,int tr)
    //     {
    //         if(tl==tr) 
    //         {
    //             tree[tid]=x;
    //             return;
    //         }
    //         int tm=(tl+tr)/2;
    //         if(i<=tm) upd(2*tid+1,tl,tm);
    //         else upd(2*tid+2,tm+1,tr);
    //         tree[tid]=tree[2*tid+1] & tree[2*tid+2];
    //     };
    //     upd(0,0,n-1);
    // }
    int query(int l,int r)
    {
        function<int(int,int,int)> qry=[&](int tid,int tl,int tr) -> int
        {
            propogate(tid,tl,tr);
            if(tl>r || tr<l) return INT_MAX;
            if(l<=tl && tr<=r) return tree[tid];
            int tm=(tl+tr)/2;
            int ans = min(qry(2*tid+1,tl,tm),qry(2*tid+2,tm+1,tr));
            // ans%=mod;
            return ans;
        };
        return qry(0,0,n-1);
    }
};
void solve()
{
    int n,m;cin >> n >> m;
    lazy_segtree st(n);
    // fon(i,n) st.update(i,0);
    while(m--)
    {
        int t;cin >> t;
        if(t==1)
        {
            int l,r,x;cin >> l >> r >> x;
            st.update(l,r-1,x);
        }
        else
        {
            int l,r;cin >> l >> r;
            cout << st.query(l,r-1) << endl;
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