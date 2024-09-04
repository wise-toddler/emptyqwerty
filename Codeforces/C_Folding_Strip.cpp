// https://codeforces.com/contest/1965/problem/C
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
    string s;cin >> s;
    vi v;
    int i=1,j=0;
    while(i<=n)
    {
        if((i==n) or (s[i]==s[i-1]))
        {
            v.pb(i-j);
            j=i;
        }
        i++;
    }
    int l=0,r=0,c=0;
    n=v.size();
    fon(i,n)
    {
        if(i&1) c+=v[i];
        else c-=v[i];
        l=min(l,c);
        r=max(r,c); 
    }
    cout << r-l << endl;
}
signed main()
{
    IOS
    int t=1;
    cin >> t;
    while(t--) solve();
}