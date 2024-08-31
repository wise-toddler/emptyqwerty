// https://codeforces.com/contest/342/problem/E
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

/*
    *   BinaryLifting: just pass adj list to the constructor (0 based indexing)
    *   Methods: KthAncestor, LCA, Dist
    *   PreComputation: O(N*LogN)
    *   Query: O(LogN)
*/ 
int n;
vvi adj;
vi dist;
vi marked;
// https://github.com/ShahjalalShohag/code-library/blob/main/Graph%20Theory/LCA%20in%20O(1).cpp

template <class T>
struct RMQ { // 0-based
  vector<vector<T>> rmq;
  T kInf = numeric_limits<T>::max();
  void build(const vector<T>& V) {
    int n = V.size(), on = 1, dep = 1;
    while (on < n) on *= 2, ++dep;
    rmq.assign(dep, V);
 
    for (int i = 0; i < dep - 1; ++i)
      for (int j = 0; j < n; ++j) {
        rmq[i + 1][j] = min(rmq[i][j], rmq[i][min(n - 1, j + (1 << i))]);
      }
  }
  T query(int a, int b) { // [a, b)
    if (b <= a) return kInf;
    int dep = 31 - __builtin_clz(b - a); // log(b - a)
    return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};

struct LCA { // 0-based
  vector<int> enter, depth, exxit;
  vector<vector<int>> G;
  vector<pair<int, int>> linear;
  RMQ<pair<int, int>> rmq;
  int timer = 0;
  LCA() {} 
  LCA(int n) : enter(n, -1), exxit(n, -1), depth(n), G(n), linear(2 * n) {}
  void dfs(int node, int dep) {
    linear[timer] = {dep, node};
    enter[node] = timer++;
    depth[node] = dep;
    for (auto vec : G[node])
    if (enter[vec] == -1) {
      dfs(vec, dep + 1);
      linear[timer++] = {dep, node};
    }
    exxit[node] = timer;
  }

  void add_edge(int a, int b) {
    G[a].push_back(b);
    G[b].push_back(a);
  }
  void build(int root) {
    dfs(root, 0);
    rmq.build(linear);
  }
  int query(int a, int b) {
    a = enter[a], b = enter[b];
    return rmq.query(min(a, b), max(a, b) + 1).second;
  }
  int dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[query(a, b)];
  }
};
void bfs()
{
    queue<int> q;
    dist.assign(n,-1);
    for(int x=0;x<n;x++)
    {
        if(marked[x])
        {
            q.push(x);
            dist[x]=0;
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto x:adj[node])
        {
            if(dist[x]==-1)
            {
                dist[x]=dist[node]+1;
                q.push(x);
            }
        }
    }
}
void solve()
{
    int q;cin>>n>>q;
    adj.assign(n,vi());
    dist.assign(n,0);
    marked.assign(n,0);
    marked[0]=1;
    LCA bl(n);
    fon(i,n-1)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
        bl.add_edge(u,v);
    }
    bfs();
    bl.build(0);
    // deb(dist)
    
    int limit=1000;
    vi buffer;
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int x;cin>>x;
            x--;
            marked[x]=1;
            buffer.pb(x);
        }
        else
        {
            int x;cin>>x;
            x--;
            int ans=dist[x];
            for(auto y:buffer)
            {
                ans=min(ans,bl.dist(x,y));
            }
            cout << ans << endl;
        }
        if(buffer.size()>=limit)
        {
            bfs();
            buffer.clear();
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