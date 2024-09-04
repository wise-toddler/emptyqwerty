// https://codeforces.com/contest/1978/problem/C
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
void solve(int n,int m)
{
    if(m&1) 
    {
        cout << "NO" << endl;
        return;
    }
    int mm=(n*n)/2;
    if(m>mm)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vi ans(n);
    fon(i,n) ans[i]=i+1;
    int i=0,j=n-1;
    while(m>0 and i<j)
    {
        if((ans[j]-ans[i])*2<=m)
        {
            m-=(ans[j]-ans[i])*2;
            swap(ans[j],ans[i]);
            i++;j--;
        }
        else
        {
            j--;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS
    // //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        solve(n,m);
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}