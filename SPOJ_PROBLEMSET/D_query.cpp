// https://www.spoj.com/problems/DQUERY/
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
class trie
{
public:
    v<trie *> child;
    vi idxs;
    trie() { child.resize(2); }
    int cnt(int l, int r)
    {
        auto ll = lower_bound(all(idxs), l);
        auto rr = lower_bound(all(idxs), r + 1);
        if (ll == idxs.end() || rr == idxs.begin())
            return 0;
        return rr - ll;
    }
};
trie *root = new trie();
void insert(int x, int idx)
{
    trie *cur = root;
    root->idxs.pb(idx);
    for (int i = 31; i >= 0; i--)
    {
        int b = (x >> i) & 1;
        if (!cur->child[b])
            cur->child[b] = new trie();
        cur = cur->child[b];
        cur->idxs.pb(idx);
    }
}
vi c;
void query()
{
    int l, r;
    cin >> l >> r;
    l--, r--;
    // int k = c[l];
    int ans = 0;
    trie *cur = root;
    for (int i = 31; i >= 0; i--)
    {
        int b = (l >> i) & 1;
        if (b == 0 && cur->child[1])
            ans += cur->child[1]->cnt(l, r);
        if (!cur->child[b])
            break;
        cur = cur->child[b];
    }
    cout << root->cnt(l, r) - ans;
    nl
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    map<int, int> mp;
    fon(i, n)
    {
        if (mp[a[i]] == 0)
            c.pb(0);
        else
            c.pb(mp[a[i]]);
        mp[a[i]] = i + 1;
    }
    // cout << c;nl
    fon(i, n) insert(c[i], i);
    // cout << root->idxs << endl;
    int q;
    cin >> q;
    while (q--)
    {
        query();
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
// struct Q
// {
//     int l,r,id;
// };
// int S=500;
// bool cmp(Q a,Q b)
// {
//     if(a.l/S!=b.l/S)return a.l<b.l;
//     return a.r<b.r;
// }
// int ans=0;
// int fr[1000001];
// void add(int idx)
// {
//     fr[idx]++;
//     if(fr[idx]==1)ans++;
// }
// void remove(int idx)
// {
//     fr[idx]--;
//     if(fr[idx]==0)ans--;
// }
// void solve()
// {
//     int n;cin >> n;
//     vi a(n);cin >> a;
//     int q;cin >> q;
//     v<Q> queries(q);
//     fon(i,q)
//     {
//         int l,r;cin >> l >> r;
//         l--,r--;
//         queries[i] = {l,r,i};
//     }
//     sort(all(queries),cmp);
//     vi res(q);
//     int l=0,r=-1;
//     for(auto i : queries)
//     {
//         while(r<i.r)add(a[++r]);
//         while(l>i.l)add(a[--l]);
//         while(r>i.r)remove(a[r--]);
//         while(l<i.l)remove(a[l++]);
//         res[i.id] = ans;
//     }
//     cout << res;
// }