// https://codeforces.com/gym/105120/problem/0
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
void solve()
{
    int k;cin >> k;
    int ta,fa;cin >> ta >> fa;
    int tb,fb;cin >> tb >> fb;
    int ans = 0;
    if(fa > fb)
    {
        swap(ta,tb);
        swap(fa,fb);
    }
    if(ta == tb)
    {
        ans = abs(fa-fb);
    }
    else
    {
        ans = 3;
        // check if there is a bridge in between fa and fb
        if((abs(fa-fb)>=k) || (fa%k==0) || (fb%k==0) || ((fb/k*k)>fa))
        {
            ans += abs(fa-fb);
        }
        else
        {
            // go down
            int a1 = (fa-fa/k*k) + (fb-fb/k*k);
            // go up 
            int a2 = (k-(fa-fa/k*k)) + (k-(fb-fb/k*k));
            ans += min(a1,a2);
        }
    }
    cout << ans << endl;

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