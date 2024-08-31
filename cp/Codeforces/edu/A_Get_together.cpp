// https://codeforces.com/edu/course/2/lesson/6/3/practice/contest/285083/problem/A
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
v<vi> a;
bool check(double mid)
{
    double l = -1e9, r = 1e9;
    for(vi &i:a)
    {
        l = max(l,i[0]-i[1]*mid);
        r = min(r,i[0]+i[1]*mid);
        if(l>r) return false;
    }
    return true;
}
void solve()
{
    int n;cin >> n;
    a.resize(n,vi(2)); cin >> a;
    double st=0,en=1e10;
    double ans=0;
    while(en-st>1e-7)
    {
        double mid=(st+en)/2;
        if(check(mid)) en=mid;
        else st=mid;
    }
    cout << fixed << setprecision(7) << st << endl;
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