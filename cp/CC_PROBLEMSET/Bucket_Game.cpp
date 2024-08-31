// https://www.codechef.com/START125B/problems/BGME
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
pii f(vi &a)
{
    int n=a.size();
    int e =0;
    for(int i:a)
        if(i%2)
            e++;
    if(e&1)
        return {n,0LL};
    else
        return {0LL,n};
    // return ((e&1)?({n,0LL}):({0LL,n}));
}
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    vi b;
    int ones = 0;
    for(int &i:a)
        if(i!=1)
            b.pb(i);
    ones = n-b.size();

    int aa = ones&1;
    auto [a1,a2] = f(b);
    if(aa) 
        swap(a1,a2);
    aa+=a1;
    if(aa==a2)
        cout << "Draw" << endl;
    else if(aa>a2)
        cout << "Alice" << endl;
    else 
        cout << "Bob" << endl;

    // if(alice==)
    // int alice = a&1;
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