// https://www.codechef.com/START137B/problems/TFALL
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
    int n;cin >> n;
    vi a(n);cin >> a;
    vi p(n);cin >> p;
    vi right,left;
    fon_(i,n)
    {
        if(i!=0 && (a[i]-p[i]<=a[i-1]))
            left.pb(1);
        else   
            left.pb(0);
    }
    reverse(all(left));
    fon(i,n)
    {
        if(i!=n-1 && (a[i]+p[i]>=a[i+1]))
            right.pb(1);
        else 
            right.pb(0);
    }
    vi leftdown,rightdown;
    int e=1;
    fon_(i,n)
    {
        while(i>=0 && left[i])leftdown.pb(e),i--;
        if(i>=0)
            leftdown.pb(e);
        e++;
    }
    reverse(all(leftdown));
    e=1;
    fon(i,n)
    {
        while(i<n && right[i])rightdown.pb(e),i++;
        if(i<n)
            rightdown.pb(e);
        e++;
    }
    // deb(leftdown)
    // deb(rightdown);
    int a1=leftdown[0],a2=rightdown[n-1];
    // ll and rr 
    if(a1<=2 || a2<=2) return 1;

    // l from n and r from 1
    int id1 = find(all(leftdown),1)-leftdown.begin();
    int id2 = find(all(rightdown),2)-rightdown.begin();
    if(id1<=id2) return 1;

    int id3 = find(all(leftdown),a1-1)-leftdown.begin(); 
    int id4 = find(all(rightdown),a2)-rightdown.begin();
    if(id3>=id4) return 1;

    return 0;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve() ? "YES" : "NO") << endl;
        // nl nl
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}