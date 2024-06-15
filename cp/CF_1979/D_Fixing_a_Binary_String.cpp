// https://codeforces.com/contest/1979/problem/D
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
void solve()
{
    int n,k;cin >> n >> k;
    string s;cin >> s;
    // check if 0*k followed by 1*k substring is present
    // if not then check if 1*k followed by 0*k substring is present
    auto ch1=[&](string s)
    {
        string kk = string(k, '0');
        string kk1 = string(k, '1');
        // return s.find(kk) != string::npos || s.find(kk1) != string::npos;
    };
    bool ch=ch1(s);
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
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}