// https://www.codechef.com/START123B/problems/CONQUEROR
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
// make trie to cnt the number of leaf nodes in the subtree of each node
pair<int,int> dfs1(int nd,vvi &adj,int k,int p=-1,v<bool> &isleaf,v<int> &height,v<pii> &inandout)
// return cnt of leafs less than height k and cnt of all leafs in the subtree
{
    auto [l,r] = inandout[nd];
    if(r-l==1)
        return {1,1};
    
    // all with k ans and without k ans 
    // can take atmost 1 without k ans and all k ans other than that of without k ans


}


class trie
{
public:
    v<trie*> child;
    vi idxs;
    trie(){child.resize(2);}
    int cnt(int l,int r)
    {
        auto ll = lower_bound(all(idxs),l);
        auto rr = lower_bound(all(idxs),r+1);
        if(ll == idxs.end() || rr == idxs.begin())
            return 0;
        return rr-ll;
    }
};
trie* root = new trie();
void insert(int x,int idx)
{
    trie* cur = root;
    root->idxs.pb(idx);
    for(int i=31;i>=0;i--)
    {
        int b = (x>>i)&1;
        if(!cur->child[b])
            cur->child[b] = new trie();
        cur = cur->child[b];
        cur->idxs.pb(idx);
    }
}
void solve()
{
    int n,k;cin >> n >> k;
    // input n-1 edges
    vvi adj(n);
    fon(i,n-1)
    {
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // BinaryLifting bl(adj);
    vi euler;
    v<pii> inandout(n);
    v<bool> isleaf(n,0);
    int level=0;
    vi height(n,0);
    vi cntleaf(n,INT_MAX);
    function<void(int,int)> dfs1 = [&](int u,int p)
    {
        inandout[u].first=euler.size();
        euler.pb(u);
        level++;
        height[u]=level;
        if(adj[u].size()==1 && u!=0)
        {
            euler.pb(u);
            inandout[u].second=euler.size()-1;
            isleaf[u]=1;
            level--;
            return;
        } 
        for(int v:adj[u])
        {
            if(v==p)continue;
            dfs1(v,u);
            euler.pb(u);
        }
        inandout[u].second=euler.size()-1;
        level--;
    };
    dfs1(0,-1);
    cout << euler << endl;
    for(auto i:isleaf) cout << i << " "; nl
    deb(height)

    for(auto i:inandout) cout << i.first << " " << i.second << endl;
    for(int i:euler)
        insert((isleaf[i]?height[i]:INT_MAX),i);
    
    
    

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}