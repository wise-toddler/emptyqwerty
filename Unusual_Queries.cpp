// https://www.codechef.com/START137B/problems/UQR
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

#define f(x) (x*(x+1))/2
void solve()
{
    int n,a,b;cin >> n >> a >> b;
    if(a==b) {cout << n/a << endl;return;}

    a=min(a,b);
    b=n/a; if(b==0){cout << 0 << endl;return;} 

    int ans=0;
    if(b>a) ans=f(a)+(b-a)*a;
    else ans=f(b);
    ans+=min(n%a,b);
    cout << ans << endl;
}
signed main()
{
    IOS
    int t; cin >> t;
    while(t--) solve();
}