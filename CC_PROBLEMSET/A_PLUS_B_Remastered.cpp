// https://www.codechef.com/START115B/problems/APLUSB
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define v vector
#define vi v<int>
#define vvi v<v<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    vi b(n);cin>>b;
    sort(all(a),greater<int>());
    sort(all(b));
    vi c(n);
    for(int i=0;i<n;i++)
        c[i]=a[i]+b[i];
    sort(all(c));
    if(c[0]!=c.back()) cout<<"-1"<<endl;
    else
    {
        cout<<a<<endl;
        cout<<b<<endl;
    }
    // vi diffa(n-1),diffb(n-1);
    // for(int i=0;i<n-1;i++)
    // {
    //     diffa[i]=a[i+1]-a[i];
    //     diffb[i]=b[i+1]-b[i];
    // }
    // if(diffa!=diffb) cout<<"-1"<<endl;
    // else
    // {
    //     reverse(all(a));
    //     cout<<a<<endl;
    //     cout<<b<<endl;
    // }
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