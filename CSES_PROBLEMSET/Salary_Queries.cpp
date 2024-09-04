// https://cses.fi/problemset/task/1144
#include <bits/stdc++.h>
using namespace std;

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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
    ordered_set<pii> s;
    for(int i=0;i<n;i++)
        s.insert({a[i],i});
    while(q--)
    {
        char c;cin >> c;
        if(c=='?')
        {
            int l,r;cin >> l >> r;
            // int ls=s.order_of_key({l,0});
            // int rs=s.order_of_key({r+1,0});
            // deb(ls)deb(rs)
            cout << s.order_of_key({r+1,-1})-s.order_of_key({l,-1}) << endl;
        }
        else
        {
            int k,x;cin >> k >> x;
            s.erase({a[k-1],k-1});
            a[k-1]=x;
            s.insert({a[k-1],k-1});
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