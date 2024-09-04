// https://cses.fi/problemset/task/1164
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
    v<tuple<int,int,int>> aa(n);
    fon(i,n)
    {
        int a,b;cin >> a >> b;
        aa[i]={a,b,i};
    }
    sort(all(aa),[](tuple<int,int,int> a,tuple<int,int,int> b){return get<0>(a)<get<0>(b);});
    // fon(i,n) cout << aa[i] << endl;
    int rooms=1;
    set<pii> ans; // end_time,room_no
    vi anss(n);
    fon(i,n)
    {   
        auto [a,b,_]=aa[i];
        if(ans.size()==0 || ans.begin()->ff>=a)
        {
            anss[_]=rooms;
            ans.insert({b,rooms++});
        }
        else
        {
            // auto it=lower_bound(all(ans),pii(a,0));
            auto it=ans.begin();
            // it--;
            anss[_]=it->ss;
            ans.erase(it);
            ans.insert({b,it->ss});
        }
    }
    cout << ans.size() << endl;
    for(int i:anss) cout << i << ' ';   
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