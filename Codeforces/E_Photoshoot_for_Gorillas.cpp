// https://codeforces.com/contest/2000/problem/E
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
    int n,m,k;cin >>n >> m>>k;
    int w;cin >>w;
    vi a(w);cin >> a;
    sort(all(a),greater<int>());
    // deb(a);
    vi con;
    // fon(i,n)
    fo1(i,1,n+1,1)
    {
        // fon(j,m)
        fo1(j,1,m+1,1)
        {
            // int ii=min(i,n-i-1);
            // int jj=min(j,m-j-1);
            // int ii=i;
            // int jj=j;
            // int cc=(ii+1-min(n-k+1,max(ii+1-k,0ll) )))*(jj+1-min(m+1-k,max(jj+1-k,0ll)));
            // int rmax=min(n,ii+k);
            // // deb(rmax);
            // int rmin=max(ii-k,0ll);
            // // deb(rmin);
            // int r=min(n,ii+k)-max(ii-k,0ll)-1;
            // // deb(r)/
            // int c=min(m,jj+k)-max(jj-k,0ll)-1;
            int r=min(i,n-k+1)-max(0ll,i-k);
            int c=min(j,m-k+1)-max(0ll,j-k);
            // deb(c)
            con.pb(r*c);
            // nl
        }
    }
    // deb(con);
    sort(all(con),greater<int>());
    int ans=0;
    fon(i,w) ans+=a[i]*con[i];
    cout << ans << endl;
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

/*

.....
.....
.....
.....
.....

*/