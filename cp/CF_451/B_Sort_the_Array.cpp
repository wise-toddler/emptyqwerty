// https://codeforces.com/problemset/problem/451/B
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
void solve()
{
    int n; cin >> n;
    vi a(n); cin >> a;
    // in dc in 
    int ls = -1;
    int rl = 1e9+1;
    int i=0;
    bool f = 1;
    while(i<n) // increasing
    {
        if(i!=n-1 && a[i]>a[i+1]) break;
        i++;
        ls = max(ls,a[i]);
    }
    if(i==n) // already sorted
    {
        cout << "yes\n1 1\n";
        return;
    }
    int lid = i;
    while(i<n) // decreasing
    {
        if(i!=lid && a[i]>a[i-1]) break;
        i++;
        rl = min(rl,a[i]);
    }
    int rid = i;
    deb(lid) deb(rid)
    // if(rid==n) 
    // {
        // cout << a[lid-1] << ' ' << a[rid-1] << endl;
        if(ls > a[rid-1]) cout << "no" << endl;
        else
        {
            cout << "yes" << endl;
            cout << lid+1 << ' ' << rid << endl;
        }
        return;
    // }
    // while(i<n) // increasing
    // {
    //     if(i!=n-1 && a[i]>a[i+1]) break;
    //     i++;
    // }
    // if(i==n) 
    // {
    //     cout << "yes\n" << lid << ' ' << rid << endl;
    //     return;
    // }


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