// https://www.codechef.com/START148B/problems/FIGBOT
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
bool solve()
{
    int n,x,y;cin >> n >> x >> y;
    string s;cin >> s;
    map<char,pii> mp;
    mp['U']={0,1};
    mp['D']={0,-1};
    mp['L']={-1,0};
    mp['R']={1,0};
    pii curr={0,0};
    auto dist=[&](pii a)
    {
        pii b={x,y};
        return abs(a.ff-b.ff)+abs(a.ss-b.ss);
    };
    fon(i,n)
    {
        pii next={curr.ff+mp[s[i]].ff,curr.ss+mp[s[i]].ss};
        int d=dist(next);
        if (d<=(i+1) && (i+1-d)%2==0) return 1;
        curr=next;
    }
    return 0;
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