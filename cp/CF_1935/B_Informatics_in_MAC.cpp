// https://codeforces.com/contest/1935/problem/B
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
    int n; cin >> n;
    vi a(n); cin >> a;      
    map<int,int> m;
    for(auto x:a)
        m[x]++;
    
    if(m[0]==0 || m[0]==n)
    {
        cout << n << endl;
        fon(i,n)
            cout << i+1 << " " << i+1 << endl;
        return;
    }
    int i=0;
    while(m[i]!=0) i++;
    int minn = INT_MAX;
    for(int j=0;j<i;j++) minn = min(minn,m[j]);
    if(minn < 2)
    {
        cout << -1 << endl;
        return;
    }
    int mex = i;

    // cout << 2 << endl;
    map<int,int> mp1;
    // find at which index the mex becomes i
    // set of 1st half and set of 2nd half
    // set<int> s1,s2;
    int cnt = 0;  
    for(int j=0;j<n;j++)
    {
        if(a[j]>mex) continue;
        mp1[a[j]]++;
        if(m[a[j]]-mp1[a[j]]==0)
        {
            // s1.insert(j);
            cout << -1 << endl;
            return;
        }
        if(mp1[a[j]]==1)
        {
            cnt++;
            // cout << j+1 << " ";
        }
        if(cnt==mex)
        {
            cout << 2 << endl;
            cout << 1 << " " << j+1 << endl;
            cout << j+2 << " " << n << endl;
            return;
        }
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