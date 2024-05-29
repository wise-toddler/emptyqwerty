// https://codeforces.com/contest/1898/problem/C
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
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, v<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, v<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int n,m,k;cin >> n >> m >> k;
    // cout << ((2-3-3)&1)==1 << endl;
    // int ch = k-m-n; 
    // deb(ch)
    // bool f= (k-m-n)&1;
    // deb(f)
    // cout << ((28-16-13)%2) << endl;
    if((k-m-n)&1 || k<n+m-2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    fon(i,n)
    {
        fon(j,m-1)
        {
            if(i==n-2 && j>=m-3)
                cout << "B ";
            else if(i==n-1 && (m-j)&1)
            {
                cout << "B ";
            }
            else
                cout << "R ";
        }
        nl
    }
    // return;
    fon(i,n-1)
    {
        fon(j,m)
            if(j==0 && (n+m-i-j-1)&1) 
                cout << "B ";
            else 
                cout << "R ";
        nl
    }
    // nl nl nl
    
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