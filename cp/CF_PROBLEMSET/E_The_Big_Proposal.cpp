// https://codeforces.com/gym/512112/problem/E
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
bool solve()
{
    int n,a,b;cin >> n >> a >> b;

    auto f = [&]() -> int
    {
        bitset<64> aa(a), bb(b);
        int cnt=0;
        fon(i,64)
        {
            if(aa[i] == 1 && bb[i] == 0)
                return 0;
            if(aa[i] == 0 && bb[i] == 1)
                cnt++;
        }

        int mxNumbers = 1ll << cnt;  
        int minNumbers = cnt == 0 ? 1 : 2;

        return minNumbers <= n and n <= mxNumbers;
    };

    cout << (f() ? "YES" : "NO") << endl;

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        cout << (solve()?"YES":"NO") << endl;
    }
}