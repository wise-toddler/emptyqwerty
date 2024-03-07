// https://cses.fi/problemset/task/1674
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
// void f()
void solve()
{
    int n;cin>>n;
    vvi a(n+1);
    fo1(i,2,n+1,1)
    {
        int x;cin>>x;
        a[x].pb(i);
    }
    vi anss(n+1);
    function<int(int)> dfs=[&](int u)
    {
        int ans=1;
        for(auto v : a[u])
            ans+=dfs(v);
        return anss[u]=ans;
    };//dfs
    dfs(1);
    fo1(i,1,n+1,1)
        cout << anss[i]-1 << ' ';

    // function<int(int)> bfs=[&](int u)
    // {
    //     queue<int> q;
    //     q.push(u);
    //     int ans=1;
    //     while(!q.empty())
    //     {
    //         int u=q.front();q.pop();
    //         for(auto v : a[u])
    //         {
    //             q.push(v);
    //             ans++;
    //         }
    //     }
    //     return ans;
    // };//bfs
    
    // fo1(i,1,n+1,1)
    //     cout << bfs(i)-1 << ' ';
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