// https://cses.fi/problemset/task/1647
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
    int n,q;cin >> n >> q;
    vi a(n);cin >> a;
    // Sparse Table
    int k=log2(n)+1;
    vvi st(n,vi(k));
    for(int i=0;i<n;i++) 
        st[i][0]=a[i];

    for(auto i:st) cout << i << endl;nl
    
    fo1(j,1,k,1) 
        for(int i=0;i+(1<<j)<=n;i++) 
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    
    for(auto i:st) cout << i << endl;nl
    
    // Queries
    while(q--)
    {
        int l,r;cin >> l >> r;
        l--;r--;
        int j=log2(r-l+1);
        cout << min(st[l][j],st[r-(1<<j)+1][j]) << endl;
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