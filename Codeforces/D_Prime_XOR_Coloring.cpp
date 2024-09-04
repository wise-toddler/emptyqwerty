// https://codeforces.com/contest/1991/problem/D
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
vvi a;
void solve()
{
    int n;cin >> n;
    if(n<=6)
    {
        vi b=a[n-1];
        cout << *max_element(all(b)) << endl;
        cout << b << endl;
        return;
    }
    vi b={1,2,3,4};
    cout << 4 << endl;  
    fon(i,n) cout << b[i%4] << ' ';
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    a={{1},{1,2},{1,2,2},{1,2,2,3},{1,2,2,3,3},{1,2,2,3,3,4}};
    cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}