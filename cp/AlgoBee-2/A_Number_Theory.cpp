// https://codeforces.com/gym/517983/problem/A
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
int MOD = 1e9+7;
int pow_mod(int x, int y) 
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return pow_mod((x*x) % MOD, y/2) % MOD;
    else
        return (x*pow_mod((x*x) % MOD, y/2)) % MOD;
}

int sum_divisors(int n, int p) {
    return (pow_mod(n, p+1) - 1) * pow_mod(n-1, MOD-2) % MOD;
}
void solve()
{
    int n; cin >> n;
    int result = 1;
    for (int i = 0; i < n; i++) {
        int p, a; cin >> p >> a;
        result *= sum_divisors(pow_mod(p, 69), a);
        result %= MOD;
    }
    cout << result << endl;
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
    }
}
