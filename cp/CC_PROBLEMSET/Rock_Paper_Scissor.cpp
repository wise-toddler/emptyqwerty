// https://www.codechef.com/START107C/problems/PASCRO
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
    string s,t;cin>>s>>t;
    // rock paper scissor
    map<string,int> mp;
    mp["RR"] = 0;
    mp["RP"] = -1;
    mp["RS"] = 1;
    mp["PR"] = 1;
    mp["PP"] = 0;
    mp["PS"] = -1;
    mp["SR"] = -1;
    mp["SP"] = 1;
    mp["SS"] = 0;
    int ans = 0;
    int draw = 0;
    int lost = 0;
    int won = 0;
    fo1(i,0,n,1)
    {
        string temp = "";
        temp+=s[i];
        temp+=t[i];
        ans+=mp[temp];
        if(mp[temp]==0)draw++;
        else if(mp[temp]==1)won++;
        else lost++;
    }
    // if(ans == -n) cout << (n/2+1) << endl;
    int e=0;
    // deb(ans)
    // deb(won)
    // deb(lost)
    // deb(draw)
    while(ans<=0 && lost>0)
    {
        e++;
        ans+=2;
        lost--;
        won++;
    }
    while(ans<=0 && draw>0)
    {
        e++;
        ans++;
        draw--;
        won++;
    }
    cout << e << endl;

    
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