// https://atcoder.jp/contests/abc361/tasks/abc361_d
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
void solve()
{
    int n;cin >> n;
    // vi a(n+2); 
    string a(n+2,'E'),b(n+2,'E');
    fon(i,n) cin >> a[i];
    fon(i,n) cin >> b[i];

    if(count(all(a),'B')!=count(all(b),'B'))
    {
        cout << -1 << endl;
        return;
    }

    queue<pair<string,int>> q;
    q.push({a,0});
    unordered_set<string> vis;
    vis.insert(a);
    while(!q.empty())
    {
        auto [c,steps]=q.front();q.pop();
        if(c==b)
        {
            cout << steps << endl;
            return;
        }
        int in = find(all(c),'E')-c.begin();
        fon(i,n+1)
        {
            if(c[i]=='E' || c[i+1]=='E')continue; 
            string d=c;
            d[in]=c[i];
            d[in+1]=c[i+1];
            d[i]=d[i+1]='E';
            if(vis.find(d)==vis.end())
            {
                vis.insert(d);
                q.push({d,steps+1});
            }
        }
    }
    cout << -1 << endl;
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