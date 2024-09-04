// https://codeforces.com/gym/494905/problem/D
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
void solve()
{
    int a,b,c,d;cin>>a>>b>>c>>d;
    if((b-a)%gcd(c,d)!=0)
    {
        cout << -1 << endl;
        return;
    }
    int a1=max(b/c*c,a);
    if(a1==b)
    {
        cout << a1 << endl;
        return;
    }
    int l1=a1,l2=b+lcm(c,d);
    int i=a1,j=b;
    while(i<j)
    {
        int k = j-i;
        if(k==0) break;
        if(k>=c)
            i+=c;
        else
            j+=d;
    }
    cout << i << endl;

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