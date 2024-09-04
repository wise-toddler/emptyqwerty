// https://codeforces.com/gym/512112/problem/G
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
// vector<vector<int>> dp;
int mod = 1e9 + 7;
vector<int> facs(1e5+1,1); 
int nCr(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    r = min(r, n - r);
    int nn = 1;
    int dd = 1;

    for (int i = 0; i < r; i++)
    {
        nn = (nn * (n - i)) % mod;
        dd = (dd * (i + 1)) % mod;
    }

    // Calculate modular inverse of dd
    int inverse = 1;
    int base = dd;
    int power = mod - 2;
    while (power > 0)
    {
        if (power & 1)
        {
            inverse = (inverse * base) % mod;
        }
        base = (base * base) % mod;
        power >>= 1;
    }

    // Calculate nCr modulo mod
    int result = (nn * inverse) % mod;
    return result;
}
int uniquePaths(int m, int n)
{
    if(m<n) swap(m,n);
    n--;
    m--;
    return nCr(m + n, n);
}
void solve()
{
    int n,m;cin >> n >> m;
    // dp.assign(n+1,vector<int>(m+1,0));
    int terms=(n-m)/2;
    int ans=1;
    int lastans=1;
    int nn = 1; 
    int dd = 1;
    fon(i,terms-1)
    {
        // (n-i , terms)*(n-terms+1,i+1)
        nn = (nn * (n-i-1)) % mod;
        dd = (dd * (i+1)) % mod;
        // Calculate modular inverse of dd
        int inverse = 1;
        int base = dd;
        int power = mod - 2;
        while (power > 0)
        {
            if (power & 1)
            {
                inverse = (inverse * base) % mod;
            }
            base = (base * base) % mod;
            power >>= 1;
        }
        int result = (nn * inverse) % mod;  
        // n = n
        // r = i+1;
        ans += (result*result)%mod;
        ans%=mod;
    }
    // for(auto x: dp)
    //     cout << x << endl;
    cout << (2*ans)%mod << endl;
    // cout << (28*28 + 36*7 + 45*1)*2 << endl;
}
signed main()
{
    IOS
    //TxtIO
    // calc factorials
    for(int i=1;i<=1e5;i++)
        facs[i]=(facs[i-1]*i)%mod;
    int t=1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}