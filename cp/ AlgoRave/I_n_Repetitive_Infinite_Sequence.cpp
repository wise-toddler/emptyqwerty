// https://codeforces.com/gym/104955/problem/I
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
vi d(10), p10(19);
vi k(10);
int g(int n)
{
    return (sqrt(1+8*n)-1)/2;
}
void solve()
{
    int n;cin >> n;
    n--;
    int l=upper_bound(all(d),n)-d.begin();
    n-=d[l-1];
    int id=n/l+k[l-1];
    n%=l;
    cout << to_string(g(id)+1)[n] << endl;

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    d[0] = 0;
    k[0] = 0;
    p10[0] = 1;
    fo1(i, 1, 19, 1) p10[i] = p10[i - 1] * 10;
    fo1(i, 1, 11, 1)
    {
        d[i] += d[i-1] + (p10[i] - p10[i - 1]) * (p10[i] + p10[i - 1] - 1) * i / 2;
        k[i]=k[i-1]+(p10[i]-p10[i-1])*(p10[i] + p10[i - 1] - 1)/2;
    }
    // cout << d << endl;nl
    // cout << k << endl;
    nl

    // cout << p10 << endl;
    while(t--)
    {
        solve();
    }
}