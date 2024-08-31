// https://codeforces.com/contest/1922/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define nl cout<<endl;
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
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
void solve()
{
    int n;cin>>n;
    n--; // empty subsequence
    // int fh=(1ll<<(int)(log(n)/log(2)))-1;
    int id=0;
    int fh=0;
    vi a;
    while((fh*2+1)<=n)
    {
        a.pb(id);
        fh+=1ll << id;
        id++;
    }
    int sh=n-fh;
    // cout << log2(n) << endl;
    // cout << n << " " <<fh << ' ' << sh << endl;
    // fo1(i,0,64,1)
    //     if(fh&(1ll<<i))
    //         a.pb(i);
    // a.pb(-1);
    fo1(i,63,-1,-1)
        if(sh&(1ll<<i))
            a.pb(i);

    cout << a.size() << endl << a << endl;
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