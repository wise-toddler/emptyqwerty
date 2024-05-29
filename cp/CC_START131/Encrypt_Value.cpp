// https://www.codechef.com/START131B/problems/ENV
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
int solve()
{
    int n;cin >> n;
    int m=1e9+7;
    vi a(n);cin >> a;
    sort(all(a));
    if(a[0]==1)
    {
        int i=0;
        while(i<n && a[i]==1) i++;
        int ans;
        if(i==1) ans=i+a[i];
        else ans=i*a[i];
        ans%=m;
        i++;  
        while(i<n)
        {
            ans=(ans*a[i])%m;
            ans%=m;
            i++;
        }
        ans%=m;
        return ans;
    }   
    else
    {
        int ans=0;
        fon(i,n)
        {
            if(i==0) ans+=a[i];
            else ans=(ans*a[i])%m;
            ans%=m;
        }
        ans%=m;
        return ans;
    }
}
// 1 5 6 7 8
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        cout << solve() << endl;
    }
}