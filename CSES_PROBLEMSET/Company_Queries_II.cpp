// 
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

#define v vector

/*
    *   BinaryLifting: just pass adj list to the constructor (0 based indexing)
    *   Methods: KthAncestor, LCA, Dist
    *   PreComputation: O(N*LogN)
    *   Query: O(LogN)
*/ 
class BinaryLifting
{
private:
    int n, LOGN, root;
    v<v<int>> up;
    v<int> depth;
    v<v<int>> children;
    void init(v<int> &parent)
    {
        LOGN = log2(n) + 1;
        up.assign(n, v<int>(LOGN, -1));
        depth.assign(n, 0);
        children.resize(n);
        
        for (int i = 0; i < n; ++i)
            up[i][0] = parent[i];
        
        for (int i = 0; i < n; ++i)
        {
            if (parent[i] != -1)
                children[parent[i]].push_back(i);
            else
                root = i;
        }
    }
    void buildDfs(int node, int d)
    {
        for(int i = 1; i < LOGN and up[node][i - 1] != -1; ++i)
        {
            int node_ = up[node][i - 1];
            if(node_ != -1) up[node][i] = up[node_][i - 1];
        }

        depth[node] = d;
        for (int child : children[node])
            buildDfs(child, d + 1);
        
    }
public:
    BinaryLifting(v<v<int>> &adj, int root = 0)
    {
        this->root = root;
        n = adj.size();
        v<int> parent(n, -1);
        function<void(int, int)> buildParentArray = [&](int cur, int p) {
            parent[cur] = p;
            for(int nb : adj[cur])
                if(nb != p)
                    buildParentArray(nb, cur);
        };
        buildParentArray(root, -1);
        init(parent);
        buildDfs(root, 0);
    }
    int getKthAncestor(int node, int k)
    {
        for (int i = LOGN - 1; i >= 0 and node != -1; --i)
        {
            if (k & (1 << i))
                node = up[node][i];
        }
        return node;
    }
    int getLCA(int node1, int node2)
    {
        if (depth[node1] < depth[node2])
            swap(node1, node2);
        node1 = getKthAncestor(node1, depth[node1] - depth[node2]);
        if (node1 == node2)
            return node1;
        for (int i = LOGN - 1; i >= 0; --i)
        {
            int node1_ = up[node1][i], node2_ = up[node2][i];
            if (node1_ != node2_)
                node1 = node1_, node2 = node2_;
        }
        return getKthAncestor(node1, 1);
    }
    int getDist(int node1, int node2)
    {
        return depth[node1] + depth[node2] - 2 * depth[getLCA(node1, node2)];
    }
};
void solve()
{
    int n,q;cin>>n>>q;
    vvi adj(n);
    fo1(i,1,n,1)
    {
        int p;cin>>p;
        p--;
        adj[i].pb(p);
        adj[p].pb(i);
    }
    BinaryLifting bl(adj);
    while(q--)
    {
        int a,b;cin>>a>>b;
        a--;
        b--;
        int ans=bl.getLCA(a,b);
        ans++;
        cout << ans << '\n';
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