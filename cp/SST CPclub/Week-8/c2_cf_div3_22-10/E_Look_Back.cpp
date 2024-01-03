// https://codeforces.com/contest/1883/problem/E
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
    int n;cin>>n;
    vi a(n);
    for(int &x:a)cin>>x;
    int ans=0;
    int lastpow=0;
    fo1(i,1,n,1)
    {
        // double aa= (a[i-1]*1.0)/a[i];
        double aa =  log2((a[i-1]*1.0)/a[i]);
        aa+=lastpow;
        if (aa < 0)
        {
            lastpow = 0;
            continue;
        }
        int ab=(int)ceil(aa);

        // a[i]*=pow(2,ab);
        lastpow=ab;
        ans+=ab;
    }
    cout<<ans<<endl;
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