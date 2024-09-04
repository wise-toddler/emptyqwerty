// https://codeforces.com/problemset/problem/1809/C
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
#define sz(x) (int)x.size()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define fon_(i,n) fo1(i,n-1,-1,-1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T> v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,k; cin >> n >> k;
    vi a(n); 
    if(k==0) 
    {
        cout << vi(n,-1) << endl;
        return;
    }
    a[0]=10;
    k-=1;
    fo1(i,1,n,1)
    {
        // deb(k)
        if(i+1<=k)
        {
            a[i]=a[i-1];
            k-=i+1;
        }
        else if(k>0)
        {
            int idx=i-1;
            int sum=0;
            int e=i-k;
            // deb(e)
            // cout << (e>0)? "YES" : "NO" << endl; 
            while(e>0)
            {
                sum+=a[idx];
                idx--;
                e--;
            }   
            // deb(sum)
            a[i]=-sum-1;
            k=0;
            // if(idx) k=0;
            // k=-e;
        }
        else
        {
            int sum=0;
            fon(j,i)
            {
                sum+=a[j];
            }
            a[i]=min(-1000ll,-sum-10);
        }
        // deb(a);
    }
    cout << a << endl;
    // nl  nl
    auto f = [&](vi x)
    {
        // every subarray sum 
        vi pre(n+1,0);  
        fo1(i,1,n+1,1)
        {
            pre[i]=pre[i-1]+x[i-1];
        }

        fo1(i,1,n+1,1)
        {
            fo1(j,i,n+1,1)
            {
                cout << pre[j]-pre[i-1] << " ";
            }
        }
    };
    // f(a);

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