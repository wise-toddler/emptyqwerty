// https://www.codechef.com/START129B/problems/GPL
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
map<pii,bool> mp;
bool f(int c0,int c1)
{
    if(c1<c0) swap(c1,c0);
    if(mp.count({c0,c1})) return mp[{c0,c1}];
    if(c1<2 && c0<2) return 0;
    if(c0==0) return mp[{c0,c1}]=!(c1&1);
    if(c0==1) return mp[{c0,c1}]=(c1&1) || (c1==2);
    if(c0==2)
    {
        if(c1==2) return mp[{c0,c1}]=0;
        if(c1<=4) return mp[{c0,c1}]=1;
    }
    int a1=!f(c0-1,c1);
    int a2=!f(c0,c1-1);
    return mp[{c0,c1}]= (a1 || a2);
}
bool solve()
{
    int n;cin >> n;
    string s;cin >> s;
    int c1=count(all(s),'1');
    int c0=count(all(s),'0');
    if(c1<2 && c0<2) return 0;
    return ((((n&1)==0) && (c1!=c0)) || ((n&1) && (abs(c1-c0)==1)));
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    // mp[{1,1}]=mp[{0,1}]=0;

    while(t--)
    {
        cout << (solve()?"ALICE":"BOB") << endl;
    }
}