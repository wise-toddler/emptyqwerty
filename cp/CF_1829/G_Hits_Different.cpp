// https://codeforces.com/contest/1829/problem/G
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
vvi a;
int psq(int l,int r,int i)
{
    l=max(0ll,l),r=min(i,r);
    int sum=a[i][r];
    if(l>0) sum-=a[i][l-1];
    return sum;
}
void prefixsum(vi &a)
{
    fo1(i,1,a.size(),1) a[i]+=a[i-1];
}
void pre()
{
    // a.pb({1});
    int st=1;
    fo1(i,1,2024,1)
    {
        vi temp;
        fo1(j,st,st+i,1) temp.pb((j*j));
        prefixsum(temp);
        a.pb(temp);
        st+=i;
    }
}
#define f(x) x*(x+1)/2
void solve()
{
    int n; cin>> n;
    int i=-1,j=-1;
    int k=1;
    while(f(k)<n) k++;
    i=k-1;
    j=n-f(i)-1;
    int ans=0;
    fon_(p,i+1)
    {
        int l=j-i+p,r=j;
        ans+=psq(l,r,p);
    }
    cout << ans << endl;
    
    
}
signed main()
{
    IOS
    //TxtIO
    pre();
    int t=1;
    cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}