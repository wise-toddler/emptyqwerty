// https://codeforces.com/contest/1946/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ff first
#define ss second
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
void solve()
{
    int n,x;cin >> n >> x;
    vvi adj(n+1);
    fon(i,n-1)
    {
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // v<pii> a(n+1); // highest level,second highest level
    map<pii,int> b; // highest level of child
    function<void(int,int)> dfs = [&](int u,int p) 
    {
        // a[u] = {l,0};
        int h=0;
        for(auto v : adj[u])
        {
            if(v == p) continue;
            dfs(v,u);
            if(b[{v,u}] > h) h = b[{v,u}];

        }
        if(p != 0) 
        {
            b[{u,p}] = h+1;
            b[{p,u}] = h+2;
        }
    };
    dfs(1,0);
    int w=0;
    // for(auto i:a) cout <<w++ << "  " <<i.ff << " " << i.ss << endl;
    for(auto i:b) cout << i.ff.ff << " " << i.ff.ss << " " << i.ss << endl;

    int c=0;
    int del = 0;
    // nl nl
    function<void(int,int)> dfs3 = [&](int u,int p)
    {
        for(auto v : adj[u])
        {
            if(v == p) continue;
            if(b[{u,v}] < x) continue;
            dfs3(v,u);
        }
        // cout << u << " " << p << " " << b[{u,p}]-del << " " << b[{p,u}] << endl;nl
        if((b[{u,p}]-del >= x) && (b[{p,u}] >= x))
        {
            c++;
            del += b[{u,p}];               
            b[{u,p}] = 0;
            b[{p,u}] = 0;  
        }
    };
    dfs3(1,0);
    cout << c+1 << endl;

    

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

// no of componect(forest) of atleast x size 
    // int n,x;cin >> n >> x;x++;
    // vvi adj(n+1);
    // fon(i,n-1)
    // {
    //     int u,v;cin >> u >> v;
    //     adj[u].pb(v);
    //     adj[v].pb(u);
    // }
    // vi a(n+1); // no of nodes 
    // function<void(int,int)> dfs = [&](int u,int p)
    // {
    //     a[u] = 1;
    //     for(auto v : adj[u])
    //     {
    //         if(v == p) continue;
    //         dfs(v,u);
    //         a[u] += a[v];
    //     }
    // };
    // dfs(1,0);
    // // for(auto i:a) cout << i << " ";

    // map<pii,int> b; 
    // int up = 0;
    // function<void(int,int)> dfs2 = [&](int u,int p)
    // {
    //     int total = a[u]+up;
    //     for(auto v : adj[u])
    //     {
    //         if(v == p) continue;
    //         b[{u,v}] = total-a[v];
    //         b[{v,u}] = a[v];
    //         up = total-a[v];
    //         dfs2(v,u);
    //     }
    // };
    // dfs2(1,0);
    // for(auto i:b) cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    // int c=0;
    // int del = 0;
    // // nl nl
    // function<void(int,int)> dfs3 = [&](int u,int p)
    // {
    //     for(auto v : adj[u])
    //     {
    //         if(v == p) continue;
    //         if(adj[v].size() <= 1) continue;
    //         dfs3(v,u);
    //         // if(b[{u,v}] >= x) c++;
    //     }
    //     // cout << u << " " << p << " " << b[{u,p}]-del << " " << b[{p,u}] << endl;nl
    //     if((b[{u,p}]-del >= x) && (b[{p,u}] >= x))
    //     {
    //         c++;
    //         del += b[{u,p}];               
    //         b[{u,p}] = 0;
    //         b[{p,u}] = 0;  
    //     }
    //     // deb(c)deb(del)nl
    // };
    // dfs3(1,0);
    // cout << c+1 << endl;