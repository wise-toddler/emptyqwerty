// https://www.codechef.com/START143B/problems/DIVCOL?tab=statement
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
vi f(200005);
vi ans(200005);
void spf()
{
    f[1]=1;
    fo1(i,2,200005,1) f[i]=i;
    fo1(i,2,200005,1)
    {
        if(f[i]==i)
        {
            for(int j=i*i;j<200005;j+=i) f[j]=i;
        }
    }
    // fon(i,100)
    // {
    //     cout << f[i] << ' ';
    // }
    ans[1]=1;
    fo1(i,2,2e5+1,1)
    {
        int x=i/f[i];
        ans[i]=ans[x]+1;
    }
}
void solve()
{
    int n;cin>>n;
    cout << *max_element(ans.begin(),ans.begin()+n+1) << endl;
    fo1(i,1,n+1,1) cout << ans[i] << ' ';
    nl
}
signed main()
{
    IOS
    //TxtIO
    spf();
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}