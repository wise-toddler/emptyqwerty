// https://www.codechef.com/START143B/problems/CONVERT
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
bool solve()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    string t;cin>>t;
    int sc1=count(all(s),'1');
    int sc0=count(all(s),'0');
    int tc1=count(all(t),'1');
    int tc0=count(all(t),'0');
    if(sc1!=tc1) return false;
    if(sc0!=tc0) return false;
    int diff=0;
    fon(i,n) if(s[i]!=t[i]) diff++;
    diff/=2;
    if(n==2) return (diff&1)==(k&1);
    if(k>=diff) return 1;    
    // deb(diff)
    assert(0);
    return 1;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}