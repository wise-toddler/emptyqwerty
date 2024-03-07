// https://www.hackerearth.com/challenges/competitive/january-circuits-24/algorithm/leafonomics-1ab974a5/?
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
template<typename T>ostream& operator<<(ostream& os, v<v<T>>& v){for(auto& x : v)os << x << endl;return os;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
void solve()
{
    int n;cin >> n;
    vvi adj(n+1);
    map<pii,int> weight;
    fon(i,n-1)
    {
        int u,v;cin >> u >> v;
        int w;cin >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        weight[{u,v}] = w;
        weight[{v,u}] = w;
    }
    // cout << adj << endl;
    vi ans(n+1,0);
    function<void(int,int)> dfs = [&](int nd,int pr)
    {
        int minn= 1e17;
        if(adj[nd].size()==1)
        {
            ans[nd] = 0;
            return;
        }
        for(auto i : adj[nd])
        {
            if(i==pr)continue;
            dfs(i,nd);
            minn = min(minn,weight[{nd,i}]+ans[i]);   
        }
        ans[nd] = minn;
    };
    dfs(1,-1);
    fo1(i,1,n+1,1)cout << ans[i] << ' ';
    // nl
    function<void(int,int)> dfs2 = [&](int nd,int pr)
    {
        int mn=1e17,smn=1e17;
        for(auto i : adj[nd])
        {
            if(i==pr)continue;
            int val = weight[{nd,i}]+ans[i];
            if(val<mn)
            {
                smn = mn;
                mn = val;
            }
            else smn = min(smn,val);
        }
        int va= ans[nd];
        for(auto i : adj[nd])
        {
            if(i==pr)continue;
            int val = weight[{nd,i}]+ans[i];
            if(val==mn)
                ans[i] = min({ans[i],smn+weight[{nd,i}],ans[nd]+weight[{nd,i}]});
            else
                ans[i] = min({ans[i],mn+weight[{nd,i}],ans[nd]+weight[{nd,i}]});      
            dfs2(i,nd);      
        }

        // cout << nd << ' ' << ans[nd] << endl;
        // fo1(i,1,n+1,1)cout << ans[i] << ' ';
        // nl
    };
    dfs2(1,-1);
    nl
    fo1(i,1,n+1,1)cout << ans[i] << ' ';
    // cout << ans << endl;
    // nl
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