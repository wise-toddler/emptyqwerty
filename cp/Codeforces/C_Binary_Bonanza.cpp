// https://codeforces.com/gym/105120/problem/C
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
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
set<int> bittoset[10];
void solve()
{
    int n,x;cin >> n >> x;
    vi a(n);cin >> a;
    vvi bits(n,vi(x,0)); // x is 1 based bit
    //bit to set
    fon(i,10)
    {
        bittoset[i].clear();
    }
    set<int> setbits1;
    fon(i,n)
    {
        int c=0;
        fo1(j,1,x+1,1)
        {
            if((a[i]>>j)&1) bittoset[j-1].insert(i),c++;
        }
        if(c==0) // if no bit is set
        {
            cout << -1 << endl;
            return;
        }
    }
    // print the bit to set
    // fon(i,10)
    // {
    //     cout << i << ": ";
    //     for(auto j : bittoset[i])
    //     {
    //         cout << j << " ";
    //     }
    //     nl
    // }
    // for(auto i : bits)
    // {
    //     cout << i << endl;
    // }
    // sort(all(setbits));
    // setbits.erase(unique(all(setbits)),setbits.end());
    // vi setbits(all(setbits1));
    int ans=INT_MAX;
    vi vis(n);
    fo1(i,1,(1<<x),1)
    {
        // set<int> temp;
        vis.assign(n,0);
        int c=0;
        fon(j,x+1)
        {
            if((i>>(j+1))&1)
            {
                for(auto k : bittoset[j])
                {
                    if(vis[k]==0)
                    {
                        vis[k]=1;
                        c++;
                    }
                }
            }
        }
        if(c==n) ans = min(ans,(int)__builtin_popcount(i));
        
    }
    cout << ans << endl;
}
signed main()
{
    // bitstring 
    int num=2047;
    // cout << bitset<14>(num) << endl;
    IOS
    //TxtIO
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}