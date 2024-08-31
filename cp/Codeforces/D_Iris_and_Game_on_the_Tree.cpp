// https://codeforces.com/contest/2007/problem/D
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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

void solve()
{
    int n;cin>>n;
    // return;
    vvi adj(n);
    fon(i,n-1)
    {
        int a,b;cin>>a>>b;
        a--,b--;
        // deb(a)deb(b)
        adj[b].pb(a);
        adj[a].pb(b);
    }
    // return;
    // find leaf nodes 
    vi leafs;
    function<void(int,int)> dfs = [&](int u,int p)
    {
        if(adj[u].size()==1 and u!=0)
        {
            leafs.pb(u);
            return;
        }
        for(int i:adj[u])
        {
            if(i==p) continue;
            dfs(i,u);
        }
    };
    dfs(0,-1);
    sort(all(leafs));
    set<int> le(all(leafs));
    // deb(leafs);
    string s;cin>>s;
    int rtd=-1;
    map<int,int> mp;
    if(s[0]!='?') 
    {
        rtd=s[0]-'0';
    }
    int c1=0,c0=0,cq=0;
    int inq=0;
    fo1(i,1,n,1)
    {
        if(le.find(i)!=le.end())
        {
            if(s[i]=='0') c0++;
            else if(s[i]=='1') c1++;
            else cq++;
        }
        else 
        {
            inq+=s[i]=='?';
        }
    }
    if(rtd!=-1)
    {
        int ans;
        if(rtd==1) 
            ans=c0;
        else 
            ans=c1;
        ans+=(cq+1)/2;
        cout << ans << endl;
        return;
    }
    else
    {   

        if(inq&1) 
        {
            // firts dora max
            if(c0==c1) 
            {
                int ans=c0;
                ans+=(cq+1)/2;  
                cout << ans << endl;
            }
            else 
            {
                int ans=max(c0,c1);
                ans+=cq/2;
                cout << ans << endl;
            }
            // return;
        }
        else 
        {
            // fist iris mini
            if(c0==c1)
            {
                int ans=c0;
                ans+=cq/2;
                cout << ans << endl;
            }
            else 
            {   
                int ans=max(c0,c1);
                ans+=cq/2;
                cout << ans << endl;
            }
        }

    }
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