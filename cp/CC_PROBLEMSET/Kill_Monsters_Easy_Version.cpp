// https://www.codechef.com/START149B/problems/CXZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
    int n,x,k;cin >> n >> x >> k;
    vi a(n);cin >> a;
    map<int,int> mp;
    for(int i:a) mp[i]++;
    vvi b;
    int id=0;
    ordered_set s;
    vi v1,v2;
    for(auto [i,c]:mp)
    {
        v1.pb(i);
        s.insert(i);
        if(c>1) v2.pb(i);
    }
    if(v2.size()==0)
    {
        int id=lower_bound(all(v1),x*k)-v1.begin();
        cout << id << endl;
        return;
    }
    INT_

    int id1=lower_bound(all(v1),x)-v1.begin();
    int ans=lower_bound(all(v1),x*k)-v1.begin();

    fon_(i,id1)
    {
        int start=v1[i];
        if(mp[start]==1) s.erase(start);
        // number of elements less than var and also support lower_bound
        int id2=distance(s.begin(),lower_bound(all(s),k*start));
        ans=max(ans,(id1-i)+id2);
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
// [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 18, 20, 21, 22, 23, 24]
// [1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 14, 15, 20, 21, 22]