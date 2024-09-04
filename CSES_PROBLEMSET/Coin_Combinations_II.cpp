// https://cses.fi/problemset/task/1636
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){int e=0;for(auto& x : v)os <<e++<<": "<<x << '\n';return os;}
const int mod = 1e9+7;

const int N = 100, SUM = 1e6;
int dp[2][SUM + 1];

// int f(int i,int s,vi& a)
// {
//     if(s==0) return 1;
//     if(s<0) return 0;
//     if(dp[i][s]!=-1) return dp[i][s];
//     int ans=0;
//     for(int j=i;j<a.size();j++)
//         ans=(ans+f(j,s-a[j],a)%mod)%mod;
//     return dp[i][s]=ans;
// } // 1e8 dp sigsegv



// int solve(vi &a, int s)
// {   
//     if(s == 0) return 1;
//     if(s < 0) return 0;
//     int n = a.size();
//     int ans = 0;
//     for(int i = 0; i < n; ++i) {
//         ans += solve(a, s - a[i]);
//     }
//     return ans;
// }

// int solve_itr(vi &a, int S)
// {
//     int n = a.size();
//     for(int s = 0; s <= S; ++s) {
//         int &ans = dp[s];
//         if(s == 0) {
//             ans = 1;
//             continue;
//         }
//         ans = 0;
//         for(int i = 0; i < n; ++i) {
//             if(s - a[i] >= 0) {
//                 ans += dp[s - a[i]];
//             }
//         }
//     }
// }


// int solve(vi &a, int pos, int sum) {
//     if(pos == a.size()) return sum == 0;
//     if(sum < 0) return 0;
//     int &ans = dp[pos][sum]; if(ans != -1) return ans;
//     int ans1 = solve(a, pos + 1, sum);
//     int ans2 = solve(a, pos, sum - a[pos]);
//     return ans = (ans1 + ans2) % mod;
// }


// i: 0......n
// s: s......0
int solve_iterative(vi& a,int s)
{   
    int n = a.size();
    for(int pos = n; pos >= 0; --pos) {
        for(int sum = 0; sum <= s; ++sum) {
            int &ans = dp[pos % 2][sum];
            if(pos == n) {
                ans = sum == 0;
                continue;
            }
            int ans1 = dp[(pos + 1) % 2][sum];
            int ans2 = (sum - a[pos] >= 0) ? dp[pos % 2][sum - a[pos]] : 0;
            ans = (ans1 + ans2) % mod;
        }
    }
    return dp[0][s];
}

void solve()
{
    int n,s;cin>>n>>s;
    vi a(n);cin>>a;
    memset(dp, -1, sizeof dp);
    cout << solve_iterative(a, s) << endl;
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
// #undef int