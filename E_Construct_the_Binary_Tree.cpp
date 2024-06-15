// https://codeforces.com/contest/1311/problem/E
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
int pre[5001];
void p()
{
    int ll =0;
    int l=0;
    fo1(i,1,5001,1)
    {
        ll+=l;
        if(((i+1)&i)==0)l++;
        pre[i]=ll;
    }
}
void solve()
{
    int n,m;cin >> n >> m;
    int ll=pre[n],rr=n*(n-1)/2;
    if(m<ll || m>rr)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
                            
}
signed main()
{
    IOS
    p();
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