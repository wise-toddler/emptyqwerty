// https://codeforces.com/contest/1980/problem/C
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
bool solve()
{
    int n;cin >> n;
    vi a(n),b(n); cin >> a >> b;
    int m;cin >> m;
    vi c(m);cin >> c;

    map<int,stack<int>> eq,uneq;
    fon(i,n)
    {
        if(a[i]==b[i]) eq[b[i]].push(i);
        else uneq[b[i]].push(i);
    }
    fon_(i,m)
    {
        int q=c[i];
        if(uneq.count(q))
        {
            a[uneq[q].top()] = q;
            uneq[q].pop();
            if(uneq[q].empty()) uneq.erase(q);
        }
        else if(eq.count(q))
        {   
            
        }   
        else if(i==m-1) return 0;
    }
    return a==b;
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
        cout << (solve() ? "YES" : "NO") << endl;
        // cout << (solve() ? "Alice" : "Bob") << endl;
    }
}