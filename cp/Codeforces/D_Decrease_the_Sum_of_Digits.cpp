// https://codeforces.com/contest/1409/problem/D
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
#define sz(x) (int)x.size()
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
void solve()
{
    int n,s;cin>>n>>s;
    int id=-1;
    string str=to_string(n);
    int sum=0;
    int nn=n;
    while(nn)
    {
        sum+=nn%10;
        nn/=10;
    }
    if(sum<=s)
    {
        cout << 0 << endl;
        return;
    }
    sum=0;
    string ans(sz(str),'0');
    fon(i,sz(str))
    {
        sum+=str[i]-'0';
        if(sum>=s) break;
        ans[i]=str[i];
        id=i;
        // deb(sum)
    }
    if(id==-1)
    {
        int d=sz(str);
        // deb(pow(10,d))
        // deb(n)
        int ans=(int)pow(10,d)-n;
        cout << ans << endl;
        return;
    }
    // deb(id)/
    int d=sz(str)-id-1;
    // deb(ans);
    nn=stoll(ans);
    // deb(nn)
    d=pow(10,d);
    // deb(d+nn)
    cout << d+nn-n << endl; 
    
    // cout << "oops" << endl;

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    // cout << 218000000000000-217871987498122 << endl;
    // cout << 217871987498122+2128012501878<< endl;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}












