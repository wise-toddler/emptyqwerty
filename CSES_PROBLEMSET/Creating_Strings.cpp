// https://cses.fi/problemset/task/1622
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
int fact(int n)
{
    int ans=1;
    fo1(i,1,n+1,1)
    {
        ans*=i;
        ans%=1000000007;
    }
    return ans;
}
void solve()
{
    string s;cin >> s;
    sort(all(s));
    map<char,int> mp;
    for(auto x : s) mp[x]++;
    int n=s.size();
    int ans=fact(n);
    int cnt=1;
    for(auto x : mp)
    {
        cnt*=fact(x.ss);
        cnt%=1000000007;
    }
    ans/=cnt;
    ans%=1000000007;
    cout << ans << endl;
    
    vi vis(n,0);
    string c;
    function<void(int)> permute=[&](int i)
    {
        if(i==n)
        {
            for(auto x : c) cout << x;
            nl
            return;
        }
        fon(j,n)
        {
            if(vis[j] || (j>0 && s[j]==s[j-1] && !vis[j-1])) continue;
            vis[j]=1;
            c.pb(s[j]);
            permute(i+1);
            c.pop_back();
            vis[j]=0;
        }
    };
    permute(0);
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