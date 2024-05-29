// https://cses.fi/problemset/task/2168
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
    vvi a(n,vi(3));
    fon(i,n)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][2]=i;
    }
    sort(all(a),[&](vi a,vi b){if(a[0]==b[0])return a[1]>b[1];return a[0]<b[0];});
    vi a1(n),a2(n);
    int m1=1e10,m2=0;
    fo1(i,n-1,-1,-1)
    {
        if(a[i][1]>=m1)
            a1[a[i][2]]=1;
        m1=min(m1,a[i][1]);
    }
    cout << a1 << endl;
    fon(i,n)
    {
        if(a[i][1]<=m2)
            a2[a[i][2]]=1;
        m2=max(m2,a[i][1]);
    }
    cout << a2 << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;    
    while(t--)
    {
        solve();
    }
}