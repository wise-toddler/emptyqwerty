// https://codeforces.com/contest/1975/problem/A
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n;cin >> n;
    vi a(n); cin >> a;
    // check if it can be split into 2 parts such that both are non decreasing
    // if a[i] > a[i+1] then a[i] = a[i+1]

    int id1 = -1;
    fon(i,n-1)
    {
        if(a[i]>a[i+1])
        {
            id1 = i;
            break;
        }
    }
    if(id1==-1)
    {
        cout << "YES" << endl;
        return;
    }
    // deb(id1)
    int id2 = -1;
    fo1(i,id1+1,n-1,1)
    {
        if(a[i]>a[i+1])
        {
            id2 = i;
            break;
        }
    }
    if(id2==-1 and a[n-1]<=a[0])
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

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
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}