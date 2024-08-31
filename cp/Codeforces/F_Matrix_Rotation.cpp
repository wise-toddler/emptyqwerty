// https://codeforces.com/gym/545754/problem/F
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,m,deg;cin >> n >> m >> deg;
    deg%=360;
    vvi a(n,vi(m));
    cin >> a;
    vvi b(m,vi(n));
    if(deg==0)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << a[i][j] << ' ';
            }
            nl
        }
    }
    else if(deg==90)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                b[j][n-i-1]=a[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << b[i][j] << ' ';
            }
            nl
        }
    }
    else if(deg==180)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << a[n-i-1][m-j-1] << ' ';
            }
            nl
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                b[m-j-1][i]=a[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << b[i][j] << ' ';
            }
            nl
        }
    }
    
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