// https: // codedrills.io/contests/icpc-india-preliminary-2023/problems/passing-game
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
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}


int pass
void solve()
{
    int n,k; cin >> n >> k;
    vi p(n),s(n); cin >> p >> s;
    // make pair of (p[i],s[i])
    vector<pii> ps(n);
    fon(i,n) ps[i]={p[i],s[i]}; // position, speed inverse
    int start=s[0];
    int end=s[n-1];
    sort(all(ps)); 
    // apply dp to find time taken to last person atmost k direction changes
    // dp[i] = min time taken to reach ith person from first person
    vi dp(n,1e18);
    dp[end]=0;




    
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