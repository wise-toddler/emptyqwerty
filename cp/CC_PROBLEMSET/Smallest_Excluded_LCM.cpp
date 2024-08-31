// https://www.codechef.com/START106C/problems/FIZZBUZZ2308
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
int np(int n)
{
    for(int i=n+1;;i++)
    {
        bool flag = true;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                flag = false;
                break;
            }
        }
        if(flag)return i;
    }
}
void solve()
{
    int n;cin>>n;
    vi a(n);
    for(int &i:a)cin>>i;
    vector<bool> vis(n+1,false);
    sort(all(a));
    for(int i:a)
    {
        if(i<=n)
            vis[i]=true;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cout << vis[i] << endl;
            return;
        }
    }
    int q=np(a.back());
    for(int i =a.back()+1;i<=q;i++)
    {
        int r = i;

        fo1(j,n-1,-1,-1)
        {
            if(r%a[j]==0)
            {
                r/=a[j];
            }
        }
        if(r!=1)
        {
            cout << i << endl;
            return;
        }
    }
    cout << q << endl;
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