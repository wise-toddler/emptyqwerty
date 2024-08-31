// https://codeforces.com/contest/1992/problem/A
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
int mx=0;
void f(int a,int b,int c,int n)
{
    if(n==0) return;
    mx=max(a*b*c,mx);
    f(a+1,b,c,n-1);
    f(a,b+1,c,n-1);
    f(a,b,c+1,n-1);
}
void solve()
{
    int a,b,c;cin >> a >> b >> c;
    int ans=0;
    // f(a,b,c,5);
    // cout << mx << endl;  
    vi aa={a,b,c};
    sort(all(aa));
    aa[0]++;
    sort(all(aa));
    aa[0]++;
    sort(all(aa));
    aa[0]++;
    sort(all(aa));
    aa[0]++;
    sort(all(aa));
    aa[0]++;
    cout << (aa[0]*aa[1]*aa[2]) << endl;

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