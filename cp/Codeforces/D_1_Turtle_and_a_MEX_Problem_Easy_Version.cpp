// https://codeforces.com/contest/2003/problem/D1
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
    vvi a(n,vi(2));
    int ll=0;
    fon(i,n)
    {
        int l;cin>>l;
        ll=max(ll,l);
        vi aa(l);cin >> aa;
        // a[i] = {1st mex and 2nd mex};
        sort(all(aa));
        unique(all(aa));
        int id=0;
        while(id<l && aa[id]==id) id++;
        a[i][0]=id;
        // deb(id)
        aa.insert(aa.begin()+id,id);
        id++;
        while(id<(l+1) && aa[id]==id) id++;
        a[i][1]=id;
    }
    // fon(i,n)
    // {
    //     cout << a[i][0] << " " << a[i][1] << endl;
    // }
    // nl nl
    sort(all(a));
    int maxm=min(m,ll+1);
    int maxy=0;
    fon_(i,n)
    {
        maxy=max(maxy,a[i][1]);
        a[i][1]=maxy;   
    }    

    int anss=0;
    fon(i,maxm+1)
    {

        // int ans=i;
        // auto lo = upper_bound(all(a),vi{i,INT_MAX});
        // if(lo!=a.begin())
        // {
        //     lo--;
        //     ans=max(ans,(*lo)[1]);
        // }
        // // cout << ans << " ";
        // anss+=ans;
    }
    #define g(x) x*(x+1)/2
    // if(maxm!=m)

    // cout << maxy << "  " ;
    // cout << (maxy*(maxy+1)) << "  " ;
    // int l=min(m+1,maxy+1);
    // deb(l);
    anss+=(g(m)-g(min(m,maxy))); 
    cout << anss << endl;
    // nl nl
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