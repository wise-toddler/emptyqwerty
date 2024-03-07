// https://codeforces.com/contest/453/problem/A
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
#define fo1(i,st,en,up) for(double i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
void solve()
{
    double m,n;cin>>m>>n;
    double ans=0;
    fo1(i,1,m,1)
        ans-=pow(i/m,n);
    ans+=m;
    cout << fixed << setprecision(12) << ans << endl;
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

/*
15 
20 34 
35  5 14 16 
26 -1 25 23 -1 30  3 36 
-1 -1  7 24 11 32 -1 -1 21 -1 -1 -1 
29  4  9 -1 33 13 -1 -1 -1 -1 
22 31 -1 27 19  1 -1 12 18  6 
-1 -1 -1  2 -1 -1 -1 -1 10 -1 -1 -1 -1  8 -1 28 
-1 -1 -1 -1 -1 17 -1 -1 
-1 -1


*/