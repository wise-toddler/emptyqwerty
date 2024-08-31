// https://codeforces.com/contest/1974/problem/C
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
bool f(int ch,vi &a,vi &b)
{
    if(ch==0) return a[0]!=b[0] && a[1]==b[1] && a[2]==b[2];
    if(ch==1) return a[0]==b[0] && a[1]!=b[1] && a[2]==b[2];
    if(ch==2) return a[0]==b[0] && a[1]==b[1] && a[2]!=b[2];
    return false;
}
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    int cnt=0;
    map<vi,int> mp;
    vvi trip(n-2,vi(3,0));

    fon(i,n-2)
    {

        vi t={a[i],a[i+1],a[i+2]};
        trip[i]=t;
        mp[t]++;
    }
    fon(i,3)
    {
        //sort on basis of other two
        sort(all(trip),[&](vi &x,vi &y){
            int a1=x[i],a2=y[i];
            int b1=x[(i+1)%3],b2=y[(i+1)%3];
            int c1=x[(i+2)%3],c2=y[(i+2)%3];
            // first sort on basis of c then b then a
            if(c1!=c2) return c1<c2;
            if(b1!=b2) return b1<b2;
            return a1<a2;
        });
        // for(auto &x:trip) cout << x << endl;
        int cnt1=0;
        int j=0;
        while(j<n-2)
        {
            map<int,int> mpp;
            int k=j;
            mpp[trip[k][i]]++;
            while((k<n-3) && (trip[k][(i+1)%3]==trip[k+1][(i+1)%3]) && (trip[k][(i+2)%3]==trip[k+1][(i+2)%3]))
            {
                mpp[trip[k+1][i]]++;
                k++;
            }
            int c1=0;
            // cout << k << " " << j << endl;
            // cout << "sz: " << mpp.size()  << " "  << c1 << endl;
            // cout << "printint map " << endl;
            for(auto [x,y]:mpp)
            {
                // cout << x << " " << y << endl;
                c1+=(k-j-y+1)*(y);
            }
            j=k+1;
            // cout << c1 << endl;
            cnt1+=c1/2;
        }
        cnt+=cnt1;
        // cout << "cnt1: " << cnt1 << endl;
        // nl nl 

    }
    cout << cnt << endl;

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
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}