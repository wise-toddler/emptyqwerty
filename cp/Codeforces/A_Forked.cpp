// https://codeforces.com/contest/1904/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define fo1(i,st,en,up) for(int i=st;(i*(up>0?1:-1))<(en*(up>0?1:-1));i+=(up))
#define fon(i,n) fo1(i,0,n,1)
#define deb(x) cout << #x << ": " << x << endl;
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
void solve()
{
    int a,b,xk,yk,xq,yq;cin >> a >> b >> xk >> yk >> xq >> yq;

    set<pii> s1,s2;
    s1.insert({xk+a,yk+b});
    s1.insert({xk+a,yk-b});
    s1.insert({xk-a,yk+b});
    s1.insert({xk-a,yk-b});
    s1.insert({xk+b,yk+a});
    s1.insert({xk+b,yk-a});
    s1.insert({xk-b,yk+a});
    s1.insert({xk-b,yk-a});

    s2.insert({xq+a,yq+b});
    s2.insert({xq+a,yq-b});
    s2.insert({xq-a,yq+b});
    s2.insert({xq-a,yq-b});
    s2.insert({xq+b,yq+a});
    s2.insert({xq+b,yq-a});
    s2.insert({xq-b,yq+a});
    s2.insert({xq-b,yq-a});

    // s1 intersection s2 ka size h ans;
    int ans=0;  
    for(auto i:s1)
    {
        if(s2.find(i)!=s2.end())
            ans++;
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