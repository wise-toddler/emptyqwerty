// https://codeforces.com/problemset/problem/1221/D
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
// no change , +1 , +2;
vi a,b;
vvi dpp;
int dp(int i,int ad)
{
    if(i>=2 && a[i-1]==a[i-2]) return 1e18;
    if(i==a.size()) return 0;
    if(dpp[ad][i]!=-1) return dpp[ad][i];
    int ans = 1e18;
    fon(j,3)
    {
        a[i]+=j;
        ans = min(ans,dp(i+1,j)+j*b[i]);
        a[i]-=j;
    }
    return dpp[ad][i]=ans;
}
void solve()
{
    int n;cin >> n;
    a.resize(n);b.resize(n);
    fon(i,n) cin >> a[i] >> b[i];
    dpp.assign(3,vi(n,-1));
    cout << dp(0,0) << endl;
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
    }
}