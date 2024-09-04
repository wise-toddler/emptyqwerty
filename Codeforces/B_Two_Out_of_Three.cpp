// https://codeforces.com/contest/1894/problem/B
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
void solve()
{
    int n;cin >> n;
    vi a(n);
    for(int &i:a)cin >> i;
    
    map<int,int> mp;
    for(int i:a)mp[i]++;


    int e=0;
    for(auto i:mp) if(i.second>=2)e++;
    
    vi vis(101,0);
    if(e<2) 
    {
        cout << -1 << endl;
        return;
    }
    int q=0;
    for(int i=0;i<n;i++)
    {
        if(vis[a[i]]==0)
        {
            cout << 1 << " ";
            vis[a[i]]=1;
            if(mp[a[i]]>1 && q==0)
            {
                q=1;
                vis[a[i]]=2; 
            }
            continue;
        }
        if(vis[a[i]]==2)
        {
            cout << 3 << " ";
            continue;
        }
        if(vis[a[i]]==1)
        {
            cout << 2 << " ";
            vis[a[i]]=1;
            continue;
        }
    }
    // print (vis);
    cout << endl;
    
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
    }
}