// https://codeforces.com/gym/545754/problem/C
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
// vi dp(1e6+1,-1);
void solve()
{
    auto f = [&](int x)
    {
        return 2*(2+3*x+(23*x*x));
    };
    int n;cin>>n;
    int l=0;
    int r=5e8;
    // cout << f(r) << endl;
    int ans=0;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(f(m)>=n)
        {
            ans=m;
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS
    // f(x) = 6*(6+9x+69x^2)/9;
    // fon(i,1e6+1)
    // {
    //     dp[i]=f(i);
    // }
    // // cout << dp[1e6] << endl;    

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