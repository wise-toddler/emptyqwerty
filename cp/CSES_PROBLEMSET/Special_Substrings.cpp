// https://cses.fi/problemset/task/2186
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
v<int> vis(26,0);
void reduceps(vi &a)
{
    int minn = INT_MAX;
    fon(i,26) if(vis[i]) minn=min(minn,a[i]);
    fon(i,26) if(vis[i]) a[i]-=minn;
}
void solve()
{
    string s;cin >> s;
    int n=s.size();
    vvi ps(n+1,vector<int>(26,0));  
    for(auto x:s) vis[x-'a']=1;
    fon(i,n)
    {
        ps[i+1]=ps[i];
        ps[i+1][s[i]-'a']++;
    }
    fon(i,n+1) reduceps(ps[i]);
    int ans=0;
    map<vi,int> cnt;
    fon(i,n+1)
    {
        ans+=cnt[ps[i]];
        cnt[ps[i]]++;
    }
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
    }
}