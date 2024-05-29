// https://www.codechef.com/START127B/problems/PURIFYIT
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
vector<int> ssp;
vector<int> maxxx;
void spf()
{
    ssp.assign(3e5 + 1, 0);
    for (int i = 2; i <= 3e5; i++)
        if (ssp[i] == 0)
            for (int j = i; j <= 3e5; j += i)
                if (ssp[j] == 0)
                    ssp[j] = i;
}
map<int, int> primefactors(int n)
{
    if(n==1) return {{1,1}};
    map<int, int> pf;
    while (n != 1)
    {
        if (pf.find(ssp[n]) == pf.end()) pf[ssp[n]] = 1;
        pf[ssp[n]] *= ssp[n];
        n /= ssp[n];
    }
    return pf;
}
void precompute()
{
    maxxx.assign(3e5 + 1, 0);
    for (int i = 1; i <= 300000; i++)
    {
        int maxx = 0;
        for (auto [c, f] : primefactors(i))
            maxx = max(maxx, f);
        maxxx[i] = maxx;
    }
    // presum so that answer can be calculated in O(1)
    for (int i = 1; i <= 300000; i++)
    {
        maxxx[i] += maxxx[i - 1];
        maxxx[i] %= 1000000007;
    }
}
void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0, m = 1e9 + 7;
    ans = (maxxx[r] - maxxx[l - 1] + m) % m;
    cout << ans%m << endl;
}
signed main()
{
    spf();
    precompute();
    IOS
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}