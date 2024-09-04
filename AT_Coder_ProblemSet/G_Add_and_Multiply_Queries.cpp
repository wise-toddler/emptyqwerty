// https://atcoder.jp/contests/abc368/tasks/abc368_g
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
#define sz(x) (int)x.size()
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
        return a*b;
        // write your merge function here
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
    int n;cin>>n;
    vi a(n);cin>>a;
    vi b(n);cin>>b;
    set<int> s; // pos of 1 in b
    fon(i,n) if(b[i]==1) s.insert(i);
    segtree<int> st(n,1);
    fon(i,n) st.upt(i,b[i]);
    int q;cin>>q;
    while(q--)
    {
        int t;cin>>t;
        switch (t)
        {
            case 1: 
            {
                int x,y;cin>>x>>y;
                x--;
                a[x]=y;
                break;
            }
            case 2:
            {
                int x,y;cin>>x>>y;
                x--;
                if(b[x]==1) s.erase(x);
                b[x]=y;
                if(b[x]==1) s.insert(x);
                st.upt(x,b[x]);        
                break;
            }
            case 3:
            {
                int l,r;cin>>l>>r;
                l--,r--;
                int ans=a[l];
                l++;
                while(l<=r)
                {
                    auto it=s.upper_bound(l);
                    // if(it!=s.end())
                    // deb(*it);
                    if(it==s.end() or *it>r)
                    {
                        deb(st.qry(l,r));
                        ans*=st.qry(l,r);
                        break;
                    }
                    else 
                    {
                        int idx=*it;
                        ans*=st.qry(l,idx-1);
                        ans+=a[idx];
                        l=idx+1;
                    }
                }
                cout << ans << endl;
            }
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