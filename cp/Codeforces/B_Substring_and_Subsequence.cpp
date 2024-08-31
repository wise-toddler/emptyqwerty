// https://codeforces.com/contest/1989/problem/B
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
// int dp[101][101];
// bool ff=0;
// int f(int i,int j,string &a,string &b)
// {
//     if(i==a.size() or j==b.size()) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(a[i]==b[j]) return dp[i][j]= 1+f(i+1,j+1,a,b);
//     return dp[i][j] = max(f(i+1,j,a,b),f(i,j+1,a,b));
// }
void solve()
{
    string a,b;cin >> a >> b;
    int n = a.size(),m = b.size();
    int ans = INT_MAX;
    fo1(a2,0,m,1)
    {    
        int a1=0;
        int idx = a2;
        while(a1 < n && idx < m)
        {
            if(a[a1] == b[idx])
                idx++;
            a1++;
        }
        ans = min(ans , a2 + (m - idx));
    }
    cout << ans + n << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}