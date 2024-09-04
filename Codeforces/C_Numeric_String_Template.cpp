// https://codeforces.com/contest/2000/problem/C
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
    vi a(n);cin>>a;
    map<int,vector<int>> mp;
    fon(i,n) mp[a[i]].pb(i);
    vvi tt;for(auto [x,y]:mp) tt.pb(y);
    sort(all(tt));
    // print
    // for(auto i:tt) cout << i << endl;
    // nl nl
    int m;cin>>m;
    while(m--)
    {
        string s;cin>>s;
        // deb(s);
        int nn=s.size();
        map<char,vector<int>> m1;
        fon(i,nn) m1[s[i]].pb(i);
        vvi t1;for(auto [x,y]:m1) t1.pb(y);
        sort(all(t1));
        // for(auto i:t1) cout << i << endl;
        // nl 
        if(t1==tt) 
        {
            cout << "YES" << endl;
        }
        else 
        {
            cout << "NO" << endl;
        }
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