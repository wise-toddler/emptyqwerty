// https://cses.fi/problemset/task/1132/
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
#define mx 0
#define smx 1
void solve()
{
    int n ;cin>>n;
    vvi adj(n+1);
    fo1(i,0,n-1,1)
    {
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int down[n+1][2],up[n+1];
    memset(down,0,sizeof down);
    memset(up,0,sizeof up);
    function<int(int,int)> f=[&](int nd,int pr)
    {
        for(int i:adj[nd])
        {
            if(i==pr) continue;
            int c=f(i,nd);
            if(c>down[nd][mx])
            {
                down[nd][smx]=down[nd][mx];
                down[nd][mx]=c;
            }
            else if(c>down[nd][smx])
                down[nd][smx]=c;
        }
        down[nd][mx]++; 
        down[nd][smx]++;
        return down[nd][mx];
    };
    f(1,0);
    function<void(int,int)> g=[&](int nd,int pr)
    {
        for(int i:adj[nd])
        {
            if(i==pr) continue;
            // int c=
            if(down[nd][mx]==down[i][mx]+1)
                up[i]=max(up[nd],down[nd][smx])+1;
            else
                up[i]=max(up[nd],down[nd][mx])+1;
            g(i,nd);
        }
    };
    g(1,0);
    for(int i=1;i<=n;i++)
        cout << max(up[i],down[i][mx])-1 << ' ';
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