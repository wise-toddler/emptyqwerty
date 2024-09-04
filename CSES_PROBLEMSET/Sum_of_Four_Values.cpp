// https://cses.fi/problemset/task/1642
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
    map<int,pii> mp;
    fon(i,n) fo1(j,i+1,n,1) mp[aa[i]+aa[j]]={i,j};
    bool found=false;
    fon(i,n)
    {
        fo1(j,i+1,n,1)
        {
            int sum=aa[i]+aa[j];
            if(mp.find(x-sum)!=mp.end())
            {
                auto [a,b]=mp[x-sum];
                if(a!=i && a!=j && b!=i && b!=j)
                {
                    cout << i+1 << ' ' << j+1 << ' ' << a+1 << ' ' << b+1 << endl;
                    found=true;
                    break;
                }
            }
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