// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
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

struct DSU
{
    v<int> parent;
    v<int> size;
    v<int> vals;

    DSU(int n)
    {
        for(int i = 0; i < n; ++i)
        {
            parent.push_back(i);
            size.push_back(1);
            vals.push_back(0);
        }
    }

    pii get(int node) // {node, val}
    {
        if(parent[node] == node)
        {
            return {node, vals[node]};
        }

        auto parentAns = get(parent[node]);
        
        
        int finalAns = parentAns.ss + vals[node];
        parent[node] = parentAns.ff;
        
        vals[node] = finalAns;
        vals[node] -= vals[parent[node]];

        return {parent[node], finalAns};
    }

    void join(int a, int b)
    {
        a = get(a).ff;
        b = get(b).ff;

        if(a == b) return;

        if(size[a] < size[b]) {
            swap(a, b);
        }

        // size a is greater

        parent[b] = a;
        vals[b] -= vals[a];
    }
};


void solve()
{
    int n,m; cin >> n >> m;
    DSU dsu(n + 1);
    while(m--)
    {
        string s; cin >> s;
        if(s=="add")
        {
            int x,y; cin >> x >> y;
            x = dsu.get(x).ff;
            dsu.vals[x] += y;
        }
        else if(s=="join")
        {
            int x,y; cin >> x >> y;
            dsu.join(x,y);
        }
        else
        {
            int x; cin >> x;
            cout << dsu.get(x).ss << endl;
        }
    }
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
    }
}