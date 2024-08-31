// https://www.codechef.com/START127B/problems/EXPCOMP
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
void solve()
{
    int n,m;cin >> n >> m;
    vi a(m);cin >> a;

    vvi adj(n+1);
    fon(i,n-1)
    {
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int explectedval = 0;
    for(auto i:a)
        explectedval += i;
    
    expectedval /= m;


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