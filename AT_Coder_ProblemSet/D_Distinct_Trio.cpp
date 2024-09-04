// https://atcoder.jp/contests/abc252/tasks/abc252_d
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
int ncm(int n,int m)
{
    if(m>n) return 0;
    if(m==0 || m==n) return 1;
    if(m==1) return n;
    if(m==3) return n*(n-1)*(n-2)/6;
    if(m==2) return n*(n-1)/2;
    return 0;
}
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    map<int,int> mp;
    for(int i:a) mp[i]++;
    int total = ncm(n,3);
    for(auto &[x,y]:mp) 
    {
        if(y>=2)
        {
            total-=ncm(y,2)*(n-y);
            total-=ncm(y,3);
        }
    }
    cout << total << endl;


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