// https://codeforces.com/contest/489/problem/C
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
    int m,s;cin>>m>>s;
    if(s==0) 
    {
        if(m==1) cout << "0 0" << endl;
        else cout << "-1 -1" << endl;
        return;
    }
    if(s>9*m) 
    {
        cout << "-1 -1" << endl;
        return;
    }
    string a,b(m,'0');
    int s1=s;
    fon(i,m)
    {
        int d=min(9ll,s1);
        a+=to_string(d);
        s1-=d;
    }
    int f=max(s-(m-1)*9,1ll);
    b[0]=f+'0';
    int s2=s-f;
    fo1(i,m-1,0,-1)
    {
        int d=min(9ll,s2);
        b[i]=d+'0';
        s2-=d;
    }
    cout << b << " " << a << endl;
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