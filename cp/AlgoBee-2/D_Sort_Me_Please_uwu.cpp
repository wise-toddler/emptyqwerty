// https://codeforces.com/gym/517983/problem/D
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
// cnt no of inverse pairs

void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    vi b(n);cin >> b;
    map<int,vi> mp;
    fon(i,n) mp[a[i]].pb(i);
    // // print the map
    // for(auto i:mp)
    // {
    //     cout << i.ff << " : ";
    //     for(auto a:i.ss)
    //         cout << a << ' ';
    //     nl
    // }
    int ak = 0;
    v<pii> ans;
    set<pii> done;
    for(auto i:mp)
    {
        vi idxs = i.ss;
        // deb(idxs)
        sort(all(idxs),[&](int x,int y){return b[x] < b[y];});
        // cnt no of swaps  

        for(int p=0;p<idxs.size();p++)
        {
            if(idxs[p]!=i.ss[p] && done.count({idxs[p],i.ss[p]})==0)
            {
                done.insert({idxs[p],i.ss[p]});
                done.insert({i.ss[p],idxs[p]});
                swap(b[idxs[p]],b[i.ss[p]]);
                // ans.pb({idxs[p],i.ss[p]});
                ans.pb({i.ss[p],idxs[p]});
                // cout << idxs[p] << ' ' << i.ss[p] << endl;
            }
        }
        // deb(idxs)
    }

    // deb(b)
    // check if b is sorted
    // bool ok = 1;
    fon(i,n-1)
    {
        if(b[i]>b[i+1])
        {
            cout << "-1" << endl;
            return;
        }
    }
    cout << ans.size() << endl;
    for(auto i:ans)
        cout << i.ff << ' ' << i.ss << endl;



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
    }
}