// https://codeforces.com/contest/1216/problem/C
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
bool solve()
{
    int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
    int x3,y3,x4,y4;cin >> x3 >> y3 >> x4 >> y4;
    int x5,y5,x6,y6;cin >> x5 >> y5 >> x6 >> y6;
    
    v<pii> v;
    if(x3<=x1 and x1<=x4 and y2>=y3 and y1<=y4) v.pb({max(y1,y3),min(y2,y4)});
    if(x5<=x1 and x1<=x6 and y2>=y5 and y1<=y6) v.pb({max(y1,y5),min(y2,y6)});
    // deb(v.size())
    if(v.size()==0) return 0;
    if(v.size()==1) if(v[0].ff!=y1 or v[0].ss!=y2) return 0;
    if(v.size()==2)
    {
        sort(all(v));
        if(min(v[0].ff,v[1].ff)!=y1 or max(v[0].ss,v[1].ss)!=y2) return 0;
        // cout << " teri maa ki " << endl;
        if(v[0].ss < v[1].ff) return 0;
    }
    v.clear();
    // return 1;
    if(y3<=y1 and y1<=y4 and x2>=x3 and x1<=x4) v.pb({max(x1,x3),min(x2,x4)});
    if(y5<=y1 and y1<=y6 and x2>=x5 and x1<=x6) v.pb({max(x1,x5),min(x2,x6)});
    // deb(v.size())
    if(v.size()==0) return 0;
    if(v.size()==1) if(v[0].ff!=x1 or v[0].ss!=x2) return 0;
    if(v.size()==2)
    {
        sort(all(v));
        if(min(v[0].ff,v[1].ff)!=x1 or max(v[0].ss,v[1].ss)!=x2) return 0;
        if(v[0].ss < v[1].ff) return 0;
    }
    v.clear();
    if(x3<=x2 and x2<=x4 and y2>=y3 and y1<=y4) v.pb({max(y1,y3),min(y2,y4)});
    if(x5<=x2 and x2<=x6 and y2>=y5 and y1<=y6) v.pb({max(y1,y5),min(y2,y6)});
    if(v.size()==0) return 0;
    if(v.size()==1) if(v[0].ff!=y1 or v[0].ss!=y2) return 0;
    if(v.size()==2)
    {
        sort(all(v));
        if(min(v[0].ff,v[1].ff)!=y1 or max(v[0].ss,v[1].ss)!=y2) return 0;
        if(v[0].ss < v[1].ff) return 0;
    }
    return 1;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "NO" : "YES") << endl;   
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}