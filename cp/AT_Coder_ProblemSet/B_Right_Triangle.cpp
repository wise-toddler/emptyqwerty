// https://atcoder.jp/contests/abc362/tasks/abc362_b
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
#define ff first
#define ss second
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
bool solve()
{
    int ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    // a^2+b^2=c^2
    double a=((double)((bx-ax)*(bx-ax)+(by-ay)*(by-ay)));
    double b=((double)((cx-bx)*(cx-bx)+(cy-by)*(cy-by)));
    double c=((double)((cx-ax)*(cx-ax)+(cy-ay)*(cy-ay)));
    return a+b==c || b+c==a || c+a==b;

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}