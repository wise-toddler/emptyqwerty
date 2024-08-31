// https://codeforces.com/contest/1993/problem/B
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
int solve()
{
    int n;cin >> n;
    int c1=0;
    vi a(n);cin >> a;
    sort(all(a));
    for(auto x:a)
    {
        c1+=x%2;
    }
    // cout << a << endl;
    if(c1==0 or c1==n) return 0;
    vi b=a;
    for(auto &i:b) i=i%2;
    int last1;
    int id=n-1;
    fon_(i,n)
    {
        if(b[i]==1)
        {
            last1=a[i];
            id=i;
            break;
        }
    }
    multiset<int> si; for(auto x:a) if(x%2==0) si.insert(x);
    int sum=last1;
    // int ans=0;
    int c0=n-c1;
    int ans=c0;
    while(si.size())
    {
        // cout << sum << " " << *si.begin() << endl;
        if(sum<*si.begin())
        {
            ans++;
            sum+=*si.rbegin();
            // si.erase(prev(si.end()));
        }
        else
        {
            sum+=*si.begin();
            si.erase(si.begin());
        }
        // deb(sum)
    }
    return ans;

}
signed main()
{
    IOS
    //TxtIO
    int t=1;
    cin >> t;
    while(t--)
    {
        // solve();
        cout << (solve()) << endl;
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}