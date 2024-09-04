// https://codeforces.com/contest/1978/problem/D
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,m;cin>>n>>m;
    vi a(n);cin>>a;
    auto mx=max_element(all(a));
    
    int mxv = *mx;
    int mxid = mx-a.begin();

    vi ans(n,-1);   
    if(m+a[0]>=mxv)
    {
        ans[0]=0;
    }
    else 
    {
        ans[0]=1;
    }
    vi presum(n);
    presum[0]=a[0];
    fo1(i,1,n,1) presum[i]=presum[i-1]+a[i];
    auto sum = [&](int l,int r)
    {
        if(l==0) return presum[r];
        return presum[r]-presum[l-1];
    };

    int rmx=a[0];
    int id=0;
    fo1(i,1,n,1) 
    {
        if(i==mxid) 
        {
            if((a[0]+m)<mxv) 
            {
                ans[i]=0;
            }
            else 
            {
                ans[i]=i;
            }
        }
        if(i>mxid)
        {
            ans[i]=i;
        }
        if(i<mxid)
        {   
            ans[i]=i;
            if(sum(0,i)+m<mxv)
            {
                ans[i]++;
            }
        }   
    }
    cout << ans << endl;
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
    }
    return 0;
}