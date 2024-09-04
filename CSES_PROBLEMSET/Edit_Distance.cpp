// https://cses.fi/problemset/task/1639
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
int minDistance(string A, string B) 
{
    int n = A.size();
    int m = B.size();
    vvi dp(n + 1,vi(m + 1, 0));
    fo1(i,0,n + 1,1) dp[i][0] = i;
    fo1(i,0,m + 1,1) dp[0][i] = i;
    fo1(i,1,n + 1,1)
        fo1(j,1,m + 1,1)
            if(A[i - 1] == B[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
    return dp[n][m];
}
signed main()
{
    IOS
    string A,B;
    cin >> A >> B;
    cout << minDistance(A,B) << endl;
}