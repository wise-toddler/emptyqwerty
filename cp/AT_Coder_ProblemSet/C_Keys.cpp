// https://atcoder.jp/contests/abc356/tasks/abc356_c
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
    int n,m,k;cin >> n >> m >> k;
    // generate all bitmasks of length n
    vvi in;
    v<bool> res;
    fon(i,m)
    {
        int nn;cin >> nn;
        vi a(nn);cin >> a;
        in.pb(a);
        char c;cin >> c;
        res.pb(c=='o');
    }
    // for(auto i:res)
    // {
    //     cout << (i?1:0) << " ";
    // }
    // cout << endl;
    nl
    int nn = 1<<n;
    int ans=0;
    fon(p,nn)
    {
        
        int pp = 0;
        fon(i,m)
        {
            int cnt=0;
            for(auto x : in[i])
                if((p>>(x-1))&1)
                    cnt++;
            if((cnt>=k)==res[i])
            {
                pp++;
                // deb(cnt)
                // deb(i)
                // // const int a=n;
                // cout << bitset<3>(p)<< endl; nl
            }
        }
        ans+=(pp==m);
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
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}