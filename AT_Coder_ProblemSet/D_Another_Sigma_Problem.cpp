// https://atcoder.jp/contests/abc353/tasks/abc353_d
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
int mod=998244353;
int modmul(vi a)
{
    int ans=1;
    for(int i:a)
    {
        ans*=i;
        ans%=mod;
    }
    return ans;
}
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    map<int,int> mp;
    for(int i:a) mp[to_string(i).size()]++;
    // print mp
    // for(auto &[x,y]:mp) cout << x << " " << y << endl;
    // nl nl
    int ans=0;
    // mp[0]=1;
    int e=0;
    for(int i:a)
    {
        mp[to_string(i).size()]--;
        int p=1;
        int ca=0;
        for(int j=1;j<=10;j++)
        {
            p*=10;
            p%=mod;
            if(mp[j]==0) continue;
            ca+=modmul({mp[j],p,i});
            ca%=mod;
        }
        ca+=(i*e)%mod;
        ca%=mod;    
        // deb(ca);
        ans+=ca;
        ans%=mod;
        e++;
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}