// https: // www.codechef.com/START105C/problems/TIES
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
    int sum=0;
    for(int &i: a) 
    {
        cin>>i;
        sum+=i;
    }
    sort(all(a));
    if((sum%n)!=0)
    {
        cout << "No" << endl;
        return;
    }
    map<int,int> mp;
    if(n==1)
    {
        cout << "Yes" << endl;
        return;
    }
    fo1(i,1,n,1)
        mp[(a[i]-a[i-1])%4]++;
    if(mp[1] || mp[3])
    {
        cout << "No" << endl;
        return;
    }
    if((a[0]%2)!=(sum/n%2))
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

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

/*
4 10 14
6 10 12
8 8 12

*/