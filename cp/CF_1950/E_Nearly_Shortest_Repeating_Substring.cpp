// https://codeforces.com/contest/1950/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define fo1(i, st, en, up) for (int i = st; (i * (up > 0 ? 1 : -1)) < (en * (up > 0 ? 1 : -1)); i += (up))
#define fon(i, n) fo1(i, 0, n, 1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
template <typename T>
istream &operator>>(istream &is, v<T> &v)
{
    for (auto &x : v)
        is >> x;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, v<T> &v)
{
    for (auto &x : v)
        os << x << ' ';
    return os;
}
vi factors(int n)
{
    vi f;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f.pb(i);
            if (i != n / i)
                f.pb(n / i);
        }
    }
    sort(all(f));
    return f;
}
string make(string s, int n)
{
    string ans;
    1 2 4 8 for (int i = 0; i < n; i++)
    {
        ans += s;
    }
    return ans;
}
bool ch(string s, string t)
{
    if (s.size() != t.size())
        return false;
    int diff = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
            diff++;
    }
    return diff <= 1;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi f = factors(n);
    int ans = n;
    // cout << f << endl;
    for (auto x : f)
    {
        string t1 = make(s.substr(0, x), n / x);
        string t2 = make(s.substr(x, x), n / x);
        // cout << t1 << " " << t2 << endl;
        if (ch(t1, s) || ch(t2, s))
        {
            ans = x;
            break;
        }
    }
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