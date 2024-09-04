// https://codeforces.com/problemset/problem/1998/E2
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
// #define nl cout << endl;
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
    vi a(n+1); fon(i,n) cin >> a[i+1]; 
    vi pre(n+1);
    fon(i,n) pre[i+1]=pre[i]+a[i+1];
    auto sum=[&](int l,int r){return pre[r]-(l==0?0:pre[l-1]);};
    auto get=[&](int l1,int i)
    {
        while(l1!=0 and a[l1] <= sum(l1+1,i))
        {
            int l=0,r=l1;
            int nl=0;
            while(l<=r)
            {
                int m=(l+r)/2;
                if(sum(m,i) > (sum(l1,i)*2))
                {
                    nl=m;
                    l=m+1;
                }
                else 
                    r=m-1;
            }
            l1=nl;
        }
        return l1;
    };
    multiset<pii> newls,idxs;
    int ans=0;
    fo1(i,1,n+1,1)
    {
        if(pre[i-1] < a[i])
        {
            ans=0;
            newls.clear();
            idxs.clear();
        }
        
        if(i==1) ans=1;
        else
        {
            while(idxs.size() and idxs.rbegin()->ff > pre[i-1]-a[i]) 
            {
                auto [val,idx]=*idxs.rbegin();
                newls.erase(newls.lower_bound({a[idx]+pre[idx],idx}));
                idxs.erase(prev(idxs.end()));
            }
            idxs.insert({pre[i-1],i-1});
            newls.insert({a[i-1]+pre[i-1],i-1});
        }
        // shift ls to the left
        while(newls.size() and newls.begin()->ff <= pre[i]) 
        {
            auto [val,idx]=*newls.begin();
            newls.erase(newls.begin());
            idxs.erase(idxs.lower_bound({pre[idx],idx}));
            int l1=get(idx,i);  
            if(l1==0) ans++;
            else 
            {
                idxs.insert({pre[l1],l1});
                newls.insert({a[l1]+pre[l1],l1});
            }
        }
        cout << ans << " ";
    }
    cout << endl;
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