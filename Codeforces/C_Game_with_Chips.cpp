// https://codeforces.com/contest/1327/problem/C
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
    int n,m,q;cin >> n >> m >> q;
    int a,b;
    fon(i,2*q) cin >> a >> b;
    int ans=n-1+m-1+n-1+n*(m-1);
    cout << ans << endl;
    // cout << (n-1+m-1+n-1+n*(m-1)) << endl;
    fon(i,n-1) cout << 'U';
    fon(i,m-1) cout << 'L';
    fon(i,n)fon(j,m-1)
    {
        if(i%2==0) cout << 'R';
        else cout << 'L';
        if((j==m-2) and (i!=n-1)) cout << 'D';
    }
    if(m==1)
    {
        fon(i,n-1) cout << 'D';
    }
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}