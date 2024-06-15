// https://codeforces.com/contest/1979/problem/C
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
    v<pii> sortedindex;
    fon(i,n)
    {
        sortedindex.pb({a[i],i});
    }
    sort(all(sortedindex),greater<pii>());  
    map<int,int> recover;
    fon(i,n)
    {
        recover[i]=sortedindex[i].ss;
    }
    sort(all(a),greater<int>());
    vi ans(n);
    ans[0]=1e8;
    fon(i,n)
    {
        if(i==0) continue;
        ans[i]=ceil(((double)ans[0]*a[0])/a[i]);
    }
    // cout << ans << endl;
    int sum= accumulate(all(ans),0LL);
    // deb(sum)
    // deb(ans)
    vi lot;
    fon(i,n)
    {
        lot.pb(a[i]*ans[i]);
    }
    // deb(sum)
    // deb(a)
    // deb(ans)
    // deb(lot)
    // cout << recover << endl;    
    if(sum<ans[0]*a[0]) 
    {
        // cout << ans << endl;
        // print back in original order
        vi final(n);
        fon(i,n)
        {
            final[recover[i]]=ans[i];
        }
        cout << final << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    // nl nl
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
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}