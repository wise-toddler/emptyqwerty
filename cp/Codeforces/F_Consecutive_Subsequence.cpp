// https://codeforces.com/problemset/problem/977/F
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
    int n;cin>>n;
    vi a(n);cin>>a;
    map<int,int> mp;
    vi dp(n,1);
    int mx=1;
    int mxid=0;
    fon(i,n)
    {
        if(mp.find(a[i]-1)!=mp.end())
        {
            dp[i]=dp[mp[a[i]-1]]+1;
        }
        mp[a[i]]=i;
        if(dp[i]>mx)
        {
            mx=dp[i];
            mxid=i;
        }
    }
    cout << mx << endl;
    vi ans;
    int val=a[mxid];
    fon_(i,n)
    {
        if(dp[i]==mx && a[i]==val)
        {
            ans.pb(i+1);
            mx--;
            val--;
        }
    }
    reverse(all(ans));
    cout << ans << endl;

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