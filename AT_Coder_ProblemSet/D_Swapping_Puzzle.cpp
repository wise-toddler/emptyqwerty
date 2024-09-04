// https://atcoder.jp/contests/abc332/tasks/abc332_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
// void print(vi v)
// {
//     for(int i=0;i<v.size();i++)
//         cout << v[i] << ' ';
//     cout << endl;
// }
// void print(vii v)
// {
//     for(int i=0;i<v.size();i++)
//     {
//         //cout << i << ' ';
//         print(v[i]);
//     }
// }
// // swap column i and i+1
// void swapCol(vii &g,int i)
// {
//     int n = g.size();
//     fon(j,n)
//     {
//         swap(g[j][i],g[j][i+1]);
//     }
// }
// // swap row i and i+1
// void swapRow(vii &g,int i)
// {
//     int n = g.size();
//     swap(g[i],g[i+1]);
// }

void solve()
{
    int n,m; cin >> n >> m;
    vii g1(n,vi(m)),g2(n,vi(m));
    fon(i,n) cin >> g1[i];
    fon(i,n) cin >> g2[i];

    vector<vector<int>> sg1 = g1, sg2 = g2;
    fon(i,n)
    {
        sort(all(sg1[i]));
        sort(all(sg2[i]));
    }
    sort(all(sg1));
    sort(all(sg2));
    int anss=0;
    if (sg1 != sg2)
    {
        cout << -1 << endl;
        return ;
    }
    int ans=0;// no of swaps
    vi prem(m);
    fon(i,m)
        prem[i]=find(all(g1[0]),g2[0][i])-g1[0].begin();
    
    vector<bool> vis(m,false);
    fon(i,m)
    {
        if(vis[i])
            continue;
        int j=i;
        while(!vis[j])
        {
            vis[j]=true;
            j=prem[j];
        }
        ans++;
    }
    anss+=m-ans;
    vector<bool> vis2(n,false);
    ans=0;
    // vi prem2(n);
    // fon(i,n)
    //     prem2[i]=find(all(g1[i]),g2[i][0])-g1[i].begin();

    // fon(i,n)
    // {
    //     if(vis2[i])
    //         continue;
    //     int j=i;
    //     while(!vis2[j])
    //     {
    //         vis2[j]=true;
    //         j=prem2[j];
    //     }
    //     ans++;
    // }
    // anss+=n-ans;

    cout << anss << endl;
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