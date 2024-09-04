// https://codeforces.com/contest/1990/problem/D
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
void solve()
{
    int n;cin>>n;
    vi a(n);cin>>a;
    // 244..4442 pattern can be skippes where 4 is even no of times 
    int ans=n;
    int cnt=-1;
    for(int i: a)
    {
        if(i==0)
        {
            ans--;
            cnt=-1;
        }
        else if(i<=2)
        {
            if(cnt>=0)
            {
                if(cnt%2==0) 
                    ans--,cnt=-1;
                else 
                    cnt=0;
            }
            else
            {
                cnt=0;
            }
        }
        else if(i<=4)
        {
            if(cnt>=0) 
                cnt++;
        }
        else 
        {
            cnt=-1;
        }
        // deb(i)
        // deb(ans)
        // deb(cnt)
        // nl
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