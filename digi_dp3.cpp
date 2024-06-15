#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
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
map<int,vi> contri;
int dp[18][18][18][18][4];
int i 
void solve()
{
    // count number of numbers in range [1,1e18] which have digit product equal to p(1<=p<=1e18)
    int n=18;
    int p=0;
    // p = 2^x * 3^y * ...
    // vi powers;
    // vi nums = {2,3,5,7};
    // for(auto i:nums)
    // {
    //     int cnt=0;
    //     while(p%i==0)
    //     {
    //         p/=i;
    //         cnt++;
    //     }
    //     powers.pb(cnt);
    // }
    // if(p>1) cout << -1 << endl;

}
signed main()
{
    IOS
    //TxtIO
    contri[1] = {0,0,0,0};
    contri[2] = {1,0,0,0};
    contri[3] = {0,1,0,0};
    contri[4] = {2,0,0,0};
    contri[5] = {0,0,1,0};
    contri[6] = {1,1,0,0};
    contri[7] = {0,0,0,1};
    contri[8] = {3,0,0,0};
    contri[9] = {0,2,0,0};
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}