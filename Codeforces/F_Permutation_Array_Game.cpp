// https://codeforces.com/gym/543239/problem/F
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
const int MOD = 1e9+7;
int f(const vector<int>& a) {
    int n = a.size();
    long long total_sum = 0;

    // Precompute factorials modulo MOD
    vector<long long> factorial(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }

    // Sum of f_a over all permutations
    for (int i = 0; i < n; ++i) {
        long long contribution = a[i] * factorial[n - 1] % MOD;
        total_sum = (total_sum + contribution) % MOD;
    }

    return total_sum;
}
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    cout << f(a) << endl;
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