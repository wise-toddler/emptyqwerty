// https://cses.fi/problemset/task/2134
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
        // write your merge function here
        return max(a,b);
    }
    segtree(){}
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
    void build(v<T>& a)
    {
        fon(i,n) upt(i,a[i]);
    }
};

class HLD 
{
public:
    int n;
    v<vi> adj;
    vi size;
    int cur_pos;
    segtree<int> st;
    vi head;
    vi path;    
    vi posinpath;
    vi parent;
    HLD(int n,int idn, vi nodeValues, v<vi> adj)
    {
        this->n = n;
        this->adj = adj;
        size.assign(n, 1);
        cur_pos = 0;
        st = segtree<int>(n, idn);
        head.assign(n,-1);
        path.clear();
        posinpath.assign(n,-1);
        parent.assign(n,-1);
        dfs(0, -1);
        // deb(size)
        bld(0, -1, true);
        fon(i,n) st.upt(posinpath[i], nodeValues[i]);
        deb(path)
        deb(posinpath)
    } 

    void dfs(int v, int p) 
    {
        for (int &u : adj[v]) 
        {
            if (u != p) 
            {
                dfs(u, v);
                size[v] += size[u];
            }
        }
    }
    void bld(int v, int p, bool new_chain) 
    {
        parent[v] = p;
        if (new_chain) head[v] = v;
        else head[v] = head[p];
        path.pb(v);
        posinpath[v] = path.size() - 1;
        // st.upt(cur_pos++, nodeValues[v]);
        int heavy_child = -1;
        for (int u : adj[v]) 
        {
            if (u==p) continue;
            if (heavy_child == -1 || size[u] > size[heavy_child]) heavy_child = u;    
        }
        if (heavy_child != -1) bld(heavy_child, v, false);
        
        for (int u : adj[v]) 
        {
            if (u != p && u != heavy_child) 
            {
                bld(u, v, true);
            }
        }
    }
    void update(int node, int val) 
    {
        st.upt(posinpath[node], val);
    }
    int query(int a, int b) 
    {
        int res = INT_MIN;
        for (; head[a] != head[b] and b!=-1 ; b = parent[head[b]]) 
        {
            if (size[head[a]] > size[head[b]]) swap(a, b);
            res = max(res, st.qry(posinpath[head[b]], posinpath[b]));
        }
        if (size[a] > size[b]) swap(a, b);

    }
    
};
void solve()
{
    int n, q;cin >> n >> q;
    vi a(n);cin >> a;
    vvi adj(n);
    fon(i,n-1)
    {
        int u, v;cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // deb(adj)
    HLD hld(n, INT_MIN, a, adj);
    // while(q--)
    // {
    //     int t;cin >> t;
    //     if(t==1)
    //     {
    //         int s, x;cin >> s >> x;
    //         hld.update(s-1, x);
    //     }
    //     else
    //     {
    //         int a, b;cin >> a >> b;
    //         cout << hld.query(a-1, b-1) << endl;
    //     }
    // }
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