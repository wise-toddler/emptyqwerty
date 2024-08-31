// https://codeforces.com/contest/2000/problem/F
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

int dp[1005][202];

int rec(int index, int pointLeft, vvi &aa)
{
    if(pointLeft <= 0) return 0;
    if(index == aa.size()) return INT_MAX;
 
    int &ans = dp[index][pointLeft]; if(ans != -1e18) return ans;
 
    ans = rec(index + 1 , pointLeft , aa);
    fon(i,aa[index].size())
    {
        if(i!=aa[index].size()-1)
            ans = min(ans , aa[index][i] + rec(index + 1 , pointLeft - i-1 , aa));
        else    
            ans = min(ans , aa[index][i] + rec(index + 1 , pointLeft - i-2 , aa));
    }
    return ans;
}
 
void solve()
{
    int n , k ; cin >> n >> k;
    fon(i,n) fon(j,2*k) dp[i][j] = -1e18;
    v<pii> a;
    fon(i,n) 
    {
        int aa, bb; cin >> aa >> bb;
        a.pb({aa,bb});
    } 
    vvi ab(n);
    for(int i = 0 ; i < n ; i++) 
    {
        int mi=min(a[i].ff,a[i].ss);
        int ma=max(a[i].ff,a[i].ss);
        fo1(j,1,a[i].ff+a[i].ss,1)
        {
            if(mi<=ma) ab[i].pb(mi),ma--;
            else ab[i].pb(ma),mi--;
        }
        fo1(j,1,ab[i].size(),1) ab[i][j]+=ab[i][j-1];
    }
 
    int ans = rec(0, k , ab);
 
    if(ans == INT_MAX) ans = -1;
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
 

