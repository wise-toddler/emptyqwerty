// https://codeforces.com/contest/1883/problem/B
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
void solve()
{
    int n,k;cin>>n>>k;
    string a;cin>>a;
    map<char,int> mp;
    for(char &c:a)
        mp[c]++;
    
    int odf =0;
    for(auto &x:mp)
    {
        if(x.second%2==1)
        {
            odf++;
        }
    }
    if((n-k)%2==0)
    {
        if((k+odf)%2==0 && odf<=k)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        if((k+odf)%2==1 && odf-1<=k)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
}
signed main()
{
    IOS
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}