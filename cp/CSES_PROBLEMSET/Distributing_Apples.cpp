// https://cses.fi/problemset/task/1716
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
int m=1e9+7;
int pow(int a,int b,int m)
{
    if(b==0) return 1;
    int ans = pow(a,b/2,m);
    ans = (ans*ans)%m;
    if(b&1) ans*=a;
    return ans%m;
}
int N=2e6+1;
vi fact(N);
vi inv(N);
void pre()
{
    fact[0]=1;
    inv[0]=1;
    fo1(i,1,N,1)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=m;
    }
    inv[N-1]=pow(fact[N-1],m-2,m);
    fon_(i,N-1)
    {
        inv[i]=inv[i+1]*(i+1);
        inv[i]%=m;
    }
}
void solve()
{
    int a,b;cin >> a >> b;
    int nu = fact[a+b-1];
    int deinv = (inv[a-1]*inv[b])%m;
    int ans= (nu*deinv)%m;
    cout << ans << endl;

}
signed main()
{
    pre();
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