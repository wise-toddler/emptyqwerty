// https://cses.fi/problemset/task/2217
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
    int n,m;cin >> n >> m;
    vi a(n); cin >> a;
    vi pos(n);
    fon(i,n)
    {
        pos[a[i]-1]=i;
    }
    int ans=1;
    fon(i,n-1)
    {
        if(pos[i]>pos[i+1])
        {
            ans++;
        }
    }
    // deb(pos);
    while(m--)
    {
        // deb(ans);
        // nl
        int l,r;cin >> l >> r;
        int x=a[l-1]-1,y=a[r-1]-1;
    
        // deb(x)deb(y)
        if(x>y) swap(x,y);
        if(x==y) cout << ans << endl;
        else if((y-x)!=1)
        {
            
            if(x>0 and pos[x-1]>pos[x]) ans--;
            // deb(ans);
            if(x<n-1 and pos[x]>pos[x+1]) ans--;
            // deb(ans);
           
            if(y>0 and pos[y-1]>pos[y]) ans--;
            if(y<n-1 and pos[y]>pos[y+1]) ans--;

            // deb(ans);
            swap(pos[x],pos[y]);
            swap(a[l-1],a[r-1]);

            if(x>0 and pos[x-1]>pos[x]) ans++;
            if(x<n-1 and pos[x]>pos[x+1]) ans++;

            // deb(ans);
            if(y>0 and pos[y-1]>pos[y]) ans++;
            if(y<n-1 and pos[y]>pos[y+1]) ans++;

            // deb(ans);
            cout << ans << endl;
        }
        else
        {
            if(x>0 and pos[x-1]>pos[x]) ans--;
            if(pos[x]>pos[y]) ans--;
            if(y<n-1 and pos[y]>pos[y+1]) ans--;

            // deb(ans);
            swap(pos[x],pos[y]);
            swap(a[l-1],a[r-1]);

            if(x>0 and pos[x-1]>pos[x]) ans++;
            if(pos[x]>pos[y]) ans++;
            if(y<n-1 and pos[y]>pos[y+1]) ans++;

            // deb(ans);
            cout << ans << endl;
        }
    }

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

