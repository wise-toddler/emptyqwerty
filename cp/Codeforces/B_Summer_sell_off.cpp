// https://codeforces.com/contest/810/problem/B
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,f;cin >> n >> f;
    v<pii> a(n);
    for(auto &[x,y]:a) cin >> x >> y;
    sort(all(a),[&](pii x,pii y){return min(2*x.ff,x.ss)-min(x.ff,x.ss)>min(2*y.ff,y.ss)-min(y.ff,y.ss);});
    int ans=0;
    fon(i,n)
    {
        if(i<f) ans+=min(2*a[i].ff,a[i].ss);
        else ans+=min(a[i].ff,a[i].ss);
    }
    cout << ans << endl;
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