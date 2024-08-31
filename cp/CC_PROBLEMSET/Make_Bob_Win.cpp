// https://www.codechef.com/START145B/problems/DLSB
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
int solve()
{
    int n;cin >> n;
    string s;cin >> s;
    // return min (n,2ll-(s[0]=='1')-(s.back()=='1'))
    v<pii> a;
    if(set<char>(all(s)).size()==1) return min(2ll,n-count(all(s),'1'));
    fon(i,n)
    {
        if(a.size()==0) 
        {
            a.pb({1,s[i]-'0'});
        }
        else
        {
            if(a.back().ss==s[i]-'0') a.back().ff++;
            else a.pb({1,s[i]-'0'});
        }
    }
    if(a.size()%2==0) 
    {
        return 1;
    }
    else
    {
        if(a[0].ss==1) return 0;
        else return 2;
    }
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        cout << solve() << endl;    
        // solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}