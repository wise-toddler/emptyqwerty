// https://www.codechef.com/START105C/problems/DUPLET
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
//factors
vi fs(int n)
{
    vi a;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a.pb(i);
            if(i!=n/i) a.pb(n/i);
        }
    }
    sort(all(a));
    return a;
}
void solve()
{
    int n;cin>>n;
    // vi a= fs(n);
    // cout << xory << " " << xxory << endl;
    // find x and y
    //   
    // deb(xory)deb(xxory)
    // fo1(i,a.size()-1,-1,-1)
    // {
    //     int xory = a[i];
    //     int xxory = n/xory;
    //     fo1(x,xory,0,-1)
    //     {
    //         fo1(y,0,(xory+1),1)
    //         {
    //             if(((x|y)==xory) && ((x^y)==xxory))
    //             {
    //                 // cout << "YES" << endl;
    //                 cout << x << " " << y << endl;
    //                 return;
    //             }
    //         }
    //     }
    // }
    int a=n,b=n-1;
    if(((a|b)*(a^b))==n)
    {
        cout << "YES  " ;
        cout << a << " " << b << endl;
        return;
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
    }
}