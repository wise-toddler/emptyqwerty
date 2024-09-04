// https://www.codechef.com/START122B/problems/ELFMINDIST
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
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
template<typename E>class mstack : public stack<E> {public: E pop(){E a=this->top();stack<E>::pop();return a;}};
void solve()
{
    int n;cin >> n;
    vi a(n);cin >> a;
    sort(all(a));
    double ans=0;//1001
    if(n==3)
    {
        ans = (double)(a[2]-a[0])/2.0;
        cout << fixed << setprecision(6) << ans << " "<< 1 << endl;
        return;
    }
    if(n&1)
    {
        ans=1e18;
        v<double> dp1; // max b/w start and pivot 
        dp1.pb((double)(a[n-1]-a[n-2])/2.0);  
        int e = 0; 
        fo1(i,n-3,0,-2) 
            dp1.pb(max(dp1.back(),(double)(a[i]-a[i-1])/2.0));
        reverse(all(dp1));
        // deb(dp1)
        v<double> dp2; // max b/w pivot and end  
        dp2.pb((double)(a[1]-a[0])/2.0);

        fo1(i,3,n,2)
            dp2.pb(max(dp2.back(),(double)(a[i]-a[i-1])/2.0));
        // deb(dp2)

        fo1(i,0,n-1,2)
        {
            double ml = i<n-3 ?dp1[(i+2)/2]:0;
            double mr = i>0?dp2[i/2-1]:0;
            double m = (double)(a[i+2]-a[i])/2.0;
            ans = min(ans,max(m,max(ml,mr)));
            // ans = max(ans,min(ml,mr));  

        }
        cout << fixed << setprecision(6) << ans << " "<< n/2 << endl;

    }
    else
    {
        fo1(i,1,n,2)
            ans =max(ans,(double)((a[i]-a[i-1])/2.0));      
        cout << fixed << setprecision(6) << ans << " "<< n/2 << endl;
    }
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
    }
}