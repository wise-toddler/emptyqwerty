// // https://codeforces.com/contest/2003/problem/D1
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
// dsu with max of each component
class maxdsu {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> maxElement;
    // int lovable=0
    vi lovable;
    int maxoflovable=0;

    maxdsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        lovable.resize(n, 0);
        maxElement.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            maxElement[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            // cout << x << " " << y << endl;
            if (size[x] < size[y]) {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
            maxElement[x] = max(maxElement[x], maxElement[y]);
            if(lovable[x])
            {
                maxoflovable = max(maxoflovable,maxElement[x]);
            }
            if(lovable[y])
            {
                lovable[x]=1;
                maxoflovable = max(maxoflovable,maxElement[x]);
            }
        }
    }

    int getMaxElement(int x) {
        return maxElement[find(x)];
    }
    void ff(int x)
    {
        lovable[find(x)] = 1;
        maxoflovable = max(maxoflovable,getMaxElement(find(x)));
    }
};
void solve()
{
    int n,m;cin>>n>>m;
    vvi a(n,vi(2));
    int ll=0;
    fon(i,n)
    {
        int l;cin>>l;
        vi aa(l);cin >> aa;
        // a[i] = {1st mex and 2nd mex};
        sort(all(aa));
        unique(all(aa));
        ll=max(ll,sz(aa));
        int id=0;
        while(id<l && aa[id]==id) id++;
        a[i][0]=id;
        // deb(id)
        aa.insert(aa.begin()+id,id);
        id++;
        while(id<(l+1) && aa[id]==id) id++;
        a[i][1]=id;
    }
    // nl nl
    sort(all(a));
    // fon(i,n) 
    // {
    //     cout << a[i] << endl;
    // }
    // nl nl
    int maxm=min(m,ll+1);
    int maxy=0;
    fon_(i,n)
    {
        maxy=max(maxy,a[i][1]);
    }    
    maxdsu dsu(maxy+1);
    vi deg(maxy+1);
    fon(i,n)
    {
        // cout << a[i][0] << " " << a[i][1] << endl;
        deg[a[i][0]]++;
        dsu.unite(a[i][0],a[i][1]);
        if(deg[a[i][0]]>1)
        {
            dsu.ff(a[i][0]);
        }
    }
    // return;
    int anss=0;
    // deb(dsu.maxoflovable);
    fon(i,maxm+1)
    {
        int ans = max({i,a.back()[0],dsu.maxoflovable,(i<maxy+1)?dsu.getMaxElement(i):0});
        // cout << ans << " ";
        anss+=ans;
    }

    #define g(x) x*(x+1)/2
    // if(maxm!=m)

    // cout << maxy << "  " ;
    // cout << (maxy*(maxy+1)) << "  " ;
    // int l=min(m+1,maxy+1);
    // deb(lx);
    // deb(anss);
    anss+=(g(m)-g(maxm)); 
    cout << anss << endl;
    // nl nl
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