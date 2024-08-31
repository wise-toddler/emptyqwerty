// https://cses.fi/problemset/task/1641
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
    int n,x;cin >> n >> x;
    vi aa(n);cin >> aa;
    // sort(all(aa));
    v<pii> bb(n);
    fon(i,n) bb[i]={aa[i],i};
    sort(all(bb));
    bool found=false;
    fon(i,n)
    {
        int l=i+1,r=n-1;
        while(l<r)
        {
            if(bb[i].ff+bb[l].ff+bb[r].ff==x)
            {
                cout << bb[i].ss+1 << ' ' << bb[l].ss+1 << ' ' << bb[r].ss+1 << endl;
                found=true;
                break;
            }
            else if(bb[i].ff+bb[l].ff+bb[r].ff>x) r--;
            else l++;
        }
        if(found) break;
    }
    if(!found) cout << "IMPOSSIBLE" << endl;
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