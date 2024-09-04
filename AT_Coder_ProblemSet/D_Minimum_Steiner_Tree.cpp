// https://atcoder.jp/contests/abc368/tasks/abc368_d
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



//A tree without skin will surely die.
//A man without face will be alive.
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
int const N=2e5+10;
int n,q,fa[20][N],g[N],dep[N],dfn[N],rev[N];
vector< pair<int,int> >a[N];
inline void dfs(int x,int Fa){
    fa[0][x]=Fa,g[x]=g[Fa]+1,dfn[x]=++dfn[0],rev[dfn[0]]=x;
    for (auto i:a[x]){
        int v=i.first,w=i.second;
        if (v==Fa) continue;
        dep[v]=dep[x]+w,dfs(v,x);
    }
}
inline int LCA(int x,int y){
    if (g[x]<g[y]) swap(x,y);
    per(i,19,0) if (g[fa[i][x]]>=g[y]) x=fa[i][x];
    if (x==y) return x;
    per(i,19,0) if (fa[i][x]^fa[i][y]) x=fa[i][x],y=fa[i][y];
    return fa[0][x];
}
inline int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int ans;set<int>s;
inline void add(int x){
    if (!s.size()) s.insert(dfn[x]);
    else{
        auto it1=s.upper_bound(dfn[x]);
        if (it1==s.end()) it1=s.begin();
        auto it2=s.upper_bound(dfn[x]);
        if (it2==s.begin()) it2=--s.end();
        else --it2;
        ans-=dis(rev[*it1],rev[*it2]);
        ans+=dis(x,rev[*it1]),ans+=dis(x,rev[*it2]);
        s.insert(dfn[x]);
    }
}
inline void del(int x){
    if (s.size()==1) s.erase(dfn[x]);
    else{
        auto it1=s.upper_bound(dfn[x]);
        if (it1==s.end()) it1=s.begin();
        auto it2=s.find(dfn[x]);
        if (it2==s.begin()) it2=--s.end();
        else --it2;
        ans+=dis(rev[*it1],rev[*it2]);
        ans-=dis(x,rev[*it1]),ans-=dis(x,rev[*it2]);
        s.erase(dfn[x]);
    }
}
inline void solve(){
    cin>>n;
    int k;cin>>k;
    rep(i,1,n-1){
        int u,v;cin>>u>>v;
        int w=1;
        a[u].emplace_back(v,w);
        a[v].emplace_back(u,w);
    }
    dfs(1,0);
    rep(j,1,19) rep(i,1,n) fa[j][i]=fa[j-1][fa[j-1][i]];
    rep(i,1,k){
        int x;cin>>x;
        add(x);
    }
    cout << ans/2+1 << endl;
    // cin>>q;
    // while (q--){
    //     char op;cin>>op;
    //     switch (op){
    //         case '+':{
    //             int x;cin>>x,add(x);
    //             break;
    //         }
    //         case '-':{
    //             int x;cin>>x,del(x);
    //             break;
    //         }
    //         case '?':{
    //             cout<<ans/2<<'\n';
    //             break;
    //         }
    //     }
    // }
}

// void solve()
// {
//     int n,k;cin>>n>>k;
//     vvi adj(n);
//     fon(i,n-1)
//     {
//         int u,v;cin>>u>>v;
//         u--,v--;
//         adj[u].pb(v);
//         adj[v].pb(u);
//     }
//     vi req(k);cin>>req;
//     vi dp(n,0);

//     // The minimum number of edges required to connect all vertices in v to form a tree 



    
// }
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