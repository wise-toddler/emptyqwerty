// https://codeforces.com/contest/1950/problem/F
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
    int a,b,c;cin >> a >> b >> c;
    if(a+1!=c) 
    {
        cout << "-1" << endl;
        return;
    }
    int ans=log2(a+1);
    // deb(ans)
    int bv = 1<<ans;
    // deb(bv)     
    int lefta = a-(bv-1);
    // deb(lefta)
    int leftb = b-(bv-lefta) +c;
    // deb(leftb)
    int noofnodestohung = (bv+lefta);
    ans+=(ceil)((1.0*leftb)/(noofnodestohung));   

    // deb(ans)
    // deb(bv)
    // if((1<<ans)!=a+b+c)
    // {
    //     cout << "-1" << endl;
    //     return;
    // }
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