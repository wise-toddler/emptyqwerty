// https://cses.fi/problemset/task/1137
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
#include <bits/stdc++.h>
using namespace std;
/*
 *  Segment Tree (0 based indexing)
 *  Point Update and Range Query O(log N)
 *  Usage:
    *   Pass initial array and neutral value to the constructor
    *   Create a merge function outside the class
 */
int merge(int a, int b) {
    return a + b;
}
#define v vector
template < typename T >
class SegmentTree 
{
    v < v < T >> Tree;
    T neutralValue;
    T query(int level, int idx, int treeLeft, int treeRight, int l, int r) {
        if (treeLeft > treeRight or treeRight < l or treeLeft > r or r < treeLeft or l > treeRight or level == Tree.size())
            return neutralValue;
        if (l <= treeLeft and treeRight <= r)
            return Tree[level][idx];
        int m = (treeLeft + treeRight) / 2;
        return merge(query(level + 1, 2 * idx, treeLeft, m, l, r), query(level + 1, 2 * idx + 1, m + 1, treeRight, l, r));
    }
public:
    SegmentTree(v<T> &A, T neutralValue) 
    {
        this -> neutralValue = neutralValue;
        int n = A.size();
        Tree.push_back(v < T > (1, neutralValue));
        int prev = 1;
        while (prev < n) {
            Tree.push_back(v < T > (2 * prev, neutralValue));
            prev *= 2;
        }
        int levels = Tree.size();
        for (int i = 0; i < n; i++)
            Tree[levels - 1][i] = A[i];
        for (int i = levels - 2; i >= 0; i--)
            for (int j = 0; j < (1 << i); j++)
                Tree[i][j] = merge(Tree[i + 1][2 * j], Tree[i + 1][2 * j + 1]);
    }
    void update(int idx, T val) {
        int levels = Tree.size();
        Tree[levels - 1][idx] = val;
        idx /= 2;
        for (int i = levels - 2; i >= 0; i--, idx /= 2)
            Tree[i][idx] = merge(Tree[i + 1][2 * idx], Tree[i + 1][2 * idx + 1]);
    }
    T query(int l, int r) {
        return query(0, 0, 0, Tree.back().size() - 1, l, r);
    }
};
void solve()
{
    int n,q;cin >> n >> q;
    vi a(n);
    vvi adj(n);
    cin >> a;
    // fo1(i,1,n+1,1)cin >> a[i];
    fon(i,n-1)
    {
        int u,v;cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);     
    }
    // flatten the tree
    vi euler;
    vi st(n),en(n);
    function<void(int,int)> dfs = [&](int nd,int pr)
    {
        st[nd] = euler.size();
        euler.pb(a[nd]);
        for(auto i : adj[nd])
        {
            if(i==pr)continue;
            dfs(i,nd);
        }
        en[nd] = euler.size();
        euler.pb(a[nd]);
    };
    dfs(0,-1);
    // cout << euler << endl;
    // cout << st << endl;
    // cout << en << endl;
    SegmentTree<int> s(euler,0);
    while(q--)
    {
        int ch;cin >> ch;
        if(ch==1)
        {
            int nd,x;cin >> nd >> x;
            nd--;
            s.update(st[nd],x);
            s.update(en[nd],x);
        }
        else
        {
            int nd;cin >> nd;
            nd--;   
            cout << s.query(st[nd],en[nd])/2 << endl;
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