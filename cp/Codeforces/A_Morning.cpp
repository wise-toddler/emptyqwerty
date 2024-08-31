// https://codeforces.com/contest/1883/problem/A
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
map<char, int> mp;
void solve()
{
    string a;cin>>a;
    int ans=0,curr=0;
    for(char &c:a)
    {
        ans+=abs(mp[c]-curr);
        curr=mp[c];
    }
    ans+=a.size();
    cout<<ans<<endl;
}
signed main()
{
    fo1(i,1,10,1)
    {
        mp['0'+i]=i-1;
    }
    mp['0']=9;
    IOS
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}