// https://cses.fi/problemset/task/1625
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

// vvi vis(9,vi(9,0));
bool vis[9][9];
string s;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dfs(int i,int j,int k)
{   
    if((vis[i-1][j] and vis[i+1][j] and !vis[i][j-1] and !vis[i][j+1]) or 
    (!vis[i-1][j] and !vis[i+1][j] and vis[i][j-1] and vis[i][j+1]))
    {
        return 0;
    }
    // if(vis[i][j]) return 0;
    if(i==7 and j==1)
    {
        return k==48;
    }
    if(k==48) return 0;
    int ans=0;
    vis[i][j]=1;
    if(s[k]=='?') 
    {
        fon(p,4)
        {
            int x=i+dx[p];
            int y=j+dy[p];
            if(!vis[x][y]) ans+=dfs(x,y,k+1);
        }
    }
    else
    {
        int x,y;
        if(s[k]=='U') x=-1,y=0;
        if(s[k]=='D') x=1,y=0;
        if(s[k]=='L') x=0,y=-1;
        if(s[k]=='R') x=0,y=1;
        if(vis[i+x][j+y]==0) ans+=dfs(i+x,j+y,k+1);
    }
    vis[i][j]=0;
    return ans;   
      
}
void solve()
{
    cin >> s;
    memset(vis,0,sizeof vis);
    fon(i,9)
    {
        vis[i][0]=1;
        vis[i][8]=1;
        vis[0][i]=1;
        vis[8][i]=1;
    }
    // print vis
    // fon(i,9)
    // {
    //     cout << vis[i] << endl;
    // }
    cout << dfs(1,1,0) << endl;


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