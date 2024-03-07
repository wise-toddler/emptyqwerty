// https://codeforces.com/gym/502762/problem/A
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

    if(n==1)
    {
        cout << 1 <<  " " << 0 << endl;
        return;
    }
    int cnt_0=count(all(a),0);
    set<int> s(all(a));
    int minpos=0;
    while(s.find(minpos)!=s.end())
        minpos++;
    int a3 = upper_bound(all(a),minpos)-a.begin();
    // cout << a3 << " " << n << endl;
    if(a3==n-1)
    {
        cout << 1 << " " << a3 << endl;
        return;
    }
    // if(cnt_0==n)
    // {

    //     cout << n << " " << 0 << endl;
    //     return;
    // }
    // cout << a << endl;
    int ins=a[0];
    ins+=n==cnt_0;
    int ans2=0;
    if(cnt_0 == n-1)
    {   
        cout << 1 << " " << n-1 << endl;
        return;
    }
    int smin;
    if(n==2)
        smin=ins;
    fo1(i,1,n,1)
    {
        if(a[i]!=a[i-1])
            ins+=a[i]-a[i-1]-1;
        if(i==n-2)
            smin=ins;            
    }
    // deb(ins);
    // int ans=(n+2*ins-1);
    // cout << "baba";
    // cout << ins << " " << smin << endl;
    // cout << (n+2*ins-1) << " " << (n+2*smin-1) << endl;
    int out = min((n+2*ins-1),(n+2*smin-1));
    cout << 1 << " " << out << endl;
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