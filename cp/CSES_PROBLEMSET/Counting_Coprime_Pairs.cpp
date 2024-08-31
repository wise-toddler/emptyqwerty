// https://cses.fi/problemset/task/2417
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
    int n;cin >> n;
    vi a(n);cin >> a;
    vi cnt(1000001,0);
    for(int i:a) cnt[i]++;
    vi cnt_pairs(1000001,0); // pairs haing i as a factor
    #define f(x) x*(x-1)/2
    fo1(i,1,1e6+1,1)
    {
        fo1(j,i,1e6+1,i)
            cnt_pairs[i]+=cnt[j];
        cnt_pairs[i]=f(cnt_pairs[i]);
    }
    fo1(i,1e6+1,0,-1) fo1(j,2*i,1e6+1,i) cnt_pairs[i]-=cnt_pairs[j];
    cout << cnt_pairs[1];
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // sieve();
    // cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}