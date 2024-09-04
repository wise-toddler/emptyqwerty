// https://atcoder.jp/contests/abc348/tasks/abc348_d
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
map<pii,int> mp;
vvi vis;
v<v<char>> a;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;
bool valid(int x,int y)
{
    return 0<=x and x<n and 0<=y and y<m;
}
bool dfs(int r,int c,int e)
{
    if(!valid(r,c)) return 0;
    if(a[r][c] == 'T') return 1;
    if(a[r][c] == '#') return 0;
    if(vis[r][c]) return 0;
    if(e==0)
    {
        if(mp.count({r,c})) return dfs(r,c,mp[{r,c}]);
        return 0;
    }
    vis[r][c] = 1;
    int olde = e;   
    if(mp.count({r,c})) e = max(e,mp[{r,c}]);
    if(e==0) return 0;
    fon(i,4)
    {
        int r_ = r+dx[i],c_ = c+dy[i];
        if(dfs(r_,c_,e-1)) return 1;
    }
    vis[r][c] = 0;
    e = olde;
    return 0;
}
void solve()
{
    cin >> n >> m;
    a.assign(n,v<char>(m));cin >> a;
    int k;cin >> k;
    vis.assign(n,vi(m,0));
    fon(i,k)
    {
        int x,y,v;cin >> x >> y >> v;
        mp[{x-1,y-1}] = v;
    }
    // find s
    pii s;
    fon(i,n)
    {
        fon(j,m)
        {
            if(a[i][j] == 'S')
            {
                s = {i,j};
                break;
            }
        }
    }
    if(dfs(s.ff,s.ss,0)) cout << "Yes";
    else cout << "No";
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