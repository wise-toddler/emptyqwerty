// https://codeforces.com/contest/1931/problem/D
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
void solve()
{
    int n,x,y;cin >> n >> x >> y;
    vi a(n);cin >> a;
    map<pii,int> mp;
    fo1(i,0,n,1)
        mp[{a[i]%x,a[i]%y}]++;
    int ans=0;

    fo1(i,0,n,1)
    {
        int cnt=0;
        int rx=x-a[i]%x;
        int ry=a[i]%y;
        if(rx==x)rx=0;
        mp[{a[i]%x,a[i]%y}]--;
        cnt+=mp[{rx,ry}];
        ans+=cnt;
    }
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