// https://atcoder.jp/contests/abc365/tasks/abc365_d
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
// int ans=0;
int dp[200005][3];
int f(string &s,char prev,int i)
{
    if(i==s.size()) 
    {
        return 0;
    }
    int &ans=dp[i][prev=='.'?2:(prev=='R'?0:(prev=='S'?1:2))];
    if(ans!=-1) return ans;
    ans=0;
    for(char c : {'R','S','P'})
    {
        if(c!=prev)
        {
            int score=0;
            if(s[i]==c) score=0;
            else if(s[i]=='R' && c=='S') score=-1;
            else if(s[i]=='S' && c=='P') score=-1;
            else if(s[i]=='P' && c=='R') score=-1;
            else if(s[i]=='R' && c=='P') score=1;
            else if(s[i]=='S' && c=='R') score=1;
            else if(s[i]=='P' && c=='S') score=1;
            if(score==-1) continue;
            int cur= score + f(s,c,i+1);
            ans=max(ans,cur);
        }
    }
    return ans;
}
void solve()
{
    int n;cin >> n;
    memset(dp,-1,sizeof(dp));
    string s;cin >> s;
    // r = rock, s = scissors, p = paper
    // string p(n,'.');
    // fon(i,n)
    // {
    //     if(s[i]=='R') p[i]='P';
    //     if(s[i]=='S') p[i]='R';
    //     if(s[i]=='P') p[i]='S';
    // }
    // p[i]!=p[i-1] && p[i]!=p[i+1]
    // count no of ways so that score >= 1 
    cout << f(s,'.',0);

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
// PRSSRS
// RSRSRS
// 112000

// PRSSRS
// RSRSPR
// 112022

// PRSSRS
// SRSRPR
// 200222
