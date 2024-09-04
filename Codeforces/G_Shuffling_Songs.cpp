// https://codeforces.com/contest/1950/problem/G
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
// multiset<string> ffi, sse;
v<pair<string, string>> a;
int check[17][17];
int dp[1<<17][17];
// int dp[17];
int rec(int mask,int pr)
{
    int &ans = dp[mask][pr]; if(ans != -1) return ans;
    ans = 0;
    fon(i,a.size())
    {
        if(mask & (1<<i)) continue;
        if((!mask) || check[pr][i])
        {
            ans = max(ans,rec(mask | (1<<i),i) + 1);
        }

    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    a.clear();
    a.resize(n);
    for (auto &[x, y] : a) cin >> x >> y;
    fon(i,n) fon(j,n) check[i][j] = ((a[i].ff == a[j].ff) || (a[i].ss == a[j].ss));
    fon(i,1<<n) fon(j,n) dp[i][j] = -1;
    cout << n-rec(0,0) << endl;
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