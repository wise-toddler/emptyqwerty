// https://www.codechef.com/START112B/problems/MAXSUMOPS
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
    int n,k;cin>>n>>k;
    vi a(n);cin>>a;
    map<int,vi> m;
    int sum=0;
    for(auto x:a)
    {
        m[x&1].pb(x);
        sum+=x;
    }
    int ans=0;
    sum+=min(k,(int)(m[1].size()));
    k-=min(k,(int)(m[1].size()));
    for(auto &x:m[1])
    {
        x++;
    }
    vector<int> temp(m[1].begin(),(m[1].begin()+2));
    cout << "R:" <<temp << endl;
    m[0].insert(m[0].end(),m[1].begin(),(m[1].begin()+min(k,(int)(m[1].size()))));
    // m[1].clear();
    // cout << m[0] << endl;



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