// https://codeforces.com/gym/105120/problem/B
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
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    vi d(n);cin >> d;
    // pregcd;
    vi pre(n);
    pre[0] = a[0];
    fo1(i,1,n,1) pre[i] = __gcd(pre[i-1],a[i]);
    // suf gcd
    vi suf(n);
    suf[n-1] = a[n-1];
    fon_(i,n-1) suf[i] = __gcd(suf[i+1],a[i]);

    // without discount
    int ans = *max_element(all(a))+pre[n-1];
    multiset<int> s(all(a));
    // with discount
    
    fon(i,n)
    {
        s.erase(s.find(a[i]));
        a[i]-=d[i];
        s.insert(a[i]);

        int temp1 = *s.rbegin();
        int temp2;
        if(i==0) temp2 = gcd(suf[i+1],a[i]);
        else if(i==n-1) temp2 = gcd(pre[i-1],a[i]);
        else temp2 = gcd(a[i],gcd(pre[i-1],suf[i+1]));
        ans = max(ans,temp1+temp2);

        s.erase(s.find(a[i]));
        a[i]+=d[i];
        s.insert(a[i]);
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