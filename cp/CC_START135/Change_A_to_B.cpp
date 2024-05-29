// https://www.codechef.com/START135B/problems/CHANGEXY
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
    int a,b,k;cin >> a >> b >> k;
    int ans=(int)(log(b/a)/log(k));
    int q=(int)(b-a*pow(k,ans));
    // convert q to base k 
    int a1=q/pow(k,ans);
    vi v;

    while(q)
    {
        v.pb(q%k);
        q/=k;
    }
    // reverse(all(v));
    // for(auto &x:v) cout << x << " ";nl
    int a2=0;
    for(int i=0;i<min((int)v.size(),ans);i++)
    {
        a2+=v[i];
    }
    // return;
    cout << (a1+a2+ans) << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}