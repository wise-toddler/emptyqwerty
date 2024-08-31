// https://atcoder.jp/contests/abc154/tasks/abc154_e
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout << endl;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
int dp[101][2][2][4];
int f(int i,int t,int l,int k,string &s)
{
    if(i==s.size()) return k==0;
    if(k<0) return 0;
    int &ans = dp[i][t][l][k]; if(ans!=-1) return ans;
    ans=0;
    int mn=0,mx=t?s[i]-'0':9;
    fo1(j,mn,mx+1,1) 
    {
        ans+=f(i+1,t&&(j==mx),l && j==0,k-(j!=0),s);
    }
    return ans;    
}
void solve()
{
    memset(dp,-1,sizeof(dp));   
    string s;int k;cin>>s>>k;
    cout << f(0,1,1,k,s) << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}