// https://codeforces.com/contest/1941/problem/D   
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
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
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
template<typename T>istream& operator>>(istream& is, vector<T>& v){for(auto& x : v)is >> x;return is;}
template<typename T>ostream& operator<<(ostream& os, vector<T>& v){for(auto& x : v)os << x << ' ';return os;}
// set<int> s;
int n;
v<pair<int,char>> a;
// set<pair<int,int>> qqq;


set<int> bfs(int st)
{
    int id=0;
    set<int> p;
    p.insert(st);
    while(id<a.size())
    {
        set<int> np;
        for(auto x : p)
        {
            // if(id==a.size())
            // {
            //     s.insert(x);
            //     continue;
            // }
            int dis = a[id].first;
            char dir = a[id].second;
            if(dir == '0')
            {
                int nc = (x+dis)%n;
                np.insert(nc);
            }
            else if(dir == '1')
            {
                int nc = (x-dis+n)%n;
                np.insert(nc);
            }
            else
            {
                int nc = (x+dis)%n;
                np.insert(nc);
                nc = (x-dis+n)%n;
                np.insert(nc);
            }
        }
        id++;
        p = np;
    }
    return p;
}
void solve()
{   
    int m,k;cin >> n >> m >> k;
    a.resize(m);
    // s.clear();
    // qqq.clear();
    k--;
    // qqq.insert(make_pair(k,0));
    for(auto &x : a) cin >> x.first >> x.second;
    set<int> s = bfs(k);

    // dp();
    cout << s.size() << endl;
    for(auto x : s) cout << x+1 << " ";
    cout << endl;
    
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
