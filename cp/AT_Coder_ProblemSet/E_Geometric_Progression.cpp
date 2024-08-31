// https://atcoder.jp/contests/abc293/tasks/abc293_e
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
int pow(int a,int b,int m)
{
    if(b==0) return 1;
    int ans = pow(a,b/2,m);
    ans = (ans*ans)%m;
    if(b&1) ans*=a;
    return ans%m;    
}

int f(int r,int n,int m)
{
    if(n==0) return 0;
    if(n==1) return 1%m;  
    int ans = ((1+pow(r,n/2,m))%m)*(f(r,n/2,m));
    ans%=m;
    if(n&1) ans=(ans+pow(r,n-1,m));
    return ans%m;
}
void solve()
{
    int r,n,m;cin >> r >> n >> m;
    cout << f(r,n,m);
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
// sum of gp = (r^n-1)/(r-1);
// n=10
// r=3
// 