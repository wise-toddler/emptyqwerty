// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
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
class dsu
{
public:
    vi p;
    vvi l;
    dsu(int n)
    {
        p.resize(n);
        l.resize(n);
        fo1(i, 0, n, 1) p[i] = i, l[i].pb(i);
    }
    int get(int a)
    {
        return p[a];
    }
    void join(int a, int b)
    {
        a = p[a];
        b = p[b];
        if (a == b)
            return;
        if (l[a].size() < l[b].size())
            swap(a, b);
        for (auto i : l[b])
            p[i] = a, l[a].pb(i);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    dsu d(n);
    while (m--)
    {
        string s;
        cin >> s;
        if (s == "union")
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            d.join(a, b);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << (d.get(a) == d.get(b) ? "YES" : "NO") << endl;
        }
    }
}
signed main()
{
    IOS
        // TxtIO
        int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}