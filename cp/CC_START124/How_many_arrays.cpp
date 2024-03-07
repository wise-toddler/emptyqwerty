// https://www.codechef.com/START124B/problems/ARRAYCOUNT
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
    int n,m;
    // count number of factors of n 
    cin >> n >> m;
    int ans = 1;
    for(int i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            int cnt = 0;
            while(m%i==0)
            {
                m/=i;
                cnt++;
            }
            ans *= (cnt+1);
        }
    }
    if(n>1)
        ans *= 2;
    // cout << (ans>=m?"YES":"NO") << endl;
    // deb(ans)
    // 10000^4 = 10^16
    // 1e16 % 998244353
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