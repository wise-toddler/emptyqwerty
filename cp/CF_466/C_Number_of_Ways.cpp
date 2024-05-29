// https://codeforces.com/problemset/problem/466/C
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    int sum = accumulate(all(a),0LL);
    if(sum%3!=0)
    {
        cout << 0 << endl;
        return;
    }
    int req = sum/3;
    vi suf(n);
    suf[n-1] = a[n-1];
    fon_(i,n-1) suf[i] = suf[i+1]+a[i];
    // deb(suf);
    if(sum==0)
    {
        int cn = count(all(suf),0LL);
        cout << ((cn-1)*(cn-2))/2 << endl;
        return;
    }
    int ans = 0;
    int cnt = 0;
    fon_(i,n)
    {
        if(suf[i]==req) cnt++;
        if(suf[i]==2*req) ans+=cnt;
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