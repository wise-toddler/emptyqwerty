// https://atcoder.jp/contests/abc366/tasks/abc366_d
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
    v<vvi> a(n,vvi(n,vi(n)));cin >> a;
    int q;cin >> q;
    // 3D prefix sum
    v<vvi> ps(n,vvi(n,vi(n)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                ps[i][j][k]=a[i][j][k];
                if(i>0) ps[i][j][k]+=ps[i-1][j][k];
                if(j>0) ps[i][j][k]+=ps[i][j-1][k];
                if(k>0) ps[i][j][k]+=ps[i][j][k-1];
                if(i>0 and j>0) ps[i][j][k]-=ps[i-1][j-1][k];
                if(j>0 and k>0) ps[i][j][k]-=ps[i][j-1][k-1];
                if(i>0 and k>0) ps[i][j][k]-=ps[i-1][j][k-1];
                if(i>0 and j>0 and k>0) ps[i][j][k]+=ps[i-1][j-1][k-1];
            }
        }
    }
    // print 3D prefix sum
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         for(int k=0;k<n;k++)
    //         {
    //             cout << ps[i][j][k] << ' ';
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    while(q--)
    {
        int lx,rx,ly,ry,lz,rz;cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--;ly--;lz--;rx--;ry--;rz--;
        int ans=ps[rx][ry][rz];
        if(lx>0) ans-=ps[lx-1][ry][rz];
        if(ly>0) ans-=ps[rx][ly-1][rz];
        if(lz>0) ans-=ps[rx][ry][lz-1];
        if(lx>0 and ly>0) ans+=ps[lx-1][ly-1][rz];
        if(ly>0 and lz>0) ans+=ps[rx][ly-1][lz-1];
        if(lx>0 and lz>0) ans+=ps[lx-1][ry][lz-1];
        if(lx>0 and ly>0 and lz>0) ans-=ps[lx-1][ly-1][lz-1];
        cout << ans << endl;
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