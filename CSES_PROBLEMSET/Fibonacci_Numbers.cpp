// https://cses.fi/problemset/task/1722
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
#define mat vi // 2*2 matrix where mat[0] and mat[1] is row 1 and mat[2] and mat[3] is row 2
int mod=1e9+7;
mat mul(mat a,mat b)
{
    mat c(4);
    c[0]=(a[0]*b[0]%mod+a[1]*b[2]%mod)%mod;
    c[1]=(a[0]*b[1]%mod+a[1]*b[3]%mod)%mod;
    c[2]=(a[2]*b[0]%mod+a[3]*b[2]%mod)%mod;
    c[3]=(a[2]*b[1]%mod+a[3]*b[3]%mod)%mod;
    return c;
}
mat pow(mat a,int n)
{
    if(n==1)
        return a;
    mat x=pow(a,n/2);
    x=mul(x,x);
    if(n%2)
        x=mul(x,a);
    return x;
}
void solve()
{
    int n;cin>>n;
    if(n==0)
    {
        cout << 0 << endl;
        return;
    }
    mat a={1,1,1,0}; // Fibonacci matrix a^n = {F(n+1),F(n),F(n),F(n-1)} for n>=1
    mat b=pow(a,n);
    cout << b[1] << endl;
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
