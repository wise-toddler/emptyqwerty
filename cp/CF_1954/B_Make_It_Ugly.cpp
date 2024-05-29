// https://codeforces.com/contest/1954/problem/B
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
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    // check if all elements are same
    bool f=1;
    fon(i,n-1)
    {
        if(a[i]!=a[i+1])
        {
            f=0;
            break;
        }
    }
    if(f)
    {
        cout << -1 << endl;
        return;
    }
    int i=0,j=n-1;
    while(a[i]==a[n-1])
    {
        i++;
    }
    while(a[j]==a[0])
    {
        j--;
    }
    // deb(i)
    // deb(n-j-1)

    // check if x a[0] y exits in the array where x!=a[0] and y!=a[0]
    // if yes then answer is 1
    bool x=0,y=0;
    vi b;

    fon(i,n)
        if(a[i]!=a[0])
            b.pb(i);
    // min difference between 2 elements of b
    int mn=1e18;
    fon(i,b.size()-1)
    {
        mn=min(mn,b[i+1]-b[i]-1);
    }
    // deb(b)
    deb(mn)/

    cout << min({i,n-j-1,mn}) << endl;

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