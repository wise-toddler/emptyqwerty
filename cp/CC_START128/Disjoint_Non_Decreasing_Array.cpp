// https://www.codechef.com/START128B/problems/DISJOINTSUB
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
bool solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    a.pb(1e9+1);
    vi b; // dip points
    fon(i,n-1)
        if(a[i]>a[i+1])
            b.pb(i+1);
    
    // rngs min a[bi-1]-a[bi] max a[bi+1]-a[bi] and if there exsist a number 
    int mx = INT_MIN;
    int mi = INT_MAX;
    for(auto i:b)
    {
        mx = max(mx,a[i-1]-a[i]);
        mi = min(mi,a[i+1]-a[i]);
    }
    // deb(mx)

    return mx<=mi;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        cout << (solve()?"Yes":"No") << endl;
    }
}