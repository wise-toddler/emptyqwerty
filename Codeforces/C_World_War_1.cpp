// https://codeforces.com/gym/105005/problem/C
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
void solve()
{
    int k;
    cin >> k; // range of gun
    // vi a(k);cin >> a;
    int l, n; cin >> l >> n; // l = starting pos of l, n = number of soldiers
    int r, m; cin >> r >> m; // r = starting pos of r, m = number of soldiers
    vi g(m); cin >> g;

    int ll = max(l - k - r, 0LL);
    int rr = min(l + n - 1 + k - r, m - 1);
    if (ll > rr || ll >= m || rr < 0)
    {
        cout << accumulate(all(g), 0LL) << endl;
        return;
    }
    // remove max +ve m soldiers in range 
    // vi rm(g.begin() + ll, g.begin() + rr + 1);
    int sz= rr-ll+1;
    // cout << sz << endl;
    // deb(sz);
    vi rm(sz);
    for (int i = ll; i <= rr; i++)   
    { 
        rm[i - ll] = g[i];
        g[i] = 0;
    }

    sort(all(rm), greater<int>());
    for (int i = 0; i < rr - ll + 1 && i<n && rm[i]>0;i++)
        rm[i] = 0;
    

    int ans = accumulate(all(rm), 0LL)+accumulate(all(g), 0LL);
    cout << ans << endl;
}
signed main()
{
    IOS
    // TxtIO
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}