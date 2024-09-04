// https://www.codechef.com/START148B/problems/JUSTTWO
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

int mod=1e9+7;
int pow(int a,int b)
{
    if(b==0) return 1;
    int ans=pow(a,b/2);
    ans*=ans;
    ans%=mod;
    if(b%2) ans*=a;
    return ans%mod;    
}
void solve()
{
    int n,k;cin>>n>>k;
    vi a(n);cin>>a;
    int c=n;
    set<int> s(all(a));
    while(c>0 and k>0)
    {
        auto it=s.begin();
        s.erase(it);
        if((*it)*2>=1e9) c--;
        s.insert((*it)*2);
        k--;
    }
    if(k==0)
    {
        int sum=0;
        for(int i:s) 
        {
            sum+=i;
            sum%=mod;
        }
        cout << sum << endl;
        return;
    }
    int r=k/n;
    int l=k%n;
    // for(int &i:sum) i%=mod;
    int sum=0;
    for(int i:s)
    {
        int c=i*pow(2,r);
        c%=mod;
        sum+=c;
        sum%=mod;
    }
    int min = *s.begin();
    c=min*pow(2,l);
    c%=mod;
    sum+=c;
    sum%=mod;
    cout << sum << endl;
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