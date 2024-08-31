// https://codeforces.com/contest/1997/problem/B
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
    int n;cin >> n;
    v<v<char>> a(2,v<char>(n));cin >> a;
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    int dx1[]={1,1,-1,-1};
    int dy1[]={1,-1,1,-1};
    int ans=0;
    fon(i,n)
    {
        fon(j,2)
        {
            int c=0;
            if(a[j][i]=='x') continue;
            fon(k,4)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 and x<n and y>=0 and y<2)
                {
                    c+=(a[y][x]=='.');
                }
            }
            if(c==3)
            {
                int cc=0;
                fon(k,4)
                {
                    int x=i+dx1[k];
                    int y=j+dy1[k];
                    if(x>=0 and x<n and y>=0 and y<2)
                    {
                        cc+=(a[y][x]=='x');
                    }
                }
                if(cc==2) ans++;
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