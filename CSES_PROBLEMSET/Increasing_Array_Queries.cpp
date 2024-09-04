// https://cses.fi/problemset/task/2416
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
struct node {
    int * arr = NULL;
    // int * pre = NULL;
    int * ps = NULL;
    int size = 0;
    int cost = 0;
};

class mst {
public:
    v<v<node>> Tree;
    node idn;
    v < node > ci;
    node merge(node a, node b) 
    {
        if (b.size == 0) return a;
        if (a.size == 0) return b;
        node result;
        result.size = a.size + b.size;
        result.arr = new int[result.size];
        // result.pre = new int[result.size];
        result.ps = new int[result.size];
        result.cost = a.cost + b.cost;
        fon(i, a.size) 
        {
            result.arr[i] = a.arr[i];
            // result.pre[i] = a.pre[i];
            result.ps[i] = a.arr[i];
            if(i) result.ps[i] += result.ps[i-1]; 
        }
        int prev = a.arr[a.size - 1];
        fon(i, b.size) 
        {
            result.arr[i + a.size] = max(prev, b.arr[i]);
            // result.pre[i + a.size] = b.pre[i] + result.arr[i + a.size]-b.arr[i]+result.pre[i + a.size-1];
            // if(i) result.pre[i+a.size] -= b.pre[i-1];
            prev = result.arr[i + a.size];
            result.cost += result.arr[i + a.size]-b.arr[i];
            result.ps[i + a.size] = result.arr[i + a.size]+result.ps[i + a.size-1];
        }
        return result;
    }
    void query(int level, int idx, int tl, int tr, int l, int r) 
    {
        if (tl > tr or tr < l or tl > r or level == Tree.size())
            return;
        if (l <= tl and tr <= r) 
        {
            ci.pb(Tree[level][idx]);
            return;
        }
        int m = (tl + tr) / 2;
        query(level + 1, 2 * idx, tl, m, l, r);
        query(level + 1, 2 * idx + 1, m + 1, tr, l, r);
    }
    mst(v < node > & A, node idn) {
        this -> idn = idn;
        int n = A.size();
        Tree.pb(v < node > (1, idn));
        int prev = 1;
        while (prev < n) {
            Tree.pb(v < node > (2 * prev, idn));
            prev *= 2;
        }
        int levels = Tree.size();
        for (int i = 0; i < n; i++)
            Tree[levels - 1][i] = A[i];
        for (int i = levels - 2; i >= 0; i--)
            for (int j = 0; j < (1 << i); j++)
                Tree[i][j] = merge(Tree[i + 1][2 * j], Tree[i + 1][2 * j + 1]);
    }
    int query(int l, int r, int k) {
        query(0, 0, 0, Tree.back().size() - 1, l, r);
        if(ci.size()==0) return 0;
        int e=0;
        for(auto x:ci) 
        {
            cout << "e: " << e++ << endl;
            // print 
            cout << "arr: ";
            for(int i=0;i<x.size;i++) cout << x.arr[i] << ' ';
            nl
            // cout << "pre: ";
            // for(int i=0;i<x.size;i++) cout << x.pre[i] << ' ';
            // nl
            cout << "ps: ";
            for(int i=0;i<x.size;i++) cout << x.ps[i] << ' ';
            nl
            cout << "cost: " << x.cost << endl;
            nl
            
        }
        int ans = 0;
        ans = ci[0].cost;
        int prev = ci[0].arr[ci[0].size - 1];
        for (int i=1;i<ci.size();i++)
        {
            ans += ci[i].cost;
            int ii = lower_bound(ci[i].arr,ci[i].arr+ci[i].size,prev)-ci[i].arr;
            // deb(ii);
        
            ans += ii*prev;
            if(ii) ans -= ci[i].ps[ii-1];
            prev = ci[i].arr[ci[i].size-1];
        }
        ci.clear();
        return ans;
    }
};
void solve()
{
    int n,q;cin>>n>>q;
    vi arr(n);cin>>arr;
    v < node > A(n);
    for (int i = 0; i < n; i++) {
        A[i].size = 1;
        A[i].arr = new int[1];
        // A[i].pre = new int[1];
        A[i].ps = new int[1];   
        A[i].cost = 0;
        A[i].arr[0] = arr[i];
        // A[i].pre[0] = 0;
        A[i].ps[0] = arr[i];
    }
    // debug node a and node b then print them 
    // node a(),b();
    // a.size = 2;
    // a.arr = new int[2];
    // a.pre = new int[2];
    // a.arr[0] = 1;
    mst tree(A, node());
    while(q--)
    {
        int l,r;cin>>l>>r;
        fo1(i,l-1,r,1) cout << arr[i] << ' ';
        nl
        cout << tree.query(l-1,r-1,0) << endl;
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
        // cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
} 

// 67 47 97 69 68 90 10 21
// 67 67 97 97 97 97 97 97
// 0  20 
