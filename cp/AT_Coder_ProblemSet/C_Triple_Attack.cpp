// https://atcoder.jp/contests/abc368/tasks/abc368_c
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
    int n;cin>>n;
    vi a(n);cin>>a;
    int ans=0;
    int c=0;
    for(int i: a)
    {   
        // cout << i << " ";
        if(ans%3==0)
        {
            int r=i/5;
            ans+=r*3;
            i-=r*5;
            if(i>2) 
            {
                ans+=3;
            }
            else if(i==2)
            {
                ans+=2;
            }
            else if(i==1)
            {
                ans++;
            }
        }else if(ans%3==1)
        {
            int r=i/5;
            ans+=r*3;
            i-=r*5;
            if(i>1) 
            {
                ans+=2;
            }
            else if(i==1)
            {
                ans++;
            }
        }else if(ans%3==2)
        {
            int r=i/5;
            ans+=r*3;
            i-=r*5;
            if(i<=3)
            {
                ans++;
            }
            else if(i==4)
            {
                ans+=2;
            }
        }
        // cout << ans << endl;    
    }
    cout << ans << endl;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}