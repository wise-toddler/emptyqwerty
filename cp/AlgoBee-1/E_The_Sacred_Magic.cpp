// https://codeforces.com/gym/505920/problem/E
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
    vi a(n);cin >> a;
    vvi b(n,vi(32,0));
    fon(i,n)
        fo1(j,0,33,1)
            b[i][j] = (a[i]>>j)&1;
    
    fon(i,32)
        fo1(j,1,n,1)
            b[j][i] = b[j][i] + b[j-1][i];

    int q;cin >> q;
    while(q--)
    {
        int l,r;cin >> l >> r;
        l--;r--;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int cnt = b[r][i] - (l==0?0:b[l-1][i]);
            if(cnt==(r-l+1))
                ans+=(1LL<<i);
        }
        cout << ans << endl;
    }
}
signed main()
{
    IOS
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}