// https://www.codechef.com/START131B/problems/DIDE
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
    int n,k;cin >> n >> k;
    vi a(n);cin >> a;
    map<int,int> cnt;    
    for(auto x:a) cnt[x]++;
    // print the map
    // for(auto [i,c]:cnt)
    // {
    //     cout << i << " " << c << endl;
    // }

    int ans=cnt[6]*6+cnt[5]*5+cnt[4]*4;
    // deb(ans)
    if(k>0) 
    {
        int x=min(cnt[1],k);
        ans+=x*6;
        k-=x;   
        cnt[1]-=x;
    }
    ans+=cnt[1];  
    // deb(ans)
    // deb(k)
    if(k>0)
    {
        int x=min(cnt[2],k);
        ans+=x*5;
        k-=x;
        cnt[2]-=x;
    }
    ans+=cnt[2]*2;
    // deb(ans)
    // deb(k)
    if(k>0)
    {
        int x=min(cnt[3],k);
        ans+=x*4;
        k-=x;
        cnt[3]-=x;
    }
    ans+=cnt[3]*3;

    return ans;
}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        cout << solve() << endl;
        // solve();
        // cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}