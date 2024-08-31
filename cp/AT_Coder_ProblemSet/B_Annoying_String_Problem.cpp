// https://atcoder.jp/contests/arc181/tasks/arc181_b
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
    string s;cin >> s;
    int n=s.size(); 
    string x,y;cin >> x >> y;
    int cx0 = count(all(x),'0');
    int cy0 = count(all(y),'0');
    int cx1 = x.size()-cx0;
    int cy1 = y.size()-cy0;
    if(cx0==cy0) return true;
    if(abs(cy1-cx1) % abs(cx0-cy0)!=0) return false;
    int parts = (cy1-cx1)/(cx0-cy0);
    deb(parts); 
    if(parts<=0) return false;
    if(n%parts!=0) return false;
    int m = n/parts;
    fon(i,n) if(s[i]!=s[i%m]) return false;
    return true; 
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
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}