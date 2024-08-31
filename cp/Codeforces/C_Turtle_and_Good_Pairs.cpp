// https://codeforces.com/contest/2003/problem/C
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
    int n;cin>>n;
    string s;cin>>s;
    map<char,int> m;
    for(char c: s)
    {
        m[c]++;
    }
    set<pair<int,char>,greater<pair<int,char>>> st;
    for(auto [c,f]: m)
    {
        st.insert({f,c});
    }
    // priority uski hogi jiski freq sabse zyaada
    int id=0;
    while(id<n)
    {
        for(auto [f,c]: st)
        {
            if(m[c]==0) continue;
            m[c]--;
            cout << c;
            id++;
        }
    }
    nl

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