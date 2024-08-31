// https://codeforces.com/contest/1997/problem/E
#include <bits/stdc++.h>
using namespace std;

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>


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
    int n,q;cin >> n >> q;
    vi a(n);cin >> a;
    vi ans(n);
    ordered_multiset s;
    // s.insert(0);
    // s.insert(0);
    // cout << s.size() << endl;
    // return;
    fon(i,n) 
    {
        int l=1,r=n; 
        int para=0;
        while(l<=r)
        {
            int m=(l+r)/2;
            // deb(i);
            // deb(m);

            int cnt=s.order_of_key(m+1);
            // deb(cnt);

            int power = cnt/m +1;
            // deb(power);
            if(power>a[i])
            {
                l=m+1;
                para=m+1;
            }
            else r=m-1;

        }
        ans[i]=l;
        // cout << " insert " << para << endl;
        s.insert(para);
        // nl nl
    }
    while(q--)
    {
        int i,x;cin >> i >> x;
        i--;
        if(x>=ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
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