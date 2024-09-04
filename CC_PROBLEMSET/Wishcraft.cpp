// https://www.codechef.com/START105C/problems/MAJIK
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
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
void print(vii v)
{
    for(int i=0;i<v.size();i++)
    {
        //cout << i << ' ';
        print(v[i]);
    }
}
void solve()
{
    int n;cin>>n;
    int p,q;cin>>p>>q;
    vi a(n);
    for(int &i: a) cin>>i;
    sort(all(a));
    // print(a);
    int i=n-2;
    int j=1;
    while(p>0 && j<=i ) 
    {   
        if(a[i]>(-a[j]) && a[n-1]>=0)
        {
            a[n-1]+=a[i];
            i--;
        }
        else if(a[0]<=0)
        {
            a[0]+=a[j];
            j++;
        }
        p--;
    }
    // print(a);
    // deb(i)deb(j)
    while(q>0 && j<=i)
    {
        if(a[i]>(-a[j]) && a[n-1]>=0)
        {
            a[0]-=a[i];
            i--;
        }
        else if(a[0]<=0)
        {
            a[n-1]-=a[j];
            j++;
        }
        q--;
    }
    // print(a);
    cout << a[n-1]-a[0] << endl;
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