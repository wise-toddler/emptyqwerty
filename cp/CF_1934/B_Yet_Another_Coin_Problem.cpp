// https://codeforces.com/contest/1934/problem/B
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
int dp[1000001];
vi a={1,3,6,10,15};
int f(int s)
{
    if (s == 0) return 0;
    if (s < 0) return 1e9;
    if (dp[s] != -1)
        return dp[s];
    int ans = 1e9;
    for (int i : a)
        ans = min(ans, f(s - i) + 1); //+1 for the current coin
    return dp[s] = ans;
    // return ans;
}
void solve()
{
    int n;cin >> n;
    int ans = (n/30)*2;
    n%=30;
    int a1 = f(n)+ans;
    int a2 = 1e9;
    if(ans != 0)
        a2 = f(n+15)+ans-1;
    cout << min(a1,a2) << endl;
    // cout << (ans+(f(n) == 1e9 ? -1 : f(n))) << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--)
    {
        solve();
    }
}