// https://atcoder.jp/contests/abc365/tasks/abc365_e
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
int findXorSum(vi &arr)
{
    int n = arr.size();
    int sum = 0;
    int mul = 1;
    for (int i = 0; i < 30; i++) {
        int c_odd = 0;
        bool odd = 0;
        for (int j = 0; j < n; j++) {
            if ((arr[j] & (1 << i)) > 0)
                odd = (!odd);
            if (odd)
                c_odd++;
        }
        for (int j = 0; j < n; j++) {
            sum += (mul * c_odd);
            if ((arr[j] & (1 << i)) > 0)
                c_odd = (n - j - c_odd);
        }
        mul *= 2;
    }
    return sum;
}
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    cout << findXorSum(a)-accumulate(all(a),0LL);   
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
