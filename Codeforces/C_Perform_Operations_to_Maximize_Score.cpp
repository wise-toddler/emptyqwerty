// https://codeforces.com/contest/1998/problem/C
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
template<typename T,typename U>ostream& operator<<(ostream& os, pair<T,U> p){os << "{" << p.ff << "," << p.ss << "}";return os;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,k;cin >> n >> k;
    vi a(n);cin >> a;
    vi b(n);cin >> b;
    v<pii> ab(n);
    fon(i,n) ab[i]={a[i],b[i]};
    sort(all(ab),[&](pii x,pii y){return x.ff < y.ff;});
    // cout << ab << endl;
    int lar1=-1;
    for(auto [x,y] : ab) if(y==1) lar1=x;
    deb(lar1)
    if(lar1==-1)
    {
        vi aa=a;
        sort(all(aa));
        int ans=a.back();
        // median of a0..an-2
        int med=aa[(n-2)/2];
        cout << ans+med << endl;
        return;
    }
    // case 1: (median of a - {lar1}) + (lar1+k)
    // case 2: max(a) + (maximize median of {a - {max(a)}})
    vi aa=a;
    sort(all(aa));
    aa.pop_back();
    int ans=0;
    int med=aa[(n-2)/2];
    ans=max(ans,med+lar1+k);
    

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