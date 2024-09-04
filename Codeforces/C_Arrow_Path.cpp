// https://codeforces.com/contest/1948/problem/C
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
template <typename E>
class mstack : public stack<E>
{
public:
    E pop()
    {
        E a = this->top();
        stack<E>::pop();
        return a;
    }
};

void solve()
{
    int n;
    cin >> n;
    v<v<char>> a(2, v<char>(n));
    cin >> a;
    int ch = 1;
    z
        vvi vis(2, vi(n, 0));
    vis[0][n - 1] = 0;
    vis[1][n - 1] = 1;
    vis[0][n - 2] = 0;
    if (a[1][n - 2] == '>')
        vis[0][n - 2] = 1;
    else
        vis[0][n - 2] = 0;

    for (int i = n - 3; i >= 0; i--)
    {
        vis[0][i] = 0;
        if (a[0][i + 1] == '>' && vis[0][i + 2] == 1)
            vis[0][i] = 1;
        if (a[1][i] == '>' && vis[1][i + 1] == 1)
            vis[0][i] = 1;
        vis[1][i] = 0;
        if (a[1][i + 1] == '>' && vis[1][i + 2] == 1)
            vis[1][i] = 1;
        if (a[0][i] == '>' && vis[0][i + 1] == 1)
            vis[1][i] = 1;
    }
    cout << (vis[0][0] ? "YES" : "NO") << endl;
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

/*
    int n; cin >> n;
    string s0; cin >> s0;
    string s1; cin >> s1;

    int dp[n][2];

    dp[n - 1][0] = 0;
    dp[n - 1][1] = 1;
    dp[n - 2][1]= 0;

    if (s1[n - 2] == '>'){
        dp[n - 2][0] = 1;
    }else{
        dp[n - 2][0] = 0;
    }
    for (int i = n - 3; i >= 0; i--){
        dp[i][0] = 0;

        if (s0[i + 1] == '>' && dp[i + 2][0] == 1) dp[i][0] = 1;
        if (s1[i] == '>' && dp[i + 1][1] == 1) dp[i][0] = 1;

        dp[i][1] = 0;

        if (s1[i + 1] == '>' && dp[i + 2][1] == 1) dp[i][1] = 1;
        if (s0[i] == '>' && dp[i + 1][0] == 1) dp[i][1] = 1;

    }

    cout << (dp[0][0] ? "YES" : "NO") << endl;
    */