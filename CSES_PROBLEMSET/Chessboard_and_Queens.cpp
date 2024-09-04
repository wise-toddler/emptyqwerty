// https://cses.fi/problemset/task/1624
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
// input chess 8*8 board
int n=8;
int ans=0;
vector<string> b(8);
bool can(int r,int c)
{
    int dy[]={-1,0,1};
    for(int i =0;i<3;i++)
    {
        int x =r,y=c;
        while(y<n and y>=0 and x>=0)
        {
            if(b[x][y]=='Q') //
                return 0;
            x-=1;
            y+=dy[i];
        }
    }
    return 1;
}
void f(int r)
{
    if(r==n) ans++;
    
    for(int i =0;i<n and r!=n;i++)
    {
        if( b[r][i]=='.' and can(r,i))
        {
            b[r][i]='Q';
            f(r+1);
            b[r][i]='.';
        }
    }
}
void solve()
{
    fon(i,8) cin >> b[i];
    f(0);
    cout << ans << endl;
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