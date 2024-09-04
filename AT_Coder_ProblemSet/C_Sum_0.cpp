// https://atcoder.jp/contests/abc362/tasks/abc362_c
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
void solve()
{
    int n;cin >> n;
    v<pii> a(n); for(auto &[x,y] : a) cin >> x >> y;
    vi b(n);
    fon(i,n) 
    {
        auto [l,r]=a[i];
        if(r<0) b[i]=r;
        else if(l>0) b[i]=l;
        else b[i]=0;
    }
    int req = -accumulate(all(b),0LL);
    int i=0;
    while(i<n and req!=0)
    {
        auto [l,r]=a[i];
        if(req>0)
        {
            int contri = r-b[i];
            if(req<=contri)
            {
                b[i]+=req;
                req=0;
            }
            else
            {
                b[i]+=contri;
                req-=contri;
            }
        }   
        else
        {
            int contri = l-b[i];
            if(req>=contri)
            {
                b[i]+=req;
                req=0;
            }
            else
            {
                b[i]+=contri;
                req-=contri;
            }
        }
        i++;
    }
    if(req!=0)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    cout << b << endl;
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