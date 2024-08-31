// https://www.codechef.com/START139B/problems/COUNTN
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
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
vector<int> sp(2000001,0);
vector<int> cnt(1000001,0);
void spf()
{
    for(int i=2;i<=2000000;i++) sp[i]=i;
    for(int i=2;i*i<=2000000;i++)
    {
        if(sp[i]==i)
        {
            for(int j=i*i;j<=2000000;j+=i)
            {
                if(sp[j]==j) sp[j]=i;
            }
        }
    }
    //prefix sum of primes
    for(int i=2;i<=1000000;i++)
    {
        cnt[i]=cnt[i-1];
        if(sp[i]==i) cnt[i]+=i;
    }
}
void solve()
{
    int k;cin>> k;
    cout << cnt[sp[k]]*k << endl;

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    spf();
    // fon(i,200) cout << i << " " << sp[i] << endl;
    // fon(i,100) cout << i << " " << cnt[i] << endl;
    cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}