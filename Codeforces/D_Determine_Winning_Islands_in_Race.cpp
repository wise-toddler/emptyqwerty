// https://codeforces.com/contest/1998/problem/D
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
void solve()
{
    int n,m;cin >> n >> m;
    vvi adj(n);
    fon(i,n-1)
    {
        adj[i].pb(i+1);
    }
    fon(i,m)
    {
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].pb(v);
    }
    // distance to n-1
    vi dist(n,LLONG_MAX);
    queue<int> q;
    q.push(0);
    dist[0]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(dist[v]>dist[u]+1)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    deb(dist);
    // winning islands
    vi win(n-1);
    win[0]=1;
    fo1(i,1,n-1,1)
    {
        int ans=1;
        fo1(j,i+1,n-1,1)
        {
            if(dist[j]<j-i)
            {
                ans=0;
                break;
            }
        }
        win[i]=ans;
    }
    cout << win << endl;
    // vi ans;

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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}