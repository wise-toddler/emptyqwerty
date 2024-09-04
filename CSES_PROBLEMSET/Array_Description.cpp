// https://cses.fi/problemset/task/1746
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
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
void solve()
{
    int n,m;cin>>n>>m;
    vi a(n);cin>>a;
    int mod = 1e9+7;
    // vvi dp(n+1,vi(m+1,-1));
    // function<int(int,int)> f = [&](int i,int l)
    // {
    //     if(i==n)return 1ll;
    //     int &an = dp[i][l]; if(an!=-1)return an;
    //     an = 0;
    //     if(a[i]!=0)
    //     {
    //         if(abs(a[i]-l)<=1)an = f(i+1,a[i]);
    //         return an;
    //     }
    //     for(auto x : {l-1,l,l+1})
    //     {
    //         if(x<1 || x>m)continue;
    //         an = (an+f(i+1,x))%mod;            
    //     }
    //     return an;
    // };
    // int o=0;
    // if(a[0]==0)fo1(i,1,m+1,1)o = (o+f(1,i))%mod;
    // else o = f(1,a[0]);
    // for(auto x : dp)
    // {
    //     cout << x << endl;
    // }
    // cout<<o<<endl;

    vvi dp(2,vi(m+1,0));
    // vvi dp(n+1,vi(m+1,0));

    fo1(i,n,0,-1)
    {
        fo1(j,1,m+1,1)
        {
            int &an = dp[i&1][j];
            // int &an = dp[i][j];
            an = 0;
            if(i==n)an = 1;
            else
            {
                if(a[i]!=0)
                {
                    if(abs(a[i]-j)<=1)
                        an = dp[(i+1)&1][a[i]];
                        // an = dp[i+1][a[i]];
                }
                else
                {
                    an = 0;
                    for(auto x : {j-1,j,j+1})
                    {
                        if(x<1 || x>m)continue;
                        an = (an+dp[(i+1)&1][x])%mod;
                        // an = (an+dp[i+1][x])%mod;
                    }
                }
            }
        }
    }
    // for(auto x : dp)
    // {
    //     cout << x << endl;
    // }
    if(a[0]==0)cout<<accumulate(all(dp[1]),0ll)%mod<<endl;
    else cout<<dp[1][a[0]]<<endl;
    /*
-1 -1 -1 -1 
-1 160 200 120 
-1 80 80 40 
-1 40 40 0 
-1 40 -1 -1 
-1 15 25 -1 
-1 5 10 10 
-1 0 5 5 
-1 -1 -1 5 
-1 -1 3 2 
-1 -1 -1 -1 
480
    */
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