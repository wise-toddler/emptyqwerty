// https://www.codechef.com/START146B/problems/BOUNCE_BALL
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
    int n;cin >> n;
    vi a(n);cin >> a;
    vi pre(n),suf(n);
    pre[0]=a[0];
    suf[n-1]=a[n-1];
    fo1(i,1,n,1)
    {
        pre[i]=pre[i-1]+a[i];
    }
    fon_(i,n-1)
    {
        suf[i]=suf[i+1]+a[i];
    }
    // deb(pre)deb(suf)
    int ans=0;
    fon(i,n)
    {
        if(a[i]) continue;  
        if(pre[i]==suf[i])
        {
            ans+=2;
        }
        if(abs(pre[i]-suf[i])==1)
        {
            ans++;
        }
    }
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