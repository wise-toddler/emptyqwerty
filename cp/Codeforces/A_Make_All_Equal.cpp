// https://codeforces.com/contest/2001/problem/A
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
int solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    if(n<2) return 0;
    map<int,int> mp;
    for(auto x:a) mp[x]++;
    int mx=0;
    for(auto x:mp) mx=max(mx,x.ss);
    return n-mx;
    // longest set of equal elements
    // int ans=0;
    // vi ans;
    // int cnt=1;
    // int prev=a[0];
    // fo1(i,1,n,1)
    // {
    //     if(a[i]==prev) cnt++;
    //     else
    //     {
    //         ans.pb(cnt);
    //         cnt=1;
    //         prev=a[i];
    //     }
    // }
    // ans.pb(cnt);
    // // deb(ans);
    // int a1=*max_element(all(ans));
    // if(a[0]==a[n-1])
    // {
    //     int a2=ans[0]+ans.back();
    //     return n-max(a1,a2);
    // }
    // return n-a1;
    // // return 1;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        cout << solve() << endl;
        // solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}