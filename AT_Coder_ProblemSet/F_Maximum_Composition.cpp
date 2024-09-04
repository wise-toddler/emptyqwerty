// https://atcoder.jp/contests/abc366/tasks/abc366_f
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
    int n,k;cin >> n >> k;
    vvi a(n,vi(2));cin >> a;
    sort(all(a),[](vi x,vi y){ if(x[0]==y[0]) return x[1]>y[1]; return x[0]>y[0];});
    fon(i,n) cout << a[i][0] << ' ' << a[i][1] << endl;
    // find max ff+ss in a then remove it 
    // int id=-1;
    // int mx=0;
    // fon(i,n)
    // {
    //     if(a[i][0]+a[i][1]>=mx)
    //     {
    //         mx=a[i][0]+a[i][1];
    //         id=i;
    //     }
    // }
    // remove id  
    // cout << "id: " << id << endl;
    // cout << a[id][0] << ' ' << a[id][1] << endl;  
    // a.erase(a.begin()+id);
    // int ans=mx;
    // int t=1,i=0;
    // while(t<k)
    // {        
    //     if(i==id) i++;
    //     ans=(a[i][0]*ans+a[i][1]);
    //     i++;
    //     t++;
    // }
    // cout << ans << endl;
    // int ans=0;
    // fon(i,n)
    // {
    //     int cans=a[i][0]+a[i][1];
    //     int t=1;
    //     int j=0;
    //     while(t<k)
    //     {
    //         if(j==i) j++;
    //         cans=(a[j][0]*cans+a[j][1]);
    //         j++;
    //         t++;
    //     }
    //     ans=max(ans,cans);
    // }
    // cout << ans << endl;
    // n*k dp take ith element or not till cnt is 
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