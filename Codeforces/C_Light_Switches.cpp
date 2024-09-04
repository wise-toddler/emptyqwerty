// https://codeforces.com/contest/1993/problem/C
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
    int n,k;cin >> n >> k;
    vi a(n);cin >> a;
    sort(all(a));
    int nn=a.back();
    // a+2*x*k // closest to nn
    // int ans=0;
    int x=0;
    set<int> si;
    vi nrs(n);
    fon(i,n)
    {
        int ans=0;
        int ss=nn-a[i];
        ss/=2*k;
        // ss or ss+1 
        if(abs(a[i]+2*ss*k-nn) > abs(a[i]+2*(ss+1)*k-nn)) ss++;
        nrs[i]=a[i]+2*ss*k;
        si.insert(nrs[i]);
    }
    // cout << nrs << endl;
    if(*si.rbegin()-*si.begin()>=k) cout << -1 << endl;
    else
    {
        cout << *si.rbegin() << endl;
    }
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