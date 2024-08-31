// https://www.codechef.com/problems/BREAKSTRING
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
// a string hashing function using 2 prime numbers and 2 mod values
const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int p1 = 31, p2 = 37;
vi p_pow1, p_pow2, hash1, hash2;

void precompute(const string &s) {
    int n = s.size();
    p_pow1.resize(n), p_pow2.resize(n);
    hash1.resize(n + 1, 0), hash2.resize(n + 1, 0);
    p_pow1[0] = p_pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow1[i] = (p_pow1[i - 1] * p1) % mod1;
        p_pow2[i] = (p_pow2[i - 1] * p2) % mod2;
    }
    for (int i = 0; i < n; i++) {
        hash1[i + 1] = (hash1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % mod1;
        hash2[i + 1] = (hash2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % mod2;
    }
}

pair<int, int> substring_hash(int l, int r) {
    int h1 = (hash1[r] - hash1[l] + mod1) % mod1;
    h1 = (h1 * p_pow1[p_pow1.size() - 1 - l]) % mod1;
    int h2 = (hash2[r] - hash2[l] + mod2) % mod2;
    h2 = (h2 * p_pow2[p_pow2.size() - 1 - l]) % mod2;
    return {h1, h2};
}

bool compare_substrings(int l1, int r1, int l2, int r2) {
    return substring_hash(l1, r1 + 1) == substring_hash(l2, r2 + 1);
}

void solve()
{
    string s;cin>>s;
    int n = s.size();
    int ans=0;
    precompute(s);
    // count the no of times when the string it is in the form of s(a)+s(a)+s(b)+s(b) 
    int a2l=0,b2l=n;
    while(b2l>=0)
    {
        int a1l=a2l/2,b1l=b2l/2;
        ans+=compare_substrings(0,a1l-1,a1l,a2l-1) and compare_substrings(a2l,n-b1l-1,n-b1l,n-1);
        a2l+=2;
        b2l-=2;
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