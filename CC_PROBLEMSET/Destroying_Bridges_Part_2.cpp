// https://www.codechef.com/START139B/problems/DESTBRIDGE2
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
void solve()
{
    int n,c;cin>> n >> c;
    vi a(n); cin >> a;
    v<pii> b(n); // cost of destroying connection 
    fon(i,n) 
    {
        int p=0;
        // cout << i << " : ";
        fon(j,n)
        {
            if(i==j) continue;
            p+=a[i]*a[j];
            // cout << a[i]*a[j] << " ";
        }
        // nl
        b[i]={p,a[i]};
    }
    if(b[0].first<=c)
    {
        cout << 1 << endl;
        return;
    }
    // cout << b << endl;
    auto pp=[&](v<pii> &a)
    {
        for(auto &[x,y] : a) cout << x << " " ;
        nl
    };
    // pp(b);
    sort(all(b));
    // pp(b);
    // ps
    int s=0;
    int i=0;
    // set<int> broken;
    while(i<n && s+b[i].first<=c)
    {
        auto [a1,a2] = b[i];
        s+=a1;
        for(int j=0;j<n;j++)
        {
            // if(j==i) continue;
            if(j<=i) c+=b[i+1].second*b[j].second;
            else b[j].first-=a2*b[j].second;
        }
        i++;
        // pp(b);
    }
    cout << n-i << endl;
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
    }
    return 0;
}