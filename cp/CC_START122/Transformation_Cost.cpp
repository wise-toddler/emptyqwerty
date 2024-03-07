// https://www.codechef.com/START122B/problems/TRANCST
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
void solve()
{
    int n;cin >> n;
    // find 1st and last non-zero bit
    bitset<32> b(n);
    int l = 0, r = 0;
    for(int i=31;i>=0;i--)
    {
        if(b[i])
        {
            r = i;
            break;
        }
    }
    for(int i=r;i>=0;i--)
    {
        if(!b[i])
        {
            l = i;
            break;
        }
    }
    int lu =-1;
    for(int i=0;i<=l;i++)
    {
        if(b[i])
        {
            lu = i;
            break;
        }
    }
    if(lu==-1)
    {
        cout << 0 << endl;
        return;
    }
    int nn = (1<<(r+1))-1;
    cout << b << endl;
    // cout << bitset<8>(nn) << endl;
    // nn -= 1<<(l);
    int ll = (1<<(l))-1;
    // cout << bitset<8>(ll) << endl;
    nn -= ll;
    // deb(r)
    // deb(l)
    // deb(lu)
    // deb (nn)
    // // deb (ll)
    // deb (n)
    // cout << ll << endl;
    // cout << nn << endl;
    // cout << n << endl;
    // cout << bitset<32>(nn) << endl;
    cout << nn -n << endl;
    // cout << bitset<5>(ll) << endl;


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