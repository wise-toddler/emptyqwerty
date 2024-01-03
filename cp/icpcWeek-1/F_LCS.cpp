// https://atcoder.jp/contests/dp/tasks/dp_f
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
vector<string> anss;
string a, b;
int dp[26][3001];
bool isSubS(string t)
{
    int n=b.size(),m=t.size();
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(b[i]==t[j])
            j++;
        i++;
    }
    return j==m;
}
void rec(int i, string s)
{
    // deb(s);
    int n=a.size();
    if(i==n)
    {
        anss.pb(s);
        return;
    }
    if(isSubS(s+a[i]))
        rec(i+1,s+a[i]);
    rec(i+1,s);
}
void solve()
{
    cin>>a>>b; 
    memset(dp,-1,sizeof(dp));
    rec(0,"");
    set<pair<int,string>> st;
    for(auto x:anss)
        st.insert({x.size(),x});   
    cout<<st.rbegin()->second<<endl;
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