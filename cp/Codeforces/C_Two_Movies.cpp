// https://codeforces.com/contest/1989/problem/C
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
vvi dp(1e5,-1);
int f(int i,vi &a,vi &b)
{
    if(i==a.size()) return 0;
    // if(dp[i]!=-1) return dp[i];
    int ans = 0;
    int ch1 = a[i]+f(i+1,a,b);
    int ch2 = b[i]+f(i+1,a,b);
    ans = max(ch1,ch2);
    ans = max(f(i+1,a,b,s1+a[i],s2),f(i+1,a,b,s1,s2+b[i]));
    return dp[i] = ans;
}

void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    vi b(n);cin>>b; 
    int s1=0,s2=0;
    dp.assign(n,-1);  
    cout << f(0,a,b,s1,s2) << endl;
    // cout << dp << endl;
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