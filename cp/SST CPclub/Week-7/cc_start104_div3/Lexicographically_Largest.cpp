// https://www.codechef.com/problems/LEXILARGEST
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define deb(x) cout << #x << ": " << x << endl;
void print(vi v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << ' ';
    cout << endl;
}
int largestB(int a, int gcd , int m)
{
    int b=(m/gcd)*gcd;
    while(__gcd(a,b)!=gcd)
    {
        b-=gcd;
    }
    return b;
}
void solve()
{
    int n,m;cin>>n>>m;
    vi a(n);
    for(int &i:a)cin>>i;
    vi b(n);
    b[0]=a[0];
    fo1(i,1,n,1)
        b[i]=largestB(a[i-1],a[i],m);
    print(b);
}
signed main()
{
    IOS
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}