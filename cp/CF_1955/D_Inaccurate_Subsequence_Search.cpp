// https://codeforces.com/contest/1955/problem/D
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,m,k;cin>>n>>m>>k;
    vi a(n);cin >> a;
    vi b(m);cin >> b;
    map<int,int> mpb,mpwindow;
    fon(i,m) mpb[b[i]]++;   
    queue<int> q;
    int kk=0;
    fon(i,m) 
    {
        q.push(a[i]);
        if(mpb.count(a[i]))
        {
            mpwindow[a[i]]++;
            if(mpwindow[a[i]]<=mpb[a[i]]) kk++;
        }
    }
    // deb(kk)
    int ans=(kk>=k);
    // deb(ans)
    fo1(i,m,n,1)
    {
        int x=q.front(); q.pop();
        if(mpb.count(x))
        {
            mpwindow[x]--;
            if(mpwindow[x]<mpb[x]) kk--;
        }
        q.push(a[i]);
        if(mpb.count(a[i]))
        {
            mpwindow[a[i]]++;
            if(mpwindow[a[i]]<=mpb[a[i]]) kk++;
        }
        if(kk>=k) ans++;
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
    }
}