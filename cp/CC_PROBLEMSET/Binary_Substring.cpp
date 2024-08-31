// https://www.codechef.com/START128B/problems/BIS
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin >> n;
    string s;cin >> s;
    int cnt00=0,cnt11=0,cnt01=0,cnt10=0;
    for(int i=0;i<n-1;i+=2)
    {
        if(s[i]=='0' and s[i+1]=='0') cnt00++;
        else if(s[i]=='1' and s[i+1]=='1') cnt11++;
        else if(s[i]=='0' and s[i+1]=='1') cnt01++;
        else if(s[i]=='1' and s[i+1]=='0') cnt10++;
    }
    // deb(cnt00)
    // deb(cnt11)
    // deb(cnt01)
    // deb(cnt10)
    int ans = cnt00*2 + cnt11*2 + (cnt01?2:0);
    if(cnt10 == 1) ans++;
    if(cnt10 >= 2) ans+=2; 
    cout << ans << endl;

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