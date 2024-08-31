// https://www.codechef.com/START117B/problems/SPREADCT
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
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
int f(int n)
{
    return (n*(n+1))/2;
}
void solve()
{
    int mod=998244353;
    int n,m;cin>>n>>m;
    // if(n<m) swap(n,m);
    int n1=(n+1)/2;
    int m1=(m+1)/2;
    int l=max({n1-1,m1-1,n-n1,m-m1});

    int r1=min(n,l+1);
    int r2=max(n-l,1ll);
    int c1=min(m,l+1);
    int c2=max(m-l,1ll);
    // int ans=0;
    // if(c2<c1)
    //     swap(c1,c2);
    // deb(r1)deb(r2)deb(c1)deb(c2)
    // fo1(i,r1,r2+1,1)
    //     fo1(j,c1,c2+1,1)
    //         ans=(ans+((i+1)*(j+1))%mod)%mod;
    int a=f(r1)-f(r2-1);
    int b=f(c1)-f(c2-1);
    a=(a+mod)%mod;
    b=(b+mod)%mod;
    cout << (a*b)%mod << endl;
    
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