// https://codeforces.com/gym/105262/problem/F
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
// vi vals;

void solve()
{
    // vals.clear();
    int nn,mm;cin>>nn>>mm;
    string s,t;cin>>s>>t;
    int x,k;cin>>x>>k;
    if(x==1) 
    {
        cout << s[k-1] << endl;
        return;
    }
    vi vals;
    vals.pb(mm);
    vals.pb(nn+mm);
    for(int i=3;i<1000;i++)
    {
        vals.pb(vals.back()+vals[vals.size()-2]); 
        if(vals.back()>=1e18) break;
    }
    // cout << vals << endl;
    while(k>(nn+mm))
    {
        // int temp= k-*lower_bound(all(vals),k);

        // k 

        int l = 0;
        int r = vals.size()-1;
        int ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(vals[mid] < k){
                ans = vals[mid];
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        // deb(ans)
        k-=ans;
    }
    string p=t+s;
    // cout << p <<endl;
    // cout << k << endl;
    cout << p[k-1] << endl;
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